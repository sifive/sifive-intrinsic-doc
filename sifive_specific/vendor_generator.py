"""
SiFive-specific generators.
"""

import copy
import re
from rvv_intrinsic_gen.generator import Generator
import rvv_intrinsic_gen.enums


def base_type_to_rif_base_type(typename):
  rif_basetype_lut = {
      "int": "Int",
      "uint": "UInt",
      "float": "Float",
      "_Float": "Float",
      "bfloat": "Bfloat"
  }

  return rif_basetype_lut[typename]

def is_tuple_type(typename):
  return "x" in typename

def parse_rif_vector_type(typename, is_always_lmul1):
  vtype = re.compile(
      r"v(int|uint|float|bfloat)(8|16|32|64)m(f8|f4|f2|1|2|4|8)x?[2-8]?_t")
  match = vtype.search(typename)
  if match:
    # LMUL information is not needed here, it is configurable in RIF.
    base_type = match.group(1)
    sew = int(match.group(2))
    base_type_str = base_type_to_rif_base_type(base_type)
    # If this type is always LMUL1 and used for reduction operation, then return
    # scalar type rather than vector type.
    if is_always_lmul1:
      return (f"Scalar{base_type_str}{sew}", f"S{base_type_str}{sew}",
              f"S{base_type_str[0]}")
    else:
      return (f"OneD{base_type_str}{sew}", f"V{base_type_str}{sew}",
              f"V{base_type_str[0]}")

  vbool = re.compile(r"vbool(1|2|4|8|16|32|64)_t")
  match = vbool.search(typename)
  if match:
    # MLEN information is not needed here as RIF will derive it there.
    return ("OneDBool", "VBool", "VB")

  return None


def parse_rif_scalar_type(typename):
  int_type_type = re.compile(r"(int|uint|float|bfloat)(8|16|32|64)_t")
  match = int_type_type.search(typename)
  if match:
    base_type = match.group(1)
    width = int(match.group(2))
    base_type_str = base_type_to_rif_base_type(base_type)
    # TODO: Only handle int with type.
    return (f"Scalar{base_type_str}{width}", f"S{base_type_str}{width}",
            f"S{base_type_str[0]}")

  if "_Float16" in typename:
    return ("ScalarFloat16", "SFloat", "SF16")
  if "float" in typename:
    return ("ScalarFloat32", "SFloat32", "SF32")
  if "double" in typename:
    return ("ScalarFloat64", "SFloat64", "SF64")

  if typename in ["size_t", "unsigned long", "unsigned int"]:
    return ("ScalarUIntXLen", "SUIntXLen", "SL")
  if typename in ["long", "ptrdiff_t", "const int", "int"]:
    return ("ScalarIntXLen", "SIntXLen", "SI")
  if typename == "void":
    return ("Void", "Void", "VO")
  if typename == "size_t *":
    return ("SizePtr", "SizePtr", "SZP")

  return None


class RIFType:
  """
  Class to handle type for RIF.
  """

  def __init__(self, typename, is_always_lmul1=False, is_force_vector=False):
    v = parse_rif_vector_type(typename, is_always_lmul1)
    if v is None:
      v = parse_rif_scalar_type(typename)
      if v and is_force_vector:
        v0 = v[0].replace("Scalar", "OneD")
        v1 = f"V{v[1][1:]}"
        v2 = f"V{v[2][1:]}"
        v = (v0, v1, v2)
    if v is None:
      raise Exception(f"Unhandled type '{typename}'.")
    self.rif_type = v[0]
    self.short_type_name = v[1]
    self.sig = v[2]

  def to_type_class(self):
    ts = self.rif_type
    if ts.startswith("OneDInt") or ts.startswith("ScalarInt"):
      return "SIGNED_INT"
    elif ts.startswith("OneDUInt") or ts.startswith("ScalarUInt"):
      return "UNSIGNED_INT"
    elif ts.startswith("OneDBool"):
      return "BOOL"
    elif ts.startswith("OneDFloat") or ts.startswith("ScalarFloat"):
      return "FLOAT"
    elif ts.startswith("OneDBfloat") or ts.startswith("ScalarBfloat"):
      return "BFLOAT"
    elif ts == "Void":
      return "VOID"
    else:
      raise Exception(f"Unhandled: {self.rif_type}")


def rvvtype2sig(typename):
  riftype = RIFType(typename)
  return riftype.sig

def first_letter_upper(s):
  return s[0].upper() + s[1:]


class RIFGenerator(Generator):
  """
  Derived generator for generating 'Operator' definitions in RIF.
  """

  def __init__(self, f, has_tail_policy):
    super().__init__()
    self.has_tail_policy = has_tail_policy
    self.fd = f
    # self.out = f
    # self.fd = open(f, "w", encoding="utf-8")

  def func(self, inst_info, name, return_type, **kwargs):
    # LMUL 0 for mask operation
    if inst_info.LMUL not in [1, 0]:
      return

    # TODO: Skip any type with tuple type for now.
    # if any(map(is_tuple_type, [return_type] + list(kwargs.values()))):
    #   return

    is_reduc = inst_info.extra_attr & rvv_intrinsic_gen.enums.ExtraAttr.REDUCE != 0
    is_load = inst_info.mem_type == rvv_intrinsic_gen.enums.MemType.LOAD
    is_store = inst_info.mem_type == rvv_intrinsic_gen.enums.MemType.STORE
    is_seg_store = is_store and any(map(is_tuple_type, [return_type] + list(kwargs.values())))
    rif_return_type = RIFType(return_type)

    # CUSTOM_OP_TYPE(AddVX32, 32, SIGNED_INT, OneDInt32, 2, OneDInt32,
    #                ScalarInt32)
    in_args_map = copy.deepcopy(kwargs)
    vl_arg_p = "vl" in in_args_map

    # Remove `vl` argument.
    in_args_map.pop("vl", None)

    # if is_reduc:
    #   # Remove `scalar` and `dest` argument for reduction.
    #   in_args_map.pop("scalar", None)
    #   in_args_map.pop("dest", None)

    if is_store:
      in_args_map.pop("base", None)

    n_in_args = len(in_args_map.keys())
    inst_attrs = self.get_tail_policy_attribute(inst_info.OP, inst_info)
    if vl_arg_p:
      inst_attrs.append("HaveVLParameter")
    else:
      inst_attrs.append("NoVLParameter")

    # Reduction operation using W1/V1 to represnt an type always LMUL=1,
    # and we translate to S here.
    output_inst_type = inst_info.inst_type.name.replace("W1",
                                                        "S").replace("V1", "S")

    def rvvtype2riftype(arg):
      arg_name = arg[0]
      arg_type = arg[1]
      is_always_lmul1 = is_reduc and (arg_name in ["dest", "scalar"])
      is_force_vector = is_load
      riftype = RIFType(arg_type, is_always_lmul1, is_force_vector)
      return riftype.rif_type
    def rvvtuple2riftype(arg):
        if type(arg) == tuple:
          arg_type = arg[1]
        else:
          arg_type = arg
        pattern = re.compile(r".*x(\d+)_t")
        match_tuple = pattern.search(arg_type)
        if pattern.match(arg_type):
          nfield = int(match_tuple.group(1))
        else:
          nfield = 1
        return nfield

    in_args = list(map(rvvtype2riftype, in_args_map.items()))
    in_args_str = ", ".join(in_args)
    in_args_sig = list(map(rvvtype2sig, in_args_map.values()))
    in_args_sig_str = "".join(in_args_sig)
    if (inst_info.inst_type == rvv_intrinsic_gen.enums.InstType.REINT
            or inst_info.inst_type == rvv_intrinsic_gen.enums.InstType.VUNDEF
            or inst_info.inst_type == rvv_intrinsic_gen.enums.InstType.LMUL_EXT
            or inst_info.inst_type == rvv_intrinsic_gen.enums.InstType.LMUL_TRUNC
            or inst_info.inst_type == rvv_intrinsic_gen.enums.InstType.VGET
            or inst_info.inst_type == rvv_intrinsic_gen.enums.InstType.VSET
            or inst_info.inst_type == rvv_intrinsic_gen.enums.InstType.VCREATE
            or inst_info.inst_type == rvv_intrinsic_gen.enums.InstType.SETVL
            or inst_info.inst_type == rvv_intrinsic_gen.enums.InstType.SETVLMAX):
      inst_attrs.append("Miscellaneous")
    if any(map(is_tuple_type, [return_type] + list(kwargs.values()))):
      input_nfields_list = list(map(rvvtuple2riftype, in_args_map.items()))
      input_nfields = "| ".join(map(str, input_nfields_list))
      output_nfield = rvvtuple2riftype(return_type)
    else:
      output_nfield = None
      input_nfields = None
    if inst_info.extra_attr & rvv_intrinsic_gen.enums.ExtraAttr.INT_EXTENSION:
      op_id = f"{inst_info.OP[1:]}"
    elif "Miscellaneous" in inst_attrs:
        op_id = f"{inst_info.OP}"
    elif inst_info.mem_type == rvv_intrinsic_gen.enums.MemType.STORE:
      op_id = f"{inst_info.OP}_v"
    elif inst_info.OP.startswith("vmv") or inst_info.OP.startswith("vfmv"):
      op_id = f"{inst_info.OP[1:]}_{'_'.join(output_inst_type.lower())}"
    elif inst_info.OP == "vid":
      op_id = "id_v"
    elif inst_info.extra_attr & rvv_intrinsic_gen.enums.ExtraAttr.CONVERT:
      x = name.split("_")
      if "rtz" in x or "rod" in x:
        suffix = "_".join(x[2:5])
      else:
        suffix = "_".join(x[1:4])
      op_id = f"{inst_info.OP[1:]}_{suffix}"
    else:
      op_id = f"{inst_info.OP[1:]}_{output_inst_type[1:].lower()}"
    if is_load or is_store:
      op_name = inst_info.OP
    else:
      op_name = inst_info.OP[1:]
    op_type = f"{first_letter_upper(op_name)}\
{output_inst_type[1:]}{inst_info.SEW}\
{rif_return_type.short_type_name + in_args_sig_str}"

    if input_nfields is not None:
      input_nf_suffix = "".join(map(str, list(map(rvvtuple2riftype, in_args_map.items()))))
      op_type = (f"{first_letter_upper(op_name)}{output_inst_type[1:]}"
                 f"{inst_info.SEW}"
                 f"{rif_return_type.short_type_name + in_args_sig_str}"
                 f"{input_nf_suffix}"
                 f"{output_nfield}"
                 )
    else:
      op_type = (f"{first_letter_upper(op_name)}{output_inst_type[1:]}"
                 f"{inst_info.SEW}"
                 f"{rif_return_type.short_type_name + in_args_sig_str}")

    patterns = re.compile(r".*_(tu.*|m.*)")
    match = patterns.search(name)
    if inst_info.mem_type == rvv_intrinsic_gen.enums.MemType.STORE and any(map(is_tuple_type, [return_type] + list(kwargs.values()))):
      # no condition here
      print("inst_info.mem_type")
      print(inst_info.mem_type)
      inst_attrs.append("SegStoreOperation")
    if inst_info.mem_type == rvv_intrinsic_gen.enums.MemType.LOAD and any(map(is_tuple_type, [return_type] + list(kwargs.values()))):
      inst_attrs.append("SegLoadOperation")
    if match:
      if op_type[-2:] == "_m":
        op_type = op_type[:-2]
      op_type = op_type + "_" + match.group(1)

    # TODO: Fix seg store.
    if is_store and not is_seg_store:
      rif_return_type = RIFType(in_args_map["vs3"], is_always_lmul1=False)

    op_ret_type_class = rif_return_type.to_type_class()

    func_decl = super().func(inst_info, name, return_type, **kwargs)
    # self.fd.write(f"// {func_decl}")
    output = f"CUSTOM_OP_TYPE({op_type}, {op_id}, {inst_info.SEW}, \
{op_ret_type_class}, {' | '.join(inst_attrs)}, \
{rif_return_type.rif_type}, {n_in_args}, {in_args_str})"

    self.fd.write(output)
    self.fd.write("\n")
  def get_tail_policy_attribute(self,name, inst_info, **kwargs):
      """
      Gets new suffix for instruction based on name and instruction information.
      """
      # policy intrinsics go here
      inst_attrs = []
      if rvv_intrinsic_gen.generator.CompatibleHeaderGenerator.is_policy_func(inst_info):
          if inst_info.extra_attr & rvv_intrinsic_gen.enums.ExtraAttr.IS_TU:
              inst_attrs.append("TailUndisturbed")
          if inst_info.extra_attr & rvv_intrinsic_gen.enums.ExtraAttr.IS_MA:
              inst_attrs.append("MaskAgnostic")
          if inst_info.extra_attr & rvv_intrinsic_gen.enums.ExtraAttr.IS_MU:
              inst_attrs.append("MaskUndisturbed")
          if inst_info.extra_attr & rvv_intrinsic_gen.enums.ExtraAttr.IS_TAMA:
              inst_attrs.append("MaskedOperation")
          if inst_info.extra_attr & rvv_intrinsic_gen.enums.ExtraAttr.IS_TAMU:
              inst_attrs.append("MaskUndisturbed")
          if inst_info.extra_attr & rvv_intrinsic_gen.enums.ExtraAttr.IS_TUMA:
              inst_attrs.append("TailUndisturbed")
              inst_attrs.append("MaskAgnostic")
          if inst_info.extra_attr & rvv_intrinsic_gen.enums.ExtraAttr.IS_TUMU:
              inst_attrs.append("TailUndisturbed")
              inst_attrs.append("MaskUndisturbed")
          if inst_info.extra_attr & rvv_intrinsic_gen.enums.ExtraAttr.IS_MASK and \
                  inst_info.extra_attr & rvv_intrinsic_gen.enums.ExtraAttr.IS_RED_TUMA:
              inst_attrs.append("TailUndisturbed")
              inst_attrs.append("MaskAgnostic")
          if inst_info.extra_attr & rvv_intrinsic_gen.enums.ExtraAttr.IS_MASK and \
                  inst_info.extra_attr & rvv_intrinsic_gen.enums.ExtraAttr.IS_RED_TAMA:
              inst_attrs.append("MaskedOperation")
          else:
            inst_attrs.append("NonmaskedOperation")
      else:  # non-policy intrinsics go here
          if inst_info.extra_attr & rvv_intrinsic_gen.enums.ExtraAttr.IS_MASK:
              inst_attrs.append("MaskedOperation")
          else:
              inst_attrs.append("NonmaskedOperation")
      if inst_info.extra_attr & rvv_intrinsic_gen.enums.ExtraAttr.REDUCE:
          inst_attrs.append("ReductionOperation")
      if inst_info.mem_type == rvv_intrinsic_gen.enums.MemType.LOAD:
          inst_attrs.append("LoadOperation")
      if inst_info.mem_type == rvv_intrinsic_gen.enums.MemType.STORE:
          inst_attrs.append("StoreOperation")
      if inst_info.extra_attr & rvv_intrinsic_gen.enums.ExtraAttr.HAS_FRM:
          inst_attrs.append("FRM")
      if inst_info.extra_attr & rvv_intrinsic_gen.enums.ExtraAttr.HAS_VXRM:
          inst_attrs.append("VXRM")
      if inst_info.extra_attr & rvv_intrinsic_gen.enums.ExtraAttr.NEED_MASKOFF:
          inst_attrs.append("NeedMaskedOff")
      if inst_info.extra_attr & rvv_intrinsic_gen.enums.ExtraAttr.NEED_MERGE:
          inst_attrs.append("NeedMerge")
      if inst_info.extra_attr & rvv_intrinsic_gen.enums.ExtraAttr.MERGE:
          inst_attrs.append("MergeOperation")
      if inst_info.extra_attr & rvv_intrinsic_gen.enums.ExtraAttr.MAC:
          inst_attrs.append("MulAddOperation")
      # if self.return_type == "VOID":
      #     inst_attrs.append("VoidOperation")
      return inst_attrs
      # CUSTOM_OP_TYPE(AddVX32, 32, SIGNED_INT, OneDInt32, 2, OneDInt32,
      #                ScalarInt32)
  def ignore_zvqmac_section(self):
    return True
