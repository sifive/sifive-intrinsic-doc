#include <riscv_vector.h>
#include <stdint.h>

vuint8mf8_t test_sf_vfnrclip_xu_f_qf_u8mf8(vfloat32mf2_t vs2, float rs1,
                                           size_t vl) {
  return __riscv_sf_vfnrclip_xu_f_qf(vs2, rs1, vl);
}

vuint8mf4_t test_sf_vfnrclip_xu_f_qf_u8mf4(vfloat32m1_t vs2, float rs1,
                                           size_t vl) {
  return __riscv_sf_vfnrclip_xu_f_qf(vs2, rs1, vl);
}

vuint8mf2_t test_sf_vfnrclip_xu_f_qf_u8mf2(vfloat32m2_t vs2, float rs1,
                                           size_t vl) {
  return __riscv_sf_vfnrclip_xu_f_qf(vs2, rs1, vl);
}

vuint8m1_t test_sf_vfnrclip_xu_f_qf_u8m1(vfloat32m4_t vs2, float rs1,
                                         size_t vl) {
  return __riscv_sf_vfnrclip_xu_f_qf(vs2, rs1, vl);
}

vuint8m2_t test_sf_vfnrclip_xu_f_qf_u8m2(vfloat32m8_t vs2, float rs1,
                                         size_t vl) {
  return __riscv_sf_vfnrclip_xu_f_qf(vs2, rs1, vl);
}

vuint8mf8_t test_sf_vfnrclip_xu_f_qf_u8mf8_m(vbool64_t vm, vfloat32mf2_t vs2,
                                             float rs1, size_t vl) {
  return __riscv_sf_vfnrclip_xu_f_qf_u8mf8(vm, vs2, rs1, vl);
}

vuint8mf4_t test_sf_vfnrclip_xu_f_qf_u8mf4_m(vbool32_t vm, vfloat32m1_t vs2,
                                             float rs1, size_t vl) {
  return __riscv_sf_vfnrclip_xu_f_qf_u8mf4(vm, vs2, rs1, vl);
}

vuint8mf2_t test_sf_vfnrclip_xu_f_qf_u8mf2_m(vbool16_t vm, vfloat32m2_t vs2,
                                             float rs1, size_t vl) {
  return __riscv_sf_vfnrclip_xu_f_qf_u8mf2(vm, vs2, rs1, vl);
}

vuint8m1_t test_sf_vfnrclip_xu_f_qf_u8m1_m(vbool8_t vm, vfloat32m4_t vs2,
                                           float rs1, size_t vl) {
  return __riscv_sf_vfnrclip_xu_f_qf_u8m1(vm, vs2, rs1, vl);
}

vuint8m2_t test_sf_vfnrclip_xu_f_qf_u8m2_m(vbool4_t vm, vfloat32m8_t vs2,
                                           float rs1, size_t vl) {
  return __riscv_sf_vfnrclip_xu_f_qf_u8m2(vm, vs2, rs1, vl);
}
