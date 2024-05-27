// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +experimental-zvfh -disable-O0-optnone \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

vint32m1_t test_sf_vqmaccsu_2x8x2_i32m1_tu(vint32m1_t vd, vint8m1_t vs1,
                                           vuint8m1_t vs2, size_t vl) {
  return __riscv_sf_vqmaccsu_2x8x2_i32m1_tu(vd, vs1, vs2, vl);
}

vint32m2_t test_sf_vqmaccsu_2x8x2_i32m2_tu(vint32m2_t vd, vint8m1_t vs1,
                                           vuint8m2_t vs2, size_t vl) {
  return __riscv_sf_vqmaccsu_2x8x2_i32m2_tu(vd, vs1, vs2, vl);
}

vint32m4_t test_sf_vqmaccsu_2x8x2_i32m4_tu(vint32m4_t vd, vint8m1_t vs1,
                                           vuint8m4_t vs2, size_t vl) {
  return __riscv_sf_vqmaccsu_2x8x2_i32m4_tu(vd, vs1, vs2, vl);
}

vint32m8_t test_sf_vqmaccsu_2x8x2_i32m8_tu(vint32m8_t vd, vint8m1_t vs1,
                                           vuint8m8_t vs2, size_t vl) {
  return __riscv_sf_vqmaccsu_2x8x2_i32m8_tu(vd, vs1, vs2, vl);
}
