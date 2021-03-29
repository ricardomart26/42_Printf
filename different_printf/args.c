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

char *ft_get_arg(va_list args, sign_t *st)
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
		return (ft_convhexa(va_arg(args, unsigned int), 0));
	else if (st->c == 'X')
		return (ft_convhexa(va_arg(args, unsigned int), 1));
	else if (st->c == 'p')
		return (ft_convadress(va_arg(args, unsigned long)));
	return (0);
}

void	do_arg(va_list args, sign_t *st)
{
	if (st->c == 's')
		return (specif_s(st, args));
	else if (st->c == 'c')
		return (specif_c(st, args));
	else if (st->c == 'i' || st->c == 'd')
		return (specif_int(st, args));
	else if (st->c == 'u')
		return (specif_uint(st, args));
	else if (st->c == 'x')
		return (specif_x(st, args));
	else if (st->c == 'X')
		return (specif_x(st, args));
	else if (st->c == 'p')
		return (specif_p(st , args));
}
