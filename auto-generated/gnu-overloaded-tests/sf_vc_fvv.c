/* { dg-do compile } */
/* { dg-options "-march=rv64gcv_zvfh -mabi=lp64d -Wno-psabi -O3 -fno-schedule-insns -fno-schedule-insns2" } */

#include <riscv_vector.h>

void test_sf_vc_fvv_se_u16mf4(int bit_field26, vuint16mf4_t vd, vuint16mf4_t vs2, _Float16 fs1, size_t vl) {
  return __riscv_sf_vc_fvv_se(0, vd, vs2, fs1, vl);
}

void test_sf_vc_fvv_se_u16mf2(int bit_field26, vuint16mf2_t vd, vuint16mf2_t vs2, _Float16 fs1, size_t vl) {
  return __riscv_sf_vc_fvv_se(0, vd, vs2, fs1, vl);
}

void test_sf_vc_fvv_se_u16m1(int bit_field26, vuint16m1_t vd, vuint16m1_t vs2, _Float16 fs1, size_t vl) {
  return __riscv_sf_vc_fvv_se(0, vd, vs2, fs1, vl);
}

void test_sf_vc_fvv_se_u16m2(int bit_field26, vuint16m2_t vd, vuint16m2_t vs2, _Float16 fs1, size_t vl) {
  return __riscv_sf_vc_fvv_se(0, vd, vs2, fs1, vl);
}

void test_sf_vc_fvv_se_u16m4(int bit_field26, vuint16m4_t vd, vuint16m4_t vs2, _Float16 fs1, size_t vl) {
  return __riscv_sf_vc_fvv_se(0, vd, vs2, fs1, vl);
}

void test_sf_vc_fvv_se_u16m8(int bit_field26, vuint16m8_t vd, vuint16m8_t vs2, _Float16 fs1, size_t vl) {
  return __riscv_sf_vc_fvv_se(0, vd, vs2, fs1, vl);
}

void test_sf_vc_fvv_se_u32mf2(int bit_field26, vuint32mf2_t vd, vuint32mf2_t vs2, float fs1, size_t vl) {
  return __riscv_sf_vc_fvv_se(0, vd, vs2, fs1, vl);
}

void test_sf_vc_fvv_se_u32m1(int bit_field26, vuint32m1_t vd, vuint32m1_t vs2, float fs1, size_t vl) {
  return __riscv_sf_vc_fvv_se(0, vd, vs2, fs1, vl);
}

void test_sf_vc_fvv_se_u32m2(int bit_field26, vuint32m2_t vd, vuint32m2_t vs2, float fs1, size_t vl) {
  return __riscv_sf_vc_fvv_se(0, vd, vs2, fs1, vl);
}

void test_sf_vc_fvv_se_u32m4(int bit_field26, vuint32m4_t vd, vuint32m4_t vs2, float fs1, size_t vl) {
  return __riscv_sf_vc_fvv_se(0, vd, vs2, fs1, vl);
}

void test_sf_vc_fvv_se_u32m8(int bit_field26, vuint32m8_t vd, vuint32m8_t vs2, float fs1, size_t vl) {
  return __riscv_sf_vc_fvv_se(0, vd, vs2, fs1, vl);
}

void test_sf_vc_fvv_se_u64m1(int bit_field26, vuint64m1_t vd, vuint64m1_t vs2, double fs1, size_t vl) {
  return __riscv_sf_vc_fvv_se(0, vd, vs2, fs1, vl);
}

void test_sf_vc_fvv_se_u64m2(int bit_field26, vuint64m2_t vd, vuint64m2_t vs2, double fs1, size_t vl) {
  return __riscv_sf_vc_fvv_se(0, vd, vs2, fs1, vl);
}

void test_sf_vc_fvv_se_u64m4(int bit_field26, vuint64m4_t vd, vuint64m4_t vs2, double fs1, size_t vl) {
  return __riscv_sf_vc_fvv_se(0, vd, vs2, fs1, vl);
}

void test_sf_vc_fvv_se_u64m8(int bit_field26, vuint64m8_t vd, vuint64m8_t vs2, double fs1, size_t vl) {
  return __riscv_sf_vc_fvv_se(0, vd, vs2, fs1, vl);
}
/* { dg-final { scan-assembler-times {vseti?vli\s+[a-z0-9]+,\s*[a-z0-9]+,\s*e[0-9]+,\s*mf?[1248],\s*t[au],\s*m[au]\s+sf\.vc\.fvv[ivxfswum.]*\s+} 15 } } */
