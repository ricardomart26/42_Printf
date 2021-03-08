#include "printf.h"

int invalid_per(char *str, int i, int size)
{
  if (str[i + 1] == ' ' && !(type(str[size - 1])))
    return (0);
  while (size - 2)
  {
    if (sign(str[i]))
      i++;
    else
    {
      printf("Invalido tipo ou sinal\n");
      return (0);
    }
    size--;
  }
  return (1);
}

int type(char c)
{
  if (c == 'c' || c == 'd' || c == 's' || c == 'i' 
    || c == 'x' || c == 'X' || c == 'p' || c == 'u') // Ver se falta algum
    return (1);
  return (0);
}

int sign(char c)
{
  if (c == '.' || c == '-' || ft_isdigit(c) || c == '*') 
    return (1);
  else
    return (0);
}
