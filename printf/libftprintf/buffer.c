#include "header.h"

bool dataType(char c) 
{
  if (c == 'd' || c == 'u' || c == 'x' || c == 'c' ||
      c == 's' || c == 'p' || c == 'X' /*|| c == 'o' */|| c == 'i')
    return (true);
  else
    return (false);
}

bool buffer(char c1, char c2, char c3)
{
  if (c1 == '%' && data_type(c2) && c3 == 32)
    return (true);
}

void cBuffer(char *str, int *size)
{
  char c;
  while (*str)
  {
    if (*str == '%' && data_type(*(str + 1)) && *(str + 2) == 32)
      (*size)++;
    str++;
  }
}
