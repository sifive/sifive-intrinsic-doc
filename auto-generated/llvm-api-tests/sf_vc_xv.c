// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -disable-O0-optnone \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

void test_sf_vc_xv_se_u8mf8(int bit_field27_26, int bit_field11_7,
                            vuint8mf8_t vs2, uint8_t xs1, size_t vl) {
  return __riscv_sf_vc_xv_se_u8mf8(0, 0, vs2, xs1, vl);
}

void test_sf_vc_xv_se_u8mf4(int bit_field27_26, int bit_field11_7,
                            vuint8mf4_t vs2, uint8_t xs1, size_t vl) {
  return __riscv_sf_vc_xv_se_u8mf4(0, 0, vs2, xs1, vl);
}

void test_sf_vc_xv_se_u8mf2(int bit_field27_26, int bit_field11_7,
                            vuint8mf2_t vs2, uint8_t xs1, size_t vl) {
  return __riscv_sf_vc_xv_se_u8mf2(0, 0, vs2, xs1, vl);
}

void test_sf_vc_xv_se_u8m1(int bit_field27_26, int bit_field11_7,
                           vuint8m1_t vs2, uint8_t xs1, size_t vl) {
  return __riscv_sf_vc_xv_se_u8m1(0, 0, vs2, xs1, vl);
}

void test_sf_vc_xv_se_u8m2(int bit_field27_26, int bit_field11_7,
                           vuint8m2_t vs2, uint8_t xs1, size_t vl) {
  return __riscv_sf_vc_xv_se_u8m2(0, 0, vs2, xs1, vl);
}

void test_sf_vc_xv_se_u8m4(int bit_field27_26, int bit_field11_7,
                           vuint8m4_t vs2, uint8_t xs1, size_t vl) {
  return __riscv_sf_vc_xv_se_u8m4(0, 0, vs2, xs1, vl);
}

void test_sf_vc_xv_se_u8m8(int bit_field27_26, int bit_field11_7,
                           vuint8m8_t vs2, uint8_t xs1, size_t vl) {
  return __riscv_sf_vc_xv_se_u8m8(0, 0, vs2, xs1, vl);
}

void test_sf_vc_xv_se_u16mf4(int bit_field27_26, int bit_field11_7,
                             vuint16mf4_t vs2, uint16_t xs1, size_t vl) {
  return __riscv_sf_vc_xv_se_u16mf4(0, 0, vs2, xs1, vl);
}

void test_sf_vc_xv_se_u16mf2(int bit_field27_26, int bit_field11_7,
                             vuint16mf2_t vs2, uint16_t xs1, size_t vl) {
  return __riscv_sf_vc_xv_se_u16mf2(0, 0, vs2, xs1, vl);
}

void test_sf_vc_xv_se_u16m1(int bit_field27_26, int bit_field11_7,
                            vuint16m1_t vs2, uint16_t xs1, size_t vl) {
  return __riscv_sf_vc_xv_se_u16m1(0, 0, vs2, xs1, vl);
}

void test_sf_vc_xv_se_u16m2(int bit_field27_26, int bit_field11_7,
                            vuint16m2_t vs2, uint16_t xs1, size_t vl) {
  return __riscv_sf_vc_xv_se_u16m2(0, 0, vs2, xs1, vl);
}

void test_sf_vc_xv_se_u16m4(int bit_field27_26, int bit_field11_7,
                            vuint16m4_t vs2, uint16_t xs1, size_t vl) {
  return __riscv_sf_vc_xv_se_u16m4(0, 0, vs2, xs1, vl);
}

void test_sf_vc_xv_se_u16m8(int bit_field27_26, int bit_field11_7,
                            vuint16m8_t vs2, uint16_t xs1, size_t vl) {
  return __riscv_sf_vc_xv_se_u16m8(0, 0, vs2, xs1, vl);
}

void test_sf_vc_xv_se_u32mf2(int bit_field27_26, int bit_field11_7,
                             vuint32mf2_t vs2, uint32_t xs1, size_t vl) {
  return __riscv_sf_vc_xv_se_u32mf2(0, 0, vs2, xs1, vl);
}

void test_sf_vc_xv_se_u32m1(int bit_field27_26, int bit_field11_7,
                            vuint32m1_t vs2, uint32_t xs1, size_t vl) {
  return __riscv_sf_vc_xv_se_u32m1(0, 0, vs2, xs1, vl);
}

void test_sf_vc_xv_se_u32m2(int bit_field27_26, int bit_field11_7,
                            vuint32m2_t vs2, uint32_t xs1, size_t vl) {
  return __riscv_sf_vc_xv_se_u32m2(0, 0, vs2, xs1, vl);
}

void test_sf_vc_xv_se_u32m4(int bit_field27_26, int bit_field11_7,
                            vuint32m4_t vs2, uint32_t xs1, size_t vl) {
  return __riscv_sf_vc_xv_se_u32m4(0, 0, vs2, xs1, vl);
}

void test_sf_vc_xv_se_u32m8(int bit_field27_26, int bit_field11_7,
                            vuint32m8_t vs2, uint32_t xs1, size_t vl) {
  return __riscv_sf_vc_xv_se_u32m8(0, 0, vs2, xs1, vl);
}

void test_sf_vc_xv_se_u64m1(int bit_field27_26, int bit_field11_7,
                            vuint64m1_t vs2, uint64_t xs1, size_t vl) {
  return __riscv_sf_vc_xv_se_u64m1(0, 0, vs2, xs1, vl);
}

void test_sf_vc_xv_se_u64m2(int bit_field27_26, int bit_field11_7,
                            vuint64m2_t vs2, uint64_t xs1, size_t vl) {
  return __riscv_sf_vc_xv_se_u64m2(0, 0, vs2, xs1, vl);
}

void test_sf_vc_xv_se_u64m4(int bit_field27_26, int bit_field11_7,
                            vuint64m4_t vs2, uint64_t xs1, size_t vl) {
  return __riscv_sf_vc_xv_se_u64m4(0, 0, vs2, xs1, vl);
}

void test_sf_vc_xv_se_u64m8(int bit_field27_26, int bit_field11_7,
                            vuint64m8_t vs2, uint64_t xs1, size_t vl) {
  return __riscv_sf_vc_xv_se_u64m8(0, 0, vs2, xs1, vl);
}
