/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xconv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:27:15 by rimartin          #+#    #+#             */
/*   Updated: 2021/04/16 19:40:33 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	precision_inteiro_x(sign_t *st)
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

void	width_int_x(sign_t *st, int uintmax)
{
	int size;
	size = st->size_c;
	if (st->temp_dot > size)
		size = st->temp_dot;
	if (st->dot == 0 && uintmax != 1)
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

void align_width_x(sign_t *st)
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

void align_int_x(sign_t *st, int xintmax)
{
	if (st->dot > st->size_c)
	{

		precision_inteiro_x(st);
		//printf("teste");
		ft_putstr(st->conv, &st->words);
		width_int_x(st, xintmax);
		//printf("\n words 1 = %d\n", st->words);
	}
	else if (st->width > st->size_c)
	{
		if (st->dot != 0 || xintmax == 1 || st->cdot > 0)
			ft_putstr(st->conv, &st->words);
		else
			st->size_c = 0;
		align_width_x(st);
	}
	else if (xintmax == 1)
		ft_putstr(st->conv, &st->words);
}

int	check_max_x_int(int size_c)
{
	if (size_c > 5)
		return (1);
	else
		return (0);
}

void specific_x(sign_t *st)
{
	int xintmax;
	//printf(" conv = %s ", st->conv);
	xintmax = check_max_x_int(st->size_c);
	if (st->align)
		align_int_x(st, xintmax);
	else
	{
		if (st->width > st->dot)
			width_int_x(st, xintmax);
		if (st->dot != -1)
			precision_inteiro_x(st);
		//printf("cdot = %d", st->cdot);
		// printf("cdot = %s", st->conv);
		if (st->dot != 0 || st->conv[0] != '0')
		{
			ft_putstr(st->conv, &st->words);
		}
	}
	free(st->conv);
	st->conv = NULL;
}
