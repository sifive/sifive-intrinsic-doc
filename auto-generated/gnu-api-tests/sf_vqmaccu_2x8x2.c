/* { dg-do compile } */
/* { dg-options "-march=rv64gcv_zvfh -mabi=lp64d -Wno-psabi -O3 -fno-schedule-insns -fno-schedule-insns2" } */

#include <riscv_vector.h>

vint32m1_t test_sf_vqmaccu_2x8x2_i32m1(vint32m1_t vd, vuint8m1_t vs1, vuint8m1_t vs2, size_t vl) {
  return __riscv_sf_vqmaccu_2x8x2_i32m1(vd, vs1, vs2, vl);
}

vint32m2_t test_sf_vqmaccu_2x8x2_i32m2(vint32m2_t vd, vuint8m1_t vs1, vuint8m2_t vs2, size_t vl) {
  return __riscv_sf_vqmaccu_2x8x2_i32m2(vd, vs1, vs2, vl);
}

vint32m4_t test_sf_vqmaccu_2x8x2_i32m4(vint32m4_t vd, vuint8m1_t vs1, vuint8m4_t vs2, size_t vl) {
  return __riscv_sf_vqmaccu_2x8x2_i32m4(vd, vs1, vs2, vl);
}

vint32m8_t test_sf_vqmaccu_2x8x2_i32m8(vint32m8_t vd, vuint8m1_t vs1, vuint8m8_t vs2, size_t vl) {
  return __riscv_sf_vqmaccu_2x8x2_i32m8(vd, vs1, vs2, vl);
}
/* { dg-final { scan-assembler-times {vseti?vli\s+[a-z0-9]+,\s*[a-z0-9]+,\s*e[0-9]+,\s*mf?[1248],\s*t[au],\s*m[au]\s+sf\.vqmaccu\.2x8x2[ivxfswum.]*\s+} 4 } } */
