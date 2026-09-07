#include "tests_main.h"

START_TEST(strncmp_test1) {
  const char *str1 = "Hello, World!";
  const char *str2 = "Hello, World!";
  size_t n = s21_strlen(str1);
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_test2) {
  const char *str1 = "Hello";
  const char *str2 = "World";
  size_t n = s21_strlen(str1);
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_test3) {
  const char *str1 = "Partial";
  const char *str2 = "Part";
  size_t n = s21_strlen(str2);
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_test4) {
  const char *str1 = "Hello";
  const char *str2 = "Hello, World!";
  size_t n = s21_strlen(str1);
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_test5) {
  const char *str1 = "Hello";
  const char *str2 = "World";
  size_t n = 0;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

Suite *suite_strncmp(void) {
  Suite *s = suite_create("strncmp_test");
  TCase *tc = tcase_create("strncmp_test_case");

  tcase_add_test(tc, strncmp_test1);
  tcase_add_test(tc, strncmp_test2);
  tcase_add_test(tc, strncmp_test3);
  tcase_add_test(tc, strncmp_test4);
  tcase_add_test(tc, strncmp_test5);

  suite_add_tcase(s, tc);
  return s;
}
