/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pconv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:22:36 by rimartin          #+#    #+#             */
/*   Updated: 2021/04/29 05:00:24 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	special_putstr(char *string, int *words, int *index)
{
	int	size;

	size = ft_strlen(string);
	if (!string)
		return ;
	if (*index == 0)
	{
		*words += size;
		write(1, string, size);
		(*index)++;
	}
}

void	align_int_p(sign_t *st)
{
	if (st->dot > st->size_c)
	{
		special_putstr("0x", &st->words, &st->index);
		precision_inteiro_p(st);
		ft_putstr(st->conv, &st->words);
		width_p(st);
	}
	else if (st->width > st->size_c)
	{
		if (st->dot != 0 || st->max_value == 1)
		{
			special_putstr("0x", &st->words, &st->index);
			ft_putstr(st->conv, &st->words);
		}
		align_width(st);
	}
	else
	{
		special_putstr("0x", &st->words, &st->index);
		ft_putstr(st->conv, &st->words);
	}
}

void	precision_inteiro_p(sign_t *st)
{
	st->size_c -= 2;
	special_putstr("0x", &st->words, &st->index);
	if (st->dot < st->size_c && st->dot != -1)
		st->size_c = st->dot;
	else if (st->dot > st->size_c)
	{
		st->dot -= st->size_c;
		mult_char('0', &st->words, st->dot);
		st->size_c -= st->dot;
	}
}

void	width_p(sign_t *st)
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
		special_putstr("0x", &st->words, &st->index);
	}
}

void	specific_p(sign_t *st)
{
	st->size_c += 2;
	if (!ft_strncmp(st->conv, "0", 1) && st->dot == 0)
	{
		st->conv = ft_strdup("");
		st->size_c -= 1;
		if (st->width)
			width_p(st);
		special_putstr("0x", &st->words, &st->index);
	}
	else if (st->align)
		align_int_p(st);
	else
	{
		if (st->size_c >= st->width)
			special_putstr("0x", &st->words, &st->index);
		if (st->width > st->dot)
			width_p(st);
		if (st->dot != -1)
			precision_inteiro_p(st);
		ft_putstr(st->conv, &st->words);
	}
	free(st->conv);
	st->conv = NULL;
}
