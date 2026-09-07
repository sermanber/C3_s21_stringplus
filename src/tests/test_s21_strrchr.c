#include "tests_main.h"

START_TEST(test_my_strrchr1) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_str_eq(s21_strrchr(testString, 'o'), strrchr(testString, 'o'));
}
END_TEST

START_TEST(test_my_strrchr2) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_ptr_null(s21_strrchr(testString, 'q'));
}
END_TEST

START_TEST(test_my_strrchr3) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_str_eq(s21_strrchr(testString, 'W'), strrchr(testString, 'W'));
}
END_TEST

START_TEST(test_my_strrchr4) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_str_eq(s21_strrchr(testString, ','), strrchr(testString, ','));
}
END_TEST

START_TEST(test_my_strrchr5) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_str_eq(s21_strrchr(testString, 'd'), strrchr(testString, 'd'));
}
END_TEST

START_TEST(test_my_strrchr6) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_str_eq(s21_strrchr(testString, '1'), strrchr(testString, '1'));
}
END_TEST

START_TEST(test_my_strrchr7) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_str_eq(s21_strrchr(testString, '\0'), strrchr(testString, '\0'));
}
END_TEST

START_TEST(test_my_strrchr8) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_str_eq(s21_strrchr(testString, ' '), strrchr(testString, ' '));
}
END_TEST

START_TEST(test_my_strrchr9) { ck_assert_ptr_null(s21_strrchr(NULL, ' ')); }
END_TEST

START_TEST(test_my_strrchr10) { ck_assert_ptr_null(s21_strrchr(NULL, 'q')); }
END_TEST

START_TEST(test_my_strrchr11) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_ptr_null(s21_strrchr(testString, 'O'));
}
END_TEST

START_TEST(test_my_strrchr12) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_pstr_eq(strrchr(testString, 'h'), s21_strrchr(testString, 'h'));
}
END_TEST

START_TEST(test_my_strrchr13) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_pstr_eq(strrchr(testString, '\0'), s21_strrchr(testString, '\0'));
}
END_TEST

START_TEST(test_my_strrchr14) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_pstr_eq(strrchr(testString, ','), s21_strrchr(testString, ','));
}
END_TEST

START_TEST(test_my_strrchr15) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_pstr_eq(strrchr(testString, 33), s21_strrchr(testString, 33));
}
END_TEST

START_TEST(test_my_strrchr16) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_pstr_eq(strrchr(testString, 'D'), s21_strrchr(testString, 'D'));
}
END_TEST

START_TEST(test_my_strrchr17) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_pstr_eq(strrchr(testString, 'w'), s21_strrchr(testString, 'w'));
}
END_TEST

START_TEST(test_my_strrchr18) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_pstr_eq(strrchr(testString, '0'), s21_strrchr(testString, '0'));
}
END_TEST

START_TEST(test_my_strrchr19) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_pstr_eq(strrchr(testString, 'm'), s21_strrchr(testString, 'm'));
}
END_TEST

Suite *test_strrchr(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("test_strrchr");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_my_strrchr1);
  tcase_add_test(tc_core, test_my_strrchr2);
  tcase_add_test(tc_core, test_my_strrchr3);
  tcase_add_test(tc_core, test_my_strrchr4);
  tcase_add_test(tc_core, test_my_strrchr5);
  tcase_add_test(tc_core, test_my_strrchr6);
  tcase_add_test(tc_core, test_my_strrchr7);
  tcase_add_test(tc_core, test_my_strrchr8);
  tcase_add_test(tc_core, test_my_strrchr9);
  tcase_add_test(tc_core, test_my_strrchr10);
  tcase_add_test(tc_core, test_my_strrchr11);
  tcase_add_test(tc_core, test_my_strrchr12);
  tcase_add_test(tc_core, test_my_strrchr13);
  tcase_add_test(tc_core, test_my_strrchr14);
  tcase_add_test(tc_core, test_my_strrchr15);
  tcase_add_test(tc_core, test_my_strrchr16);
  tcase_add_test(tc_core, test_my_strrchr17);
  tcase_add_test(tc_core, test_my_strrchr18);
  tcase_add_test(tc_core, test_my_strrchr19);

  suite_add_tcase(s, tc_core);
  return s;
}
