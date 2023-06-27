#include "../s21_decimal.h"

int test_bit(unsigned int bits, int index) { return bits & (1U << index); }

int exp_float_bin2dec(unsigned int bits) {
  int exp_int = 0;
  int index = 30;
  int exp_2 = 7;
  while (index >= 23) {
    if (test_bit(bits, index)) {
      exp_int += pow(2, exp_2);
    }
    index--;
    exp_2--;
  }
  return exp_int - 127;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  if (dst == NULL || src == INFINITY || src == -INFINITY || src < MIN_DEC ||
      src > MAX_DEC)
    return convertation_error;

  memset(&(dst->bits), 0, sizeof(dst->bits));

  if (src < 0) s21_set_sign(dst, 1);
  src = fabsf(src);

  unsigned int float_bits = *((unsigned int *)&src);
  int exp_value = exp_float_bin2dec(float_bits);

  if (exp_value > 95) return convertation_error;

  int scale = 0;
  for (; !((unsigned int)src); src *= 10, scale++) {
  }

  src *= 10 * FLOAT_PRECISION;
  scale += FLOAT_PRECISION;

  float_bits = *((unsigned int *)&src);
  exp_value = exp_float_bin2dec(float_bits);

  if (exp_value < -94 || scale > 28) return calculation_error;

  s21_set_bit(dst, scale--, 1);

  dst->bits[0] = float_bits;

  for (int i = 31; i != 22; i--) {
    s21_set_bit(dst, i, 0);
  }
  s21_set_power(dst, scale);

  return convertation_ok;
}
