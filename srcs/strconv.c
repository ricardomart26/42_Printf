/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strconv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:56:38 by rimartin          #+#    #+#             */
/*   Updated: 2021/04/29 17:57:08 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	percentagem(t_sign *st)
{
	if (st->align)
	{
		ft_putchar(st->conv[0], &st->words);
		if (st->width)
			width(st);
	}
	else if (st->width)
		width(st);
	else
		ft_putchar(st->conv[0], &st->words);
	free(st->conv);
	st->conv = NULL;
}

void	width(t_sign *st)
{
	if (st->size_c < st->width)
	{
		st->width -= st->size_c;
		if (st->zero)
			mult_char('0', &st->words, st->width);
		else
			mult_char(' ', &st->words, st->width);
	}
	if (!(st->align))
	{
		if (st->c == 'c')
			ft_putchar(st->conv[0], &st->words);
		else
			ft_putstr(st->conv, &st->words);
	}
}

void	specific_c(t_sign *st)
{
	st->size_c = 1;
	if (st->align)
	{
		ft_putchar(st->conv[0], &st->words);
		if (st->width > st->size_c)
			width(st);
	}
	else if (st->width)
		width(st);
	else
		ft_putchar(st->conv[0], &st->words);
	free(st->conv);
	st->conv = NULL;
}

char	*ft_convert_char(int inteiro)
{
	char	c;
	char	*temp;

	temp = (char *)malloc(2);
	if (!temp)
		return (NULL);
	c = (char)inteiro;
	temp[0] = c;
	temp[1] = '\0';
	return (temp);
}

void	specific_s(t_sign *st)
{
	int	control;

	control = 0;
	if (st->conv == NULL)
	{
		st->conv = "(null)";
		st->size_c = ft_strlen(st->conv);
	}
	if (st->negprec)
		st->dot = st->size_c;
	else if (st->dot < st->size_c && st->dot != -1)
	{
		st->size_c = st->dot;
		swap(&st->conv, st->size_c, &st->dot);
		control = 1;
	}
	if (st->align)
		ft_putstr(st->conv, &st->words);
	if (st->width)
		width(st);
	else if (!(st->align))
		ft_putstr(st->conv, &st->words);
	if (control == 1)
		free(st->conv);
}
