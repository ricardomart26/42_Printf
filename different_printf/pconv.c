/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pconv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:22:36 by rimartin          #+#    #+#             */
/*   Updated: 2021/03/25 20:47:35 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void specif_p(sign_t *st, va_list args)
{
	st->conv = ft_get_arg(args, st);
	//printf("\n\n st->conv = %s\n\n", st->conv);
	st->size_c = ft_strlen(st->conv);
	if (st->align)
	{
		st->zero = 0;
		if_align(st);
	}
	else if (st->width && !(st->dot))
		if_width(st);
	else if (!(st->width) && st->dot)
		if_precision(st);
	else if (st->width > !(st->dot))
		width_b_precision(st);
	else if (st->width < st->dot)
		width_s_precision(st);
	else if (st->width == st->dot)
		width_e_precision(st);

	free_if_needed(st);

}
