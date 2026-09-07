#include "../s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *result = NULL;
  if (str != NULL) {
    for (int i = 0; str[i] != '\0' && result == NULL; i++) {
      if (str[i] == (char)c) {
        result = (char *)&str[i];
      }
    }

    if (c == '\0') {
      result = (char *)&str[s21_strlen(str)];
    }
  }

  return result;
}
