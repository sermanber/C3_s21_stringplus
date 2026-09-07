#include "../s21_string.h"

void *s21_insert(const char *src, const char *str, size_t start_index) {
  if (src == NULL || str == NULL) {
    return NULL;
  }
  char *result = NULL;
  size_t len_of_src = s21_strlen(src);
  size_t len_of_str = s21_strlen(str);
  size_t overall = len_of_src + len_of_str;
  if (start_index <= len_of_src) {
    result = (char *)calloc(overall + 2, sizeof(char));
    if (result) {
      for (size_t i = 0; i < start_index; i++) {
        result[i] = src[i];
      }
      for (size_t i = start_index; i < start_index + len_of_str; i++) {
        result[i] = str[i - start_index];
      }
      for (size_t i = start_index + len_of_str; i <= overall; i++) {
        result[i] = src[i - len_of_str];
      }
      result[overall + 1] = '\0';
    }
  }
  return result;
}