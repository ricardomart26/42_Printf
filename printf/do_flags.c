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

// Como passar arg para uma string se nao sabemos o tamanho a alocar na heap?

char *edge_cases(va_list args, sign_t signs)
{
	char *temp;
	char *str;
	int c;

	c = 0;
	temp = va_arg(args, char *);
	// printf("temp = %s\n", temp);
	// printf("value = %d\n", signs->v_precision);

	str = malloc(signs.v_precision);
	if (!str)
		return (NULL);
	while (signs.v_precision > 0)
	{
		str[c] = temp[c];
		c++;
		signs.v_precision--;
	}
	str[c] == '\0';
	//	printf("str = %s\n", str);
	return (str);
}

void handle_signs(sign_t *signs, va_list args)
{
	if (signs->precision_s == 1)
		signs->conv = edge_cases(args, *signs);
	else
		signs->conv = ft_letter(args, signs);

	//printf("\nconv = %s\n", signs->conv);
	signs->size_conv = ft_strlen(signs->conv);
	signs->counter_words += signs->size_conv;

	if (signs->p_align && !signs->v_precision)
	{
		ft_putstr_fd(signs->conv, 1);
		free_if_needed(signs);
		do_precision(signs);
	}
	else if (signs->v_width || signs->v_precision)
	{
		do_precision(signs);
		ft_putstr_fd(signs->conv, 1);
		free_if_needed(signs);
	}
	else
	{
		ft_putstr_fd(signs->conv, 1);
		free_if_needed(signs);
	}
}

void do_precision(sign_t *signs)
{
	//printf("\nprecisao = %d\n", signs->v_precision);
	if (signs->c != 's')
	{
		// printf("\nteste\n");
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
	}
	// printf("\nteste\n");
	do_width(signs);
}

void do_width(sign_t *signs)
{
	//printf("precisao = %d\n", signs->v_precision);
	while (signs->v_precision && signs->c != 's')
	{
		write(1, "0", 1);
		signs->v_precision--;
		signs->counter_words++;
	}
	printf("\nwidth = %d\n", signs->v_width);
	if (signs->size_conv < signs->v_width)
	{
		signs->v_width -= signs->size_conv;
		signs->counter_words += signs->v_width;
		//printf("\nwidth = %d\n", signs->v_width);
		while (signs->v_width > 0)
		{
			if (signs->p_zero)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			signs->v_width--;
		}
	}
}

// void	get_arg_and_size(signs)
