/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geral.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:25:34 by rimartin          #+#    #+#             */
/*   Updated: 2021/04/13 19:25:56 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void free_needed(char *string, char c)
// {
// 	if (c == 'd' || c == 'i' || c == 'x' || c == 'X' ||
// 		c == 'p' || c == 'u' || c == 'c')
// 	{
// 		free(string);
// 		string = NULL;
// 	}
// }

// void align(sign_t *st)
// {
// 	if (st->dot)
// 		precision(st);
// 	ft_putstr_fd(1, st);
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



void	width_s_precision(sign_t *st)
{
	if (st->dot < st->size_c)
	{
		st->size_c = st->dot;
		swap(&st->conv, st->size_c, &st->dot);
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
