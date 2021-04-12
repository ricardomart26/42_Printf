/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strconv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:56:38 by rimartin          #+#    #+#             */
/*   Updated: 2021/04/12 17:22:42 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void	align_s(sign_t *st);
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

// void	precision_s(sign_t *st)
// {
// 	if (st->dot < st->size_c)
// 	{
// 		st->size_c = st->dot;
// 		swap(st);
// 		st->dot = 0;
// 	}
// }

void specific_c(sign_t *st)
{
	if (st->align && st->width)
		ft_putchar(st->conv[0], &st->words);
	//printf("\nteste width = %d\n", st->width);
	if (st->width)
		width(st);
	else
		ft_putchar(st->conv[0], &st->words);
	free(st->conv);
	st->conv = NULL;
}

void specific_s(sign_t *st)
{
	//printf("conv = %s ", st->conv);
	if (!st->conv)
		st->conv = "(null)";
	//printf("\ndot = %d\n", st->dot);
	if (st->negprec)
		st->dot = st->size_c;
	else if (st->dot < st->size_c && st->dot != -1)
	{
		//printf("\nteste n\n");
		st->size_c = st->dot;
		swap(&st->conv, &st->size_c, &st->dot);
	}
	if (st->align)
		ft_putstr(st->conv, &st->words);
	if (st->width)
		width(st);
	else if (!(st->align))
		ft_putstr(st->conv, &st->words);
// Pode faltar free
}
