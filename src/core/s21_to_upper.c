#include "../s21_string.h"

void *s21_to_upper(const char *str) {
  if (str == NULL) return NULL;
  int len = s21_strlen(str);
  char *res = calloc(len + 1, sizeof(char));
  if (res != NULL) {
    int i = 0;
    for (; i < len; i++) {
      if (str[i] >= 'a' && str[i] <= 'z') {
        res[i] = str[i] - 'a' + 'A';
      } else {
        res[i] = str[i];
      }
    }
    res[i] = '\0';
  }
  return (void *)res;
}