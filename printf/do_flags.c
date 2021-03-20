/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 03:01:08 by marvin            #+#    #+#             */
/*   Updated: 2021/03/20 19:02:15 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Como passar arg para uma string se nao sabemos o tamanho a alojar na heap?

void if_width_or_precision(sign_t *st)
{
	handle_signs(st);
	ft_putstr_fd(st->conv, 1);
	free_if_needed(st);
}

void if_align(sign_t *st)
{
	ft_putstr_fd(st->conv, 1);
	free_if_needed(st);
	handle_signs(st);
}

// char *edge_cases(va_list args, sign_t st)
// {
// 	char *temp;
// 	char *str;
// 	int c;

// 	c = 0;
// 	temp = va_arg(args, char *);
// 	str = malloc(st.dot + 1);
// 	if (!str)
// 		return (NULL);
// 	while (st.dot > 0)
// 	{
// 		str[c] = temp[c];
// 		c++;
// 		st.dot--;
// 	}
// 	str[c] = '\0';
// 	return (str);
// }

void middle_man(sign_t *st, va_list args)
{
	// if (st->edge_s == 1)
	// 	st->conv = edge_cases(args, *st);
	// else
	st->conv = ft_get_arg(args, st);

	st->size_c = ft_strlen(st->conv);
	st->words += st->size_c;
	if (st->align && !(st->dot > st->width))
		if_align(st);
	else if (st->width || st->dot)
		if_width_or_precision(st);
	else
	{
		ft_putstr_fd(st->conv, 1);
		free_if_needed(st);
	}
}

void handle_signs(sign_t *st)
{
	if (st->c == 'p')
		st->dot = 0;
	else if (st->c != 's' && st->c != 'c')
	{
		if (st->dot > st->size_c)
		{
			st->temp_dot = st->dot;
			if (st->dot > st->size_c)
				st->dot -= st->size_c + 1;
			st->size_c = st->temp_dot;
		}
		else
			st->dot = 0;
	}
	else if (st->dot < st->size_c && st->c == 's')
	{
		st->size_c = st->dot;
		swap(st);
	}
	do_width(st);
}

void	swap(sign_t *st)
{
	char *temp;
	int size;

	size = st->dot;
	if (size == 0)
	{
		temp = malloc(1);
		temp[0] = '\0';
		st->conv = temp;
	}
	else
	{
		temp = (char *)malloc(size + 1);
		if (!temp)
			return ;
		while (size)
		{
			temp[size - 1] = st->conv[size - 1];
			size--;
		}
		temp[st->dot + 1] = '\0';
		st->conv = temp;
	}
	free(temp);
}

void do_width(sign_t *st)
{
	if (st->size_c < st->width)
	{
		st->width -= st->size_c;
		st->words += st->width;
		while (st->width-- > 0)
			if (st->zero)
				write(1, "0", 1);
			else
				write(1, " ", 1);
	}
	while (st->dot && (st->c != 's' && st->c != 'c'))
	{
		write(1, "0", 1);
		st->dot--;
		st->words++;
	}
}

// void	get_arg_and_size(st)
