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

void free_needed(sign_t *st)
{
	if (st->c == 'd' || st->c == 'i' || st->c == 'x' || st->c == 'X' ||
		st->c == 'p' || st->c == 'u' || st->c == 'c')
	{
		free(st->conv);
		st->conv = NULL;
	}
}

// void align(sign_t *st)
// {
// 	if (st->dot)
// 		precision(st);
// 	ft_putstr_fd(st->conv, 1, st);
// 	free_needed(st);
// 	width(st);
// }

// void	write_size(sign_t *st, int size)
// {
// 	if (!st->conv)
// 		return ;
// 	st->words += size;
// 	while (size--)
// 		write(1, st->conv++, 1);
	
// }

void	width(sign_t *st)
{
	if (st->size_c < st->width)
	{
		st->width -= st->size_c;
			if (st->zero)
				mult_char('0', st, st->width);
			else
				mult_char(' ', st, st->width);
				
	}
	if (!(st->align))
		ft_putstr(st->conv, st);
}

void	width_s_precision(sign_t *st)
{
	if (st->dot < st->size_c)
	{
		st->size_c = st->dot;
		swap(st, st->size_c);
		st->dot = 0;
	}
}


// void	width_b_precision(sign_t *st)
// {
// 	// printf("\nteste n 8\n");
// 	st = 0;
// 	return ;
// }

// void	precision(sign_t *st)
// {
// 	// printf("\nteste n 7\n");
// 	st = 0;
// 	return ;
// }


// void	width_e_precision(sign_t *st)
// {
// 	// printf("\nteste n 9\n");
// 	st = 0;
// 	return ;
// }
