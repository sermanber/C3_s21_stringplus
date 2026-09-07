#include "../s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  int i_s = 0, i_f = 0, len;
  va_list param;
  va_start(param, format);
  char *start_pattern;
  const char *end_pattern;
  format_specifier spec = {1, 0, 0, 0, 0, 0};
  while (format[i_f]) {
    for (; format[i_f] && format[i_f] != '%';) {
      str[i_s++] = format[i_f++];
    }
    str[i_s] = 0;
    if (format[i_f] == '%') {
      i_f++;
      start_pattern = (char *)format + i_f;
      end_pattern = start_pattern;
      parse_format_specifier(&end_pattern, &spec, param);
      i_f += end_pattern - start_pattern;
      if (spec.conversion) {
        len = pattern_to_str(str + i_s, &spec, &param, i_s);
        i_s += len;
      } else {
        i_f--;
      }
    }
  }
  va_end(param);
  str[i_s] = 0;
  return i_s;
}

int pattern_to_str(char *dest, format_specifier *spec, va_list *param,
                   int total_printed) {
  int count = 0, shift = 0;
  char sign = spec_str(dest, &count, spec, param, total_printed);
  if (sign) {
    shift++;
    if (sign == 'p' || sign == 'x') shift++;
  }
  if (spec->width > count + shift && !(spec->flags & FLAG_MINUS))
    shift = spec->width - count;
  for (int i = 0; i <= count; i++) dest[shift + count - i] = dest[count - i];
  int zero_or_space = (spec->flags & FLAG_ZERO) &&
                      (spec->precision == -1 ||
                       NULL == s21_strchr("diuoxXp", spec->conversion));
  if (spec->flags & FLAG_MINUS) {
    if (sign) count += print_sign(dest, sign);
    for (; count < spec->width; count++) dest[count] = ' ';
  } else {
    for (int i = 0; i < shift; i++, count++) {
      dest[i] = zero_or_space ? '0' : ' ';
    }
    if (sign) {
      if (zero_or_space) {
        print_sign(dest, sign);
      } else {
        if (sign == 'p') {
          dest[shift - 2] = '0';
          dest[shift - 1] = 'x';
        } else if (sign == 'x') {
          dest[shift - 2] = '0';
          dest[shift - 1] = 'X';
        } else {
          dest[shift - 1] = sign;
        }
      }
    }
  }
  dest[count] = 0;
  return count;
}

int print_sign(char *dest, char sign) {
  int res = 1;
  if (sign == 'p') {
    dest[0] = '0';
    dest[1] = 'x';
    res++;
  } else if (sign == 'x') {
    dest[0] = '0';
    dest[1] = 'X';
    res++;
  } else {
    dest[0] = sign;
  }
  return res;
}

char spec_str(char *dest, int *count, format_specifier *spec, va_list *param,
              int total_printed) {
  char char_for_sign = 0;
  dest[0] = 0;
  switch (spec->conversion) {
    case 'c':
      *count = get_c(dest, spec, param);
      break;
    case 'd':
    case 'i':
      *count = get_int(dest, spec, param, &char_for_sign);
      break;
    case 'p':
    case 'u':
    case 'o':
    case 'x':
    case 'X':
      *count = get_uint(dest, spec, param, &char_for_sign);
      break;
    case 's':
      *count = get_str(dest, spec, param);
      break;
    case 'f':
    case 'e':
    case 'E':
    case 'g':
    case 'G':
      *count = get_float(dest, spec, param, &char_for_sign);
      break;
    case 'n':
      int *ptr;
      ptr = va_arg(*param, int *);
      *ptr = total_printed;
      break;
    default:
      dest[*count] = spec->conversion;
      *count += 1;
      break;
  }
  dest[*count] = 0;
  return char_for_sign;
}

char set_sign(int sign, format_specifier *spec) {
  char res = 0;
  if (sign < 0) {
    res = '-';
  } else {
    if (spec->flags & FLAG_PLUS) {
      res = '+';
    } else if (spec->flags & FLAG_SPACE) {
      res = ' ';
    }
  }
  return res;
}

int get_c(char *dest, format_specifier *spec, va_list *param) {
  int len = 0;
  wchar_t wc_tmp;
  if (spec->modifier == 'l') {
    wc_tmp = va_arg(*param, wchar_t);
  } else {
    wc_tmp = (char)va_arg(*param, int);
  }
  char c_tmp[sizeof(wchar_t) + 1] = {0};
  wctomb(c_tmp, wc_tmp);
  for (int i = 0; c_tmp[i]; i++)
    if (c_tmp[i]) dest[len++] = c_tmp[i];
  return len;
}

int get_int(char *dest, format_specifier *spec, va_list *param,
            char *char_for_sign) {
  long long int number;
  switch (spec->modifier) {
    case 'h':
      short int args = (short int)va_arg(*param, int);
      number = (long int)args;
      break;
    case 'l':
      long int argl = va_arg(*param, long int);
      number = (long int)argl;
      break;
    default:
      int argi = va_arg(*param, int);
      number = (long int)argi;
      break;
  }
  int sign = (number >= 0) ? 1 : -1;
  number *= sign;
  *char_for_sign = set_sign(sign, spec);
  return num_to_str(dest, number, 10,
                    spec->precision == -1 ? 1 : spec->precision, 0);
}

int get_uint(char *dest, format_specifier *spec, va_list *param,
             char *char_for_sign) {
  unsigned long int res;
  if (spec->conversion == 'p') spec->modifier = 'l';
  switch (spec->modifier) {
    case 'h':
      unsigned short int args = (unsigned short int)va_arg(*param, int);
      res = (unsigned long long int)args;
      break;
    case 'l':
      unsigned long int argl = va_arg(*param, unsigned long int);
      res = (unsigned long long int)argl;
      break;
    default:
      unsigned int argi = va_arg(*param, unsigned int);
      res = (unsigned long int)argi;
      break;
  }
  int len;
  int prec = spec->precision == -1 ? 1 : spec->precision;
  switch (spec->conversion) {
    case 'u':
      len = num_to_str(dest, res, 10, prec, 0);
      break;
    case 'o':
      len = num_to_str(dest, res, 8, prec, 0);
      if ((res || (!res && !spec->precision)) && (spec->flags & FLAG_HASH)) {
        *char_for_sign = '0';
      }
      break;
    case 'x':
      len = num_to_str(dest, res, 16, prec, 0);
      if (res && (spec->flags & FLAG_HASH)) *char_for_sign = 'p';
      break;
    case 'X':
      len = num_to_str(dest, res, 16, prec, 1);
      if (res && (spec->flags & FLAG_HASH)) *char_for_sign = 'x';
      break;
    case 'p':
      len = num_to_str(dest, res, 16, prec, 0);
      *char_for_sign = 'p';
      break;
  }
  return len;
}

int get_float(char *dest, format_specifier *spec, va_list *param,
              char *char_for_sign) {
  long double number;
  int exp = 0, trim_flag = 0;
  int prec = spec->precision == -1 ? 6 : spec->precision;
  if (spec->modifier == 'L') {
    number = va_arg(*param, long double);
  } else {
    number = (long double)va_arg(*param, double);
  }
  int sign = (number >= 0) ? 1 : -1;
  number *= sign;
  *char_for_sign = set_sign(sign, spec);
  if (spec->conversion == 'e' || spec->conversion == 'E') {
    exp = normalization(&number);
  } else if (spec->conversion == 'g' || spec->conversion == 'G') {
    long double tmp = number;
    exp = normalization(&tmp);
    if (prec == 0) prec = 1;
    if (exp >= -4 && exp < prec) {
      prec = prec - (exp + 1);
    } else {
      if (spec->conversion == 'g') {
        spec->conversion = 'e';
      } else {
        spec->conversion = 'E';
      }
      prec--;
      number = tmp;
    }
    if (!(spec->flags & FLAG_HASH)) trim_flag = 1;
  }
  int len = double_to_str(dest, number, prec, spec);
  if (trim_flag) trim_zero_from_end(dest, &len, spec);
  if (spec->conversion == 'e' || spec->conversion == 'E') {
    dest[len++] = spec->conversion;
    dest[len++] = exp >= 0 ? '+' : '-';
    exp = (exp >= 0) ? exp : -exp;
    len += num_to_str(dest + len, exp, 10, 2, 0);
  }
  return len;
}

void trim_zero_from_end(char *dest, int *len, format_specifier *spec) {
  if (s21_strchr(dest, '.')) {
    while (dest[*len - 1] == '0') {
      *len -= 1;
      dest[*len] = '\0';
    }
    if (dest[*len - 1] == '.' && !(spec->flags & FLAG_HASH)) {
      *len -= 1;
      dest[*len] = '\0';
    }
  }
}

int get_str(char *dest, format_specifier *spec, va_list *param) {
  if (spec->modifier != 'l') {
    if (spec->precision == -1) {
      s21_strcat(dest, va_arg(*param, const char *));
    } else {
      s21_strncpy(dest, va_arg(*param, const char *), spec->precision);
      dest[spec->precision] = '\0';
    }
  } else {
    wchar_t *wstr;
    wstr = va_arg(*param, wchar_t *);
    int len = s21_wcslen(wstr);
    s21_wcstombs(dest, wstr);
    if (spec->precision != -1 && spec->precision < len)
      dest[spec->precision] = '\0';
  }
  return s21_strlen(dest);
}

int num_to_str(char *dest, unsigned long long int number, int base, int size,
               int upper) {
  int len = 0;
  int c;
  while (number > 0 || len < size) {
    c = number % base;
    number /= base;
    if (c < 10) {
      dest[len++] = '0' + c;
    } else {
      char letter_for_10 = 'a';
      if (upper) letter_for_10 = 'A';
      dest[len++] = c - 10 + letter_for_10;
    }
  }
  dest[len] = 0;
  reverse(dest, len);
  return len;
}

int int_double_to_str(char *dest, long double number, int size) {
  int len = 0;
  int c;
  long double buffer;
  while (number > 0 || len < size) {
    buffer = floorl(number / 10);
    c = number - 10 * buffer;
    number = buffer;
    dest[len++] = '0' + c;
  }
  dest[len] = 0;
  reverse(dest, len);
  return len;
}

void reverse(char *dest, int len) {
  char tmp;
  for (int i = 0; i < len / 2; i++) {
    tmp = dest[i];
    dest[i] = dest[len - 1 - i];
    dest[len - 1 - i] = tmp;
  }
}

int double_to_str(char *str_from_num, long double fnumber, int size,
                  format_specifier *spec) {
  int len = 0;
  unsigned long long int p = pow(10, size);
  long double n_total = roundl(fnumber * p);
  long double n1 = floorl(n_total / p);
  long double n2 = n_total - n1 * p;
  len = int_double_to_str(str_from_num, n1, 1);
  if ((int)n2 != 0 || size != 0 || (spec->flags & FLAG_HASH))
    str_from_num[len++] = '.';
  len += int_double_to_str(str_from_num + len, n2, size);
  return len;
}

int normalization(long double *number) {
  int exp = 0;
  if (*number != 0) {
    if (*number >= 10) {
      while (*number >= 10) {
        exp++;
        *number /= 10;
      }
    } else if (*number < 1) {
      while (*number < 1 && *number != 0) {
        exp--;
        *number *= 10;
      }
    }
  }
  return exp;
}

void s21_wcstombs(char *dest, wchar_t *wstr) {
  int dest_index = 0;
  char c_tmp[sizeof(wchar_t) + 1] = {0};
  for (int i = 0; wstr[i]; i++) {
    for (unsigned int j = 0; j < sizeof(wchar_t); j++) c_tmp[j] = 0;
    wctomb(c_tmp, wstr[i]);
    for (unsigned int j = 0; c_tmp[j] && j < sizeof(wchar_t); j++)
      dest[dest_index++] = c_tmp[j];
  }
  dest[dest_index] = '\0';
}

int s21_wcslen(wchar_t *wstr) {
  int len = 0;
  while (wstr[len]) len++;
  return len;
}

void s21_strcat(char *dest, const char *src) {
  size_t i = 0;
  for (; src[i]; i++) {
    dest[i] = src[i];
  }
  dest[i] = '\0';
}
