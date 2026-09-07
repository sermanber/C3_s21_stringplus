#include "../s21_string.h"

size_t s21_strcspn(const char *str1, const char *str2) {
  size_t cnt = 0, len2 = 0;
  bool flag = true;

  while (str1[cnt] != '\0' && flag == true) {
    while (str2[len2] != '\0' && flag == true) {
      if (str1[cnt] == str2[len2]) {
        flag = false;
      } else
        len2++;
    }
    if (flag == true) cnt++;
    len2 = 0;
  }
  return cnt;
}