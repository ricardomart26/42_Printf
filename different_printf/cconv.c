/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cconv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:23:10 by rimartin          #+#    #+#             */
/*   Updated: 2021/03/25 20:45:14 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void specif_c(sign_t *st, va_list args)
{
	st->conv = ft_get_arg(args, st);
	st->size_c = 1;
	if (st->align && st->width)
		ft_putchar(st->conv[0], st);
	if (st->width)
		if_width(st);
	else
		ft_putchar(st->conv[0], st);
	free_if_needed(st);
}
