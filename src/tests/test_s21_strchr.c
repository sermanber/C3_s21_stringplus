#include "tests_main.h"

START_TEST(test_my_strchr1) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_str_eq(s21_strchr(testString, 'o'), strchr(testString, 'o'));
}
END_TEST

START_TEST(test_my_strchr2) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_ptr_null(s21_strchr(testString, 'q'));
}
END_TEST

START_TEST(test_my_strchr3) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_str_eq(s21_strchr(testString, 'W'), strchr(testString, 'W'));
}
END_TEST

START_TEST(test_my_strchr4) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_str_eq(s21_strchr(testString, ','), strchr(testString, ','));
}
END_TEST

START_TEST(test_my_strchr5) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_str_eq(s21_strchr(testString, 'd'), strchr(testString, 'd'));
}
END_TEST

START_TEST(test_my_strchr6) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_str_eq(s21_strchr(testString, '1'), strchr(testString, '1'));
}
END_TEST

START_TEST(test_my_strchr7) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_str_eq(s21_strchr(testString, '\0'), strchr(testString, '\0'));
}
END_TEST

START_TEST(test_my_strchr8) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_str_eq(s21_strchr(testString, ' '), strchr(testString, ' '));
}
END_TEST

START_TEST(test_my_strchr9) { ck_assert_ptr_null(s21_strchr(NULL, 'u')); }
END_TEST

START_TEST(test_my_strchr10) { ck_assert_ptr_null(s21_strchr(NULL, 'l')); }
END_TEST

START_TEST(test_my_strchr11) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_pstr_eq(strchr(testString, 'h'), s21_strchr(testString, 'h'));
}
END_TEST

START_TEST(test_my_strchr12) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_pstr_eq(strchr(testString, '\0'), s21_strchr(testString, '\0'));
}
END_TEST

START_TEST(test_my_strchr13) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_pstr_eq(strchr(testString, ','), s21_strchr(testString, ','));
}
END_TEST

START_TEST(test_my_strchr14) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_pstr_eq(strchr(testString, 33), s21_strchr(testString, 33));
}
END_TEST

START_TEST(test_my_strchr15) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_pstr_eq(strchr(testString, 'D'), s21_strchr(testString, 'D'));
}
END_TEST

START_TEST(test_my_strchr16) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_pstr_eq(strchr(testString, 'w'), s21_strchr(testString, 'w'));
}
END_TEST

START_TEST(test_my_strchr17) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_pstr_eq(strchr(testString, '0'), s21_strchr(testString, '0'));
}
END_TEST

START_TEST(test_my_strchr18) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_pstr_eq(strchr(testString, 'm'), s21_strchr(testString, 'm'));
}
END_TEST

Suite *test_strchr(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("test_strchr");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_my_strchr1);
  tcase_add_test(tc_core, test_my_strchr2);
  tcase_add_test(tc_core, test_my_strchr3);
  tcase_add_test(tc_core, test_my_strchr4);
  tcase_add_test(tc_core, test_my_strchr5);
  tcase_add_test(tc_core, test_my_strchr6);
  tcase_add_test(tc_core, test_my_strchr7);
  tcase_add_test(tc_core, test_my_strchr8);
  tcase_add_test(tc_core, test_my_strchr9);
  tcase_add_test(tc_core, test_my_strchr10);
  tcase_add_test(tc_core, test_my_strchr11);
  tcase_add_test(tc_core, test_my_strchr12);
  tcase_add_test(tc_core, test_my_strchr13);
  tcase_add_test(tc_core, test_my_strchr14);
  tcase_add_test(tc_core, test_my_strchr15);
  tcase_add_test(tc_core, test_my_strchr16);
  tcase_add_test(tc_core, test_my_strchr17);
  tcase_add_test(tc_core, test_my_strchr18);

  suite_add_tcase(s, tc_core);
  return s;
}
