#include "s21_decimal.h"

#include <check.h>
#include <stdlib.h>

START_TEST(s21_is_less_null) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  value_1.bits[0] = 0;
  value_2.bits[0] = 0;
  ck_assert_int_eq(s21_is_less(value_1, value_2), FALSE);
  s21_set_sign(&value_2, 1);
  ck_assert_int_eq(s21_is_less(value_1, value_2), FALSE);
}
END_TEST

START_TEST(s21_is_less_normal) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  for (int i = 1, j = 2; i < 50 || j < 51; i++, j++) {
    value_1.bits[0] = i;
    value_2.bits[0] = j;
    ck_assert_int_eq(s21_is_less(value_1, value_2), TRUE);
    ck_assert_int_eq(s21_is_less(value_2, value_1), FALSE);
  }
}
END_TEST

START_TEST(s21_is_less_negative) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  value_1.bits[0] = 20;
  value_2.bits[0] = 5;
  s21_set_sign(&value_1, 1);
  ck_assert_int_eq(s21_is_less(value_1, value_2), TRUE);
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 1);
  ck_assert_int_eq(s21_is_less(value_1, value_2), FALSE);
}
END_TEST

START_TEST(s21_is_less_pow) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  value_1.bits[0] = 50;
  value_2.bits[0] = 30;
  s21_set_power(&value_1, 8);
  s21_set_power(&value_2, 8);
  ck_assert_int_eq(s21_is_less(value_1, value_2), FALSE);
  s21_set_power(&value_2, 0);
  ck_assert_int_eq(s21_is_less(value_1, value_2), TRUE);
}
END_TEST

START_TEST(s21_is_less_both_above_zero) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  value_1.bits[0] = 50;
  value_2.bits[0] = 30;
  s21_set_power(&value_1, 8);
  s21_set_power(&value_2, 9);
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  ck_assert_int_eq(s21_is_less(value_1, value_2), TRUE);
}
END_TEST

START_TEST(s21_is_less_or_equal_normal) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  for (int i = 0, j = 1; i < 51 || j < 52; i++, j++) {
    value_1.bits[0] = i;
    value_2.bits[0] = j;
    ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), TRUE);
  }
  for (int i = 0, j = 0; i < 52 || j < 52; i++, j++) {
    value_1.bits[0] = i;
    value_2.bits[0] = j;
    ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), TRUE);
  }
}
END_TEST

START_TEST(s21_is_less_or_equal_with_sign) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  value_1.bits[0] = 123450;
  value_2.bits[0] = 123450;
  s21_set_sign(&value_2, 1);
  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), FALSE);
  s21_set_sign(&value_1, 1);
  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), TRUE);
  s21_set_sign(&value_1, 0);
  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), FALSE);
}
END_TEST

START_TEST(s21_is_greater_null) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  value_1.bits[0] = 0;
  value_2.bits[0] = 0;
  ck_assert_int_eq(s21_is_greater(value_1, value_2), FALSE);
  s21_set_sign(&value_2, 1);
  ck_assert_int_eq(s21_is_greater(value_1, value_2), FALSE);
}
END_TEST

START_TEST(s21_is_greater_normal) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  for (int i = 1, j = 2; i < 50 || j < 51; i++, j++) {
    value_1.bits[0] = i;
    value_2.bits[0] = j;
    ck_assert_int_eq(s21_is_greater(value_1, value_2), FALSE);
    ck_assert_int_eq(s21_is_greater(value_2, value_1), TRUE);
  }
}
END_TEST

START_TEST(s21_is_greater_negative) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  value_1.bits[0] = 20;
  value_2.bits[0] = 5;
  s21_set_sign(&value_1, 1);
  ck_assert_int_eq(s21_is_greater(value_1, value_2), FALSE);
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 1);
  ck_assert_int_eq(s21_is_greater(value_1, value_2), TRUE);
}
END_TEST

START_TEST(s21_is_greater_two_negative) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  value_1.bits[0] = 20;
  value_2.bits[0] = 5;
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  ck_assert_int_eq(s21_is_greater(value_1, value_2), FALSE);
}
END_TEST

START_TEST(s21_is_greater_pow) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  value_1.bits[0] = 50;
  value_2.bits[0] = 30;
  s21_set_power(&value_1, 8);
  s21_set_power(&value_2, 8);
  ck_assert_int_eq(s21_is_greater(value_1, value_2), TRUE);
  s21_set_power(&value_2, 0);
  ck_assert_int_eq(s21_is_greater(value_1, value_2), FALSE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_normal) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  for (int i = 0, j = 1; i < 51 || j < 52; i++, j++) {
    value_1.bits[0] = i;
    value_2.bits[0] = j;
    ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), FALSE);
  }
  for (int i = 0, j = 0; i < 52 || j < 52; i++, j++) {
    value_1.bits[0] = i;
    value_2.bits[0] = j;
    ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), TRUE);
  }
}
END_TEST

START_TEST(s21_is_greater_or_equal_with_sign) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  value_1.bits[0] = 123450;
  value_2.bits[0] = 123450;
  s21_set_sign(&value_2, 1);
  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), TRUE);
  s21_set_sign(&value_1, 1);
  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), TRUE);
  s21_set_sign(&value_2, 0);
  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), FALSE);
}
END_TEST

START_TEST(s21_int_and_decimal_max) {
  s21_decimal value_1 = {0};
  value_1.bits[0] = 4294967295;
  int a = 0;
  int res = s21_from_decimal_to_int(value_1, &a);
  ck_assert_int_eq(res, convertation_error);
}
END_TEST

START_TEST(s21_int_and_decimal_big_pow) {
  s21_decimal value_1 = {0};
  int result = 184467440;
  value_1.bits[0] = 344;
  value_1.bits[1] = 4294967295;
  int a = 0;
  s21_set_power(&value_1, 11);
  s21_from_decimal_to_int(value_1, &a);
  ck_assert_int_eq(a, result);
}
END_TEST

START_TEST(s21_int_and_decimal_int_overflow) {
  s21_decimal value_1 = {0};
  value_1.bits[0] = 2147483650U;
  s21_set_sign(&value_1, 1);
  int a = 0;
  ck_assert_int_eq(s21_from_decimal_to_int(value_1, &a), convertation_error);
}
END_TEST

START_TEST(s21_int_and_decimal_error) {
  s21_decimal value_1 = {0};
  value_1.bits[0] = 2147483648;
  int a = 0;
  s21_set_sign(&value_1, 1);
  int res = s21_from_decimal_to_int(value_1, &a);
  ck_assert_int_eq(res, convertation_error);
  s21_decimal value_2 = {0};
  int *b = NULL;
  res = s21_from_decimal_to_int(value_2, b);
  ck_assert_int_eq(res, convertation_error);
  s21_decimal *dst = NULL;
  int c = 0;
  res = s21_from_int_to_decimal(c, dst);
  ck_assert_int_eq(res, convertation_error);
}
END_TEST

START_TEST(s21_int_and_decimal_sign) {
  s21_decimal value_1 = {0};
  int a = -5;
  s21_decimal test = {{5}};
  s21_from_int_to_decimal(a, &value_1);
  ck_assert_int_eq(value_1.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(value_1), 1);
}
END_TEST

START_TEST(s21_int_and_decimal_whith_pow) {
  s21_decimal value_1 = {0};
  int a = 0;
  value_1.bits[0] = 5;
  s21_set_power(&value_1, 20);
  s21_from_decimal_to_int(value_1, &a);
  ck_assert_int_eq(a, 0);
}
END_TEST

START_TEST(s21_int_and_decimal_nul) {
  s21_decimal value_1 = {0};
  s21_decimal test = {0};
  int a = 0;
  s21_from_int_to_decimal(a, &value_1);
  ck_assert_int_eq(value_1.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(value_1), 0);
  a = 123456;
  test.bits[0] = 123456;
  s21_from_int_to_decimal(a, &value_1);
  ck_assert_int_eq(value_1.bits[0], test.bits[0]);
  s21_set_sign(&value_1, 1);
  int b = 0;
  s21_from_decimal_to_int(value_1, &b);
  ck_assert_int_eq(value_1.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(value_1), 1);
}
END_TEST

START_TEST(s21_sub_normal) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  value_1.bits[0] = 155;
  value_2.bits[0] = 55;
  s21_sub(value_1, value_2, &result);
  s21_decimal test = {0};
  test.bits[0] = 100;
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  memset(&result, 0, sizeof(s21_decimal));
  value_1.bits[0] = 50;
  value_2.bits[0] = 150;
  s21_sub(value_1, value_2, &result);
  int sign = s21_get_sign(result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(sign, 1);
  memset(&result, 0, sizeof(s21_decimal));
  s21_set_power(&value_2, 2);
  test.bits[0] = 4850;
  s21_sub(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_power(result), 2);
  ck_assert_uint_eq(s21_get_sign(result), 0);
}
END_TEST

START_TEST(s21_sub_inf) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  value_1.bits[0] = 4294967295;
  value_1.bits[1] = 4294967295;
  value_1.bits[2] = 4294967295;
  value_2.bits[0] = 55;
  s21_set_sign(&value_1, 1);
  int res = s21_sub(value_1, value_2, &result);
  ck_assert_uint_eq(res, arth_small_number);
}
END_TEST

START_TEST(s21_sub_one_sign) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  value_1.bits[0] = 150;
  value_2.bits[0] = 50;
  s21_set_sign(&value_1, 1);
  s21_sub(value_1, value_2, &result);
  s21_decimal test = {0};
  test.bits[0] = 200;
  ck_assert_int_eq(result.bits[0], test.bits[0]);
  int sign = s21_get_sign(result);
  ck_assert_int_eq(sign, 1);
  memset(&result, 0, sizeof(s21_decimal));
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 1);
  s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0], test.bits[0]);
  int sign1 = s21_get_sign(result);
  ck_assert_int_eq(sign1, 0);
}
END_TEST

START_TEST(s21_sub_two_sign) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  value_1.bits[0] = 150;
  value_2.bits[0] = 50;
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  s21_sub(value_1, value_2, &result);
  s21_decimal test = {0};
  test.bits[0] = 100;
  ck_assert_int_eq(result.bits[0], test.bits[0]);
  int sign = s21_get_sign(result);
  ck_assert_int_eq(sign, 1);
  memset(&result, 0, sizeof(s21_decimal));
  s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0], test.bits[0]);
  int sign1 = s21_get_sign(result);
  ck_assert_int_eq(sign1, 1);
  value_1.bits[0] = 50;
  value_2.bits[0] = 150;
  memset(&result, 0, sizeof(s21_decimal));
  s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0], test.bits[0]);
  sign1 = s21_get_sign(result);
  ck_assert_int_eq(sign1, 1);
}
END_TEST

START_TEST(s21_div_normal) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  value_1.bits[0] = 150;
  value_2.bits[0] = 10;
  s21_div(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0], 15);
  value_1.bits[0] = 5;
  value_2.bits[0] = 500;
  s21_div(value_2, value_1, &result);
  ck_assert_int_eq(result.bits[0], 100);
  value_1.bits[0] = 5;
  value_2.bits[0] = 350;
  s21_div(value_2, value_1, &result);
  ck_assert_int_eq(result.bits[0], 70);
}
END_TEST

START_TEST(s21_div_equal) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  value_1.bits[0] = 150;
  value_2.bits[0] = 150;
  s21_div(value_1, value_1, &result);
  ck_assert_int_eq(result.bits[0], 1);
  s21_set_sign(&value_1, 1);
  s21_div(value_2, value_1, &result);
  ck_assert_int_eq(result.bits[0], 1);
  ck_assert_int_eq(s21_get_sign(result), 1);
}
END_TEST

START_TEST(part1_div_zero) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  value_1.bits[0] = 150;
  value_2.bits[0] = 0;
  int result1 = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(result1, arth_div_zero);
  s21_set_sign(&value_2, 1);
  result1 = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(result1, arth_div_zero);
}
END_TEST

START_TEST(s21_div_one) {
  s21_decimal value_1 = {{745}};
  s21_decimal value_2 = {{1}};
  s21_decimal result = {0};
  s21_div(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], value_1.bits[0]);
  ck_assert_uint_eq(s21_get_sign(result), 0);
  memset(&result, 0, sizeof(s21_decimal));
  s21_set_sign(&value_2, 1);
  s21_div(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], value_1.bits[0]);
  ck_assert_uint_eq(s21_get_sign(result), 1);
}
END_TEST

START_TEST(s21_mod_max_dec) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  value_1.bits[0] = 4294967295;
  value_1.bits[1] = 4294967295;
  value_1.bits[2] = 4294967295;
  value_2.bits[0] = 4294967295;
  value_2.bits[1] = 4294967295;
  value_2.bits[2] = 4294967295;
  s21_mod(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_power(result), 0);
}
END_TEST

START_TEST(s21_mod_max_dec_and_two) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  value_1.bits[0] = 4294967295;
  value_1.bits[1] = 4294967295;
  value_1.bits[2] = 4294967295;
  value_2.bits[0] = 2;
  test.bits[0] = 1;
  s21_mod(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_power(result), 0);
}
END_TEST

START_TEST(s21_mod_max_dec_and_biguint) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  value_1.bits[0] = 4294967295;
  value_1.bits[1] = 4294967295;
  value_1.bits[2] = 4294967295;
  value_2.bits[0] = 429496729;
  test.bits[0] = 215;
  s21_mod(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_power(result), 0);
}
END_TEST

START_TEST(s21_mod_dec_with_pow) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  value_1.bits[0] = 4294967295;
  value_2.bits[0] = 523467;
  test.bits[0] = 222906;
  s21_set_power(&value_2, 4);
  s21_mod(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_power(result), 4);
}
END_TEST

START_TEST(s21_mod_dec_revers) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  value_1.bits[0] = 523467;
  value_2.bits[0] = 4294967295;
  test.bits[0] = 523467;
  s21_set_power(&value_1, 4);
  s21_mod(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_power(result), 4);
}
END_TEST

START_TEST(s21_mod_dec_error) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  value_1.bits[0] = 523467;
  int over = s21_mod(value_1, value_2, &result);
  ck_assert_uint_eq(over, arth_div_zero);
}
END_TEST

START_TEST(s21_mod_sign) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  value_1.bits[0] = 523467;
  value_2.bits[0] = 4294967295;
  test.bits[0] = 523467;
  s21_set_power(&value_1, 4);
  s21_set_sign(&value_1, 1);
  s21_mod(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_power(result), 4);
  ck_assert_uint_eq(s21_get_sign(result), 1);
}
END_TEST

START_TEST(s21_mod_over) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  value_1.bits[0] = 4294967295;
  value_1.bits[1] = 4294967295;
  value_1.bits[2] = 4294967295;
  value_2.bits[0] = 523467;
  s21_set_power(&value_2, 10);
  s21_mod(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
}
END_TEST

START_TEST(s21_mod_over_norm) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  value_1.bits[0] = 4294967295;
  value_1.bits[1] = 4294967295;
  value_1.bits[2] = 4294967295;
  value_2.bits[0] = 523467;
  test.bits[0] = 4257;
  s21_set_power(&value_2, 1);
  s21_mod(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
}
END_TEST

START_TEST(isEqual_1) {
  s21_decimal a = {{48, 0}}, b = {{48, 0}};
  ck_assert_uint_eq(s21_is_equal(a, b), 1);
}
END_TEST

START_TEST(isEqual_2) {
  s21_decimal a = {{1, 1, 0, 0}}, b = {{1, 1, 1, 0}};
  ck_assert_uint_eq(s21_is_equal(a, b), 0);
}
END_TEST

START_TEST(s21_mul_value_1_is_one) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  value_1.bits[0] = 1;
  value_2.bits[0] = 10;
  test.bits[0] = 10;
  s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  s21_set_sign(&value_1, 1);
  memset(&result, 0, sizeof(s21_decimal));
  s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_sign(result), 1);
}
END_TEST

START_TEST(s21_mul_value_2_is_one) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  value_1.bits[0] = 15;
  value_2.bits[0] = 1;
  test.bits[0] = 15;
  s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
}
END_TEST

START_TEST(s21_mul_value_1_is_zero) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  value_1.bits[0] = 0;
  value_2.bits[0] = 100;
  test.bits[0] = 0;
  s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
}
END_TEST

START_TEST(s21_mul_value_2_is_zero) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  value_1.bits[0] = 7;
  value_2.bits[0] = 0;
  test.bits[0] = 0;
  s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
}
END_TEST

START_TEST(s21_mul_max) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  value_1.bits[0] = 4294967295;
  value_1.bits[1] = 4294967295;
  value_1.bits[2] = 4294967295;
  value_2.bits[0] = 5;
  test.bits[0] = 4294967293;
  test.bits[1] = 4294967295;
  test.bits[2] = 2147483647;
  s21_set_power(&value_2, 1);
  int res = s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_power(result), 0);
  ck_assert_uint_eq(s21_get_sign(result), 0);
  ck_assert_uint_eq(res, 0);
}
END_TEST

START_TEST(s21_mul_big_power) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  value_1.bits[0] = 4294967295;
  value_2.bits[0] = 255;
  test.bits[0] = 4294967041;
  test.bits[1] = 254;
  s21_set_power(&value_2, 10);
  int res = s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_power(result), 10);
  ck_assert_uint_eq(s21_get_sign(result), 0);
  ck_assert_uint_eq(res, 0);
}
END_TEST

START_TEST(s21_mul_big_negative_over) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  value_1.bits[0] = 4294967295;
  value_1.bits[1] = 4294967295;
  value_1.bits[2] = 4294967295;
  value_2.bits[0] = 15;
  s21_set_power(&value_2, 1);
  s21_set_sign(&value_2, 1);
  int res = s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(res, arth_small_number);
}
END_TEST

START_TEST(s21_mul_big_over) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  value_1.bits[0] = 4294967295;
  value_1.bits[1] = 4294967295;
  value_1.bits[2] = 4294967295;
  value_2.bits[0] = 15;
  s21_set_power(&value_2, 1);
  int res = s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(res, arth_large_number);
}
END_TEST

START_TEST(s21_mul_norm) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  value_1.bits[0] = 4294967295;
  value_1.bits[1] = 4294967295;
  value_1.bits[2] = 4294967295;
  value_2.bits[0] = 15;
  s21_set_power(&value_2, 4);
  int res = s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(s21_get_power(result), 2);
  ck_assert_uint_eq(res, arth_ok);
}
END_TEST

START_TEST(s21_mul_value_1_is_minus) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  s21_set_sign(&value_1, 1);
  value_1.bits[0] = 15;
  value_2.bits[0] = 1;
  test.bits[0] = 15;
  s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_sign(result), 1);
}
END_TEST

START_TEST(s21_mul_value_2_is_minus) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  value_1.bits[0] = 15;
  s21_set_sign(&value_2, 1);
  value_2.bits[0] = 1;
  test.bits[0] = 15;
  s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_sign(result), 1);
}
END_TEST

START_TEST(s21_mul_value_1_is_zero_minus) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  s21_set_sign(&value_1, 1);
  value_1.bits[0] = 0;
  value_2.bits[0] = 100;
  test.bits[0] = 0;
  s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_sign(result), 1);
}
END_TEST

START_TEST(s21_mul_value_2_is_zero_minus) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  value_1.bits[0] = 7;
  s21_set_sign(&value_2, 1);
  value_2.bits[0] = 0;
  test.bits[0] = 0;
  s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_sign(result), 1);
}
END_TEST

START_TEST(s21_mul_value_1_2_is_minus) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  value_1.bits[0] = 0;
  value_2.bits[0] = 100;
  test.bits[0] = 0;
  s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_sign(result), 0);
}
END_TEST

START_TEST(s21_mul_max_1) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  value_1.bits[0] = 4294967295;
  value_1.bits[1] = 4294967295;
  value_1.bits[2] = 4294967295;
  s21_set_sign(&value_1, 1);
  value_2.bits[0] = 5;
  s21_set_sign(&value_2, 1);
  test.bits[0] = 4294967293;
  test.bits[1] = 4294967295;
  test.bits[2] = 2147483647;
  s21_set_power(&value_2, 1);
  int res = s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_power(result), 0);
  ck_assert_uint_eq(s21_get_sign(result), 0);
  ck_assert_uint_eq(res, 0);
}
END_TEST

START_TEST(s21_mul_max_2) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  value_1.bits[0] = 4294967295;
  s21_set_sign(&value_1, 1);
  value_1.bits[1] = 4294967295;
  value_1.bits[2] = 4294967295;
  value_2.bits[0] = 5;
  test.bits[0] = 4294967293;
  test.bits[1] = 4294967295;
  test.bits[2] = 2147483647;
  s21_set_power(&value_2, 1);
  int res = s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_power(result), 0);
  ck_assert_uint_eq(s21_get_sign(result), 1);
  ck_assert_uint_eq(res, 0);
}
END_TEST

START_TEST(s21_mul_max_3) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  s21_set_sign(&value_1, 1);
  value_1.bits[0] = 4294967295;
  value_1.bits[1] = 4294967295;
  value_1.bits[2] = 4294967295;
  value_2.bits[0] = 5;
  test.bits[0] = 4294967293;
  test.bits[1] = 4294967295;
  test.bits[2] = 2147483647;
  s21_set_power(&value_2, 1);
  int res = s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_power(result), 0);
  ck_assert_uint_eq(s21_get_sign(result), 1);
  ck_assert_uint_eq(res, 0);
}
END_TEST

START_TEST(s21_round_positive_integer) {
  s21_decimal result = {0};
  s21_decimal value = {0};
  value.bits[0] = 11;
  s21_decimal test = {{11}};
  int s21_result = s21_round(value, &result);
  ck_assert_int_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 0);
  ck_assert_int_eq(s21_result, arth_ok);
}
END_TEST

START_TEST(s21_round_null) {
  s21_decimal *result = NULL;
  s21_decimal value = {0};
  int s21_result = s21_round(value, result);
  ck_assert_int_eq(s21_result, convertation_error);
}
END_TEST

START_TEST(s21_round_negative_integer) {
  s21_decimal result = {0};
  s21_decimal value = {0};
  value.bits[0] = 12;
  s21_decimal test = {{12}};
  s21_set_sign(&value, 1);
  int s21_result = s21_round(value, &result);
  ck_assert_int_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 1);
  ck_assert_int_eq(s21_result, arth_ok);
}
END_TEST

START_TEST(s21_round_positive_non_integer_1) {
  s21_decimal result = {0};
  s21_decimal value = {0};
  value.bits[0] = 2463;
  s21_decimal test = {{2}};
  s21_set_power(&value, 3);
  int s21_result = s21_round(value, &result);
  ck_assert_int_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 0);
  ck_assert_int_eq(s21_result, arth_ok);
}
END_TEST

START_TEST(s21_round_positive_non_integer_2) {
  s21_decimal result = {0};
  s21_decimal value = {0};
  value.bits[0] = 2863;
  s21_decimal test = {{3}};
  s21_set_power(&value, 3);
  int s21_result = s21_round(value, &result);
  ck_assert_int_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 0);
  ck_assert_int_eq(s21_result, arth_ok);
}
END_TEST

START_TEST(s21_round_negative_non_integer_1) {
  s21_decimal result = {0};
  s21_decimal value = {0};
  value.bits[0] = 2463;
  s21_decimal test = {{2}};
  s21_set_sign(&value, 1);
  s21_set_power(&value, 3);
  int s21_result = s21_round(value, &result);
  ck_assert_int_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 1);
  ck_assert_int_eq(s21_result, arth_ok);
}
END_TEST

START_TEST(s21_round_negative_non_integer_2) {
  s21_decimal result = {0};
  s21_decimal value = {0};
  value.bits[0] = 2753;
  s21_decimal test = {{3}};
  s21_set_sign(&value, 1);
  s21_set_power(&value, 3);
  int s21_result = s21_round(value, &result);
  ck_assert_int_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 1);
  ck_assert_int_eq(s21_result, arth_ok);
}
END_TEST

START_TEST(s21_round_zero) {
  s21_decimal result = {0};
  s21_decimal value = {0};
  s21_decimal test = {0};
  int s21_result = s21_round(value, &result);
  ck_assert_int_eq(s21_result, arth_ok);
  ck_assert_int_eq(s21_get_sign(result), 0);
  ck_assert_int_eq(result.bits[0], test.bits[0]);
}
END_TEST

START_TEST(s21_floor_positive_integer) {
  s21_decimal result = {0};
  s21_decimal value = {0};
  value.bits[0] = 7;
  s21_decimal test = {{7}};
  int s21_result = s21_floor(value, &result);
  ck_assert_int_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 0);
  ck_assert_int_eq(s21_result, arth_ok);
}
END_TEST

START_TEST(s21_floor_null) {
  s21_decimal *result = NULL;
  s21_decimal value = {0};
  int s21_result = s21_floor(value, result);
  ck_assert_int_eq(s21_result, convertation_error);
}
END_TEST

START_TEST(s21_floor_negative_integer) {
  s21_decimal result = {0};
  s21_decimal value = {0};
  value.bits[0] = 12;
  s21_decimal test = {{12}};
  s21_set_sign(&value, 1);
  int s21_result = s21_floor(value, &result);
  ck_assert_int_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 1);
  ck_assert_int_eq(s21_result, arth_ok);
}
END_TEST

START_TEST(s21_floor_positive_non_integer) {
  s21_decimal result = {0};
  s21_decimal value = {0};
  value.bits[0] = 2463;
  s21_decimal test = {{2}};
  s21_set_power(&value, 3);
  int s21_result = s21_floor(value, &result);
  ck_assert_int_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 0);
  ck_assert_int_eq(s21_result, arth_ok);
}
END_TEST

START_TEST(s21_floor_negative_non_integer) {
  s21_decimal result = {0};
  s21_decimal value = {0};
  value.bits[0] = 2463;
  s21_decimal test = {{3}};
  s21_set_sign(&value, 1);
  s21_set_power(&value, 3);
  int s21_result = s21_floor(value, &result);
  ck_assert_int_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 1);
  ck_assert_int_eq(s21_result, arth_ok);
}
END_TEST

START_TEST(s21_floor_zero) {
  s21_decimal result = {0};
  s21_decimal value = {0};
  s21_decimal test = {0};
  int s21_result = s21_floor(value, &result);
  ck_assert_int_eq(s21_result, arth_ok);
  ck_assert_int_eq(s21_get_sign(result), 0);
  ck_assert_int_eq(result.bits[0], test.bits[0]);
}
END_TEST

START_TEST(s21_not_equal_null) {
  s21_decimal value = {0};
  s21_decimal test = {0};
  int res = s21_is_not_equal(value, test);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_not_equal_normal) {
  s21_decimal value = {{5}};
  s21_decimal test = {{6}};
  int res = s21_is_not_equal(value, test);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_not_equal_negative) {
  s21_decimal value = {{5}};
  s21_decimal test = {{5}};
  s21_set_sign(&value, 1);
  int res = s21_is_not_equal(value, test);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_sum_normal) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {{1535}};
  value_1.bits[0] = 150;
  value_2.bits[0] = 35;
  s21_set_power(&value_2, 1);
  s21_add(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_power(result), 1);
  ck_assert_int_eq(s21_get_sign(result), 0);
}
END_TEST

START_TEST(s21_sum_both_neg) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {{1535}};
  value_1.bits[0] = 150;
  value_2.bits[0] = 35;
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  s21_set_power(&value_2, 1);
  s21_add(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_power(result), 1);
  ck_assert_int_eq(s21_get_sign(result), 1);
}
END_TEST

START_TEST(s21_sum_error) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  value_1.bits[0] = 4294967295;
  value_1.bits[1] = 4294967295;
  value_1.bits[2] = 4294967295;
  value_2.bits[0] = 35;
  int res = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(res, arth_large_number);
  s21_set_sign(&value_2, 1);
  s21_set_sign(&value_1, 1);
  memset(&result, 0, sizeof(s21_decimal));
  res = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(res, arth_small_number);
}
END_TEST

START_TEST(s21_one_greater) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  value_1.bits[0] = 540;
  value_2.bits[0] = 560;
  s21_decimal test = {{20}};
  s21_set_sign(&value_2, 1);
  s21_add(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 1);
}
END_TEST

START_TEST(s21_one_sign) {
  s21_decimal value_1 = {{150}};
  s21_decimal value_2 = {{50}};
  s21_decimal result = {0};
  s21_decimal test = {{100}};
  s21_set_sign(&value_1, 1);
  s21_add(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_power(result), 0);
  ck_assert_int_eq(s21_get_sign(result), 1);
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 1);
  memset(&result, 0, sizeof(s21_decimal));
  s21_add(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_power(result), 0);
  ck_assert_int_eq(s21_get_sign(result), 0);
}
END_TEST

START_TEST(s21_truncate_normal) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  s21_decimal test = {{150}};
  value_1.bits[0] = 150;
  s21_truncate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 0);
}
END_TEST

START_TEST(s21_truncate_null) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  s21_decimal test = {{0}};
  s21_truncate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 0);
}
END_TEST

START_TEST(s21_truncate_negative) {
  s21_decimal value_1 = {{150}};
  s21_decimal result = {0};
  s21_decimal test = {{150}};
  s21_set_sign(&value_1, 1);
  s21_truncate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 1);
}
END_TEST

START_TEST(s21_truncate_pow) {
  s21_decimal value_1 = {{154345}};
  s21_decimal result = {0};
  s21_decimal test = {{154}};
  s21_set_sign(&value_1, 1);
  s21_set_power(&value_1, 3);
  s21_truncate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 1);
}
END_TEST

START_TEST(s21_negate_normal) {
  s21_decimal value_1 = {{154345}};
  s21_decimal result = {0};
  s21_decimal test = {{154345}};
  s21_set_sign(&value_1, 1);
  s21_negate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 0);
}
END_TEST

START_TEST(s21_negate_null) {
  s21_decimal value_1 = {{0}};
  s21_decimal result = {0};
  s21_decimal test = {0};
  s21_negate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 1);
}
END_TEST

START_TEST(s21_negate_negative) {
  s21_decimal value_1 = {{123455}};
  s21_decimal result = {0};
  s21_decimal test = {{123455}};
  s21_set_sign(&value_1, 1);
  s21_negate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 0);
}
END_TEST

START_TEST(s21_negate_pow) {
  s21_decimal value_1 = {{123455}};
  s21_decimal result = {0};
  s21_decimal test = {{123455}};
  s21_set_sign(&value_1, 1);
  s21_set_power(&value_1, 3);
  s21_negate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 0);
  ck_assert_int_eq(s21_get_power(result), 3);
}
END_TEST

START_TEST(s21_decimal_float_normal) {
  s21_decimal value = {{8}};
  float a = 0;
  float b = 8.0;
  s21_from_decimal_to_float(value, &a);
  ck_assert_int_eq(s21_get_sign(value), 0);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(s21_decimal_float_null) {
  s21_decimal value = {0};
  float a = 0.0;
  float b = 0.0;
  s21_from_decimal_to_float(value, &a);
  ck_assert_int_eq(s21_get_sign(value), 0);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(s21_decimal_float_power) {
  s21_decimal value = {{8}};
  float a = 0.0;
  float b = -0.8;
  s21_set_power(&value, 1);
  s21_set_sign(&value, 1);
  s21_from_decimal_to_float(value, &a);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(s21_decimal_float_big_power) {
  s21_decimal value = {{8}};
  float a = 0.0;
  float b = -0.0000000000000000000000000008;
  s21_set_power(&value, 28);
  s21_set_sign(&value, 1);
  s21_from_decimal_to_float(value, &a);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(s21_decimal_float_power_max_value) {
  s21_decimal value = {0};
  value.bits[0] = 147484107;
  float a = 0.0;
  float b = -1.47484107;
  s21_set_power(&value, 8);
  s21_set_sign(&value, 1);
  s21_from_decimal_to_float(value, &a);
  ck_assert_float_eq_tol(a, b, 1e-6);
}
END_TEST

START_TEST(s21_decimal_float_power_max_dec) {
  s21_decimal value = {0};
  value.bits[0] = 214748;
  float a = 0.0;
  float b = -0.00000214748;
  s21_set_power(&value, 11);
  s21_set_sign(&value, 1);
  s21_from_decimal_to_float(value, &a);
  ck_assert_float_eq_tol(a, b, 1e-6);
}
END_TEST

START_TEST(s21_decimal_float_error) {
  s21_decimal value = {0};
  float *a = NULL;
  int res = s21_from_decimal_to_float(value, a);
  ck_assert_uint_eq(res, convertation_error);
}
END_TEST

START_TEST(s21_float_dec_normal) {
  s21_decimal value_2 = {0};
  s21_decimal test = {0};
  float a = 0.8;
  s21_set_power(&test, 7);
  int res = s21_from_float_to_decimal(a, &value_2);
  ck_assert_uint_eq(res, 0);
  ck_assert_uint_eq(s21_get_power(value_2), s21_get_power(test));
}
END_TEST

START_TEST(s21_float_dec_negative) {
  s21_decimal value_2 = {0};
  s21_decimal test = {0};
  float a = -12.8;
  s21_set_power(&test, 6);
  int res = s21_from_float_to_decimal(a, &value_2);
  ck_assert_uint_eq(res, 0);
  ck_assert_uint_eq(s21_get_power(value_2), 6);
}
END_TEST

START_TEST(s21_float_dec_error) {
  s21_decimal *value_2 = NULL;
  float a = -12.8;
  int res = s21_from_float_to_decimal(a, value_2);
  ck_assert_uint_eq(res, convertation_error);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, s21_is_less_null);
  tcase_add_test(tc1_1, s21_is_less_normal);
  tcase_add_test(tc1_1, s21_is_less_negative);
  tcase_add_test(tc1_1, s21_is_less_pow);
  tcase_add_test(tc1_1, s21_is_less_both_above_zero);
  tcase_add_test(tc1_1, s21_is_less_or_equal_normal);
  tcase_add_test(tc1_1, s21_is_less_or_equal_with_sign);
  tcase_add_test(tc1_1, s21_is_greater_null);
  tcase_add_test(tc1_1, s21_is_greater_normal);
  tcase_add_test(tc1_1, s21_is_greater_negative);
  tcase_add_test(tc1_1, s21_is_greater_two_negative);
  tcase_add_test(tc1_1, s21_is_greater_pow);
  tcase_add_test(tc1_1, s21_is_greater_or_equal_normal);
  tcase_add_test(tc1_1, s21_is_greater_or_equal_with_sign);
  tcase_add_test(tc1_1, s21_int_and_decimal_max);
  tcase_add_test(tc1_1, s21_int_and_decimal_big_pow);
  tcase_add_test(tc1_1, s21_int_and_decimal_int_overflow);
  tcase_add_test(tc1_1, s21_int_and_decimal_error);
  tcase_add_test(tc1_1, s21_int_and_decimal_sign);
  tcase_add_test(tc1_1, s21_int_and_decimal_whith_pow);
  tcase_add_test(tc1_1, s21_int_and_decimal_nul);
  tcase_add_test(tc1_1, s21_sub_normal);
  tcase_add_test(tc1_1, s21_sub_inf);
  tcase_add_test(tc1_1, s21_sub_one_sign);
  tcase_add_test(tc1_1, s21_sub_two_sign);
  tcase_add_test(tc1_1, s21_div_normal);
  tcase_add_test(tc1_1, s21_div_equal);
  tcase_add_test(tc1_1, part1_div_zero);
  tcase_add_test(tc1_1, s21_div_one);
  tcase_add_test(tc1_1, s21_mod_max_dec);
  tcase_add_test(tc1_1, s21_mod_max_dec_and_two);
  tcase_add_test(tc1_1, s21_mod_max_dec_and_biguint);
  tcase_add_test(tc1_1, s21_mod_dec_with_pow);
  tcase_add_test(tc1_1, s21_mod_dec_revers);
  tcase_add_test(tc1_1, s21_mod_dec_error);
  tcase_add_test(tc1_1, s21_mod_sign);
  tcase_add_test(tc1_1, s21_mod_over);
  tcase_add_test(tc1_1, s21_mod_over_norm);
  tcase_add_test(tc1_1, isEqual_1);
  tcase_add_test(tc1_1, isEqual_2);
  tcase_add_test(tc1_1, s21_mul_value_1_is_one);
  tcase_add_test(tc1_1, s21_mul_value_2_is_one);
  tcase_add_test(tc1_1, s21_mul_value_1_is_zero);
  tcase_add_test(tc1_1, s21_mul_value_2_is_zero);
  tcase_add_test(tc1_1, s21_mul_max);
  tcase_add_test(tc1_1, s21_mul_big_power);
  tcase_add_test(tc1_1, s21_mul_big_negative_over);
  tcase_add_test(tc1_1, s21_mul_big_over);
  tcase_add_test(tc1_1, s21_mul_norm);
  tcase_add_test(tc1_1, s21_mul_value_1_is_minus);
  tcase_add_test(tc1_1, s21_mul_value_2_is_minus);
  tcase_add_test(tc1_1, s21_mul_value_1_is_zero_minus);
  tcase_add_test(tc1_1, s21_mul_value_2_is_zero_minus);
  tcase_add_test(tc1_1, s21_mul_value_1_2_is_minus);
  tcase_add_test(tc1_1, s21_mul_max_1);
  tcase_add_test(tc1_1, s21_mul_max_2);
  tcase_add_test(tc1_1, s21_mul_max_3);
  tcase_add_test(tc1_1, s21_round_positive_integer);
  tcase_add_test(tc1_1, s21_round_null);
  tcase_add_test(tc1_1, s21_round_negative_integer);
  tcase_add_test(tc1_1, s21_round_positive_non_integer_1);
  tcase_add_test(tc1_1, s21_round_positive_non_integer_2);
  tcase_add_test(tc1_1, s21_round_negative_non_integer_1);
  tcase_add_test(tc1_1, s21_round_negative_non_integer_2);
  tcase_add_test(tc1_1, s21_round_zero);
  tcase_add_test(tc1_1, s21_floor_positive_integer);
  tcase_add_test(tc1_1, s21_floor_null);
  tcase_add_test(tc1_1, s21_floor_negative_integer);
  tcase_add_test(tc1_1, s21_floor_positive_non_integer);
  tcase_add_test(tc1_1, s21_floor_negative_non_integer);
  tcase_add_test(tc1_1, s21_floor_zero);
  tcase_add_test(tc1_1, s21_not_equal_null);
  tcase_add_test(tc1_1, s21_not_equal_normal);
  tcase_add_test(tc1_1, s21_not_equal_negative);
  tcase_add_test(tc1_1, s21_sum_normal);
  tcase_add_test(tc1_1, s21_sum_both_neg);
  tcase_add_test(tc1_1, s21_sum_error);
  tcase_add_test(tc1_1, s21_one_greater);
  tcase_add_test(tc1_1, s21_one_sign);
  tcase_add_test(tc1_1, s21_truncate_normal);
  tcase_add_test(tc1_1, s21_truncate_null);
  tcase_add_test(tc1_1, s21_truncate_negative);
  tcase_add_test(tc1_1, s21_truncate_pow);
  tcase_add_test(tc1_1, s21_negate_normal);
  tcase_add_test(tc1_1, s21_negate_null);
  tcase_add_test(tc1_1, s21_negate_negative);
  tcase_add_test(tc1_1, s21_negate_pow);
  tcase_add_test(tc1_1, s21_decimal_float_normal);
  tcase_add_test(tc1_1, s21_decimal_float_null);
  tcase_add_test(tc1_1, s21_decimal_float_power);
  tcase_add_test(tc1_1, s21_decimal_float_big_power);
  tcase_add_test(tc1_1, s21_decimal_float_power_max_value);
  tcase_add_test(tc1_1, s21_decimal_float_power_max_dec);
  tcase_add_test(tc1_1, s21_decimal_float_error);
  tcase_add_test(tc1_1, s21_float_dec_normal);
  tcase_add_test(tc1_1, s21_float_dec_negative);
  tcase_add_test(tc1_1, s21_float_dec_error);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}