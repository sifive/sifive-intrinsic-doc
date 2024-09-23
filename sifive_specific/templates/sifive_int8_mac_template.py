"""
Template for rendering SiFive Custom int8 Matrix-Multiply
instruction to their corresponding intrinsics.
"""

#pylint: disable=relative-beyond-top-level
from utils import prod
from utils import TypeHelper
from enums import InstInfo
from enums import InstType


def sfqv4x8x4(args):
  return "vint{QSEW}m{WLMUL}_t".format_map(args)


def sfqv2x8x2(args):
  return "vint{QSEW}m{LMUL}_t".format_map(args)


def uivm1(args):
  return "vuint8m1_t".format_map(args)


def sivm1(args):
  return "vint8m1_t".format_map(args)


def render(G, op_list, type_list, sew_list, lmul_list, decorator_list):
  #pylint: disable=invalid-name
  # FIXME: Renaming 'G' to 'g' all in once later.
  G.inst_group_prologue()
  for decorator in decorator_list:
    decorator.write_text_header(G)
    for args in prod(OP=op_list, TYPE=type_list, SEW=sew_list, LMUL=lmul_list):
      data_type = args["TYPE"] # int or uint
      print("------------")
      print("data_type:"+data_type)
      op = args["OP"].replace(".", "_")
      real_op = args["OP"].split(".")[1]
      print("real_op:"+real_op)
      sew = args["SEW"]
      print("sew:"+str(sew))
      lmul = args["LMUL"]
      print("lmul:"+str(lmul))
      args["OP"] = real_op

#       don't have float type now according to the spec
#       if data_type == "float":
#         args["S_TYPE"] = "f"
#         args["OP"] = "f" + op
#       else:
#         args["S_TYPE"] = "x"

# return type: all vint{sew}m{lmul}
#       if real_op == "vqmaccu" and data_type == "int":
#         continue
#       elif real_op == "vqmacc" and data_type == "uint":
#         continue
#       elif real_op != "vqmaccu" and data_type == "uint":
#         continue
      if data_type == "uint":
        continue

      type_helper = TypeHelper(**args)
      args["SEW"] = args["QSEW"] # 4*sew
      lmul_multipler = 4
      print("op:"+op)
      if op.endswith("4x8x4"):
        w_vtype = sfqv4x8x4(args)
        args["LMUL"] = args["WLMUL"]
        lmul_multipler = 2
      else:
        w_vtype = sfqv2x8x2(args)

      # We don"t support all combination of sew x Fractional LMUL
      # E.g.
      #   e32mf8, e32mf4
      if (((sew*lmul_multipler) > 8 and lmul == "f8") or \
          ((sew*lmul_multipler) > 16 and lmul == "f4") or \
          ((sew*lmul_multipler) > 32 and lmul == "f2")):
        continue

      inst_info = InstInfo.get(args, decorator, InstType.VVV)
      rt = w_vtype
      print("rt:"+rt)
      if "maccsu" in op:
        print("maccsu op:"+op)
        G.func(
            inst_info,
            name="{OP}_4x8x4_int{SEW}m{LMUL}".format_map(args) +
            decorator.func_suffix,
            return_type=rt,
            **decorator.mask_args(type_helper.m, type_helper.v),
            vd=rt,
            vs1=sivm1(args),
            vs2=type_helper.uiv,
            vl=type_helper.size_t)
        G.func(
            inst_info,
            name="{OP}_2x8x2_int{SEW}m{LMUL}".format_map(args) +
            decorator.func_suffix,
            return_type=rt,
            **decorator.mask_args(type_helper.m, type_helper.v),
            vd=rt,
            vs1=sivm1(args),
            vs2=type_helper.uiv,
            vl=type_helper.size_t)
      elif "maccus" in op:
        print("maccus op:"+op)
        G.func(
            inst_info,
            name="{OP}_4x8x4_int{SEW}m{LMUL}".format_map(args) +
            decorator.func_suffix,
            return_type=rt,
            **decorator.mask_args(type_helper.m, type_helper.v),
            vd=rt,
            vs1=uivm1(args),
            vs2=type_helper.siv,
            vl=type_helper.size_t)
        G.func(
            inst_info,
            name="{OP}_2x8x2_int{SEW}m{LMUL}".format_map(args) +
            decorator.func_suffix,
            return_type=rt,
            **decorator.mask_args(type_helper.m, type_helper.v),
            vd=rt,
            vs1=uivm1(args),
            vs2=type_helper.siv,
            vl=type_helper.size_t)
      else:
        print("else op:"+op)
        G.func(
            inst_info,
            name="{OP}_4x8x4_int{SEW}m{LMUL}".format_map(args) +
            decorator.func_suffix,
            return_type=rt,
            **decorator.mask_args(type_helper.m, type_helper.v),
            vd=rt,
            vs1=type_helper.vm1,
            vs2=type_helper.v,
            vl=type_helper.size_t)
        G.func(
            inst_info,
            name="{OP}_2x8x2_int{SEW}m{LMUL}".format_map(args) +
            decorator.func_suffix,
            return_type=rt,
            **decorator.mask_args(type_helper.m, type_helper.v),
            vd=rt,
            vs1=type_helper.vm1,
            vs2=type_helper.v,
            vl=type_helper.size_t)
  G.inst_group_epilogue()
