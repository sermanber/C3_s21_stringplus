#include "tests_main.h"

START_TEST(strtok_test1) {
  char str[] = "apple,orange,banana";
  const char delim[] = ",";
  char *token = s21_strtok(str, delim);

  ck_assert_str_eq(token, "apple");
}
END_TEST

START_TEST(strtok_test2) {
  char str[] = "apple,orange,banana";
  const char delim[] = ",";
  char *token = s21_strtok(str, delim);
  token = s21_strtok(NULL, delim);

  ck_assert_str_eq(token, "orange");
}
END_TEST

START_TEST(strtok_test3) {
  char str[] = "apple,orange,banana";
  const char delim[] = ",";
  char *token = s21_strtok(str, delim);
  token = s21_strtok(NULL, delim);
  token = s21_strtok(NULL, delim);

  ck_assert_str_eq(token, "banana");
}
END_TEST

START_TEST(strtok_test4) {
  char str[] = "apple,orange,banana";
  const char delim[] = ",";
  char *token = s21_strtok(str, delim);
  token = s21_strtok(NULL, delim);
  token = s21_strtok(NULL, delim);
  token = s21_strtok(NULL, delim);

  ck_assert_ptr_eq(token, NULL);
}
END_TEST

START_TEST(strtok_test5) {
  char str[] = "apple, orange, banana";
  const char delim[] = ",";
  char *token = s21_strtok(str, delim);

  ck_assert_str_eq(token, "apple");

  token = s21_strtok(NULL, delim);
  ck_assert_str_eq(token, " orange");

  token = s21_strtok(NULL, delim);
  ck_assert_str_eq(token, " banana");
}
END_TEST

START_TEST(strtok_test6) {
  char str[] = ",,,apple,orange,banana";
  const char delim[] = ",";
  char *token = s21_strtok(str, delim);

  ck_assert_str_eq(token, "apple");
}
END_TEST

Suite *suite_strtok(void) {
  Suite *s = suite_create("strtok_test");
  TCase *tc = tcase_create("strtok_test_case");

  tcase_add_test(tc, strtok_test1);
  tcase_add_test(tc, strtok_test2);
  tcase_add_test(tc, strtok_test3);
  tcase_add_test(tc, strtok_test4);
  tcase_add_test(tc, strtok_test5);
  tcase_add_test(tc, strtok_test6);

  suite_add_tcase(s, tc);
  return s;
}