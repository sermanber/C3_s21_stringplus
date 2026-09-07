#include "tests_main.h"

START_TEST(test_my_memchr1) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_str_eq(s21_memchr(testString, 'o', 25),
                   memchr(testString, 'o', 25));
}
END_TEST

START_TEST(test_my_memchr2) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_str_eq(s21_memchr(testString, 'W', 25),
                   memchr(testString, 'W', 25));
}
END_TEST

START_TEST(test_my_memchr3) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_str_eq(s21_memchr(testString, ',', 25),
                   memchr(testString, ',', 25));
}
END_TEST

START_TEST(test_my_memchr4) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_str_eq(s21_memchr(testString, 'd', 25),
                   memchr(testString, 'd', 25));
}
END_TEST

START_TEST(test_my_memchr5) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_str_eq(s21_memchr(testString, 'l', 25),
                   memchr(testString, 'l', 25));
}
END_TEST

START_TEST(test_my_memchr6) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_str_eq(s21_memchr(testString, '\0', 25),
                   memchr(testString, '\0', 25));
}
END_TEST

START_TEST(test_my_memchr7) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_str_eq(s21_memchr(testString, ' ', 25),
                   memchr(testString, ' ', 25));
}
END_TEST

START_TEST(test_my_memchr8) { ck_assert_ptr_null(s21_memchr(NULL, 0, 25)); }
END_TEST

START_TEST(test_my_memchr9) { ck_assert_ptr_null(s21_memchr(NULL, 'l', 25)); }
END_TEST

START_TEST(test_my_memchr10) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_ptr_null(s21_memchr(testString, 'q', 25));
}
END_TEST

START_TEST(test_my_memchr11) {
  char testString[] = "Hello, World, World! 123";
  ck_assert_ptr_null(s21_memchr(testString, 'W', 5));
}
END_TEST

START_TEST(test_my_memchr13) {
  char testString[] = "Hello, World, World! 123";
  size_t len = strlen(testString);
  ck_assert_ptr_eq(memchr(testString, ' ', len),
                   s21_memchr(testString, ' ', len));
}
END_TEST

START_TEST(test_my_memchr14) {
  char testString[] = "Hello, World, World! 123";
  size_t len = strlen(testString);
  ck_assert_ptr_eq(memchr(testString, 101, len),
                   s21_memchr(testString, 101, len));
}
END_TEST

START_TEST(test_my_memchr15) {
  char testString[] = "Hello, World, World! 123";
  size_t len = strlen(testString);
  ck_assert_ptr_eq(memchr(testString, '1', len),
                   s21_memchr(testString, '1', len));
}
END_TEST

START_TEST(test_my_memchr16) {
  char testString[] = "Hello, World, World! 123";
  size_t len = strlen(testString);
  ck_assert_ptr_eq(memchr(testString, 65, len),
                   s21_memchr(testString, 65, len));
}
END_TEST

START_TEST(test_my_memchr17) {
  char testString[] = "Hello, World, World! 123";
  size_t len = 10;
  ck_assert_ptr_eq(memchr(testString, 'l', len),
                   s21_memchr(testString, 'l', len));
}
END_TEST

START_TEST(test_my_memchr18) {
  char testString[] = "Hello, World, World! 123";
  size_t len = 5;
  ck_assert_ptr_eq(memchr(testString, 'w', len),
                   s21_memchr(testString, 'w', len));
}
END_TEST

START_TEST(test_my_memchr19) {
  char testString[] = "69917020";
  size_t len = strlen(testString);
  ck_assert_ptr_eq(memchr(testString, '3', len),
                   s21_memchr(testString, '3', len));
}
END_TEST

START_TEST(test_my_memchr20) {
  char testString[] = "69917020";
  size_t len = 0;
  ck_assert_ptr_eq(memchr(testString, '6', len),
                   s21_memchr(testString, '6', len));
}
END_TEST

START_TEST(test_my_memchr21) {
  char testString[] = "69917020";
  size_t len = strlen(testString);
  ck_assert_ptr_eq(memchr(testString, 'g', len),
                   s21_memchr(testString, 'g', len));
}
END_TEST

START_TEST(test_my_memchr22) {
  char testString[] = "69917020";
  size_t len = 9;
  ck_assert_ptr_eq(memchr(testString, '\0', len),
                   s21_memchr(testString, '\0', len));
}
END_TEST

Suite *test_memchr(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("test_memchr");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_my_memchr1);
  tcase_add_test(tc_core, test_my_memchr2);
  tcase_add_test(tc_core, test_my_memchr3);
  tcase_add_test(tc_core, test_my_memchr4);
  tcase_add_test(tc_core, test_my_memchr5);
  tcase_add_test(tc_core, test_my_memchr6);
  tcase_add_test(tc_core, test_my_memchr7);
  tcase_add_test(tc_core, test_my_memchr8);
  tcase_add_test(tc_core, test_my_memchr9);
  tcase_add_test(tc_core, test_my_memchr10);
  tcase_add_test(tc_core, test_my_memchr11);
  tcase_add_test(tc_core, test_my_memchr13);
  tcase_add_test(tc_core, test_my_memchr14);
  tcase_add_test(tc_core, test_my_memchr15);
  tcase_add_test(tc_core, test_my_memchr16);
  tcase_add_test(tc_core, test_my_memchr17);
  tcase_add_test(tc_core, test_my_memchr18);
  tcase_add_test(tc_core, test_my_memchr19);
  tcase_add_test(tc_core, test_my_memchr20);
  tcase_add_test(tc_core, test_my_memchr21);
  tcase_add_test(tc_core, test_my_memchr22);

  suite_add_tcase(s, tc_core);
  return s;
}
