#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int	count_uni(long int adress)
{
	int counter;

	counter = 0;
	while (adress > 0)
	{
		adress /= 16;
		counter++;
	}
	return (counter);
}

void	write_adress(long int adress)
{
	int uni;
	char *temp;
	char str[16] = {"0123456789abcdef"};
	int index;

	uni = count_uni(adress);
	uni += 2;
	temp = (char *)malloc(uni + 1);
	temp[0] = '0';
	temp[1] = 'x';
	temp[uni] = '\0';
	while (adress > 0)
	{
		index = adress % 16;
		temp[--uni] = str[index];
		adress /= 16;
	}
	return (temp);
}


void	print_adress(const char *format, ...)
{
	va_list ap;
	long int adress;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1)== 'p')
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
	char a = 'b';

	ptr = &a;

	print_adress("teste dos pointers = %p", ptr);

}
