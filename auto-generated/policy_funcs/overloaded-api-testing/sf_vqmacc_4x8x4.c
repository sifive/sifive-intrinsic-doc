#include <riscv_vector.h>
#include <stdint.h>

vint32m1_t test_sf_vqmacc_4x8x4_i32m1_tu(vint32m1_t vd, vint8m1_t vs1,
                                         vint8mf2_t vs2, size_t vl) {
  return __riscv_sf_vqmacc_4x8x4_i32m1_tu(vd, vs1, vs2, vl);
}

vint32m2_t test_sf_vqmacc_4x8x4_i32m2_tu(vint32m2_t vd, vint8m1_t vs1,
                                         vint8m1_t vs2, size_t vl) {
  return __riscv_sf_vqmacc_4x8x4_i32m2_tu(vd, vs1, vs2, vl);
}

vint32m4_t test_sf_vqmacc_4x8x4_i32m4_tu(vint32m4_t vd, vint8m1_t vs1,
                                         vint8m2_t vs2, size_t vl) {
  return __riscv_sf_vqmacc_4x8x4_i32m4_tu(vd, vs1, vs2, vl);
}

vint32m8_t test_sf_vqmacc_4x8x4_i32m8_tu(vint32m8_t vd, vint8m1_t vs1,
                                         vint8m4_t vs2, size_t vl) {
  return __riscv_sf_vqmacc_4x8x4_i32m8_tu(vd, vs1, vs2, vl);
}
