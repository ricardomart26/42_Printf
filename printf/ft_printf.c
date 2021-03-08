#include "printf.h"
// int size_of_%()
// Ver se da para fazer o tamanho da string para ver
// Como usar o args noutras funções?

int invalid_per(char *str, int i, int size);

int number_per(char *format, int size)
{
  int counter;
  int c;

  c = 0;
  counter = 0;

  while (format[c] != '\0')
  {
    if (format[c] == '%')
    {
      if (!(invalid_per((char *)format, c, size)))
        counter++;
    }
    c++;
  }
  return (counter);
}

int size_per(char *format)
{
  int counter;

  counter = 0;
  while (!ft_isalpha(format[counter]))
  {
    counter++;
    printf("%d\n", counter);
  }
  if (counter > 5 || counter == 0)
  {
    printf("Too many arguments in percent\n");
    return (0);
  }
  printf("format[counter] = %c\n", format[counter]);
  if (type(format[counter]))
  {
    counter++;
    return (counter);
  }
  else
  {
    printf("Don't match any data type\n");
    return (0);
  }
  return (0);
}

int print_until_perc(char *format) // Write até ao %
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

void basic_perc(va_list args, char *format, int size)
{
  int c;

  c = 0;
  if (format[c] == '%' && format[c - 1] == '%')
    ft_putchar_fd('%', 1);
  if (format[c] == '%' && format[size - 1] == 's')
    convert_strings(args);
}

void start_loop(char *format, va_list args, int count_args)
{
  int size_perc;
  sign_t signs;
  printf("count args = %d", count_args);
  while (count_args)
  {
    format += print_until_perc((char *)format); // Imprimir até ao % e adicionar ao pointer para ficar no %
    if (!(*format == '%'))
      size_perc = size_per((char *)format); // tamanho da percentagem
    if (size_perc == 2)
      basic_perc(args, (char *)format, size_perc);
    else if (size_perc > 2)
      see_signs(format, &signs, size_perc);
    format++;
    count_args--;
  }
}

int ft_printf(const char *format, ...)
{
  va_list args;
  int count_args;

  if (!format)
    return (0);
  count_args = number_per((char *)format, size_per((char *)format)); // Contar quantidade de % validos
  va_start(args, (char *)format);                                    // Inicializar args

  start_loop((char *)format, args, count_args);
  return (0);
}

int main(void)
{
  char *str = "string qualquer % com uma percentagem";

  ft_printf("%s ", str);
  return (0);
}
