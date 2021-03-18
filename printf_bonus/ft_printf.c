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

// Verificar se esta a contar bem as palavras
// Ver se e melhor fazer uma função para escrever e depois as flags ou vice versa
// Como converter um numero para notação cientifica (string)
// Perceber o n
// Float, acrescenta sempre 6 casas a seguir a virgula e não funciona com a width
// Float, fazer função para so contar a frente da virgula


char *ft_letter(va_list args, sign_t signs)
{
	if (signs.c == 's')
		return (va_arg(args, char *));
	else if (signs.c == '%')
		return (ft_convert_char(va_arg(args, int)));
	else if (signs.c == 'c')
		return (ft_convert_char(va_arg(args, int)));
	else if (signs.c == 'i' || signs.c == 'd')
		return (ft_itoa(va_arg(args, int)));
	else if (signs.c == 'u')
		return (ft_unsigneditoa(va_arg(args, unsigned int)));
	else if (signs.c == 'x')
		return (ft_convhexa(va_arg(args, unsigned int), 0));
	else if (signs.c == 'X')
		return (ft_convhexa(va_arg(args, unsigned int), 1));
	else if (signs.c == 'p')
		return (ft_convadress(va_arg(args, long int)));
	return (0);
}

int print_until_perc(char *format, sign_t *signs) // Write até ao %
{
	int c;

	c = 0;
	while (format[c] != '%' && format[c] != '\0')
	{
		signs->ret++;
		write(1, &format[c], 1);
		c++;
	}
	return (c);
}

int size_per(char *format, sign_t *signs)
{
	int counter;

	counter = 0;
	if (format[counter + 1] == '%')
	{
		signs->c = '%';
		return (2);
	}
	while ((!type(format[counter])))
		counter++;
	if (type(format[counter]))
	{
		signs->c = format[counter++];
		return (counter);
	}
	return (0);
}


void start_loop(char *format, va_list args, sign_t *signs)
{
	int size_perc;
	
	signs->ret = 0;
	while (*format != '\0')
	{
		init_struct(signs);
		format += print_until_perc((char *)format, signs);
		if (*format == '\0')
			break;
		size_perc = size_per((char *)format, signs);
		if (size_perc == 2)
		{
			if (format[1] == '%')
				write(1, "%%", 1);
			else
			{
				signs->conv = ft_letter(args, *signs);
				ft_putstr_fd(signs->conv, 1);
			}
		}
		else if (size_perc > 2)
			flags(signs, format, args);
		format += size_perc;
	}
}



int ft_printf(const char *format, ...)
{
	va_list args;
	sign_t signs;

	if (!format)
		return (0);
	if (invalid(format) != 0)
		return (-1);

	va_start(args, (char *)format);
	start_loop((char *)format, args, &signs);
	va_end(args);
	return (signs.ret);
}

int main()
{
	// char str[8] = "Ricardo";
	// char c = 'i';
	// int i = 10;
	int d = 1020;
	// unsigned int u = 60;
	// unsigned int v = -60;
	// unsigned int hexa = -65464872;
	// int *ptr;
	// int b;

	// b = 5;
	int *ptr = &d;
	// ptr = &b;

	// printf("TESTE STRING PRINTF = Este e o resultado do %s printf real %s \n", str, str);
	// ft_printf("TESTE STRING MEU PRINTF = Este e o resultado do %s meu printf. %s\n", str, str);

	// printf("\nTESTE PRINTF = %% (precent) e sem args\n");
	// ft_printf("MEU PRINTF = %% (percent) e sem args\n");

	// printf("\nTESTE CHAR = %c (char)\n", c);
	//  ft_printf("MEU PRINTF CHAR = %c (char)\n", c);

	// printf("\nTESTE NUMBER = %i = 10 (i) , %d (d)= 55 \n", i, d);
	// ft_printf("MEU PRINTF NUMBER = %i = 10 (i) , %d (d) = 55 \n", i, d );

	// printf("\nTESTE UNSIGNED = %u = 60 (u) , %u (u) = 60 \n", u, v);
	// ft_printf("MEU PRINTF UNSIGNED = %u = 60 (u) , %u (u) = -60 \n", u, v);

	// printf("\nHexadecimal = %x (x) , %X (X)\n", 10241241, 10241241);
	// ft_printf("MEU HEXA = %x (x), %X (X)\n", 10241241, 10241241); // nao funciona com numeros negativos.

	// printf("\n\nTESTE POINTER: %p (p)\n", ptr);
	// ft_printf("MEU PTR = %p (p)\n\n", ptr);

	// printf("Teste ao meu new-line.");
	// ft_printf("\nTeste s.kmfao meu new-line.");

	// ft_printf("Teste\a ao meu\a bell char\n\n."); //TERMINAL DON'T RING
	// printf("Teste\a ao verdadeiro\a bell char\n\n."); //TERMINAL DON'T RING

	// ft_printf("Teste\f ao meu\f form feed char\f.\n");
	// printf("\nTeste\f ao verdadeiro\f form feed char\f.\n");

	// ft_printf("Teste\r ao meu\r return carriage char\r.\n");
	// printf("Teste\r ao verdadeiro\r return carriage char\r.\n");

	// ft_printf("Teste\tao meu\ttab char\t.\n");
	// printf("Teste\t ao verdadeiro\ttab char\t.\n");

	// ft_printf("Teste\vao meu \vvertical tab char\v .\n");
	// printf("Teste\vao verdadeiro \vvertical tab char\v .\n");

	// ft_printf("Teste\'ao meu \'single quote char\' .\n");
	// printf("Teste\'ao verdadeiro \'single quote char\' .\n");

	// ft_printf("Teste\"ao meu \"double quote char\" .\n");
	// printf("Teste\"ao verdadeiro \"double quote char\" .\n");

	// ft_printf("Teste\\ao meu \\backslash char\\ .\n");
	// printf("Teste\\ao verdadeiro \\backslash char\\ .\n");

	// ft_printf("teste num \126\n");
	// printf("test num  \126\n");

	// printf("Teste Width real: .%4d (d) , .%5d (5d)\n", d, d);
	// ft_printf("Teste Width: .%4d (d) , .%100d (5d)\n", d, d);

	// printf("\nTeste Width star real: .%*d (5d)\n", 5, d);
	// ft_printf("Teste Width star meu: .%*d (*8d)\n", 8, d);

	// printf("\nTeste align real: .%-5d (-5d) , .%-*d (-*d)",  d, 8, d);
	// ft_printf("\nTeste align meu: .%-*d (-*d)\n", 8, d);











	// printf("\n exprimentar %3d\n", 3194);
	// printf(" exprimentar %3s\n", "Claudia");
	// printf(" exprimentar %f\n", 324.234);

	// ft_printf("\n meu : exprimentar %3d\n", 3194);
	// ft_printf(" meu : exprimentar %3s\n", "Claudia");

	// printf("\n exprimentar %g\n", 3194.23);
	// printf(" exprimentar %e\n", 324.234);

	// printf("\n exprimentar %n\n", ptr);
	// printf(" exprimentar %.3f\n", 324.234);
	// printf(" exprimentar %.9f\n", 324.234); // (324.234000000) Fica 9 a partir da virgula 
	// printf(" exprimentar %9f\n", 324.234); // width no float nao faz nada

	
	// printf("\n exprimentar %.1f\n", 3194.23); // 3194.2
	// printf("\n exprimentar %1f\n", 3194.23); // Nada mudou
	// printf("\n exprimentar %-9f ffef\n", 3194.23); //  Nada mudou
	// printf("\n exprimentar % f\n", 3194.23); // espaço
	// printf("\n exprimentar %#f\n", 3194.23); //  Nada mudou
	// printf("\n exprimentar %+f\n", 3194.23); // sinal de mais
	// printf("\n exprimentar %-f did\n", 3194.23); // nada mudou



	// printf("\n exprimentar %4g\n", 3194.23); // Nao mudou nada
	// printf("\n exprimentar %2g\n", 3194.23); // Nao mudou nada
	// printf("\n exprimentar %1g\n", 3194.23); // Nao mudou nada
	// printf("\n exprimentar %.6g\n", 3194.23); // Nao mudou nada



	// printf("\n exprimentar %-3g\n", 3194.23); // Nao mudou nada
	// printf("\n exprimentar %-63g\n", 3194.23); // Nao mudou nada
	// printf("\n exprimentar %0g\n", 3194.23); // Nao mudou nada
	// printf("\n exprimentar %.06g\n", 3194.23); // Nao mudou nada
	// printf("\n exprimentar %0.0g\n", 3194.23); // notação cientifica
	// printf("\n exprimentar % g\n", 3194.23); // Faz um espaco
	// printf("\n exprimentar %#g\n", 3194.23); // Nao mudou nada
	// printf("\n exprimentar %+g\n", 3194.23); // Adiciona um mais
	



	// printf("\n exprimentar %4e\n", 3194.23); // Nao mudou nada
	// printf("\n exprimentar %2e\n", 3194.23); // Nao mudou nada
	// printf("\n exprimentar %1e\n", 3194.23); // Nao mudou nada
	// printf("\n exprimentar %.6e\n", 3194.23); // Nao mudou nada



	// printf("\n exprimentar %-3e\n", 3194.23); // Nao mudou nada
	// printf("\n exprimentar %-63e\n", 3194.23); // Nao mudou nada
	// printf("\n exprimentar %0e\n", 3194.23); // Nao mudou nada
	// printf("\n exprimentar %.06e\n", 3194.23); // Nao mudou nada
	// printf("\n exprimentar %0.0e\n", 3194.23); // 3e+003 corta os numeros do meio
	// printf("\n exprimentar % e\n", 3194.23); // Faz um espaco
	// printf("\n exprimentar %#e\n", 3194.23); // Nao mudou nada
	// printf("\n exprimentar %+e\n", 3194.23); // Adiciona um mais
	



	// printf("\n exprimentar %4e\n", 3194.23); // Nao mudou nada
	// printf("\n exprimentar %2e\n", 3194.23); // Nao mudou nada
	// printf("\n exprimentar %1e\n", 3194.23); // Nao mudou nada
	// printf("\n exprimentar %.6e\n", 3194.23); // Nao mudou nada



// ---------------------------------------------------------  O "n" nao pode ter formato ---------------------------------------------

	// printf("\n exprimentar %-3n\n", ptr); // Nao mudou nada
	// printf("\n exprimentar %-63n\n", ptr); // Nao mudou nada
	// printf("\n exprimentar %0n\n", ptr); // Nao mudou nada
	// printf("\n exprimentar %.06n\n", ptr); // Nao mudou nada
	// printf("\n exprimentar %0.0n\n", ptr); // 3e+003 corta os numeros do meio
	// printf("\n exprimentar % n\n", ptr); // Faz um espaco
	// printf("\n exprimentar %#n\n", ptr); // Nao mudou nada
	// printf("\n exprimentar %+n\n", ptr); // Adiciona um mais
	









	// printf("printf real = %10.5d\n", 10); // (  00010)
	// ft_printf("meu printf = %10.5d\n", 10); // (  00010)



	return 0;
}
