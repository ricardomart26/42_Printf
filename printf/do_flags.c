/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 03:01:08 by marvin            #+#    #+#             */
/*   Updated: 2021/03/18 18:15:41 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void handle_signs(sign_t *signs, va_list args)
{
	if (signs->p_align)
	{
		signs->conv = ft_letter(args, signs);
		signs->size_conv = ft_strlen(signs->conv);
		ft_putstr_fd(signs->conv, 1);
		do_width(signs);
	}
	else if (signs->v_width || signs->v_precision)
	{
		signs->conv = ft_letter(args, signs);
		signs->size_conv = ft_strlen(signs->conv);
		do_precision(signs);
		ft_putstr_fd(signs->conv, 1);
	}
}

void do_precision(sign_t *signs)
{
	if (signs->v_precision > signs->size_conv)
	{
		signs->new_precision = signs->v_precision;
		while (signs->v_precision > signs->size_conv)
		{
			signs->v_precision--;
			signs->counter_precision++;
		}
		signs->size_conv = signs->new_precision;
	}
	do_width(signs);
}

void do_width(sign_t *signs)
{
	if (signs->size_conv < signs->v_width)
	{
		signs->v_width -= signs->size_conv;
		signs->counter_words = signs->v_width;
		while (signs->v_width > 0)
		{
			if (signs->p_zero)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			signs->v_width--;
		}
	}
	while (signs->counter_precision)
	{
		write(1, "0", 1);
		signs->counter_precision--;
		signs->counter_words++;
	}
}

// void	get_arg_and_size(signs)
