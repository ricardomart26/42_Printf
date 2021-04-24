/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:48:11 by rimartin          #+#    #+#             */
/*   Updated: 2021/03/10 20:58:44 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	mult_char(char c, int *words, int size)
{
	*words += size;
	while (size--)
		write(1, &c, 1);
}

void	ft_putstr(char *string, int *words)
{
	int	size;

	size = ft_strlen(string);
	if (!string)
		return ;
	*words += size;
	write(1, string, size);
}

void	ft_putchar(char c, int *words)
{
	write(1, &c, 1);
	(*words)++;
}
