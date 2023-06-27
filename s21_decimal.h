#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct s21_decimal {
  unsigned int bits[4];
} s21_decimal;

enum convert_error_code { convertation_ok, convertation_error };
enum calculation_error_code { calculation_ok, calculation_error };
enum arithmetic_error_code {
  arth_ok,
  arth_large_number,
  arth_small_number,
  arth_div_zero
};
enum { EQUAL, VALUE1_GREATER, VALUE2_GREATER };
enum other_defs { BEGIN_POWER = 16, END_POWER = 23, SIGN = 31 };

#define TRUE 1
#define FALSE 0
#define S21_EPS 1e-6
#define S21_INF 1 / 0.0
#define MAX_POWER 28
#define MAX_INT 2147483647
#define MIN_INT 2147483648U
#define S21_EPS 1e-6
#define S21_INF 1 / 0.0
#define MAX_POWER 28
#define MAX_INT 2147483647
#define MIN_INT 2147483648U
#define MAX_DEC 79228162514264337593543950335.0F
#define MIN_DEC -79228162514264337593543950335.0F
#define FLOAT_PRECISION 7

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_is_less(s21_decimal num1, s21_decimal num2);
int s21_is_less_or_equal(s21_decimal num1, s21_decimal num2);
int s21_is_greater(s21_decimal num1, s21_decimal num2);
int s21_is_greater_or_equal(s21_decimal num1, s21_decimal num2);
int s21_is_equal(s21_decimal num1, s21_decimal num2);
int s21_is_not_equal(s21_decimal num1, s21_decimal num2);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

//  UTILS
int s21_get_bit(s21_decimal number, int position);
void s21_set_bit(s21_decimal *number, int position, int val);
int s21_get_sign(s21_decimal number);
void s21_set_sign(s21_decimal *number, int sign);
void s21_delete_sign(s21_decimal *number);
int s21_get_power(s21_decimal number);
void s21_set_power(s21_decimal *number, int pow);
void s21_delete_power(s21_decimal *number);
int lshift(s21_decimal *number);
void rshift(s21_decimal *number);
int s21_div_ten(s21_decimal value);
void dec_to_zero(s21_decimal *number);
int loop_multiple(s21_decimal *src, s21_decimal multiplicand, size_t times);
int s21_normalize(s21_decimal *a, s21_decimal *b);
s21_decimal make_dec(int a, int b, int c);
unsigned int s21_get_bin_exp(unsigned int src);
void dec_to_dec(s21_decimal source, s21_decimal *dest);
s21_decimal int_div(s21_decimal divident, s21_decimal divider,
                    s21_decimal *result);
int find_first_one_bit(s21_decimal src);
s21_decimal s21_bank_rounding(s21_decimal value);
s21_decimal s21_base_bank_round(s21_decimal last_decimal, s21_decimal pre_digit,
                                s21_decimal result);
s21_decimal s21_get_pre_digit(s21_decimal value);
int s21_comparison(s21_decimal value_1, s21_decimal value_2);
int s21_sum(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_multiply(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int count_shift(s21_decimal *value, int count);
void s21_sub_util(s21_decimal max, s21_decimal min, s21_decimal *result);
int comparison_value_bits(s21_decimal value1, s21_decimal value2);
int is_zero(s21_decimal number);
s21_decimal s21_binary_mod(s21_decimal value_1, s21_decimal value_2);
s21_decimal s21_add_code(s21_decimal value);
s21_decimal s21_inversion(s21_decimal number);

#endif //  SRC_S21_DECIMAL_H_
