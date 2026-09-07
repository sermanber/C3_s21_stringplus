#include "tests_main.h"

#include "../s21_string.h"

Suite *s21_sscanf_suite_1(void);
Suite *test_sscanf_n(void);
Suite *test_sscanf_o(void);
Suite *test_sscanf_p(void);
Suite *test_sscanf_real(void);
Suite *test_sscanf_x(void);
Suite *test_sscanf_empty(void);
Suite *test_trim(void);
Suite *test_insert(void);
Suite *test_suite_s21_sscanf(void);
Suite *suite_insert(void);
Suite *suite_trim(void);
Suite *test_strstr(void);
Suite *suite_strstr(void);
Suite *suite_strncpy(void);
Suite *test_strncpy(void);
Suite *my_suite(void);
Suite *test_memchr(void);
Suite *test_strchr(void);
Suite *test_strpbrk(void);
Suite *test_strrchr(void);
Suite *test_strtok(void);
Suite *test_strcspn(void);
Suite *test_strerror(void);
Suite *test_strlen(void);
Suite *test_strncat(void);
Suite *test_memset(void);
Suite *suite_sprintf(void);
Suite *suite_memcmp(void);
Suite *suite_strncmp(void);
Suite *test_memcpy(void);
Suite *test_memcmp(void);
Suite *test_to_lower(void);
Suite *test_to_upper(void);
Suite *test_memchr_2(void);
Suite *suite_strtok(void);

int main(void) {
  int number_failed;
  setlocale(LC_ALL, "");
  Suite *s = s21_sscanf_suite_1();
  SRunner *sr = srunner_create(s);
  srunner_add_suite(sr, test_sscanf_n());
  srunner_add_suite(sr, test_sscanf_o());
  srunner_add_suite(sr, test_sscanf_p());
  srunner_add_suite(sr, test_sscanf_real());
  srunner_add_suite(sr, test_sscanf_x());
  srunner_add_suite(sr, test_sscanf_empty());
  srunner_add_suite(sr, test_trim());
  srunner_add_suite(sr, test_insert());
  srunner_add_suite(sr, test_suite_s21_sscanf());
  srunner_add_suite(sr, suite_insert());
  srunner_add_suite(sr, suite_trim());
  srunner_add_suite(sr, test_strstr());
  srunner_add_suite(sr, suite_strstr());
  srunner_add_suite(sr, suite_strncpy());
  srunner_add_suite(sr, test_strncpy());
  srunner_add_suite(sr, my_suite());
  srunner_add_suite(sr, test_memchr());
  srunner_add_suite(sr, test_memchr_2());
  srunner_add_suite(sr, test_strpbrk());
  srunner_add_suite(sr, test_strrchr());
  srunner_add_suite(sr, test_strtok());
  srunner_add_suite(sr, test_strcspn());
  srunner_add_suite(sr, test_strerror());
  srunner_add_suite(sr, test_strlen());
  srunner_add_suite(sr, test_strncat());
  srunner_add_suite(sr, test_memset());
  srunner_add_suite(sr, suite_sprintf());
  srunner_add_suite(sr, suite_memcmp());
  srunner_add_suite(sr, suite_strncmp());
  srunner_add_suite(sr, test_memcpy());
  srunner_add_suite(sr, test_memcmp());
  srunner_add_suite(sr, test_to_lower());
  srunner_add_suite(sr, test_to_upper());
  srunner_add_suite(sr, suite_strtok());

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}