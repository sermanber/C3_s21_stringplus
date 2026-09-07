#include "tests_main.h"

START_TEST(strncpy_test1) {
  char text_one[21] = "1324";
  char text_two[21] = "1324";
  size_t n = 5;
  ck_assert_str_eq(strncpy(text_one, "Overflow", n),
                   s21_strncpy(text_two, "Overflow", n));
}
END_TEST

START_TEST(strncpy_test2) {
  char text_one[21] = "1324";
  char text_two[21] = "1324";
  size_t n = 3;
  ck_assert_str_eq(strncpy(text_one, "Short", n),
                   s21_strncpy(text_two, "Short", n));
}
END_TEST

START_TEST(strncpy_test3) {
  char text_one[21] = "1324";
  char text_two[21] = "1324";
  size_t n = 7;
  ck_assert_str_eq(strncpy(text_one, "", n), s21_strncpy(text_two, "", n));
}
END_TEST

START_TEST(strncpy_test4) {
  char text_one[21] = "1324";
  char text_two[21] = "1324";
  size_t n = 0;
  ck_assert_str_eq(strncpy(text_one, "NotCopied", n),
                   s21_strncpy(text_two, "NotCopied", n));
}
END_TEST

START_TEST(strncpy_test5) {
  char text_one[21] = "1324";
  char text_two[21] = "1324";
  size_t n = 8;
  ck_assert_str_eq(strncpy(text_one, "NullTest", n),
                   s21_strncpy(text_two, "NullTest", n));
}
END_TEST

Suite *suite_strncpy(void) {
  Suite *s = suite_create("strncpy_test");
  TCase *tc = tcase_create("strncpy_test_case");

  tcase_add_test(tc, strncpy_test1);
  tcase_add_test(tc, strncpy_test2);
  tcase_add_test(tc, strncpy_test3);
  tcase_add_test(tc, strncpy_test4);
  tcase_add_test(tc, strncpy_test5);

  suite_add_tcase(s, tc);
  return s;
}
