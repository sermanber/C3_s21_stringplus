#include "tests_main.h"

START_TEST(test_strlen_1) {
  char str[] = "Hello, world!";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_strlen_2) {
  char str[] = "";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_strlen_3) {
  char str[] = "\0";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_strlen_4) {
  char str[] = "zzzzzzzzzzzzzzzzzzzzzzzz";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_strlen_5) {
  char str[] = "              ";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_strlen_6) {
  char str[] = "\n\n\n\n\n\t";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

Suite *test_strlen(void) {
  Suite *s1 = suite_create("S21_STRLEN");
  TCase *tc1_1 = tcase_create("strlen_tc");

  tcase_add_test(tc1_1, test_strlen_1);
  tcase_add_test(tc1_1, test_strlen_2);
  tcase_add_test(tc1_1, test_strlen_3);
  tcase_add_test(tc1_1, test_strlen_4);
  tcase_add_test(tc1_1, test_strlen_5);
  tcase_add_test(tc1_1, test_strlen_6);

  suite_add_tcase(s1, tc1_1);
  return s1;
}