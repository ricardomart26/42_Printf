#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

static int count_uni_adress(long int adress)
{
  int counter;

  counter = 0;
  while (adress > 0)
  {
    adress /= 16;
    counter++;
  }
  return (counter + 2);
}

char	*ft_convhexa(unsigned int decimal, int control)
{
	char	*hexa;
	int		index;
	char 	strx[16] = "0123456789abcdef";
	char 	strX[16] = "0123456789ABCDEF";
	int		uni;

	uni =	count_uni_adress(decimal) - 2;
	hexa = malloc(uni + 1);
	hexa[uni] = '\0';
	while (decimal > 0)
	{
		index = decimal % 16;
		if (control == 1)
			hexa[--uni] = strX[index];
		else
			hexa[--uni] = strx[index];
		decimal /= 16;
	}
  printf("hexa = %s\n", hexa);
	return (hexa);
}


void  function(const char *format, ...)
{
  va_list ap;
  char *hexa;
  int nbr;

  va_start(ap, format);
  while (*format)
  {
    if (*format == '%' && *(format + 1) == 'x')
    {
      nbr = va_arg(ap, int);
      ft_convhexa(nbr, 1);
      //printf(" hexa = %s \n", hexa);
      format += 2;
    }
    if (*format == '%' && *(format + 1) == 'X')
    {
      nbr = va_arg(ap, int);
      ft_convhexa(nbr, 1);
      //printf(" hexa = %s\n ", hexa);
      format += 2;
    }
    write(1, *&format, 1);
    format++;
  }
}

int main(void)
{
  char *ptr;
  char c = 'a';

  ptr = &c;

  function("Teste nmr 1, hexa = %x\n", 10);
  function("Teste nmr 2, hexa = %X\n", 21);

  printf("%p\n", &c);
  printf("%p\n", ptr);
}