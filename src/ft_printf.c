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

int	print_until_perc(char *fmt, int *words)
{
	int	c;

	c = 0;
	while (fmt[c] != '%' && fmt[c] != '\0')
		c++;
	write(1, fmt, c);
	*words += c;
	return (c);
}

int	size_per(char *fmt, char *c)
{
	int	counter;

	counter = 1;
	while ((!type(fmt[counter])))
		counter++;
	if (type(fmt[counter]))
	{
		*c = fmt[counter];
		return (counter);
	}
	return (1);
}

void	with_no_flags(va_list args, sign_t *st, char *fmt)
{
	if (fmt[1] == '%')
	{
		write(1, "%%", 1);
		st->words++;
		return ;
	}
	st->conv = get_arg(args, st->c, &st->cminus, &st->max_value);
	//printf("conv = %s", st->conv);
	if (st->cminus == 1)
		ft_putchar('-', &st->words);
	if (st->conv == NULL)
		st->conv = "(null)";
	if (st->c == 'c')
		ft_putchar(st->conv[0], &st->words);
	else if (st->c == 'p')
	{
		ft_putstr("0x", &st->words);
		ft_putstr(st->conv, &st->words);
	}
	else
		ft_putstr(st->conv, &st->words);
	if (st->c != 's')
		free(st->conv);
}

void	start_loop(char *fmt, va_list args, sign_t *st)
{
	int	size_perc;

	st->words = 0;
	while (*fmt != '\0')
	{
		init_struct(st);
		fmt += print_until_perc((char *)fmt, &st->words);
		if (*fmt == '\0')
			break ;
		size_perc = size_per((char *)fmt, &st->c);
		if (size_perc == 1)
			with_no_flags(args, st, fmt);
		else if (size_perc > 1)
			with_flags(st, fmt, args);
		fmt += size_perc + 1;
	}
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	sign_t	st;

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
// 	int i;

// 	i = 0;
// 	i = printf("%12.12i, %12.12d \n", -42, 42);
// 	printf("i = %d", i);
// 	i = ft_printf("%12.12i, %12.12d \n", -42, 42);
// 	printf(" i = %d", i);

// }
