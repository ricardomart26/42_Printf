#include "printf.h"

void see_signs(char *format, sign_t *signs, int size_perc)
{
  int c;

  c = 1;
  while (size_perc)
  {
    if (format[c] == '-')
      signs->align = 1;
    if (format[c] == '.')
      signs->dot = 1;
    if (format[c] == '*')
      signs->star = 1;
    if (ft_isdigit(format[c]))
      signs->zero = 1;
    size_perc--;
    c++;
  }
}