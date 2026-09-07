#include "tests_main.h"

START_TEST(memcmp_test1) {
  char test1[] = "abcdefghij";
  char test2[] = "abcdEfghij";
  ck_assert_uint_eq(s21_memcmp(test1, test2, 10) < 0,
                    memcmp(test1, test2, 10) < 0);
}
END_TEST

START_TEST(memcmp_test2) {
  char test1[] = "1234";
  char test2[] = "5678";
  ck_assert_uint_eq(s21_memcmp(test1, test2, 4) < 0,
                    memcmp(test1, test2, 4) < 0);
}
END_TEST

START_TEST(memcmp_test3) {
  char test2[] = "0123456789";
  char test3[] = "\0";
  ck_assert_uint_eq(s21_memcmp(test2, test3, 2) > 0,
                    memcmp(test2, test3, 2) > 0);
}
END_TEST

START_TEST(memcmp_test4) {
  char test1[] = "apple";
  char test2[] = "orange";
  ck_assert_uint_eq(s21_memcmp(test1, test2, 5) > 0,
                    memcmp(test1, test2, 5) > 0);
}
END_TEST

START_TEST(memcmp_test5) {
  char test1[] = "programming";
  char test2[] = "program";
  ck_assert_uint_eq(s21_memcmp(test1, test2, 7) > 0,
                    memcmp(test1, test2, 7) > 0);
}
END_TEST

START_TEST(memcmp_test6) {
  char test1[] = "abcdefghij";
  char test2[] = "abcdEfghij";
  ck_assert_uint_eq(s21_memcmp(test1, test2, 0) < 0,
                    memcmp(test1, test2, 0) < 0);
}
END_TEST

Suite *suite_memcmp(void) {
  Suite *s = suite_create("memcmp_test");
  TCase *tc = tcase_create("memcmp_test_case");

  tcase_add_test(tc, memcmp_test1);
  tcase_add_test(tc, memcmp_test2);
  tcase_add_test(tc, memcmp_test3);
  tcase_add_test(tc, memcmp_test4);
  tcase_add_test(tc, memcmp_test5);
  tcase_add_test(tc, memcmp_test6);

  suite_add_tcase(s, tc);
  return s;
}