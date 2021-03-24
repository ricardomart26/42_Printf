/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 03:01:08 by marvin            #+#    #+#             */
/*   Updated: 2021/03/24 18:44:47 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Como passar arg para uma string se nao sabemos o tamanho a alojar na heap?

// void if_zero(sign_t *st)
// {
// 	//printf("\nteste n1\n");
// 	//printf("st -> dot = %d\n", st->dot);
// 	if (st->dot > st->width)
// 	{
// 		do_precision(st);
// 		do_width(st);
// 	}
// 	if (st->width > st->dot)
// 	{
// 		do_width(st);
// 		do_precision(st);
// 	}
// 	ft_putstr_fd(st->conv, 1);
// 	free_if_needed(st);
// }


void if_width_or_precision(sign_t *st)
{
	//printf("\nteste n1\n");
	//printf("st -> dot = %d\n", st->dot);
	if (st->dot > st->width && st->width)
	{
		do_precision(st);
		do_width(st);
		ft_putstr_fd(st->conv, 1);
	}
	else if (st->width > st->dot && st->dot)
	{
		do_width(st);
		do_precision(st);
		ft_putstr_fd(st->conv, 1);

	}
	else if (st->width > st->dot)
	{
		do_width(st);
		ft_putstr_fd(st->conv, 1);
	}
	free_if_needed(st);
}

void if_align(sign_t *st)
{
	if (st->dot)
		do_precision(st);
	//printf("st->conv = %s\n", st->conv);
	ft_putstr_fd(st->conv, 1);
	free_if_needed(st);
	//printf("\nst->width = %d", st->width);

	do_width(st);
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
	st->conv = ft_get_arg(args, st);
	//printf("\n\n st->conv = %s\n\n", st->conv);
	st->size_c = ft_strlen(st->conv);
	st->words += st->size_c;
	if (st->align)
		if_align(st);
	else if (st->width || st->dot || st->zero)
		if_width_or_precision(st);
	// else if (st->zero)
	// 	if_zero(st);
}

void do_precision(sign_t *st)
{
	printf("st->dot = %d", st->dot);
	printf("st->size_c = %d", st->size_c);
	//printf("\nteste n3\n");
	if (st->c == 'p')
		st->dot = 0;
	else if (st->c != 's')
	{
		//printf("\nteste n1\n");
		if (st->dot > st->size_c)
		{
			st->temp_dot = st->dot;
			st->dot -= st->size_c;
			st->size_c = st->temp_dot;
			//printf("st->dot = %d", st->dot);
			//printf("st->size_c = %d", st->size_c);
		}
		else
			st->dot = 0;
	}
	else if (st->dot < st->size_c)
	{
		//printf("\nteste n2\n");
		st->size_c = st->dot;
		swap(st);
		st->dot = 0;
	}
	else
		return ;
	while (st->dot)
	{
		write(1, "0", 1);
		st->dot--;
		st->words++;
	}
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
}

// void	get_arg_and_size(st)
