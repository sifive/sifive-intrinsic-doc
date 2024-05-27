"""
SiFive-specific instructions.
"""

from intrinsic_decorator import IntrinsicDecorators

from templates import sifive_int8_mac_template as sfint8mac_op_tmpl
from templates import sifive_clipxfqf_template as sfclipxfqf_op_tmpl
from templates import sifive_vcix_op_template as sifive_vcix_op_tmpl
from constants import LMULS, WLMULS, NCVTLMULS, SEWS, WSEWS, ITYPES


def gen(g):
  decorators = IntrinsicDecorators(g.has_tail_policy)
  g.start_group("SiFive Custom Vector Extension Functions")

  g.function_group(
      sfint8mac_op_tmpl,
      "SiFive Custom int8 Matrix-Multiply Instructions for DLEN >= 256," +
      " Xsfvqmaccqoq", "sifive-int8-sfvqmaccqoq", [
          "sf.vqmaccu.4x8x4", "sf.vqmacc.4x8x4", "sf.vqmaccus.4x8x4",
          "sf.vqmaccsu.4x8x4"
      ], ITYPES, [8], ["f2", 1, 2, 4], decorators.has_no_masking_policy)

  g.function_group(
      sfint8mac_op_tmpl,
      "SiFive Custom int8 Matrix-Multiply Instructions for DLEN >= 128," +
      " Xsfvqmaccdod", "sifive-int8-sfvqmaccdod", [
          "sf.vqmaccu.2x8x2", "sf.vqmacc.2x8x2", "sf.vqmaccus.2x8x2",
          "sf.vqmaccsu.2x8x2"
      ], ITYPES, [8], [1, 2, 4, 8], decorators.has_no_masking_policy)

  g.function_group(
      sfclipxfqf_op_tmpl,
      "SiFive Custom FP32-to-int8 Ranged Clip Instructions, Xsfvfnrclipxfqf",
      "sifive-ranged-clip-sfvfnrclipxfqf",
      ["sf.vfnrclip.xu.f.qf", "sf.vfnrclip.x.f.qf"], ITYPES, [8],
      ["f8", "f4", "f2", 1, 2], decorators.has_masking_maskedoff_policy)

  g.function_group(
      sifive_vcix_op_tmpl, "VCIX Instructions, Xsfvcp",
      "sifive-vcix", [
          "sf.vc.x", "sf.vc.v.x", "sf.vc.i", "sf.vc.v.i", "sf.vc.vv",
          "sf.vc.v.vv", "sf.vc.xv", "sf.vc.v.xv", "sf.vc.iv", "sf.vc.v.iv",
          "sf.vc.fv", "sf.vc.v.fv", "sf.vc.vvv", "sf.vc.v.vvv", "sf.vc.xvv",
          "sf.vc.v.xvv", "sf.vc.ivv", "sf.vc.v.ivv", "sf.vc.fvv", "sf.vc.v.fvv"
      ], ["uint"], SEWS, LMULS, decorators.has_no_masking)

  g.function_group(sifive_vcix_op_tmpl, "VCIX Widen Instructions, Xsfvcp",
                   "sifive-vcix", [
                       "sf.vc.vvw", "sf.vc.v.vvw", "sf.vc.xvw", "sf.vc.v.xvw",
                       "sf.vc.ivw", "sf.vc.v.ivw", "sf.vc.fvw", "sf.vc.v.fvw"
                   ], ["uint"], WSEWS, WLMULS, decorators.has_no_masking)
