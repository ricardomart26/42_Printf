/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:47:34 by rimartin          #+#    #+#             */
/*   Updated: 2021/03/11 18:32:13 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
// int size_of_%()
// Ver se da para fazer o tamanho da string para ver
// Como usar o args noutras funções

char	*ft_letter(va_list args, const char *format, sign_t *signs)
{
	if (signs->c == 's')
		return (va_arg(args, char *));
	else if (signs->c == '%')
		return (ft_convert_char(va_arg(args, int)));
	else if (signs->c == 'c')
		return (ft_convert_char(va_arg(args, int)));
	else if (signs->c == 'i' || signs->c == 'd')
		return (ft_itoa(va_arg(args, int)));
	else if (signs->c == 'u')
		return (ft_unsigneditoa(va_arg(args, unsigned int)));
	else if (signs->c == 'x')
		return (ft_convhexa(va_arg(args, unsigned int), 0));
	else if (signs->c == 'X')
		return (ft_convhexa(va_arg(args, unsigned int), 1));
	else if (signs->c == 'p')
		return (ft_convaddr(va_arg(args, void *)));
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

char *start_loop(char *format, va_list args, sign_t *signs)
{
	int size_perc;
	char *temp;
	char c;

	while (*format)
	{
		format += print_until_perc((char *)format); // Imprimir até ao % e adicionar ao pointer para ficar no %
		size_perc = size_per((char *)format, &c);	// tamanho da percentagem
		if (size_perc == 2)
		{
			temp = ft_letter(args, (char *)format, signs);
			//ft_putstr_fd(temp, 1);
		}
		else if (size_perc > 2)
		{
			flags(format, signs, args);
			handle_signs(format, signs, c);
			temp = ft_letter(args, format, signs);
			//ft_putstr_fd(temp, 1);
		}
		format += size_perc;
	}
	return (temp);
}

int		ft_printit(char *temp, sign_t signs)
{
	int size;

	size = ft_strlen(temp);


}

int	ft_printf(const char *format, ...)
{
	va_list args;
	char *temp;
	int counter;
	sign_t signs;

	counter = 0;
	if (!format)
		return (0);
	if (ft_checkvalid(format) != 0)
		return (-1);
	va_start(args, (char *)format);		// Inicializar args
	temp = start_loop((char *)format, args, &signs);
	counter = ft_printit(temp, signs);
	va_end(args);
	return (counter);
}

int main()
{
	char str[7] = "Ricardo";
	char c = 'i';
	int i = 10;
	int d = 1020;
	unsigned int u = 60;
	unsigned int v = -60;
	unsigned int hexa = -65464872;
	int *ptr;
	int b;

	b = 5;

	ptr = &b;

	printf("TESTE STRING PRINTF = Este e o resultado do %s printf real %s \n", str, str);
	ft_printf("TESTE STRING MEU PRINTF = Este e o resultado do %s meu printf. %s", str, str);

	printf("\nTESTE PRINTF = %% (precent) e sem args\n");
	ft_printf("MEU PRINTF = %% (percent) e sem args\n");

	printf("\nTESTE CHAR = %c (char)\n", c);
	ft_printf("MEU PRINTF CHAR = %c (char)\n", c);

	printf("\nTESTE NUMBER = %i = 10 (i) , %d (d)= 55 \n", i, d);
	ft_printf("MEU PRINTF NUMBER = %i = 10 (i) , %d (d) = 55 \n", i, d );

	printf("\nTESTE UNSIGNED = %u = 60 (u) , %u (u) = 60 \n", u, v);
	ft_printf("MEU PRINTF UNSIGNED = %u = 60 (u) , %u (u) = -60 \n", u, v);

	printf("\nHexadecimal = %x (x) , %X (X)\n", hexa, hexa);
	ft_printf("MEU HEXA = %x (x), %X (X)", hexa, hexa);

	printf("\n\nTESTE POINTER: %p (p)\n", ptr);
	ft_printf("MEU PTR = %p (p)", ptr);

	printf("Teste ao meu new-line.");
	ft_printf("\nTeste s.kmfao meu new-line.");


	ft_printf("Teste\a ao meu\a bell char\n\n."); //TERMINAL DON'T RING
	printf("Teste\a ao verdadeiro\a bell char\n\n."); //TERMINAL DON'T RING

	ft_printf("Teste\f ao meu\f form feed char\f.");
	printf("\nTeste\f ao verdadeiro\f form feed char\f.");

	ft_printf("Teste\r ao meu\r return carriage char\r.");
	printf("Teste\r ao verdadeiro\r return carriage char\r.");

	ft_printf("Teste\tao meu\ttab char\t.");
	printf("Teste\t ao verdadeiro\ttab char\t.");

	ft_printf("Teste\vao meu \vvertical tab char\v .");
	printf("Teste\vao verdadeiro \vvertical tab char\v .");

	ft_printf("Teste\'ao meu \'single quote char\' .");
	printf("Teste\'ao verdadeiro \'single quote char\' .");

	ft_printf("Teste\"ao meu \"double quote char\" .");
	printf("Teste\"ao verdadeiro \"double quote char\" .");

	ft_printf("Teste\\ao meu \\backslash char\\ .");
	printf("Teste\\ao verdadeiro \\backslash char\\ .");

	ft_printf("teste num \126");
	printf("test num  \126");

	printf("Teste Width: .%d (d) , .%d (5d), .%5i, .%-5d. , .%-5i.", d, d, i, d, i);
	ft_printf("Teste Width: .%d (d) , .%5d (5d)", d, d);


	return  0;

}
