#include "../s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *result = NULL;
  if (trim_chars == NULL && src != NULL) {
    trim_chars = "";
  }
  if (src && trim_chars) {
    int len_src = s21_strlen(src);
    int found = 1;
    int left_index = 0;
    int right_index = len_src - 1;
    result = (char *)calloc(s21_strlen(src) + 1, sizeof(char));
    if (result) {
      for (int i = 0; i < len_src && found; i++) {
        found = 0;
        if (s21_strchr(trim_chars, src[i])) {
          found = 1;
          left_index += 1;
        }
      }
      found = 1;
      for (int i = len_src - 1; i > left_index && found; i--) {
        found = 0;
        if (s21_strchr(trim_chars, src[i])) {
          found = 1;
          right_index -= 1;
        }
      }
      for (int i = left_index; i <= right_index; i++) {
        result[i - left_index] = src[i];
      }
      result[right_index - left_index + 1] = '\0';
    }
  }
  return result;
}