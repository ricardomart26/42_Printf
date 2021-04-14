/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xconv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:27:15 by rimartin          #+#    #+#             */
/*   Updated: 2021/04/14 19:44:52 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void specific_x(sign_t *st)
{
	int uintmax;

	uintmax = check_max_u_int(st->size_c);
	// if (st->dot == 0 && !st->width && !st->align && st->conv[0] != '0')
	// 	ft_putstr(st->conv, &st->words);
	if (st->align)
		align_int_u(st, uintmax);
	else
	{
		if (st->width > st->dot)
			width_int_u(st, uintmax);
		if (st->dot != -1)
			precision_inteiro(st);
		if (st->dot != 0 || uintmax == 1)
			ft_putstr(st->conv, &st->words);
	}

	free(st->conv);
	st->conv = NULL;
}
