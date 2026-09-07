#include "../s21_string.h"

char *s21_strncat(char *dest, const char *src, size_t n) {
  size_t i = 0, j;

  while (dest[i] != '\0') {
    i++;
  }

  for (j = 0; j < n; j++) {
    dest[i + j] = src[j];
  }

  dest[i + j] = '\0';

  return dest;
}