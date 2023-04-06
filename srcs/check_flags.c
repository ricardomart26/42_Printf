/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:48:25 by rimartin          #+#    #+#             */
/*   Updated: 2021/03/21 15:26:11 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_struct(t_sign *st)
{
	st->zero = 0;
	st->align = 0;
	st->width = 0;
	st->dot = -1;
	st->c = 48;
	st->conv = 0;
	st->size_c = 0;
	st->temp_dot = 0;
	st->negprec = 0;
	st->negwidth = 0;
	st->cminus = 0;
	st->max_value = 0;
	st->index = 0;
	st->space = 0;
	st->plus = 0;
	st->hash = 0;
}

void	with_flags(t_sign *st, char *fmt, va_list args)
{
	int	c;

	c = 1;
	while (fmt[c] == '0' || fmt[c] == '-' || fmt[c] == '+' || fmt[c] == ' ' || fmt[c] == '#')
	{
		if (fmt[c] == '0' )
			st->zero = c++;
		if (fmt[c] == '-')
			st->align = c++;
		if (fmt[c] == ' ' )
			st->space = c++;
		if (fmt[c] == '+')
			st->plus = c++;
		if (fmt[c] == '#')
			st->hash = c++;
	}
	if (ft_isdigit(fmt[c]) || fmt[c] == '*')
		see_width(st, fmt, args, &c);
	fmt += c;
	if (*fmt == '.')
		see_precision(st, fmt + 1, args);
	if (st->zero && ((st->dot != -1 && st->negprec == 0) || st->align))
		st->zero = 0;
	st->temp_dot = st->dot;
	do_arg(args, st);
}

void	see_width(t_sign *st, char *fmt, va_list args, int *c)
{
	if (ft_isdigit(fmt[*c]))
	{
		st->width = ft_atoi(fmt + *c);
		*c += ft_intlen(st->width);
	}
	else if (fmt[(*c)++] == '*')
	{
		st->width = va_arg(args, int);
		if (st->width < 0)
		{
			st->width *= -1;
			st->align = 1;
			st->negwidth = 1;
		}
	}
}

void	see_precision(t_sign *st, char *fmt, va_list args)
{
	if (type(*fmt))
		st->dot = 0;
	else if (*fmt == '-')
	{
		fmt++;
		st->negprec = 1;
	}
	else if (*fmt == '*')
	{
		st->dot = va_arg(args, int);
		if (st->dot < 0)
		{
			st->dot = 0;
			st->negprec = 1;
		}
	}
	if (ft_isdigit(*fmt))
		st->dot = ft_atoi(fmt);
}
