#include "tests_main.h"

START_TEST(test_my_strtok1) {
  char testString_strtok[] = "Hel lo, Wor ld!";
  ck_assert_str_eq(s21_strtok(testString_strtok, ","),
                   strtok(testString_strtok, ","));
}
END_TEST

START_TEST(test_my_strtok2) {
  char testString_strtok[] = "Hel lo, Wor ld!";
  ck_assert_str_eq(s21_strtok(testString_strtok, " ,"),
                   strtok(testString_strtok, " ,"));
}
END_TEST

START_TEST(test_my_strtok3) {
  char testString_strtok[] = "Hel lo, Wor ld!";
  ck_assert_str_eq(s21_strtok(testString_strtok, " ,!"),
                   strtok(testString_strtok, " ,!"));
}
END_TEST

START_TEST(test_my_strtok4) {
  char testString_strtok[] = "Hel lo, Wor ld!";
  ck_assert_str_eq(s21_strtok(testString_strtok, "l,"),
                   strtok(testString_strtok, "l,"));
}
END_TEST

START_TEST(test_my_strtok5) {
  char testString_strtok[] = "Hel lo, Wor ld!";
  ck_assert_ptr_null(s21_strtok(testString_strtok, NULL));
}
END_TEST

START_TEST(test_my_strtok6) {
  char testString_strtok[] = "Hel lo, Wor ld!";
  ck_assert_str_eq(s21_strtok(testString_strtok, "l"),
                   strtok(testString_strtok, "l"));
}
END_TEST

START_TEST(test_my_strtok7) {
  char testString_strtok[] = "Hel lo, Wor ld!";
  ck_assert_str_eq(s21_strtok(testString_strtok, " ,!1"),
                   strtok(testString_strtok, " ,!1"));
}
END_TEST

START_TEST(test_my_strtok8) {
  char testString_strtok[] = "Hel lo, Wor ld!";
  ck_assert_str_eq(s21_strtok(testString_strtok, "qyu"),
                   strtok(testString_strtok, "qyu"));
}
END_TEST

START_TEST(test_my_strtok9) { ck_assert_ptr_null(s21_strtok(NULL, NULL)); }
END_TEST

START_TEST(test_my_strtok10) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "!";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_my_strtok12) {
  char s1[] = "";
  char s2[] = "";
  char s3[] = "";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_my_strtok13) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "\0";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_my_strtok14) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_my_strtok15) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "Hello, world!";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_my_strtok16) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "My name is Dasha. I hate this, maybe I'm not supposed for this.";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_my_strtok17) {
  char s1[] = "ABABABABABBABABABBABABABABABBA";
  char s2[] = "ABABABABABBABABABBABABABABABBA";
  char s3[] = "B";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_my_strtok18) {
  char s1[] = "\0ABABABABABBABABABBABABABABABBA";
  char s2[] = "\0ABABABABABBABABABBABABABABABBA";
  char s3[] = "A";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_my_strtok19) {
  char s1[] = "\0Hello, world!";
  char s2[] = "\0Hello, world!";
  char s3[] = "\0";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_my_strtok20) {
  char s1[] = "\0Hello, world!";
  char s2[] = "\0Hello, world!";
  char s3[] = "";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_my_strtok22) {
  char s1[] = "tuz-tuz-tuz";
  char s2[] = "tuz-tuz-tuz";
  char s3[] = "z-tuz-tuz";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_my_strtok23) {
  char s1[] = "Hello, world! And other people";
  char s2[] = "Hello, world! And other people";
  char s3[] = "\0Come here";
  char s4[] = "\0Come here";
  char s5[] = "";

  ck_assert_pstr_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(NULL, s5), s21_strtok(NULL, s5));
  }
  ck_assert_pstr_eq(strtok(s3, s5), s21_strtok(s4, s5));
  ck_assert_pstr_eq(strtok(NULL, s5), s21_strtok(NULL, s5));
  ck_assert_pstr_eq(strtok(NULL, s5), s21_strtok(NULL, s5));
}
END_TEST

START_TEST(test_my_strtok24) {
  char s1[] = "Hello,       world! And other people";
  char s2[] = "Hello,       world! And other people";
  char s3[] = "Come here";
  char s4[] = "Come here";
  char s5[] = " o";

  ck_assert_pstr_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(NULL, s5), s21_strtok(NULL, s5));
  }
  ck_assert_pstr_eq(strtok(s3, s5), s21_strtok(s4, s5));
  ck_assert_pstr_eq(strtok(NULL, s5), s21_strtok(NULL, s5));
  ck_assert_pstr_eq(strtok(NULL, s5), s21_strtok(NULL, s5));
}
END_TEST

START_TEST(test_my_strtok25) {
  char s1[] = "Hello,      worllllllllllld! And lother people      ";
  char s2[] = "Hello,      worllllllllllld! And lother people      ";
  char s3[] = "Come here";
  char s4[] = "Come here";
  char s5[] = " l";

  ck_assert_pstr_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(NULL, s5), s21_strtok(NULL, s5));
  }
  ck_assert_pstr_eq(strtok(s3, s5), s21_strtok(s4, s5));
  ck_assert_pstr_eq(strtok(NULL, s5), s21_strtok(NULL, s5));
  ck_assert_pstr_eq(strtok(NULL, s5), s21_strtok(NULL, s5));
}
END_TEST

START_TEST(test_my_strtok26) {
  char s1[] = "Helllllllo,      worllllllllllld! And lother people      ";
  char s2[] = "Helllllllo,      worllllllllllld! And lother people      ";
  char s3[] = "Come here";
  char s4[] = "Come here";
  char s5[] = "l";
  char s6[] = " ";

  ck_assert_str_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(NULL, s6), s21_strtok(NULL, s6));
  }
  ck_assert_pstr_eq(strtok(s3, s6), s21_strtok(s4, s6));
  ck_assert_pstr_eq(strtok(NULL, s6), s21_strtok(NULL, s6));
  ck_assert_pstr_eq(strtok(NULL, s6), s21_strtok(NULL, s6));
}
END_TEST

START_TEST(test_my_strtok27) {
  char s1[] = "ROROROROMA!!!!!!!!!";
  char s2[] = "ROROROROMA!!!!!!!!!";
  char s3[] = "R";
  strtok(s1, s3);
  strtok(NULL, s3);
  s21_strtok(s2, s3);
  s21_strtok(NULL, s3);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(test_my_strtok28) {
  char s1[] = "AGONIA";
  char s2[] = "AGONIA";
  char s3[] = "A";
  strtok(s1, s3);
  strtok(NULL, s3);
  strtok(NULL, s3);
  s21_strtok(s2, s3);
  s21_strtok(NULL, s3);
  s21_strtok(NULL, s3);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(test_my_strtok29) {
  char s1[] = "MYPHONENUM68697317172648";
  char s2[] = "MYPHONENUM68697317172648";
  char s3[] = "MYPHONENUM6869";
  char *s4 = strtok(s1, s3);
  char *s6 = strtok(NULL, s3);

  char *s5 = s21_strtok(s2, s3);
  char *s7 = s21_strtok(NULL, s3);

  ck_assert_pstr_eq(s1, s2);
  ck_assert_pstr_eq(s4, s5);
  ck_assert_pstr_eq(s6, s7);
}
END_TEST

START_TEST(test_my_strtok30) {
  char s1[] = "AAAAAAGOONIAAAAA";
  char s2[] = "AAAAAAGOONIAAAAA";
  char s3[] = "A";
  strtok(s1, s3);
  strtok(NULL, s2);
  strtok(NULL, s2);
  s21_strtok(s2, s3);
  s21_strtok(NULL, s3);
  s21_strtok(NULL, s3);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

Suite *test_strtok(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("test_strtok");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_my_strtok1);
  tcase_add_test(tc_core, test_my_strtok2);
  tcase_add_test(tc_core, test_my_strtok3);
  tcase_add_test(tc_core, test_my_strtok4);
  tcase_add_test(tc_core, test_my_strtok5);
  tcase_add_test(tc_core, test_my_strtok6);
  tcase_add_test(tc_core, test_my_strtok7);
  tcase_add_test(tc_core, test_my_strtok8);
  tcase_add_test(tc_core, test_my_strtok9);
  tcase_add_test(tc_core, test_my_strtok10);
  tcase_add_test(tc_core, test_my_strtok12);
  tcase_add_test(tc_core, test_my_strtok13);
  tcase_add_test(tc_core, test_my_strtok14);
  tcase_add_test(tc_core, test_my_strtok15);
  tcase_add_test(tc_core, test_my_strtok16);
  tcase_add_test(tc_core, test_my_strtok17);
  tcase_add_test(tc_core, test_my_strtok18);
  tcase_add_test(tc_core, test_my_strtok19);
  tcase_add_test(tc_core, test_my_strtok20);
  tcase_add_test(tc_core, test_my_strtok22);
  tcase_add_test(tc_core, test_my_strtok23);
  tcase_add_test(tc_core, test_my_strtok24);
  tcase_add_test(tc_core, test_my_strtok25);
  tcase_add_test(tc_core, test_my_strtok26);
  tcase_add_test(tc_core, test_my_strtok27);
  tcase_add_test(tc_core, test_my_strtok28);
  tcase_add_test(tc_core, test_my_strtok29);
  tcase_add_test(tc_core, test_my_strtok30);

  suite_add_tcase(s, tc_core);
  return s;
}
