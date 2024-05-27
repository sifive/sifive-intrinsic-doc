// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +experimental-zvfh -disable-O0-optnone \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

vint8mf8_t test_sf_vfnrclip_x_f_qf_i8mf8_tu(vint8mf8_t vd, vfloat32mf2_t vs2, float rs1, size_t vl) {
  return __riscv_sf_vfnrclip_x_f_qf_i8mf8_tu(vd, vs2, rs1, vl);
}

vint8mf4_t test_sf_vfnrclip_x_f_qf_i8mf4_tu(vint8mf4_t vd, vfloat32m1_t vs2, float rs1, size_t vl) {
  return __riscv_sf_vfnrclip_x_f_qf_i8mf4_tu(vd, vs2, rs1, vl);
}

vint8mf2_t test_sf_vfnrclip_x_f_qf_i8mf2_tu(vint8mf2_t vd, vfloat32m2_t vs2, float rs1, size_t vl) {
  return __riscv_sf_vfnrclip_x_f_qf_i8mf2_tu(vd, vs2, rs1, vl);
}

vint8m1_t test_sf_vfnrclip_x_f_qf_i8m1_tu(vint8m1_t vd, vfloat32m4_t vs2, float rs1, size_t vl) {
  return __riscv_sf_vfnrclip_x_f_qf_i8m1_tu(vd, vs2, rs1, vl);
}

vint8m2_t test_sf_vfnrclip_x_f_qf_i8m2_tu(vint8m2_t vd, vfloat32m8_t vs2, float rs1, size_t vl) {
  return __riscv_sf_vfnrclip_x_f_qf_i8m2_tu(vd, vs2, rs1, vl);
}

vint8mf8_t test_sf_vfnrclip_x_f_qf_i8mf8_tum(vbool64_t vm, vint8mf8_t vd, vfloat32mf2_t vs2, float rs1, size_t vl) {
  return __riscv_sf_vfnrclip_x_f_qf_i8mf8_tum(vm, vd, vs2, rs1, vl);
}

vint8mf4_t test_sf_vfnrclip_x_f_qf_i8mf4_tum(vbool32_t vm, vint8mf4_t vd, vfloat32m1_t vs2, float rs1, size_t vl) {
  return __riscv_sf_vfnrclip_x_f_qf_i8mf4_tum(vm, vd, vs2, rs1, vl);
}

vint8mf2_t test_sf_vfnrclip_x_f_qf_i8mf2_tum(vbool16_t vm, vint8mf2_t vd, vfloat32m2_t vs2, float rs1, size_t vl) {
  return __riscv_sf_vfnrclip_x_f_qf_i8mf2_tum(vm, vd, vs2, rs1, vl);
}

vint8m1_t test_sf_vfnrclip_x_f_qf_i8m1_tum(vbool8_t vm, vint8m1_t vd, vfloat32m4_t vs2, float rs1, size_t vl) {
  return __riscv_sf_vfnrclip_x_f_qf_i8m1_tum(vm, vd, vs2, rs1, vl);
}

vint8m2_t test_sf_vfnrclip_x_f_qf_i8m2_tum(vbool4_t vm, vint8m2_t vd, vfloat32m8_t vs2, float rs1, size_t vl) {
  return __riscv_sf_vfnrclip_x_f_qf_i8m2_tum(vm, vd, vs2, rs1, vl);
}

vint8mf8_t test_sf_vfnrclip_x_f_qf_i8mf8_tumu(vbool64_t vm, vint8mf8_t vd, vfloat32mf2_t vs2, float rs1, size_t vl) {
  return __riscv_sf_vfnrclip_x_f_qf_i8mf8_tumu(vm, vd, vs2, rs1, vl);
}

vint8mf4_t test_sf_vfnrclip_x_f_qf_i8mf4_tumu(vbool32_t vm, vint8mf4_t vd, vfloat32m1_t vs2, float rs1, size_t vl) {
  return __riscv_sf_vfnrclip_x_f_qf_i8mf4_tumu(vm, vd, vs2, rs1, vl);
}

vint8mf2_t test_sf_vfnrclip_x_f_qf_i8mf2_tumu(vbool16_t vm, vint8mf2_t vd, vfloat32m2_t vs2, float rs1, size_t vl) {
  return __riscv_sf_vfnrclip_x_f_qf_i8mf2_tumu(vm, vd, vs2, rs1, vl);
}

vint8m1_t test_sf_vfnrclip_x_f_qf_i8m1_tumu(vbool8_t vm, vint8m1_t vd, vfloat32m4_t vs2, float rs1, size_t vl) {
  return __riscv_sf_vfnrclip_x_f_qf_i8m1_tumu(vm, vd, vs2, rs1, vl);
}

vint8m2_t test_sf_vfnrclip_x_f_qf_i8m2_tumu(vbool4_t vm, vint8m2_t vd, vfloat32m8_t vs2, float rs1, size_t vl) {
  return __riscv_sf_vfnrclip_x_f_qf_i8m2_tumu(vm, vd, vs2, rs1, vl);
}

vint8mf8_t test_sf_vfnrclip_x_f_qf_i8mf8_mu(vbool64_t vm, vint8mf8_t vd, vfloat32mf2_t vs2, float rs1, size_t vl) {
  return __riscv_sf_vfnrclip_x_f_qf_i8mf8_mu(vm, vd, vs2, rs1, vl);
}

vint8mf4_t test_sf_vfnrclip_x_f_qf_i8mf4_mu(vbool32_t vm, vint8mf4_t vd, vfloat32m1_t vs2, float rs1, size_t vl) {
  return __riscv_sf_vfnrclip_x_f_qf_i8mf4_mu(vm, vd, vs2, rs1, vl);
}

vint8mf2_t test_sf_vfnrclip_x_f_qf_i8mf2_mu(vbool16_t vm, vint8mf2_t vd, vfloat32m2_t vs2, float rs1, size_t vl) {
  return __riscv_sf_vfnrclip_x_f_qf_i8mf2_mu(vm, vd, vs2, rs1, vl);
}

vint8m1_t test_sf_vfnrclip_x_f_qf_i8m1_mu(vbool8_t vm, vint8m1_t vd, vfloat32m4_t vs2, float rs1, size_t vl) {
  return __riscv_sf_vfnrclip_x_f_qf_i8m1_mu(vm, vd, vs2, rs1, vl);
}

vint8m2_t test_sf_vfnrclip_x_f_qf_i8m2_mu(vbool4_t vm, vint8m2_t vd, vfloat32m8_t vs2, float rs1, size_t vl) {
  return __riscv_sf_vfnrclip_x_f_qf_i8m2_mu(vm, vd, vs2, rs1, vl);
}
