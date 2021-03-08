/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:48:25 by rimartin          #+#    #+#             */
/*   Updated: 2021/03/08 19:29:50 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void see_signs(char **format, sign_t *signs, int size_perc)
{
	while (size_perc)
	{
		if (**format == '-')
			signs->align = 1;
		if (**format == '.')
			signs->dot = 1;
		if (**format == '*')
			signs->star = 1;
		if (ft_isdigit(**format))
			signs->zero = 1;
		size_perc--;
		(*format)++;
	}
}
