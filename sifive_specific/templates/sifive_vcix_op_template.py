"""
Template for rendering VCIX Instructions, Xsfvcp instruction to their
corresponding intrinsics.
"""

#pylint: disable=relative-beyond-top-level
from utils import prod
from utils import TypeHelper
from enums import InstInfo
from enums import InstType

from collections import OrderedDict


def fs(args):
  return "float{SEW}_t".format_map(args)


def render(G, op_list, type_list, sew_list, lmul_list, decorator_list):
  #pylint: disable=invalid-name
  # FIXME: Renaming 'G' to 'g' all in once later.
  G.inst_group_prologue()
  for decorator in decorator_list:
    decorator.write_text_header(G)
    for args in prod(OP=op_list, TYPE=type_list, SEW=sew_list, LMUL=lmul_list):
      op = args["OP"]
      sew = args["SEW"]

      type_helper = TypeHelper(**args)

      op_components = op.split(".")
      has_vd = len(op_components) > 3

      bitfield_argumentes = OrderedDict()

      if has_vd:
        input_op_types = op_components[3]
        inst_type_str = input_op_types[::-1].upper()
        if len(input_op_types) == 3:
          vd_type = op_components[3][-1]
        else:
          vd_type = op_components[2]
          inst_type_str = vd_type.upper() + inst_type_str
      else:
        vd_type = None
        input_op_types = op_components[2]
        inst_type_str = input_op_types[::-1].upper()

      in_vd_type = vd_type

      # Construct immdiate arguments
      if "f" in input_op_types:
        bitfield_argumentes["bit_field26"] = type_helper.int
      else:
        bitfield_argumentes["bit_field27_26"] = type_helper.int

      if len(input_op_types) < 2:
        bitfield_argumentes["bit_field24_20"] = type_helper.int

      if not vd_type:
        if len(input_op_types) < 3:
          bitfield_argumentes["bit_field11_7"] = type_helper.int
        else:
          in_vd_type = input_op_types[-1]

      input_op_args = OrderedDict()

      # Construct other inputs operands
      if len(input_op_types) == 3 and in_vd_type:
        if in_vd_type == "v":
          input_op_args["vd"] = type_helper.v
        elif in_vd_type == "w":
          input_op_args["vd"] = type_helper.wv
        else:
          raise Exception(f"Unknown type? '{in_vd_type}'")

      if len(input_op_types) >= 2:
        input_op_args["vs2"] = type_helper.v

      vs1_type = input_op_types[0]
      if vs1_type == "x":
        input_op_args["xs1"] = type_helper.s
      elif vs1_type == "f":
        input_op_args["fs1"] = fs(args)
      elif vs1_type == "i":
        input_op_args["simm5"] = "int"
      elif vs1_type == "v":
        input_op_args["rs1"] = type_helper.v
      else:
        raise Exception("Unknown type?")

      # NO float8
      if vs1_type == "f" and sew < 16:
        continue

      if vd_type is None:
        return_type = type_helper.void
      elif vd_type == "w":
        return_type = type_helper.wv
      else:
        return_type = type_helper.v

      args["OP"] = args["OP"].replace(".", "_").split("_")[1]
      inst_info = InstInfo.get(args, decorator, getattr(InstType,
                                                        inst_type_str))

      # We only provide se version if there is no return value.
      if vd_type is not None:
        G.func(
            inst_info,
            name="{OP}_{TYPE}{SEW}m{LMUL}".format_map(args) +
            decorator.func_suffix,
            return_type=return_type,
            **bitfield_argumentes,
            **input_op_args,
            vl=type_helper.size_t)

      G.func(
          inst_info,
          name="{OP}_se_{TYPE}{SEW}m{LMUL}".format_map(args) +
          decorator.func_suffix,
          return_type=return_type,
          **bitfield_argumentes,
          **input_op_args,
          vl=type_helper.size_t)

  G.inst_group_epilogue()
