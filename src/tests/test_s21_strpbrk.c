#include "tests_main.h"

START_TEST(test_my_strpbrk1) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_str_eq(s21_strpbrk(testString, "Wl"), strpbrk(testString, "Wl"));
}
END_TEST

START_TEST(test_my_strpbrk2) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_str_eq(s21_strpbrk(testString, "o"), strpbrk(testString, "o"));
}
END_TEST

START_TEST(test_my_strpbrk3) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_str_eq(s21_strpbrk(testString, "123"), strpbrk(testString, "123"));
}
END_TEST

START_TEST(test_my_strpbrk4) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_str_eq(s21_strpbrk(testString, "l,"), strpbrk(testString, "l,"));
}
END_TEST

START_TEST(test_my_strpbrk5) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_str_eq(s21_strpbrk(testString, "ll"), strpbrk(testString, "ll"));
}
END_TEST

START_TEST(test_my_strpbrk6) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_str_eq(s21_strpbrk(testString, "eoWr"),
                   strpbrk(testString, "eoWr"));
}
END_TEST

START_TEST(test_my_strpbrk7) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_str_eq(s21_strpbrk(testString, " ,!1"),
                   strpbrk(testString, " ,!1"));
}
END_TEST

START_TEST(test_my_strpbrk8) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_ptr_null(s21_strpbrk(testString, "qyu"));
}
END_TEST

START_TEST(test_my_strpbrk9) { ck_assert_ptr_null(s21_strpbrk(NULL, "qyu")); }
END_TEST

START_TEST(test_my_strpbrk10) { ck_assert_ptr_null(s21_strpbrk(NULL, "lW")); }
END_TEST

START_TEST(test_my_strpbrk11) { ck_assert_ptr_null(s21_strpbrk(NULL, NULL)); }
END_TEST

START_TEST(test_my_strpbrk12) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_pstr_eq(strpbrk(testString, "Hello, world!"),
                    s21_strpbrk(testString, "Hello, world!"));
}
END_TEST

START_TEST(test_my_strpbrk13) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_pstr_eq(strpbrk(testString, "!"), s21_strpbrk(testString, "!"));
}
END_TEST

START_TEST(test_my_strpbrk14) {
  char testString[] = "";
  ck_assert_pstr_eq(strpbrk(testString, "He"), s21_strpbrk(testString, "He"));
}
END_TEST

START_TEST(test_my_strpbrk15) {
  char testString[] = "\0";
  ck_assert_pstr_eq(strpbrk(testString, ""), s21_strpbrk(testString, ""));
}
END_TEST

START_TEST(test_my_strpbrk16) {
  char testString[] = "";
  ck_assert_pstr_eq(strpbrk(testString, ""), s21_strpbrk(testString, ""));
}
END_TEST

START_TEST(test_my_strpbrk17) {
  char testString[] = "1242434246364377659";
  ck_assert_pstr_eq(strpbrk(testString, "364377659"),
                    s21_strpbrk(testString, "364377659"));
}
END_TEST

Suite *test_strpbrk(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("test_strpbrk");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_my_strpbrk1);
  tcase_add_test(tc_core, test_my_strpbrk2);
  tcase_add_test(tc_core, test_my_strpbrk3);
  tcase_add_test(tc_core, test_my_strpbrk4);
  tcase_add_test(tc_core, test_my_strpbrk5);
  tcase_add_test(tc_core, test_my_strpbrk6);
  tcase_add_test(tc_core, test_my_strpbrk7);
  tcase_add_test(tc_core, test_my_strpbrk8);
  tcase_add_test(tc_core, test_my_strpbrk9);
  tcase_add_test(tc_core, test_my_strpbrk10);
  tcase_add_test(tc_core, test_my_strpbrk11);
  tcase_add_test(tc_core, test_my_strpbrk12);
  tcase_add_test(tc_core, test_my_strpbrk13);
  tcase_add_test(tc_core, test_my_strpbrk14);
  tcase_add_test(tc_core, test_my_strpbrk15);
  tcase_add_test(tc_core, test_my_strpbrk16);
  tcase_add_test(tc_core, test_my_strpbrk17);

  suite_add_tcase(s, tc_core);
  return s;
}
