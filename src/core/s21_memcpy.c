#include "../s21_string.h"

void *s21_memcpy(void *dest, const void *src, size_t size) {
  if (dest != NULL && src != NULL && size > 0) {
    char *str1 = (char *)dest;
    const char *str2 = (const char *)src;
    for (size_t i = 0; i < size; i++) {
      *(str1 + i) = *(str2 + i);
    }
  }

  return dest;
}
