/* { dg-do compile } */
/* { dg-options "-march=rv64gcv_zvfh -mabi=lp64d -Wno-psabi -O3 -fno-schedule-insns -fno-schedule-insns2" } */

#include <riscv_vector.h>

vuint8mf8_t test_sf_vc_v_i_u8mf8(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_u8mf8(0, 0, 0, vl);
}

vuint8mf8_t test_sf_vc_v_i_se_u8mf8(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_se_u8mf8(0, 0, 0, vl);
}

vuint8mf4_t test_sf_vc_v_i_u8mf4(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_u8mf4(0, 0, 0, vl);
}

vuint8mf4_t test_sf_vc_v_i_se_u8mf4(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_se_u8mf4(0, 0, 0, vl);
}

vuint8mf2_t test_sf_vc_v_i_u8mf2(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_u8mf2(0, 0, 0, vl);
}

vuint8mf2_t test_sf_vc_v_i_se_u8mf2(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_se_u8mf2(0, 0, 0, vl);
}

vuint8m1_t test_sf_vc_v_i_u8m1(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_u8m1(0, 0, 0, vl);
}

vuint8m1_t test_sf_vc_v_i_se_u8m1(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_se_u8m1(0, 0, 0, vl);
}

vuint8m2_t test_sf_vc_v_i_u8m2(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_u8m2(0, 0, 0, vl);
}

vuint8m2_t test_sf_vc_v_i_se_u8m2(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_se_u8m2(0, 0, 0, vl);
}

vuint8m4_t test_sf_vc_v_i_u8m4(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_u8m4(0, 0, 0, vl);
}

vuint8m4_t test_sf_vc_v_i_se_u8m4(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_se_u8m4(0, 0, 0, vl);
}

vuint8m8_t test_sf_vc_v_i_u8m8(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_u8m8(0, 0, 0, vl);
}

vuint8m8_t test_sf_vc_v_i_se_u8m8(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_se_u8m8(0, 0, 0, vl);
}

vuint16mf4_t test_sf_vc_v_i_u16mf4(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_u16mf4(0, 0, 0, vl);
}

vuint16mf4_t test_sf_vc_v_i_se_u16mf4(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_se_u16mf4(0, 0, 0, vl);
}

vuint16mf2_t test_sf_vc_v_i_u16mf2(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_u16mf2(0, 0, 0, vl);
}

vuint16mf2_t test_sf_vc_v_i_se_u16mf2(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_se_u16mf2(0, 0, 0, vl);
}

vuint16m1_t test_sf_vc_v_i_u16m1(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_u16m1(0, 0, 0, vl);
}

vuint16m1_t test_sf_vc_v_i_se_u16m1(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_se_u16m1(0, 0, 0, vl);
}

vuint16m2_t test_sf_vc_v_i_u16m2(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_u16m2(0, 0, 0, vl);
}

vuint16m2_t test_sf_vc_v_i_se_u16m2(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_se_u16m2(0, 0, 0, vl);
}

vuint16m4_t test_sf_vc_v_i_u16m4(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_u16m4(0, 0, 0, vl);
}

vuint16m4_t test_sf_vc_v_i_se_u16m4(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_se_u16m4(0, 0, 0, vl);
}

vuint16m8_t test_sf_vc_v_i_u16m8(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_u16m8(0, 0, 0, vl);
}

vuint16m8_t test_sf_vc_v_i_se_u16m8(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_se_u16m8(0, 0, 0, vl);
}

vuint32mf2_t test_sf_vc_v_i_u32mf2(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_u32mf2(0, 0, 0, vl);
}

vuint32mf2_t test_sf_vc_v_i_se_u32mf2(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_se_u32mf2(0, 0, 0, vl);
}

vuint32m1_t test_sf_vc_v_i_u32m1(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_u32m1(0, 0, 0, vl);
}

vuint32m1_t test_sf_vc_v_i_se_u32m1(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_se_u32m1(0, 0, 0, vl);
}

vuint32m2_t test_sf_vc_v_i_u32m2(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_u32m2(0, 0, 0, vl);
}

vuint32m2_t test_sf_vc_v_i_se_u32m2(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_se_u32m2(0, 0, 0, vl);
}

vuint32m4_t test_sf_vc_v_i_u32m4(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_u32m4(0, 0, 0, vl);
}

vuint32m4_t test_sf_vc_v_i_se_u32m4(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_se_u32m4(0, 0, 0, vl);
}

vuint32m8_t test_sf_vc_v_i_u32m8(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_u32m8(0, 0, 0, vl);
}

vuint32m8_t test_sf_vc_v_i_se_u32m8(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_se_u32m8(0, 0, 0, vl);
}

vuint64m1_t test_sf_vc_v_i_u64m1(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_u64m1(0, 0, 0, vl);
}

vuint64m1_t test_sf_vc_v_i_se_u64m1(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_se_u64m1(0, 0, 0, vl);
}

vuint64m2_t test_sf_vc_v_i_u64m2(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_u64m2(0, 0, 0, vl);
}

vuint64m2_t test_sf_vc_v_i_se_u64m2(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_se_u64m2(0, 0, 0, vl);
}

vuint64m4_t test_sf_vc_v_i_u64m4(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_u64m4(0, 0, 0, vl);
}

vuint64m4_t test_sf_vc_v_i_se_u64m4(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_se_u64m4(0, 0, 0, vl);
}

vuint64m8_t test_sf_vc_v_i_u64m8(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_u64m8(0, 0, 0, vl);
}

vuint64m8_t test_sf_vc_v_i_se_u64m8(int bit_field27_26, int bit_field24_20, int simm5, size_t vl) {
  return __riscv_sf_vc_v_i_se_u64m8(0, 0, 0, vl);
}
/* { dg-final { scan-assembler-times {vseti?vli\s+[a-z0-9]+,\s*[a-z0-9]+,\s*e[0-9]+,\s*mf?[1248],\s*t[au],\s*m[au]\s+sf\.vc\.v\.i[ivxfswum.]*\s+} 44 } } */
