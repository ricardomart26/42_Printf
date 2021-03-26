/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geral.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:25:34 by rimartin          #+#    #+#             */
/*   Updated: 2021/03/26 17:52:56 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void free_if_needed(sign_t *st)
{
	if (st->c == 'd' || st->c == 'i' || st->c == 'x' || st->c == 'X' ||
		st->c == 'p' || st->c == 'u' || st->c == 'c')
	{
		free(st->conv);
		st->conv = NULL;
	}
}

void if_align(sign_t *st)
{
	if (st->dot)
		if_precision(st);
	ft_putstr_fd(st->conv, 1, st);
	free_if_needed(st);
	if_width(st);
}

void	if_width(sign_t *st)
{
	if (st->size_c < st->width)
	{
		st->width -= st->size_c;
		while (st->width-- > 0)
			if (st->zero)
				ft_putstr_fd("0", 1, st);
			else
				ft_putstr_fd(" ", 1, st);
	}
	if (!(st->align))
		ft_putstr_fd(st->conv, 1, st);
}

void	width_s_precision(sign_t *st)
{
	if (st->dot < st->size_c)
	{
		st->size_c = st->dot;
		swap(st);
		st->dot = 0;
	}
}


void	width_b_precision(sign_t *st)
{
	// printf("\nteste n 8\n");
	st = 0;
	return ;
}

void	if_precision(sign_t *st)
{
	// printf("\nteste n 7\n");
	st = 0;
	return ;
}


void	width_e_precision(sign_t *st)
{
	// printf("\nteste n 9\n");
	st = 0;
	return ;
}
