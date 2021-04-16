/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strconv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:56:38 by rimartin          #+#    #+#             */
/*   Updated: 2021/04/16 20:32:50 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	width(sign_t *st)
{
	if (st->size_c < st->width)
	{
		if (st->conv[0] == 0 && st->align == 1)
			st->size_c++;
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
	// printf(" align = %d ", st->align);
	// printf(" dot = %d ", st->dot);
	// printf(" width = %d ", st->width);
	// printf(" zero = %d ", st->zero);
	if (st->align)
	{
		ft_putchar(st->conv[0], &st->words);
		if (st->width)
			width(st);
	}
	else if (st->width)
		width(st);
	else
		ft_putchar(st->conv[0], &st->words);
	free(st->conv);
	st->conv = NULL;
}

void specific_s(sign_t *st)
{
	if (st->conv == NULL)
	{
		st->conv = "(null)";
		st->size_c = ft_strlen(st->conv);
		if (st->dot == 0)
			st->width++;
	}
	if (st->negprec)
		st->dot = st->size_c;
	else if (st->dot < st->size_c && st->dot != -1)
	{
		st->size_c = st->dot;
		swap(&st->conv, st->size_c, &st->dot);
	}
	if (st->align)
		ft_putstr(st->conv, &st->words);
	if (st->width)
		width(st);
	else if (!(st->align))
		ft_putstr(st->conv, &st->words);
}
