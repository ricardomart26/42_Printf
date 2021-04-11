/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intconv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:23:48 by rimartin          #+#    #+#             */
/*   Updated: 2021/04/11 19:50:54 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	precision_inteiro(sign_t *st)
{
	if (st->dot < st->size_c && st->dot != -1) //&& (!st->align)
	{
		st->size_c = st->dot; // O size fica com 0
	}
	else if (st->dot > st->size_c)
	{
		st->dot -= st->size_c;
		mult_char('0', &st->words, st->dot);
		st->size_c -= st->dot;
	}
}



void	width_int(sign_t *st)
{
	int size;
	size = st->size_c;
	if (st->temp_dot > size)
		size += st->temp_dot;
	if (size < st->width)
	{
		st->width -= size;
		if (st->zero)
			mult_char('0', &st->words, st->width);
		else
			mult_char(' ', &st->words, st->width);
	}

}


void align_width(sign_t *st)
{
	if (st->size_c < st->width)
	{
		st->width -= st->size_c;
		if (st->zero)
			mult_char('0', &st->words, st->width);
		else
			mult_char(' ', &st->words, st->width);
	}

}

void align_int(sign_t *st)
{
	if (st->dot > st->size_c)
	{
		precision_inteiro(st);
		//printf("teste");
		ft_putstr(st->conv, &st->words);
		width_int(st);
	}
	// else if (st->dot == 0)
	// {
	// 	align_width(st);
	// }
	else if (st->width > st->size_c)
	{
		ft_putstr(st->conv, &st->words);
		align_width(st);
	}
}

void specific_i(sign_t *st, va_list args)
{

	st->conv = get_arg(args, st->c, st->cminus);
	st->size_c = ft_strlen(st->conv);

	st->temp_dot = st->dot;
	if (st->align)
		align_int(st);
	else
	{
		if (st->width > st->dot)
			width_int(st);
		if (st->dot != -1)
			precision_inteiro(st);
		if (st->dot != 0)
		{
			//printf("\ndot = %d\n", st->dot);
			ft_putstr(st->conv, &st->words);
		}
	}

	free(st->conv);
	st->conv = NULL;
}

















void specific_u(sign_t *st, va_list args)
{

	st->conv = get_arg(args, st->c, st->cminus);
	//printf("\n\n st->conv = %s\n\n", st->conv);
	st->size_c = ft_strlen(st->conv);
	if (st->align)
	{
		st->zero = 0;
		align_int(st);
	}
	else if (st->width && !(st->dot))
		width(st);
	// else if (!(st->width) && st->dot != -1)
	// 	precision(st);
	// else if (st->width > !(st->dot))
	// 	width_b_precision(st);
	// else if (st->width < st->dot)
	// 	width_s_precision(st);
	// else if (st->width == st->dot)
	// 	width_e_precision(st);

	free(st->conv);
}

