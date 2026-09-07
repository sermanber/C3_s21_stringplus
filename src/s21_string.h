#ifndef S21_STRING_H
#define S21_STRING_H

#define FLAG_MINUS (1 << 0)
#define FLAG_PLUS (1 << 1)
#define FLAG_ZERO (1 << 2)
#define FLAG_SPACE (1 << 3)
#define FLAG_HASH (1 << 4)
#define FLAG_SKIP_NEXT (1 << 5)

#include <ctype.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct format_specifier {
  int springf_mod;
  int flags;
  int width;
  int precision;
  char modifier;
  char conversion;
} format_specifier;

// for sscanf
void parse_format_specifier(const char **format, format_specifier *spec,
                            va_list args);
void skip_whitespace(const char **str);
int determine_base(const char **str, int base, int *digit_read, int width);
int handle_sign(const char **str, int *sign_read);
void skip_leading_zeros_base10(const char **str, int *digits_read, int width);
void skip_leading_zeros_base8(const char **str, int *digits_read, int width);
long long unsigned int build_number(const char **str, int base, int width,
                                    int *digits_read);
int check_for_mantissa(const char **str);
void parse_flags(const char **format, format_specifier *spec);
int parse_integer(const char **str, void *value, int base, int width);
int parse_float(const char **str, long double *value, int width);
int parse_char(const char **str, void *value, int flags);
int parse_string(const char **str, void *value, int flags);
int handle_integer(const char **input, const format_specifier *spec,
                   va_list args);
int store_integer_value(const format_specifier *spec, va_list args,
                        long long int value);
int handle_float(const char **input, const format_specifier *spec,
                 va_list args);
void store_float_value(const format_specifier *spec, va_list args,
                       long double value);
int handle_char(const char **input, const format_specifier *spec, va_list args);
int handle_string(const char **input, const format_specifier *spec,
                  va_list args);
int handle_pointer(const char **input, const format_specifier *spec,
                   va_list args);
int handle_perc(const char **input);
void handle_n(const char **input, const format_specifier *spec, va_list args,
              const char *initial_input);
int get_base(char conversion);
int empty(const char *str);
int space_only(const char *str);
int check_str(const char *str, char conversion);
int process_exponent(const char **str, int width, int *digits_read,
                     long double *result);
int handle_specifier(const char **input, const format_specifier *spec,
                     va_list args, const char *initial_input, int *stop_flag);
int s21_sscanf(const char *str, const char *format, ...);

// for sprintf

int s21_sprintf(char *str, const char *format, ...);
int pattern_to_str(char *dest, format_specifier *spec, va_list *param,
                   int total_printed);
int num_to_str(char *dest, unsigned long long int number, int base, int size,
               int upper);
int int_double_to_str(char *dest, long double number, int size);
int double_to_str(char *str_from_num, long double fnumber, int size,
                  format_specifier *spec);
char spec_str(char *dest, int *count, format_specifier *spec, va_list *param,
              int total_printed);
char set_sign(int sign, format_specifier *spec);
int get_c(char *dest, format_specifier *spec, va_list *param);
int get_int(char *dest, format_specifier *spec, va_list *param,
            char *char_for_sign);
int get_uint(char *dest, format_specifier *spec, va_list *param,
             char *char_for_sign);
int get_float(char *dest, format_specifier *spec, va_list *param,
              char *char_for_sign);
void trim_zero_from_end(char *dest, int *len, format_specifier *spec);
int get_str(char *dest, format_specifier *spec, va_list *param);
int print_sign(char *dest, char sign);
int normalization(long double *number);
void s21_wcstombs(char *dest, wchar_t *wstr);
int s21_wcslen(wchar_t *wstr);
void reverse(char *dest, int len);
void s21_strcat(char *dest, const char *src);

// from string.h
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strncpy(char *dest, const char *src, size_t n);
void *s21_memchr(const void *str, int c, size_t size);
void *s21_memcpy(void *dest, const void *src, size_t size);
char *s21_strchr(const char *str, int c);
int s21_memcmp(const void *str1, const void *str2, size_t size);
int s21_strncmp(const char *str1, const char *str2, size_t n);
char *s21_strpbrk(const char *string, const char *string2);
char *s21_strrchr(const char *str, int c);
char *s21_strtok(char *str, const char *delim);
void *s21_memset(void *str, int c, size_t n);
size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
size_t s21_strlen(const char *str);
char *s21_strncat(char *dest, const char *src, size_t n);

// from C#
void *s21_insert(const char *src, const char *str, size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);
void *s21_to_lower(const char *str);
void *s21_to_upper(const char *str);

#endif