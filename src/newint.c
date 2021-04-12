/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 18:45:47 by rimartin          #+#    #+#             */
/*   Updated: 2021/04/12 18:44:40 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



// // void do_width_int
// // {

// // }


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
			mult_char(' ', &st->words, st->width);
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
		mult_char(' ', &st->words, st->width);
		ft_putchar('-', &st->words);
	}
	if (st->dot > st->size_c)
	{
		st->dot -= st->size_c;
		mult_char('0', &st->words, st->width);
		st->size_c -= st->dot;
	}
	if (!st->align)
		ft_putstr(st->conv, &st->words);
}





void	negative_int(sign_t *st)
{
	if (st->dot >= st->width)
	{
		ft_putchar('-', &st->words);
		//precision_inteiro(st);
		ft_putstr(st->conv, &st->words);
	}
	else if (st->width && st->dot == -1)
	{
		ft_putchar('-', &st->words);
		st->width -= st->size_c + 1;
		mult_char('0', &st->words, st->width);
		ft_putstr(st->conv, &st->words);
	}
	else if (st->dot < st->width)
	{
		if (st->zero)
			zero_neg_width(st);
		else
			width_neg(st);
	}
}



void negative_align(sign_t *st)
{
	ft_putchar('-', &st->words);
	st->width--;
	if (st->dot >= st->width)
	{
		precision_inteiro(st);
		ft_putstr(st->conv, &st->words);
	}
	else if (st->width > st->size_c)
	{
		if (st->dot > st->size_c)
			st->size_c = st->dot;
		st->width -= st->size_c;
		ft_putstr(st->conv, &st->words);
		mult_char(' ', &st->words, st->width);
	}
}


// void do_align(sign_t *st)
// {
// 	if (st->cminus)
// 		negative_align(st);
// 	else if (st->dot > st->size_c)
// 	{
// 		if (st->dot < st->width)
// 		{
// 			mult_char(' ', &st->words, st->width - st->dot);
// 			mult_char('0', &st->words, st->dot - st->size_c);
// 			ft_putstr(st->conv, &st->words);
// 		}
// 		else
// 		{
// 			mult_char('0', &st->words, st->dot - st->size_c);
// 			ft_putstr(st->conv, &st->words);
// 		}
// 	}
// 	else if (st->width > st->size_c)
// 	{

// 	}
// }
void	see_if_zero_neg(sign_t *st)
{
	if (!st->zero)
	{
		mult_char(' ', &st->words, st->width);
		ft_putchar('-', &st->words);
	}
	else
	{
		ft_putchar('-', &st->words);
		mult_char('0', &st->words, st->width);
	}
	mult_char('0', &st->words, st->temp_dot);

}

void	width_negative(sign_t *st)
{
	if (st->dot > st->size_c)
	{
		st->temp_dot -= st->size_c;
		st->width -= st->dot + 1;
	}
	else
		st->width -= st->size_c + 1;

	
}

void specific_i_neg(sign_t *st)
{
	//printf("\nteste n\n");

	if (st->align)
		negative_align(st);
	else if (st->dot > st->width)
	{
		ft_putchar('-', &st->words);
		precision_inteiro(st);
		ft_putstr(st->conv, &st->words);
	}
	else if (st->width > st->size_c)
	{
		width_negative(st);
		see_if_zero_neg(st);
		ft_putstr(st->conv, &st->words);

	}
	free(st->conv);
	st->conv = NULL;
}

// if (st->cminus)
// {
// 	//printf("\nteste n\n");
// 	ft_putchar('-', &st->words);
// 	ft_putstr(st->conv, &st->words);
// 	negative_int(st);
// }
