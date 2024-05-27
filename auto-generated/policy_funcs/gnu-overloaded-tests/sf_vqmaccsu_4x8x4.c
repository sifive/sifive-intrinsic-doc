/* { dg-do compile } */
/* { dg-options "-march=rv64gcv_zvfh -mabi=lp64d -Wno-psabi -O3 -fno-schedule-insns -fno-schedule-insns2" } */

#include <riscv_vector.h>

vint32m1_t test_sf_vqmaccsu_4x8x4_i32m1_tu(vint32m1_t vd, vint8m1_t vs1, vuint8mf2_t vs2, size_t vl) {
  return __riscv_sf_vqmaccsu_4x8x4_i32m1_tu(vd, vs1, vs2, vl);
}

vint32m2_t test_sf_vqmaccsu_4x8x4_i32m2_tu(vint32m2_t vd, vint8m1_t vs1, vuint8m1_t vs2, size_t vl) {
  return __riscv_sf_vqmaccsu_4x8x4_i32m2_tu(vd, vs1, vs2, vl);
}

vint32m4_t test_sf_vqmaccsu_4x8x4_i32m4_tu(vint32m4_t vd, vint8m1_t vs1, vuint8m2_t vs2, size_t vl) {
  return __riscv_sf_vqmaccsu_4x8x4_i32m4_tu(vd, vs1, vs2, vl);
}

vint32m8_t test_sf_vqmaccsu_4x8x4_i32m8_tu(vint32m8_t vd, vint8m1_t vs1, vuint8m4_t vs2, size_t vl) {
  return __riscv_sf_vqmaccsu_4x8x4_i32m8_tu(vd, vs1, vs2, vl);
}
/* { dg-final { scan-assembler-times {vseti?vli\s+[a-z0-9]+,\s*[a-z0-9]+,\s*e[0-9]+,\s*mf?[1248],\s*t[au],\s*m[au]\s+sf\.vqmaccsu\.4x8x4[ivxfswum.]*\s+} 4 } } */
