#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <stdarg.h>

// int size_of_%()
// Ver se da para fazer o tamanho da string para ver 
// Como usar o args noutras funções?


int type(char c)
{
  if (c == 'c' || c == 'd' || c == 's' || c == 'i' 
    || c == 'x' || c == 'X' || c == 'p' || c == 'u') // Ver se falta algum
    return (1);
  else
    return (0);
}


int invalid_per(char *str, int i, int size_per)
{
  if (str[i] != '%' /* Posso tirar!! */ && str[i + 1] == ' ' && str[i + 1] == '%')
    return (0);
  else if (!(type(str[size_per - 1])))
    return (0);
  else
    return (1);
}


int number_per(char *format)
{
  int counter;
  int c;

  c = 0;
  counter = 0;

  while (format[c] != '\0')
  {
    if (!(invalid_per(format, c, size_per(format))))
      counter++;
    c++;
  }
  return (counter);
}

int size_per(char *format)
{
  int counter;
  int c;

  counter = 0;
  while (format[counter] != ' ')
  {
    counter++;
    printf("%d", counter);
  }
  if (counter > 6 || counter == 1)
  {
    printf("Too many arguments in percent");
    return (0);
  }
  // if (format[c] == '%' && format[c + 1] == '%')
  // {
  //   write(1, &format[c], 1);
  //   return (0);
  // }
  return(counter);
}


int print_until_perc(char *format)
{
  int c;

  c = 0;
  while (format[c] != '%' && format[c] != '\0')
  {
    write(1, &format[c], 1);
    c++;
  }
  return (c);
}

int basic_perc(va_list args, char *format)
{
  int c;

  c = 0;
  if (format[c] == '%' && format[c + 1] == '%')
     write(1, &format[c], 1);
  if (format[c] = '%' && format[c + 1] == 's')
  {
    va_arg(args, char *);
  }
  return (0);
}

int ft_printf(const char *format, ...)
{
  int size_perc;
  int smaller_perc;
  va_list args;
  int counter;
  // counter = number_per(format);
  va_start(args, format);
  if (!format)
    return (0);
  while (*format != '\0')
  {
    format += print_until_perc((char *)format);
    if (!(*format == '\0'))
      size_perc = size_per((char *)format);
    if (size_perc == 2)
      smaller_perc = basic_perc(args , (char *)format);
    format++;
  }
  return (0);
}

int main(void)
{
  char *str = "string qualquer % com uma percentagem";

  ft_printf(str);
  printf("%s", str);
  return (0);
}
