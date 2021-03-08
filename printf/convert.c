#include "printf.h"

void convert_strings(va_list args)
{
  char *string;

  string = va_arg(args, char *);
  ft_putstr_fd(string, 1);
}
