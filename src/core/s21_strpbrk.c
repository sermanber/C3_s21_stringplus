#include "../s21_string.h"

char *s21_strpbrk(const char *string, const char *string2) {
  char *result = NULL;
  int is_match = 0;
  if (string != NULL && string2 != NULL) {
    int size_string = s21_strlen(string);
    int size_string2 = s21_strlen(string2);

    for (int i = 0; i < size_string && result == NULL; i++) {
      for (int j = 0; j < size_string2 && !is_match; j++) {
        if (string[i] == string2[j]) {
          result = (char *)&string[i];
          is_match = 1;
        }
      }
    }
  }

  return result;
}
