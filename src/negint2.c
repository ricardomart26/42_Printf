/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negint2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:31:55 by rimartin          #+#    #+#             */
/*   Updated: 2021/04/29 05:00:54 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	precision_inteiro_neg(sign_t *st)
{
	int	temp;

	temp = st->dot;
	if (st->dot < st->size_c && st->dot != -1)
		st->size_c = st->dot;
	else if (st->dot > st->size_c)
	{
		temp -= st->size_c;
		mult_char('0', &st->words, temp);
		st->size_c = st->dot;
	}
}

void	zero_neg_width(sign_t *st)
{
	int	size;

	size = 0;
	if (st->temp_dot > st->size_c)
	{
		size = st->temp_dot;
		if (size < st->width)
		{
			st->width -= size;
			mult_char(' ', &st->words, st->width);
			ft_putchar('-', &st->words);
		}
	}
}

void	width_neg(sign_t *st)
{
	int	size;

	size = 0;
	if (st->temp_dot > st->size_c)
		size = st->temp_dot;
	else
		st->width--;
	if (size < st->width)
	{
		st->width -= size + 1;
		mult_char(' ', &st->words, st->width);
		ft_putchar('-', &st->words);
	}
	if (st->dot > st->size_c)
	{
		st->dot -= st->size_c;
		mult_char('0', &st->words, st->width);
		st->size_c -= st->dot;
	}
	if (!st->align)
		ft_putstr(st->conv, &st->words);
}

void	negative_int(sign_t *st)
{
	if (st->dot >= st->width)
	{
		ft_putchar('-', &st->words);
		ft_putstr(st->conv, &st->words);
	}
	else if (st->width && st->dot == -1)
	{
		ft_putchar('-', &st->words);
		st->width -= st->size_c + 1;
		mult_char('0', &st->words, st->width);
		ft_putstr(st->conv, &st->words);
	}
	else if (st->dot < st->width)
	{
		if (st->zero)
			zero_neg_width(st);
		else
			width_neg(st);
	}
}
