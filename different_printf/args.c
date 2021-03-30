/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:26:30 by rimartin          #+#    #+#             */
/*   Updated: 2021/03/29 17:36:02 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *get_arg(va_list args, sign_t *st)
{
	if (st->c == 's')
		return (va_arg(args, char *));
	else if (st->c == 'c')
		return (ft_convert_char(va_arg(args, int)));
	else if (st->c == 'i' || st->c == 'd')
		return (ft_itoa(va_arg(args, int), st));
	else if (st->c == 'u')
		return (ft_unsigneditoa(va_arg(args, unsigned int)));
	else if (st->c == 'x')
		return (ft_convhexa(va_arg(args, unsigned int), 0, st));
	else if (st->c == 'X')
		return (ft_convhexa(va_arg(args, unsigned int), 1, st));
	else if (st->c == 'p')
		return (ft_convadress(va_arg(args, unsigned long), st));
	return (0);
}

void	do_arg(va_list args, sign_t *st)
{
	if (st->c == 's')
		return (specific_s(st, args));
	else if (st->c == 'c')
		return (specific_c(st, args));
	else if (st->c == 'i' || st->c == 'd')
		return (specific_i(st, args));
	else if (st->c == 'u')
		return (specific_u(st, args));
	else if (st->c == 'x')
		return (specific_x(st, args));
	else if (st->c == 'X')
		return (specific_x(st, args));
	else if (st->c == 'p')
		return (specific_p(st , args));
}
