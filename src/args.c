/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:26:30 by rimartin          #+#    #+#             */
/*   Updated: 2021/04/16 20:31:58 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *get_arg(va_list args, char c, int *cminus, int *max)
{
	if (c == 's')
		return (va_arg(args, char *));
	else if (c == 'c')
		return (ft_convert_char(va_arg(args, int)));
	else if (c == 'i' || c == 'd')
		return (ft_itoa(va_arg(args, int), &cminus, &max));
	else if (c == 'u')
		return (ft_unsigneditoa(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_convhexa(va_arg(args, unsigned int), 0));
	else if (c == 'X')
		return (ft_convhexa(va_arg(args, unsigned int), 1));
	else if (c == 'p')
		return (ft_convadress(va_arg(args, unsigned long long)));
	return (0);
}

void	do_arg(va_list args, sign_t *st)
{
	st->conv = get_arg(args, st->c, &st->cminus, &st->max_value);
	if (st->conv != NULL)
		st->size_c = ft_strlen(st->conv);
	if (st->c == 's')
		return (specific_s(st));
	else if (st->c == 'c')
		return (specific_c(st));
	else if (st->c == 'i' || st->c == 'd')
		if (st->cminus)
			return (specific_i_neg(st));
		else
			return (specific_i(st));
	else if (st->c == 'u')
		return (specific_u(st));
	else if (st->c == 'x' || st->c == 'X')
		return (specific_x(st));
	else if (st->c == 'p')
		return (specific_p(st ));
}
