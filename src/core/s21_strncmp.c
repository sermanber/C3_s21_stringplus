#include "../s21_string.h"

int s21_strncmp(const char *str1, const char *str2, size_t n) {
  size_t i = 0;
  int result = 0;
  int stop_flag = 0;
  while (i < n && !stop_flag) {
    if (str1[i] != str2[i] || str1[i] == '\0' || str2[i] == '\0') {
      result = (unsigned char)str1[i] - (unsigned char)str2[i];
      stop_flag = 1;
    }
    i++;
  }
  return result;
}