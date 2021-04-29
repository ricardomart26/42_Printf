/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intspecial.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 05:04:31 by rimartin          #+#    #+#             */
/*   Updated: 2021/04/29 05:05:39 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	align_special(sign_t *st)
{
	if (st->width > st->size_c)
	{
		if (st->max_value == 1 || st->negprec)
			ft_putstr(st->conv, &st->words);
		align_width(st);
	}
	else if (st->conv[0] != '0' || st->negwidth || st->negprec)
		ft_putstr(st->conv, &st->words);
}

void	special_case(sign_t *st)
{
	if (st->negprec)
		st->size_c = 1;
	else
		st->size_c = 0;
	if (st->align)
		align_special(st);
	else
	{
		if (st->width)
			width_int(st);
		if (st->negprec)
			ft_putstr(st->conv, &st->words);
		return ;
	}
}
