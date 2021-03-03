#include "header.h"

/* Resolver se for usado um escape?  */
/* Contar o numero de argumentos */
/* Fazer uma struct Para guardar tipos de dados */
/* Como fazer para o octal? */

int ft_printf(const char *format, ...)
{
  va_list args;
  Data dataType;
  int c;
  char *ptr;
  int count_buffers;
  char *integerString;
  char *StringUnsignedInt;

  count_buffers = 0;
  cBuffer(format, &count_buffers);
  va_start(args, count_buffers);
  ptr = (char *)format;
  c = 0;
  while (ptr[c] != '\0')
    if (buffer(ptr[c], ptr[c + 1], ptr[c + 2]))
    {
      if (ptr[c + 1] == 'd' || ptr[c + 1] == 'i')
      {
        dataType.inteiro = va_arg(args, int);
        dataType.size = intSize(dataType.inteiro);
        itoa(dataType.inteiro, integerString, dataType.size);
        write(1, &dataType.inteiro, dataType.size);
      }
      if (ptr[c + 1] == 's')
      {
        dataType.str = va_arg(args, char *);
        dataType.size = ft_strlen(dataType.str);
        write(1, dataType.str, dataType.size); // Ver melhor
      }
      if (ptr[c + 1] == 'u')
      {
        dataType.uInt = va_arg(args, unsigned);
        dataType.size = uSize(dataType.uInt);
        StringUnsignedInt = utoa(dataType.size, dataType.uInt);
        write(1, &StringUnsignedInt, dataType.size);
      }
      if (ptr[c + 1] == 'x' || ptr[c + 1] == 'X')
      {
        dataType.uInt = va_arg(args, unsigned);
        Hexadecimal(dataType.uInt);
      }
      if (ptr[c + 1] == 'o')
      {
        dataType.uInt = va_arg(args, unsigned);
        octal(dataType.uInt);
      }
      if (ptr[c + 1] == 'c')
      {
        dataType.character = va_arg(args, unsigned);
        write(1, &dataType.character, 1);
      }
      if (ptr[c + 1] == 'p')
      {
        dataType.str = va_arg(args, unsigned);
        pointer(&dataType.str);
      }
    }
    else
      write(1, ptr[c++], 1);
  va_end(args);
}

int main(void)
{
  char *array = "lol";

  int c = 0;
  ft_printf("lol");
}
