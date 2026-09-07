#include "../s21_string.h"

void *s21_memchr(const void *str, int c, size_t size) {
  void *result = NULL;

  if (str != NULL) {
    for (size_t i = 0; i < size && result == NULL; i++) {
      if (*((char *)str + i) == c) {
        result = (void *)((char *)str + i);
      }
    }
  }

  return result;
}
