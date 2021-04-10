/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 18:45:47 by rimartin          #+#    #+#             */
/*   Updated: 2021/04/10 19:09:11 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"



// // void do_width_int
// // {

// // }

// void negative_align(sign_t *st)
// {
// 	ft_putchar('-', &st->words);
// 	st->width--;
// 	if (st->dot >= st->width)
// 	{
// 		precision_inteiro(st);
// 		ft_putstr(st->conv, &st->words);
// 	}
// 	else if (st->width > st->size_c)
// 	{
// 		if (st->dot > st->size_c)
// 			st->size_c = st->dot;
// 		st->width -= st->size_c + 1;
// 		mult_char('0', &st->words, &st->width);
// 		ft_putstr(st->conv, &st->words);
// 	}
// }


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


// void specific_i_second(sign_t *st, va_list args)
// {
// 	//printf("teste 1");
// 	st->conv = get_arg(args, st->c, &st->cminus);
// 	st->size_c = ft_strlen(st->conv);

// 	if (st->align)
// 		do_align(st);
// }
