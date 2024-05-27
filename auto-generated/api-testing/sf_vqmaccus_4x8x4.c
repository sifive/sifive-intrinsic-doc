#include <riscv_vector.h>
#include <stdint.h>

vint32m1_t test_sf_vqmaccus_4x8x4_i32m1(vint32m1_t vd, vuint8m1_t vs1,
                                        vint8mf2_t vs2, size_t vl) {
  return __riscv_sf_vqmaccus_4x8x4_i32m1(vd, vs1, vs2, vl);
}

vint32m2_t test_sf_vqmaccus_4x8x4_i32m2(vint32m2_t vd, vuint8m1_t vs1,
                                        vint8m1_t vs2, size_t vl) {
  return __riscv_sf_vqmaccus_4x8x4_i32m2(vd, vs1, vs2, vl);
}

vint32m4_t test_sf_vqmaccus_4x8x4_i32m4(vint32m4_t vd, vuint8m1_t vs1,
                                        vint8m2_t vs2, size_t vl) {
  return __riscv_sf_vqmaccus_4x8x4_i32m4(vd, vs1, vs2, vl);
}

vint32m8_t test_sf_vqmaccus_4x8x4_i32m8(vint32m8_t vd, vuint8m1_t vs1,
                                        vint8m4_t vs2, size_t vl) {
  return __riscv_sf_vqmaccus_4x8x4_i32m8(vd, vs1, vs2, vl);
}
