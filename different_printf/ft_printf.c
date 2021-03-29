/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:47:34 by rimartin          #+#    #+#             */
/*   Updated: 2021/03/21 15:31:02 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Verificar se esta a contar bem as palavras
// Ver se e melhor fazer uma função para escrever e depois as flags ou vice versa
// Ver o 0
// Perguntar se temos que meter o 0x ja que o # faz isso

int print_until_perc(char *fmt, sign_t *st) // Write até ao %
{
	int c;

	c = 0;
	while (fmt[c] != '%' && fmt[c] != '\0')
		ft_putchar(fmt[c++], st);
	return (c);
}

int size_per(char *fmt, sign_t *st)
{
	int counter;

	counter = 0;
	if (fmt[counter + 1] == '%')
		return (2);

	while ((!type(fmt[counter])))
		counter++;
	if (type(fmt[counter]))
	{
		st->c = fmt[counter];
		return (counter + 1);
	}

	return (1);
}

void with_no_flags(va_list args, sign_t *st)
{
	st->conv = ft_get_arg(args, st);
	if (st->c == 'c')
		ft_putchar(st->conv[0], st);
	else
		ft_putstr_fd(st->conv, 1, st);
	free_if_needed(st);
}

void start_loop(char *fmt, va_list args, sign_t *st)
{
	int size_perc;

	st->words = 0;
	while (*fmt != '\0')
	{
		//printf("\nbe words = %d", st->words);
		init_struct(st);
		fmt += print_until_perc((char *)fmt, st);
		//printf("\naf words = %d", st->words);

		if (*fmt == '\0')
			break;
		size_perc = size_per((char *)fmt, st);
		if (size_perc == 2)
			if (fmt[1] == '%')
				write(1, "%%", 1);
			else
				with_no_flags(args, st);
		else if (size_perc > 2)
			with_flags(st, fmt, args);
		fmt += size_perc;
	}
}

int ft_printf(const char *fmt, ...)
{
	va_list args;
	sign_t st;

	if (!fmt)
		return (0);
	if (invalid(fmt) != 0)
		return (-1);

	va_start(args, (char *)fmt);
	start_loop((char *)fmt, args, &st);
	va_end(args);
	return (st.words);
}

// int main(void)
// {
// 	printf(" 0*%-0*.10d*0 0*%-0*.0d*0 ", 21, 1021, 21, -1011);
// 	ft_printf(" 0*%-0*.10d*0 0*%-0*.0d*0 ", 21, 1021, 21, -1011);
// }
