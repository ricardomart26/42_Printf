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

char  *write_adress(long int adress)
{
  int index;
  char str[16] = "0123456789abcdef";
  char *ret;
  int uni;

  uni = count_uni(adress);
  ret = malloc(uni + 1);
  ret[0] = '0';
  ret[1] = 'x';
  ret[uni] = '\0';
  while (adress > 0)
  {
    index = adress % 16;
    ret[--uni] = str[index];
    adress /= 16; 
  }
  return (ret);
}


void  function(const char *format, ...)
{
  va_list ap;
  long int adress;

  va_start(ap, format);
  while (*format)
  {
    if (*format == '%' && *(format + 1) == 'p')
    {
      adress = va_arg(ap, long int);
      write_adress(adress);
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
  function("Teste nmr 1, ptr adress = %p\n", ptr);

  printf("%p\n", &c);
  printf("%p\n", ptr);
}