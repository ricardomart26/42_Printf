/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intconv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:23:48 by rimartin          #+#    #+#             */
/*   Updated: 2021/04/08 18:03:16 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


// void	precision_neg(sign_t *st)
// {
// }

void	precision_inteiro(sign_t *st)
{
	//printf("\n size_c = %d , width = %d\n", st->size_c, st->dot);
	// if (st->width > st->dot && (!st->align))
	// 	width_int(st);

	//printf("\nst->size_c = %d \n", st->size_c);
	if (st->dot < st->size_c && st->dot != -1) //&& (!st->align)
	{
		st->size_c = st->dot; // O size fica com 0
		st->c_dot = 1;
	}
	else if (st->dot > st->size_c)
	{
		st->dot -= st->size_c;
		mult_char('0', &st->words, &st->dot);
		st->size_c -= st->dot;
	}
	if (!st->align)
		ft_putstr(st->conv, &st->words);
}


void	zero_neg_width(sign_t *st)
{
	int size;

	size = 0;
	if (st->temp_dot > st->size_c)
	{

		size = st->temp_dot;
		if (size < st->width)
		{
			st->width -= size;
			mult_char(' ', &st->words, &st->width);
			ft_putchar('-', &st->words);
		}
	}
}

void	width_neg(sign_t *st)
{
	int size;

	size = 0;
	if (st->temp_dot > st->size_c)
		size = st->temp_dot;
	else
		st->width--;
	if (size < st->width)
	{
		st->width -= size + 1;
		mult_char(' ', &st->words, &st->width);
		ft_putchar('-', &st->words);
	}
	if (st->dot > st->size_c)
	{
		st->dot -= st->size_c;
		mult_char('0', &st->words, &st->width);
		st->size_c -= st->dot;
	}
	if (!st->align)
		ft_putstr(st->conv, &st->words);
}

void	width_int(sign_t *st)
{
	//printf("\n size_c = %d , width = %d\n", st->size_c, st->width);
	//int temp;
	int size;
	//printf("teste");


	//temp = 0;
	size = st->temp_dot;
	//else if (st->temp_dot > size)
		//temp = st->temp_dot;
	if (size < st->width)
	{
		st->width -= size;
		if (st->zero)
			mult_char('0', &st->words, &st->width);
		else
			mult_char(' ', &st->words, &st->width);
	}

}


void	negative_int(sign_t *st)
{
	if (st->dot >= st->width)
	{
		ft_putchar('-', &st->words);
		if (st->align)
			align_int(st);
		else if (st->dot)
			precision_inteiro(st);
	}
	else if (st->width && st->dot == -1)
	{
		ft_putchar('-', &st->words);
		st->width -= st->size_c + 1;
		mult_char('0', &st->words, &st->width);
		ft_putstr(st->conv, &st->words);
	}
	else if (st->dot < st->width)
	{
		if (st->align)
		 	align_int(st);
		else if (st->zero)
			zero_neg_width(st);
		else
			width_neg(st);
		// if (st->align)
		// 	align_int(st);
		// if (st->dot != -1)
		// 	precision_inteiro(st);
	}
}

static void align_width(sign_t *st)
{
	int size;


	size = st->size_c;
	if (size < st->width)
	{
		st->width -= size;
		if (st->zero)
			mult_char('0', &st->words, &st->width);
		else
			mult_char(' ', &st->words, &st->width);
	}

}

void align_int(sign_t *st)
{
	int temp;

	temp = 0;
	if (st->cminus)
	{
		ft_putchar('-', &st->words);
		ft_putstr(st->conv, &st->words);
		negative_int(st);
	}
	else if (st->dot > st->size_c)
	{
		precision_inteiro(st);
		//printf("teste");
		ft_putstr(st->conv, &st->words);
		//width_int(st);
		width_int(st);
	}
	else if (st->width > st->size_c)
	{
		ft_putstr(st->conv, &st->words);
		align_width(st);
	}
}

void specific_i(sign_t *st, va_list args)
{
	//printf("teste 1");
	st->conv = get_arg(args, st->c, &st->cminus);
	st->size_c = ft_strlen(st->conv);
	//printf("\n\n size_c = %d", st->size_c);

	st->temp_dot = st->dot;
	//printf("\nst->minus = %d \n", st->cminus);
	//printf("\nst->dot = %d \n", st->dot);
	if (st->align)
		align_int(st);
	else if (st->cminus)
		negative_int(st);
	else
	{
		//printf("teste 2");
		if (st->width)
			width_int(st);
		if (st->dot != -1)
			precision_inteiro(st);
		// if (st->width > st->temp_dot)
		// 	width_int(st);
		else if (st->dot != 0)
			ft_putstr(st->conv, &st->words);
	}
	// if (st->width && !(st->dot))
	// 	width(st);
	// else if (!(st->width) && st->dot)
	// 	precision(st);
	//printf("\nwords = %d", st->words);
	// printf("\ndot = %d", st->dot);
	// printf("\nsize = %d", st->size_c);
	free(st->conv);
	st->conv = NULL;

}

















void specific_u(sign_t *st, va_list args)
{
	st->conv = get_arg(args, st->c, &st->cminus);
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

