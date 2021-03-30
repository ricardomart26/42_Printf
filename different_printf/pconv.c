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

void	width_p(sign_t *st)
{
	//printf("teste 2");
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


void align_p(sign_t *st)
{
	//printf("\nwidth = %d", st->width);

	if (st->cminus)
	{
		ft_putstr_fd(st->conv, 1, st);
		negative_int(st);
	}
	else if (st->dot > st->size_c)
	{
		precision_int(st, 1);
		ft_putstr_fd(st->conv, 1, st);
		width_int(st);
	}
	if (st->width > st->size_c)
	{
		//printf("teste");
		ft_putstr_fd(st->conv, 1, st);
		width_int(st);
	}

}


void	negative_p(sign_t *st)
{
	if (st->dot > st->width)
	{
		ft_putchar('-', st);
		precision_int(st, 0);
		if (st->align)
			align_int(st);
		else if (st->dot)
			precision_int(st, 1);
	}
	else if (st->dot < st->width)
	{
		if (st->zero)
			width_neg(st, 0);
		else
			width_neg(st, 1);
		if (st->align)
			align_int(st);
		if (st->dot != -1)
			precision_int(st, 1);
	}
	if (!st->cminus)
		ft_putstr_fd(st->conv, 1, st);
}

void specific_p(sign_t *st, va_list args)
{
	//printf("teste");
	st->conv = get_arg(args, st);
	//printf("\n\n st->conv = %s\n\n", st->conv);
	st->size_c = ft_strlen(st->conv);
	//printf("\nwidth = %d", st->width);
	//printf("\ndot = %d", st->dot);
	// printf("\nalign = %d", st->align);
	//printf("\nsize_c = %d", st->size_c);

	if (st->align == 1 && st->zero != 0)
		st->zero = 0;
	if (st->align)
		align_p(st);
	else if (st->cminus)
		negative_p(st);
	else if (st->width > st->size_c && st->dot == -1)
		width_p(st);
	else
		ft_putstr_fd(st->conv, 1, st);
	// else if (!(st->width) && st->dot)
	// 	precision(st);
	// else if (st->width > !(st->dot))
	// 	width_b_precision(st);
	// else if (st->width < st->dot)
	// 	width_s_precision(st);
	// else if (st->width == st->dot)
	// 	width_e_precision(st);
	free_needed(st);

}
