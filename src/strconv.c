/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strconv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:56:38 by rimartin          #+#    #+#             */
/*   Updated: 2021/04/14 19:28:50 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



void	width(sign_t *st)
{
	if (st->size_c < st->width)
	{
		st->width -= st->size_c;
		if (st->zero)
			mult_char('0', &st->words, st->width);
		else
			mult_char(' ', &st->words, st->width);

	}
	if (!(st->align))
		ft_putstr(st->conv, &st->words);
}


void specific_c(sign_t *st)
{
	// if (st->align && st->width)
	// 	ft_putchar(st->conv[0], &st->words);
	//printf("\nteste width = %d\n", st->width);
	if (st->align)
	{
		ft_putchar(st->conv[0], &st->words);
		if (st->width)
			width(st);
	}
	else if (st->width)
	{
			//printf(" words = %d ", st->words);

		width(st);
	}
	else
		ft_putchar(st->conv[0], &st->words);
	free(st->conv);
	st->conv = NULL;
}

void specific_s(sign_t *st)
{
	//printf("conv = %s ", st->conv);
	if (!st->conv)
		st->conv = "(null)";
	//printf("\ndot = %d\n", st->dot);
	if (st->negprec)
		st->dot = st->size_c;
	else if (st->dot < st->size_c && st->dot != -1)
	{
		//printf("\nteste n\n");
		st->size_c = st->dot;
		swap(&st->conv, st->size_c, &st->dot);
	}
	if (st->align)
		ft_putstr(st->conv, &st->words);
	if (st->width)
		width(st);
	else if (!(st->align))
		ft_putstr(st->conv, &st->words);
// Pode faltar free
}
