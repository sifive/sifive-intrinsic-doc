/* { dg-do compile } */
/* { dg-options "-march=rv64gcv_zvfh -mabi=lp64d -Wno-psabi -O3 -fno-schedule-insns -fno-schedule-insns2" } */

#include <riscv_vector.h>

vint8mf8_t test_sf_vfnrclip_x_f_qf_i8mf8(vfloat32mf2_t vs2, float rs1, size_t vl) {
  return __riscv_sf_vfnrclip_x_f_qf_i8mf8(vs2, rs1, vl);
}

vint8mf4_t test_sf_vfnrclip_x_f_qf_i8mf4(vfloat32m1_t vs2, float rs1, size_t vl) {
  return __riscv_sf_vfnrclip_x_f_qf_i8mf4(vs2, rs1, vl);
}

vint8mf2_t test_sf_vfnrclip_x_f_qf_i8mf2(vfloat32m2_t vs2, float rs1, size_t vl) {
  return __riscv_sf_vfnrclip_x_f_qf_i8mf2(vs2, rs1, vl);
}

vint8m1_t test_sf_vfnrclip_x_f_qf_i8m1(vfloat32m4_t vs2, float rs1, size_t vl) {
  return __riscv_sf_vfnrclip_x_f_qf_i8m1(vs2, rs1, vl);
}

vint8m2_t test_sf_vfnrclip_x_f_qf_i8m2(vfloat32m8_t vs2, float rs1, size_t vl) {
  return __riscv_sf_vfnrclip_x_f_qf_i8m2(vs2, rs1, vl);
}

vint8mf8_t test_sf_vfnrclip_x_f_qf_i8mf8_m(vbool64_t vm, vfloat32mf2_t vs2, float rs1, size_t vl) {
  return __riscv_sf_vfnrclip_x_f_qf_i8mf8_m(vm, vs2, rs1, vl);
}

vint8mf4_t test_sf_vfnrclip_x_f_qf_i8mf4_m(vbool32_t vm, vfloat32m1_t vs2, float rs1, size_t vl) {
  return __riscv_sf_vfnrclip_x_f_qf_i8mf4_m(vm, vs2, rs1, vl);
}

vint8mf2_t test_sf_vfnrclip_x_f_qf_i8mf2_m(vbool16_t vm, vfloat32m2_t vs2, float rs1, size_t vl) {
  return __riscv_sf_vfnrclip_x_f_qf_i8mf2_m(vm, vs2, rs1, vl);
}

vint8m1_t test_sf_vfnrclip_x_f_qf_i8m1_m(vbool8_t vm, vfloat32m4_t vs2, float rs1, size_t vl) {
  return __riscv_sf_vfnrclip_x_f_qf_i8m1_m(vm, vs2, rs1, vl);
}

vint8m2_t test_sf_vfnrclip_x_f_qf_i8m2_m(vbool4_t vm, vfloat32m8_t vs2, float rs1, size_t vl) {
  return __riscv_sf_vfnrclip_x_f_qf_i8m2_m(vm, vs2, rs1, vl);
}
/* { dg-final { scan-assembler-times {vseti?vli\s+[a-z0-9]+,\s*[a-z0-9]+,\s*e[0-9]+,\s*mf?[1248],\s*t[au],\s*m[au]\s+sf\.vfnrclip\.x\.f\.qf[ivxfswum.]*\s+} 10 } } */
