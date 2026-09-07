#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, size_t size) {
  int result = 0;
  int stop_flag = 0;
  const unsigned char *str_1 = str1;
  const unsigned char *str_2 = str2;

  for (size_t i = 0; i < size && !stop_flag; i++) {
    if (*(str_1 + i) != *(str_2 + i)) {
      result = *(str_1 + i) - *(str_2 + i);
      stop_flag = 1;
    }
  }

  return result;
}
