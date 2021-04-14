/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pconv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:22:36 by rimartin          #+#    #+#             */
/*   Updated: 2021/04/14 18:49:05 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


// Nao tem precision


// void	width_p(sign_t *st)
// {
// 	//printf("teste 2");
// 	if (st->size_c < st->width)
// 	{
// 		st->width -= st->size_c;
// 		while (st->width-- > 0)
// 			if (st->zero)
// 				ft_putstr("0", &st->words);
// 			else
// 				ft_putstr(" ", &st->words);
// 	}
// 	if (!(st->align))
// 		ft_putstr(st->conv, &st->words);
// }


// void align_p(sign_t *st)
// {
// 	//printf("\nwidth = %d", st->width);

// 	if (st->cminus)
// 	{
// 		ft_putstr(st->conv, &st->words);
// 		negative_int(st);
// 	}
// 	else if (st->dot > st->size_c)
// 	{
// 		precision_inteiro(st);
// 		ft_putstr(st->conv, &st->words);
// 		width_int(st);
// 	}
// 	if (st->width > st->size_c)
// 	{
// 		//printf("teste");
// 		ft_putstr(st->conv, &st->words);
// 		width_int(st);
// 	}

// }


// void	negative_p(sign_t *st)
// {
// 	if (st->dot > st->width)
// 	{
// 		ft_putchar('-', &st->words);
// 		precision_inteiro(st);
// 		if (st->align)
// 			align_int(st);
// 		else if (st->dot)
// 			precision_inteiro(st);
// 	}
// 	else if (st->dot < st->width)
// 	{
// 		if (st->zero)
// 			zero_neg_width(st);
// 		else
// 			width_neg(st);
// 		if (st->align)
// 			align_int(st);
// 		if (st->dot != -1)
// 			precision_inteiro(st);
// 	}
// 	if (!st->cminus)
// 		ft_putstr(st->conv, &st->words);
// }

// void specific_p(sign_t *st)
// {
// 	// printf("teste");
// 	// printf("\nwidth = %d", st->width);
// 	// printf("\ndot = %d", st->dot);
// 	// printf("\nalign = %d", st->align);
// 	// printf("\nsize_c = %d", st->size_c);

// 	if (st->align == 1 && st->zero != 0)
// 		st->zero = 0;
// 	if (st->align)
// 		align_p(st);
// 	else if (st->cminus)
// 		negative_p(st);
// 	else if (st->width > st->size_c && st->dot == -1)
// 		width_p(st);
// 	else
// 		ft_putstr(st->conv, &st->words);
// 	// // else if (!(st->width) && st->dot)
// 	// 	precision(st);
// 	// else if (st->width > !(st->dot))
// 	// 	width_b_precision(st);
// 	// else if (st->width < st->dot)
// 	// 	width_s_precision(st);
// 	// else if (st->width == st->dot)
// 	// 	width_e_precision(st);
// 	free(st->conv);
// 	st->conv = NULL;

// }

void align_int_p(sign_t *st)
{
	if (st->dot > st->size_c)
	{
		precision_inteiro(st);
		//printf("teste");
		ft_putstr(st->conv, &st->words);
		width_int(st);
	}
	else if (st->width > st->size_c)
	{
		if (st->dot != 0 || st->max_value == 1)
			ft_putstr(st->conv, &st->words);
		align_width(st);
	}
	else
		ft_putstr(st->conv, &st->words);
	// else if (st->dot == 0)
	// {
	// 	align_width(st);
	// }
}

void specific_p(sign_t *st)
{
	// if (st->dot == 0 && !st->width && !st->align && st->conv[0] != '0')
	// 	ft_putstr(st->conv, &st->words);

	if (st->align)
		align_int_p(st);
	else
	{
		if (st->width > st->dot)
			width_int(st);
		if (st->dot != -1)
			precision_inteiro(st);
		if (st->dot != 0)
			ft_putstr(st->conv, &st->words);
	}

	free(st->conv);
	st->conv = NULL;

}
