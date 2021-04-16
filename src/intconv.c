/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intconv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:23:48 by rimartin          #+#    #+#             */
/*   Updated: 2021/04/16 19:22:13 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	precision_inteiro(sign_t *st)
{
	if (st->dot < st->size_c && st->dot != -1) //&& (!st->align)
		st->size_c = st->dot; // O size fica com 0
	else if (st->dot > st->size_c)
	{
		st->dot -= st->size_c;
		mult_char('0', &st->words, st->dot);
		st->size_c -= st->dot;
	}
}

void	width_int(sign_t *st)
{
	int size;
	size = st->size_c;
	if (st->temp_dot > size)
		size = st->temp_dot;
	if (st->dot == 0)
		size = 0;
	if (size < st->width)
	{
		st->width -= size;
		if (st->zero)
			mult_char('0', &st->words, st->width);
		else
			mult_char(' ', &st->words, st->width);
	}

}

void align_width(sign_t *st)
{
	if (st->dot == 0 && st->max_value != 1)
		st->size_c = 0;
	if (st->size_c < st->width)
	{
		st->width -= st->size_c;
		if (st->zero)
			mult_char('0', &st->words, st->width);
		else
			mult_char(' ', &st->words, st->width);
	}

}

void align_int(sign_t *st)
{
	if (st->dot > st->size_c)
	{
		precision_inteiro(st);
		//printf("teste");
		ft_putstr(st->conv, &st->words);
		width_int(st);
	}
	else if (st->width > st->size_c)
	{
		if (st->dot != 0 || st->max_value == 1)
			ft_putstr(st->conv, &st->words);
		align_width(st);
	}
}

void specific_i(sign_t *st)
{
	if (st->dot == 0 && !st->width && !st->align && st->conv[0] != '0')
		ft_putstr(st->conv, &st->words);
	if (st->align)
		align_int(st);
	else
	{
		if (st->width > st->dot)
			width_int(st);
		if (st->dot != -1)
			precision_inteiro(st);
		if (st->dot != 0)
			ft_putstr(st->conv, &st->words);
	}
	free(st->conv);
	st->conv = NULL;
}


