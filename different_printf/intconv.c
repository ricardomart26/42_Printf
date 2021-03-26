/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intconv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:23:48 by rimartin          #+#    #+#             */
/*   Updated: 2021/03/25 21:40:55 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	if_width_int(sign_t *st)
{
	if (st->size_c < st->width)
	{
		st->width -= st->size_c + 1;
		while (st->width-- > 0)
			if (st->zero)
				ft_putstr_fd("0", 1, st);
			else
				ft_putstr_fd(" ", 1, st);
	}
	if (!(st->align))
		ft_putstr_fd(st->conv, 1, st);
}

void	if_precision_int(sign_t *st, int control)
{
	//printf("\nst->dot = %d", st->dot);
	if (st->dot < st->size_c && st->dot != -1)
	{
		st->size_c = st->dot; // O size fica com 0
		st->c_dot = 1;
		swap(st);
	}
	else if (st->dot > st->size_c)
	{

		// printf("\nteste");
		if (control == 0)
			st->size_c -= 1;
	
		st->dot -= st->size_c;
		while (st->dot > 0)
		{
			ft_putstr_fd("0", 1, st);
			st->dot--;
		}
		st->size_c -= st->dot;
	}
}


void if_align_int(sign_t *st)
{
	if (st->dot)
		if_precision_int(st, 1);
	ft_putstr_fd(st->conv, 1, st);
	free_if_needed(st);
	if_width_int(st);
}

void specif_int(sign_t *st, va_list args)
{
	st->conv = ft_get_arg(args, st);
	st->size_c = ft_strlen(st->conv);

	if (st->align)
		if_align_int(st);
	// if (st->width && !(st->dot))
	// 	if_width(st);z
	// else if (!(st->width) && st->dot)
	// 	if_precision(st);
	if (st->dot > st->width && !(st->align))
		if_precision_int(st, 0);
	else
		if_precision_int(st, 1);
	if (st->width > st->size_c && !(st->align))
		if_width_int(st);
	printf("\nwords = %d", st->words);
	free_if_needed(st);
}

void specif_uint(sign_t *st, va_list args)
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
	// else if (st->width == st->dot)
	// 	width_e_precision(st);

	free_if_needed(st);

}

