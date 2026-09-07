#include "tests_main.h"

START_TEST(trim_test1) {
  char text_one[] = "    probel    ";
  char text_two[] = " ";
  char text_three[] = "probel";
  char *got = s21_trim(text_one, text_two);
  ck_assert_str_eq(got, text_three);
  if (got) free(got);
}
END_TEST

START_TEST(trim_test2) {
  char text_one2[] = "      ";
  char text_two2[] = " ";
  char text_three2[] = "";
  char *got2 = s21_trim(text_one2, text_two2);
  ck_assert_str_eq(got2, text_three2);
  if (got2) free(got2);
}
END_TEST

START_TEST(trim_test3) {
  char text_one3[] = "text without spaces";
  char text_two3[] = " ";
  char text_three3[] = "text without spaces";
  char *got3 = s21_trim(text_one3, text_two3);
  ck_assert_str_eq(got3, text_three3);
  if (got3) free(got3);
}
END_TEST

START_TEST(trim_test4) {
  char text_one4[] = "spaces on both sides   ";
  char text_two4[] = " ";
  char text_three4[] = "spaces on both sides";
  char *got4 = s21_trim(text_one4, text_two4);
  ck_assert_str_eq(got4, text_three4);
  if (got4) free(got4);
}
END_TEST

START_TEST(trim_test5) {
  char *text_one5 = NULL;
  char text_two5[] = " ";
  char *text_three5 = NULL;
  char *got5 = s21_trim(text_one5, text_two5);
  ck_assert_ptr_eq(got5, text_three5);
  // No need to free, as it is already NULL
}
END_TEST

START_TEST(trim_test7) {
  char src[] = "";
  char trim_chars[] = "abc";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

Suite *suite_trim(void) {
  Suite *s = suite_create("trim_test");
  TCase *tc = tcase_create("trim_test_case");

  tcase_add_test(tc, trim_test1);
  tcase_add_test(tc, trim_test2);
  tcase_add_test(tc, trim_test3);
  tcase_add_test(tc, trim_test4);
  tcase_add_test(tc, trim_test5);
  tcase_add_test(tc, trim_test7);

  suite_add_tcase(s, tc);
  return s;
}