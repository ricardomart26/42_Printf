/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intconv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:23:48 by rimartin          #+#    #+#             */
/*   Updated: 2021/04/29 05:04:56 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	precision_inteiro(sign_t *st)
{
	if (st->dot > st->size_c)
	{
		st->dot -= st->size_c;
		mult_char('0', &st->words, st->dot);
		st->size_c -= st->dot;
	}
}

void	width_int(sign_t *st)
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

void	align_width(sign_t *st)
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

void	align_int(sign_t *st)
{
	if (st->dot > st->size_c)
	{
		precision_inteiro(st);
		ft_putstr(st->conv, &st->words);
		width_int(st);
	}
	else if (st->width > st->size_c)
	{
		ft_putstr(st->conv, &st->words);
		align_width(st);
	}
	else if (st->conv[0] != '0' || st->dot != 0)
		ft_putstr(st->conv, &st->words);
}

void	specific_i(sign_t *st)
{
	if (!ft_strncmp(st->conv, "0", 1) && st->dot == 0)
		special_case(st);
	else if (st->align)
		align_int(st);
	else
	{
		if (st->width > st->dot)
			width_int(st);
		if (st->dot != -1)
			precision_inteiro(st);
		ft_putstr(st->conv, &st->words);
	}
	free(st->conv);
	st->conv = NULL;
}
