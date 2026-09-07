#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  if (!haystack) {
    return NULL;
  }
  if (!needle || *needle == '\0') {
    return (char *)haystack;
  }
  char *result = NULL;
  int stop_flag = 0;
  for (; *haystack && !stop_flag; haystack++) {
    const char *h = haystack;
    const char *n = needle;

    while (*h && *n && *h == *n && !stop_flag) {
      h++;
      n++;
    }
    if (!*n) {
      result = (char *)haystack;
      stop_flag = 1;
    }
  }
  return result;
}