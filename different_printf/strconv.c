/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strconv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:56:38 by rimartin          #+#    #+#             */
/*   Updated: 2021/03/29 17:41:22 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void	if_align_s(sign_t *st);
// {

// }

// void	width_s_precision_s(sign_t *st)
// {
// 	if (st->dot < st->size_c)
// 	{
// 		st->size_c = st->dot;
// 		swap(st);
// 		st->dot = 0;
// 	}
// }

// void	width_e_precision_s(sign_t *st)
// {
// 	if (st->dot < st->size_c)
// 	{
// 		st->size_c = st->dot;
// 		swap(st);
// 		st->dot = 0;
// 	}
// }

// void	if_precision_s(sign_t *st)
// {
// 	if (st->dot < st->size_c)
// 	{
// 		st->size_c = st->dot;
// 		swap(st);
// 		st->dot = 0;
// 	}
// }

void specif_s(sign_t *st, va_list args)
{
	st->conv = ft_get_arg(args, st);
	if ((!st->conv))
		st->conv = "(null)";
	if (st->conv)
		st->size_c = ft_strlen(st->conv);
	//printf("\ndot = %d\n", st->dot);
	if (st->negprec)
		st->dot = st->size_c;
	if (st->dot < st->size_c && st->dot != -1)
	{
		st->size_c = st->dot;
		st->c_dot = 1;
		swap(st);
	}
	if (st->align)
		ft_putstr_fd(st->conv, 1, st);

	if (st->width)
		if_width(st);
	else if (st->c_dot != 1 && !(st->align))
		ft_putstr_fd(st->conv, 1, st);
	else if (st->c_dot == 1)
		ft_putstr_fd(st->conv, 1, st);

	free_if_needed(st);
}
