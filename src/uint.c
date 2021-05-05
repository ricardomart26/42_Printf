/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 09:19:46 by rimartin          #+#    #+#             */
/*   Updated: 2021/05/02 23:04:44 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	width_int_u(sign_t *st)
{
	int	size;

	size = st->size_c;
	if (st->temp_dot > size)
		size = st->temp_dot;
	if (size < st->width)
	{
		st->width -= size;
		if (st->zero)
			mult_char('0', &st->words, st->width);
		else
			mult_char(' ', &st->words, st->width);
	}
}

void	align_width_u(sign_t *st)
{
	if (st->size_c < st->width)
	{
		st->width -= st->size_c;
		if (st->zero)
			mult_char('0', &st->words, st->width);
		else
			mult_char(' ', &st->words, st->width);
	}
}

void	align_int_u(sign_t *st)
{
	//printf("teste");
	if (st->dot > st->size_c)
	{
		precision_inteiro(st);
		ft_putstr(st->conv, &st->words);
		if (st->width > st->size_c)
		width_int_u(st);
	}
	else if (st->width >= st->size_c)
	{
	//	printf("teste");
		// if (!st->negprec)
		// 	ft_putstr(" ", &st->words);
		if (st->dot != 0 || st->negprec)
			ft_putstr(st->conv, &st->words);
		else
			st->size_c = 0;
		align_width_u(st);
	}
	else if (st->conv[0] == '0' && st->negprec == 0 && st->dot == 0)
		return ;
	else
		ft_putstr(st->conv, &st->words);
}

int	check_max_u_int(int size_c)
{
	if (size_c > 9)
		return (1);
	else
		return (0);
}

void	specific_u(sign_t *st)
{
	int	uintmax;

	uintmax = check_max_u_int(st->size_c);
	if (st->dot == 0 && (st->negprec || st->conv[0] != '0'))
	{
		if (st->align && st->negprec)
			align_int_u(st);
		else
		{
			if (st->width > st->size_c)
				width_int_u(st);
			ft_putstr(st->conv, &st->words);
		} 
	}
	else if (st->align)
		align_int_u(st);
	else
	{

		if (st->dot == 0 && !st->negprec && st->conv[0] == '0')
			st->size_c = 0;
		if (st->width > st->dot)
			width_int_u(st);
		if (st->dot != -1)
			precision_inteiro(st);
		if ((st->dot != 0)|| uintmax == 1)
			ft_putstr(st->conv, &st->words);
	}
	free(st->conv);
	st->conv = NULL;
}
