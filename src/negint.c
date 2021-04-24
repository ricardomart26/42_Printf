/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 18:45:47 by rimartin          #+#    #+#             */
/*   Updated: 2021/04/24 17:32:22 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	negative_align(sign_t *st)
{
	ft_putchar('-', &st->words);
	st->width--;
	if (st->dot >= st->width)
	{
		precision_inteiro_neg(st);
		ft_putstr(st->conv, &st->words);
	}
	else if (st->width > st->size_c)
	{
		if (st->dot > st->size_c)
			precision_inteiro_neg(st);
		st->width -= st->size_c;
		ft_putstr(st->conv, &st->words);
		mult_char(' ', &st->words, st->width);
	}
	else
		ft_putstr(st->conv, &st->words);
}

void	width_negative(sign_t *st)
{
	if (st->dot > st->size_c)
	{
		st->temp_dot -= st->size_c;
		st->width -= st->dot + 1;
	}
	else
		st->width -= st->size_c + 1;
	if (!st->zero)
	{
		mult_char(' ', &st->words, st->width);
		ft_putchar('-', &st->words);
	}
	else
	{
		ft_putchar('-', &st->words);
		mult_char('0', &st->words, st->width);
	}
	if (st->dot > st->size_c)
		mult_char('0', &st->words, st->temp_dot);
}


void	specific_i_neg(sign_t *st)
{
	if (st->align)
		negative_align(st);
	else if (st->dot >= st->width)
	{
		ft_putchar('-', &st->words);
		precision_inteiro_neg(st);
		ft_putstr(st->conv, &st->words);
	}
	else if (st->width > st->size_c)
	{
		width_negative(st);
		ft_putstr(st->conv, &st->words);
	}
	else
	{
		ft_putchar('-', &st->words);
		ft_putstr(st->conv, &st->words);
	}
	free(st->conv);
	st->conv = NULL;
}
