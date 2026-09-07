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

//-------------------------------------------------------------------------------------------------

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

//-------------------------------------------------------------------------------------------------

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

//-------------------------------------------------------------------------------------------------

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

//-------------------------------------------------------------------------------------------------

Suite *my_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("MyFunctions");
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
