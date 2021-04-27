/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pconv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:22:36 by rimartin          #+#    #+#             */
/*   Updated: 2021/04/27 19:57:12 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && (*s1 == *s2) && n-- > 0)
	{
		s1++;
		s2++;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	align_int_p(sign_t *st)
{
	if (st->dot > st->size_c)
	{
		ft_putstr("0x", &st->words);
		precision_inteiro(st);
		ft_putstr(st->conv, &st->words);
		width_p(st);
	}
	else if (st->width > st->size_c)
	{
		if (st->dot != 0 || st->max_value == 1)
		{
			ft_putstr("0x", &st->words);
			ft_putstr(st->conv, &st->words);
		}
		align_width(st);
	}
	else
		ft_putstr(st->conv, &st->words);
}

void	width_p(sign_t *st)
{
	int size;

	size = st->size_c;
	if (st->temp_dot > size)
		size = st->temp_dot;
	if (st->dot == 0 && ft_strncmp(st->conv, "", 0))
		size = 0;
	if (size < st->width)
	{
		st->width -= size;
		if (st->zero)
			mult_char('0', &st->words, st->width);
		else
			mult_char(' ', &st->words, st->width);
		ft_putstr("0x", &st->words);
	}
}

void	special_p(sign_t *st)
{
	if (st->width > st->dot)
		width_p(st);
	if (st->dot != -1)
		precision_inteiro(st);
	if (st->dot == -1 && !st->width)
	{
		ft_putstr("0x", &st->words);
		ft_putstr(st->conv, &st->words);
	}
}

void	specific_p(sign_t *st)
{
	//printf("\nconv = %s\n", st->conv);
	st->size_c += 2;
	if (!ft_strncmp(st->conv, "0", 1) && st->dot == 0)
	{
		//printf("\nteste n\n");
		st->conv = ft_strdup("");
		st->size_c = ft_strlen(st->conv);
		special_p(st);
	}
	else if (st->align)
		align_int_p(st);
	else
	{
		if (st->size_c > st->width)
			ft_putstr("0x", &st->words);
		if (st->width > st->dot)
			width_p(st);
		if (st->dot != -1)
			precision_inteiro(st);
		ft_putstr(st->conv, &st->words);
	}
	free(st->conv);
	st->conv = NULL;
}
