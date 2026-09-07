#include "../s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *result = NULL;
  if (str != NULL) {
    int size = s21_strlen(str);

    for (int i = size; i >= 0 && result == NULL; i--) {
      if (str[i] == (char)c) {
        result = (char *)&str[i];
      }
    }

    if (c == '\0') {
      result = (char *)&str[size];
    }
  }

  return result;
}
