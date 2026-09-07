#include "../s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *current_position = NULL;
  if (delim == NULL) {
    return NULL;
  }
  if (str != NULL) {
    current_position = str;
  } else if (current_position == NULL) {
    return NULL;
  } else if (*current_position == '\0') {
    return NULL;
  }
  char *token_start = NULL;
  int token_found = 0;

  while (*current_position && s21_strchr(delim, *current_position)) {
    current_position++;
  }

  if (*current_position != '\0') {
    token_start = current_position;
    token_found = 1;

    while (*current_position && !s21_strchr(delim, *current_position)) {
      current_position++;
    }

    if (*current_position) {
      *current_position = '\0';
      current_position++;
    }
  }

  return token_found ? token_start : NULL;
}
