"""
Template for rendering SiFive Custom FP32-to-int8 Ranged Clip instruction to
their corresponding intrinsics.
"""

#pylint: disable=relative-beyond-top-level
from utils import prod
from utils import TypeHelper
import copy
from enums import InstInfo
from enums import InstType


def render(G, op_list, type_list, sew_list, lmul_list, decorator_list):
  #pylint: disable=invalid-name
  # FIXME: Renaming 'G' to 'g' all in once later.
  G.inst_group_prologue()
  for decorator in decorator_list:
    decorator.write_text_header(G)
    for args in prod(OP=op_list, TYPE=type_list, SEW=sew_list, LMUL=lmul_list):
      data_type = args["TYPE"]
      op = args["OP"].replace(".", "_")
      real_op = args["OP"].split(".")[1]
      sew = args["SEW"]
      lmul = args["LMUL"]
      args["OP"] = real_op

      unsigned_p = "_xu_" in op

      if (unsigned_p and data_type == "int") \
         or not unsigned_p and data_type == "uint":
        continue

      type_helper = TypeHelper(**args)
      qfargs = copy.deepcopy(args)
      qfargs["TYPE"] = "float"
      qfargs["SEW"] = sew * 4
      if isinstance(lmul, int):
        qfargs["LMUL"] = lmul * 4
      else:
        assert lmul[0] == "f"
        if lmul[1] == "8":
          quad_lmul = "f2"
        elif lmul[1] == "4":
          quad_lmul = 1
        elif lmul[1] == "2":
          quad_lmul = 2
        qfargs["LMUL"] = quad_lmul
      quadf_type_helper = TypeHelper(**qfargs)
      G.func(
          InstInfo.get(args, decorator, InstType.VVF),
          name="{OP}_{TYPE}{SEW}m{LMUL}".format_map(args) +
          decorator.func_suffix,
          return_type=type_helper.v,
          **decorator.mask_args(type_helper.m, type_helper.v),
          **decorator.tu_dest_args(type_helper.v),
          vs2=quadf_type_helper.v,
          rs1=quadf_type_helper.s,
          vl=type_helper.size_t)

  G.inst_group_epilogue()
