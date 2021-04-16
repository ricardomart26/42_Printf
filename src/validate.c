/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:48:31 by rimartin          #+#    #+#             */
/*   Updated: 2021/03/11 18:30:37 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int invalid(char const *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{

		if (str[i] == '%')
		{
			if (str[i + 1] == '%')
				return (0);
			while (!type(str[i]))
			{
				if (!sign(str[i]))
					exit (0);
				i++;
			}
			if (!type(str[i]))
				exit (0);
		}
		i++;
	}
	return (0);
}

int type(char c)
{
	if (c == 'c' || c == 'd' || c == 's' || c == 'i'
		|| c == 'x' || c == 'X' || c == 'p' || c == 'u')
		return (1);
	return (0);
}

int sign(char c)
{
	if (c == '.' || c == '-' || ft_isdigit(c) || c == '*' || c == '%')
		return (1);
	else
		return (0);
}
