#include "tests_main.h"

START_TEST(test_strcspn_1) {
  char str1[] = "Hello, world!";
  char str2[] = "abcdef";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(test_strcspn_2) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(test_strcspn_3) {
  char str1[] = "Hello, world!";
  char str2[] = "";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(test_strcspn_4) {
  char str1[] = "";
  char str2[] = "Hello, world!";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(test_strcspn_5) {
  char str1[] = "";
  char str2[] = "";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(test_strcspn_6) {
  char str1[] = "1234567890";
  char str2[] = "0000000000";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

Suite *test_strcspn(void) {
  Suite *s1 = suite_create("S21_STRCSPN");
  TCase *tc1_1 = tcase_create("strcspn_tc");

  tcase_add_test(tc1_1, test_strcspn_1);
  tcase_add_test(tc1_1, test_strcspn_2);
  tcase_add_test(tc1_1, test_strcspn_3);
  tcase_add_test(tc1_1, test_strcspn_4);
  tcase_add_test(tc1_1, test_strcspn_5);
  tcase_add_test(tc1_1, test_strcspn_6);

  suite_add_tcase(s1, tc1_1);
  return s1;
}