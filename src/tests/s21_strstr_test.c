#include "tests_main.h"

START_TEST(strstr_test1) {
  const char *haystack = "Hello, World!";
  const char *needle = "World";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_test2) {
  const char *haystack = "abcabcabc";
  const char *needle = "c";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_test3) {
  const char *haystack = "programming";
  const char *needle = "gram";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_test4) {
  const char *haystack = "test";
  const char *needle = "123";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_test5) {
  const char *haystack = "";
  const char *needle = "abc";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

Suite *suite_strstr(void) {
  Suite *s = suite_create("strstr_test");
  TCase *tc = tcase_create("strstr_test_case");

  tcase_add_test(tc, strstr_test1);
  tcase_add_test(tc, strstr_test2);
  tcase_add_test(tc, strstr_test3);
  tcase_add_test(tc, strstr_test4);
  tcase_add_test(tc, strstr_test5);

  suite_add_tcase(s, tc);
  return s;
}
