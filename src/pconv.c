/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pconv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:22:36 by rimartin          #+#    #+#             */
/*   Updated: 2021/04/16 18:51:05 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void align_int_p(sign_t *st)
{
	if (st->dot > st->size_c)
	{
		precision_inteiro(st);
		ft_putstr(st->conv, &st->words);
		width_int(st);
	}
	else if (st->width > st->size_c)
	{
		if (st->dot != 0 || st->max_value == 1)
			ft_putstr(st->conv, &st->words);
		align_width(st);
	}
	else
		ft_putstr(st->conv, &st->words);
}

void specific_p(sign_t *st)
{
	if (st->align)
		align_int_p(st);
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
