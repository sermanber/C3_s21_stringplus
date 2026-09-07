#include "../s21_string.h"

long s21_strtol(const char *nptr, char **endptr, int base) {
  long result = 0;
  int sign = 1;
  const char *s = nptr;
  while (isspace(*s)) s++;
  if (*s == '+' || *s == '-') {
    if (*s == '-') sign = -1;
    s++;
  }
  if (base == 0) {
    base = 10;
    if (*s == '0') {
      base = 8;
      s++;
      if ((toupper(*s) == 'X') && isxdigit(s[1])) {
        base = 16;
        s++;
      }
    }
  }
  if (base < 2 || base > 36) base = 10;
  int val;
  int stop_flag = 0;
  while (*s && !stop_flag) {
    if (*s >= '0' && *s <= '9')
      val = *s - '0';
    else if (*s >= 'A' && *s <= 'Z')
      val = *s - 'A' + 10;
    else if (*s >= 'a' && *s <= 'z')
      val = *s - 'a' + 10;
    else
      val = -1;

    if (val < 0 || val >= base) {
      stop_flag = 1;
    }
    if (!stop_flag) {
      result = result * base + val;
      s++;
    }
  }
  if (sign == -1) result = -result;
  if (endptr != NULL) *endptr = (char *)s;
  return result;
}

void parse_flags(const char **format, format_specifier *spec) {
  while (**format == ' ' || **format == '-' || **format == '+' ||
         **format == '0' || **format == '#') {
    switch (**format) {
      case ' ':
        spec->flags |= FLAG_SPACE;
        break;
      case '-':
        spec->flags |= FLAG_MINUS;
        break;
      case '+':
        spec->flags |= FLAG_PLUS;
        break;
      case '0':
        spec->flags |= FLAG_ZERO;
        break;
      case '#':
        spec->flags |= FLAG_HASH;
        break;
    }
    (*format)++;
  }
}

void parse_format_specifier(const char **format, format_specifier *spec,
                            va_list args) {
  spec->flags = 0;
  spec->width = 0;
  spec->precision = -1;
  spec->modifier = 0;
  spec->conversion = '\0';
  parse_flags(format, spec);
  if (isdigit(**format)) {
    char *end;
    spec->width = s21_strtol(*format, &end, 10);
    *format = end;
  } else if (**format == '*' &&
             spec->springf_mod) {  // for springf, '*' works this way
    spec->width = va_arg(args, int);
    (*format)++;
  } else if (**format == '*') {  // for spring_f
    spec->flags |= FLAG_SKIP_NEXT;
    (*format)++;
  }
  if (**format == '.') {
    (*format)++;
    if (isdigit(**format)) {
      char *end;
      spec->precision = s21_strtol(*format, &end, 10);
      *format = end;
    } else if (**format == '*') {
      spec->precision = va_arg(args, int);
      (*format)++;
    } else {
      spec->precision = 0;
    }
  }
  if (s21_strchr("hlL", **format) && **format != '\0') {
    spec->modifier = **format;
    (*format)++;
  }
  if (spec->conversion == '\0') {
    spec->conversion = **format;
    (*format)++;
  }
}

void skip_whitespace(const char **str) {
  while (**str == ' ' || **str == '\n' || **str == '\t') {
    (*str)++;
  }
}

int determine_base(const char **str, int base, int *digit_read, int width) {
  if (width == 1) {
    return 10;
  }
  if (base == 0) {
    if (**str == '0') {
      (*str)++;
      *digit_read += 1;
      if (**str == 'x' || **str == 'X') {
        if (width > 2 || width == 0) {
          (*str)++;
          *digit_read += 1;
        }
        base = 16;
      } else {
        base = 8;
      }
    } else {
      base = 10;
    }
  } else if (base == 16 && **str == '0' && toupper((*str)[1]) == 'X' &&
             (width > 2 || width == 0)) {
    (*str) += 2;
    *digit_read += 2;
  }
  return base;
}

int handle_sign(const char **str, int *sign_read) {
  int sign = 1;
  if (**str == '-') {
    *sign_read += 1;
    sign = -1;
    (*str)++;
  } else if (**str == '+') {
    (*str)++;
    *sign_read += 1;
  }
  return sign;
}

void skip_leading_zeros_base10(const char **str, int *digits_read, int width) {
  if (**str == '0' && (*digits_read < width || width == 0)) {
    while (**str == '0') {
      (*str)++;
      *digits_read += 1;
    }
    if (!isdigit(**str)) {
      (*str)--;
      *digits_read -= 1;
    }
  }
}

void skip_leading_zeros_base8(const char **str, int *digits_read, int width) {
  if ((*str)[1] == '0' && (*digits_read < width || width == 0)) {
    while ((*str)[1] == '0') {
      (*str)++;
      *digits_read += 1;
    }
  }
}

long long unsigned int build_number(const char **str, int base, int width,
                                    int *digits_read) {
  long long unsigned int result = 0;
  int stop_flag = 0;
  while (isalnum(**str) && !stop_flag) {
    char c = **str;
    int digit = 0;
    if (isdigit(c)) {
      digit = c - '0';
    } else if (isalpha(c) && base != 10 && base != 8) {
      digit = toupper(c) - 'A' + 10;
    } else {
      stop_flag = 1;
    }
    if (digit >= base) {
      stop_flag = 1;
    }
    if (width > 0 && *digits_read >= width) {
      stop_flag = 1;
    }
    if (!stop_flag) {
      result = result * base + digit;
      (*str)++;
      *digits_read += 1;
    }
  }
  return result;
}

int check_for_mantissa(const char **str) {
  int result = 0;
  if (**str == 'e' || **str == 'E') {
    if ((*str)[1] == '+' || (*str)[1] == '-') {
      if (isdigit((*str)[2])) {
        result = 1;
      }
    } else if (isdigit((*str)[1])) {
      result = 1;
    }
  }
  return result;
}

int parse_integer(const char **str, void *value, int base, int width) {
  const char *start = *str;
  long long unsigned int result = 0;
  int read_result = 1;
  skip_whitespace(str);
  int digits_read = 0;
  int sign_read = 0;
  int sign = 1;
  sign = handle_sign(str, &sign_read);
  digits_read += sign_read;
  if (base == 0) {
    base = determine_base(str, base, &digits_read, width);
  } else if (base == 16 && **str == '0' && toupper((*str)[1]) == 'X') {
    (*str) += 2;
    digits_read += 2;
  }
  if (base == 10) {
    skip_leading_zeros_base10(str, &digits_read, width);
  } else if (base == 8) {
    skip_leading_zeros_base8(str, &digits_read, width);
  }
  result = build_number(str, base, width, &digits_read);
  if ((digits_read > 0 && sign_read == 0) ||
      (sign_read > 0 && digits_read > 1)) {
    *(long long int *)value = (long long int)result;
    *(long long int *)value = *(long long int *)value * (long long int)sign;
  } else {
    *str = start;
    read_result = 0;
  }
  return read_result;
}

int process_exponent(const char **str, int width, int *digits_read,
                     long double *result) {
  int success = 0;
  char mant_sign = ((*str)[1] == '+' || (*str)[1] == '-') ? (*str)[1] : '+';
  if ((width == 0) || (width - *digits_read >= 2)) {
    if ((*str)[1] == '+' || (*str)[1] == '-') {
      (*str) += 2;
      *digits_read += 2;
    } else {
      (*str) += 1;
      *digits_read += 1;
    }
    skip_leading_zeros_base10(str, digits_read, width);
    int power = build_number(str, 10, width, digits_read);
    if (mant_sign == '+') {
      *result *= pow(10, power);
    } else {
      *result *= pow(10, -power);
    }
    success = 1;
  }
  return success;
}

int parse_float(const char **str, long double *value, int width) {
  const char *start = *str;
  long long unsigned int integer_part = 0;
  long double float_part = 0;
  long double result = 0;
  int digits_read = 0;
  int sign_read = 0;
  int read_result = 1;
  skip_whitespace(str);
  int sign = handle_sign(str, &sign_read);
  digits_read += sign_read;
  skip_leading_zeros_base10(str, &digits_read, width);
  int integer_before_point = isdigit((**str));
  integer_part = build_number(str, 10, width, &digits_read);
  if (**str == '.' && (digits_read < width || width == 0) &&
      (isdigit((*str)[1]) || (toupper(**str) == 'E') || integer_before_point)) {
    (*str)++;
    digits_read += 1;
    int start_pos = digits_read;
    float_part = (long double)build_number(str, 10, width, &digits_read);
    int number_of_digits = digits_read - start_pos;
    float_part /= pow(10, number_of_digits);
  }
  result += (long double)integer_part;
  result += float_part;
  if (check_for_mantissa(str)) {
    if (!process_exponent(str, width, &digits_read, &result)) {
      *str = start;
    }
  }
  if ((digits_read > 0 && sign_read == 0) ||
      (sign_read > 0 && digits_read > 1)) {
    *value = result * (long double)sign;
  } else {
    *str = start;
    read_result = 0;
  }
  return read_result;
}

int parse_char(const char **str, void *value, int flags) {
  int result = 0;
  if (**str != '\0') {
    char c = **str;
    if (!(flags & FLAG_SKIP_NEXT)) {
      *(char *)value = c;
      result = 1;
    }
    (*str)++;
  }
  return result;
}

int parse_string(const char **str, void *value, int flags) {
  skip_whitespace(str);
  char *dest = (char *)value;
  int result = 0;
  while (**str != ' ' && **str != '\n' && **str != '\t' && **str != '\0') {
    if (!(flags & FLAG_SKIP_NEXT)) {
      *dest = **str;
      if (!result) {
        result = 1;
      }
    }
    dest++;
    (*str)++;
  }
  *dest = '\0';
  return result;
}

int handle_integer(const char **input, const format_specifier *spec,
                   va_list args) {
  long long int value = 0;
  int fail = 0;
  int result =
      parse_integer(input, &value, get_base(spec->conversion), spec->width);
  if (!(spec->flags & FLAG_SKIP_NEXT)) {
    fail = store_integer_value(spec, args, value);
  } else {
    result = 0;
  }
  if (fail) {
    result = -1;
  }
  return result;
}

int store_integer_value(const format_specifier *spec, va_list args,
                        long long int value) {
  int fail = 0;
  int disable_checks = 1;
  if (!(spec->flags & FLAG_SKIP_NEXT)) {
    switch (spec->modifier) {
      case 'l':
        if ((value >= LONG_MIN && value <= LONG_MAX) || disable_checks) {
          *(va_arg(args, long int *)) = (long int)value;
        } else {
          fail = 1;
        }
        break;
      case 'h':
        if ((value >= SHRT_MIN && value <= SHRT_MAX) || disable_checks) {
          *(va_arg(args, short int *)) = (short int)value;
        } else {
          fail = 1;
        }
        break;
      default:
        if ((value >= INT_MIN && value <= INT_MAX) || disable_checks) {
          *(va_arg(args, int *)) = (int)value;
        } else {
          fail = 1;
        }
        break;
    }
  }
  return fail;
}

int handle_float(const char **input, const format_specifier *spec,
                 va_list args) {
  long double value = 0;
  int result = parse_float(input, &value, spec->width);
  if (!(spec->flags & FLAG_SKIP_NEXT)) {
    store_float_value(spec, args, value);
  } else {
    result = 0;
  }
  return result;
}

void store_float_value(const format_specifier *spec, va_list args,
                       long double value) {
  switch (spec->modifier) {
    case 'L':
      *(va_arg(args, long double *)) = value;
      break;
    case 'l':
      *(va_arg(args, double *)) = (double)value;
      break;
    default:
      *(va_arg(args, float *)) = (float)value;
      break;
  }
}

int handle_char(const char **input, const format_specifier *spec,
                va_list args) {
  void *ptr = NULL;
  if (!(spec->flags & FLAG_SKIP_NEXT)) {
    ptr = va_arg(args, void *);
  }
  int result = parse_char(input, ptr, spec->flags);
  return result;
}

int handle_string(const char **input, const format_specifier *spec,
                  va_list args) {
  void *ptr = NULL;
  if (!(spec->flags & FLAG_SKIP_NEXT)) {
    ptr = va_arg(args, void *);
  }
  int result = parse_string(input, ptr, spec->flags);
  return result;
}

int handle_pointer(const char **input, const format_specifier *spec,
                   va_list args) {
  void **ptr = va_arg(args, void **);
  uintptr_t value;
  int result =
      parse_integer(input, &value, get_base(spec->conversion), spec->width);
  if (!(spec->flags & FLAG_SKIP_NEXT)) {
    *ptr = (void *)value;
  } else {
    result = 0;
  }
  return result;
}

void handle_n(const char **input, const format_specifier *spec, va_list args,
              const char *initial_input) {
  int *ptr = NULL;
  if (!(spec->flags & FLAG_SKIP_NEXT)) {
    ptr = va_arg(args, void *);
  }
  if (!(spec->flags & FLAG_SKIP_NEXT)) {
    *ptr = (int)(*input - initial_input);
  }
}

int handle_perc(const char **input) {
  int found = 0;
  while (!isspace(**input) && (**input != '%')) {
    (*input)++;
  }
  if (**input == '%') {
    found = 1;
    (*input)++;
  }
  return found;
}

int get_base(char conversion) {
  int base;
  switch (conversion) {
    case 'o':
      base = 8;
      break;
    case 'x':
    case 'X':
      base = 16;
      break;
    case 'd':
    case 'i':
      base = 0;
      break;
    case 'u':
      base = 10;
      break;
    case 'p':
      base = 16;
      break;
    default:
      base = 10;
  }
  return base;
}

int empty(const char *str) {
  if (*str == '\0') {
    return 1;
  }
  return 0;
}

int space_only(const char *str) {
  if (*str == '\0') {
    return 0;
  }
  int result = 0;
  skip_whitespace(&str);
  if (*str == '\0') {
    result = 1;
  }
  return result;
}

int check_str(const char *str, char conversion) {
  int result = 1;
  ;
  if (conversion != 'c' && space_only(str)) {
    result = 0;
  }
  return result;
}

int handle_specifier(const char **input, const format_specifier *spec,
                     va_list args, const char *initial_input, int *stop_flag) {
  int count = 0;
  switch (spec->conversion) {
    case 'd':
    case 'i':
    case 'o':
    case 'u':
    case 'x':
    case 'X': {
      count += handle_integer(input, spec, args);
      break;
    }
    case 'e':
    case 'E':
    case 'f':
    case 'g':
    case 'G': {
      count += handle_float(input, spec, args);
      break;
    }
    case 'c': {
      count += handle_char(input, spec, args);
      break;
    }
    case 's': {
      count += handle_string(input, spec, args);
      break;
    }
    case 'p': {
      count += handle_pointer(input, spec, args);
      break;
    }
    case 'n': {
      handle_n(input, spec, args, initial_input);
      break;
    }
    case '%': {
      int found = handle_perc(input);
      if (found == 0) {
        *stop_flag = 1;
      }
      break;
    }
    default:
      *stop_flag = 1;
      break;
  }
  return count;
}

int s21_sscanf(const char *str, const char *format, ...) {
  if (str == NULL || format == NULL) {
    return 0;
  } else if (empty(str)) {
    return -1;
  }
  va_list args;
  va_start(args, format);
  int stop_flag = 0;
  int count = 0;
  const char *input = str;
  const char *initial_input = input;
  while (*format != '\0' && !stop_flag) {
    while (*input == *format && *input != '%') {
      input++;
      format++;
    }
    if (*format == '%') {
      format++;
      format_specifier spec;
      spec.springf_mod = 0;
      parse_format_specifier(&format, &spec, args);

      if (check_str(input, spec.conversion)) {
        count +=
            handle_specifier(&input, &spec, args, initial_input, &stop_flag);
      } else {
        stop_flag = 1;
        count = -1;
      }
    }
    if (*format != '\0' && *format != '%') {
      if (*input == *format && *input != '%') {
        format++;
        input++;
      } else {
        format++;
      }
      if (*input == ' ' || *input == '\n' || *input == '\t') {
        skip_whitespace(&input);
      }
    }
  }
  va_end(args);
  return count;
}
