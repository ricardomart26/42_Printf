/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:48:25 by rimartin          #+#    #+#             */
/*   Updated: 2021/03/21 15:26:11 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void init_struct(sign_t *st)
{
	st->align = 0;
	st->zero = 0;
	st->dot = -1;
	st->width = 0;
	st->c = 48;
	st->conv = 0;
	st->size_c = 0;
	st->temp_dot = 0;
	st->c_dot = 0;
	st->c_signs = 1;
	st->cminus = 0;
	st->width_c = 0;
	st->negprec = 0;
}

// Posso guardar os args na struct?
// Como alocar memoria para variavel que vai guardar a string convertida?
// Nao esquecer de chamar as funcoes width e sign
// Precisao %5.4d (10) sao 5 espacos, mas 3 numeros, exemplo ( 0010);
// Precisao das strings %10.4s (      olai)a esquerda sao os espacos e a direita os caracteres
// Width .carateres
// if (width menor que a string ignorar, se for maior acrescentar espacos.)
// if (width menor que a string ignorar, se for maior acrescentar espacos.)
// if (menos entao print string e acrescentar espacos a direita)
// Fazer align depois de escrever a conversao
// Funcao para saber o tamanho, para onde mandar mos o tamanho?

void	with_flags(sign_t *st, char *fmt, va_list args)
{
	while (fmt[st->c_signs] == '0' || fmt[st->c_signs] == '-')
	{
		if (fmt[st->c_signs] == '0' )
			st->zero = st->c_signs++;
		if (fmt[st->c_signs] == '-')
			st->align = st->c_signs++;
	}
	//printf("\nzero = %d\n", st->zero);

	if (ft_isdigit(fmt[st->c_signs]) || fmt[st->c_signs] == '*')
		width(st, fmt, args);
	if (fmt[st->c_signs] == '.')
		precision(st, fmt + 1, args);
	if (st->zero && (st->dot != -1 || st->align))
		st->zero = 0;

	//printf("\nalign = %d", st->align);
	//printf("\ndot = %d", st->dot);
	//printf("\nzero = %d\n", st->zero);
	// printf("\nwidth = %d ", st->width);
	//printf("\nalign = %d", st->align);
	//printf("\nalign = %d", st->align);

	do_arg(args, st);
}

void	width(sign_t *st, char *fmt, va_list args)
{
	char *temp;
	int counter;
	int size;

	size = 0;
	counter = 0;

	if (fmt[st->c_signs] == '-')
		st->cminus = 1;
	//st->c_signs++;
	while (ft_isdigit(fmt[size]))
		size++;
	temp = malloc(size);
	if (!temp)
		return ;
	if (ft_isdigit(fmt[st->c_signs]))
	{
		while (ft_isdigit(fmt[st->c_signs]))
			temp[counter++] = fmt[(st->c_signs)++];
		temp[counter] = '\0';
		st->width = ft_atoi(temp);
	}
	else if (fmt[st->c_signs] == '*')
	{
		st->c_signs++;
		st->width = va_arg(args, int);
		if (st->width < 0)
		{
			st->width *= -1;
			st->align = 1;
		}
	}
	// printf("\nwidth = %d", st->width);

	free(temp);
}

// default . e 6 sem certezas
void	precision(sign_t *st, char *fmt, va_list args)
{
	char *temp;
	int counter;
	int size;

	size = 0;
	//printf("\nsign = %c", fmt[st->c_signs]);
	//printf("\nsign size = %c", fmt[size]);
	if (type(fmt[st->c_signs]))
		st->dot = 0;
	else if (fmt[st->c_signs] == '-')
	{
		//printf("\nteste n 1\n");
		st->c_signs++;
		st->negprec = 1;
		size++;
	}
	while (ft_isdigit(fmt[st->c_signs]))
	{
		//printf("\nteste n 2\n");
		st->c_signs++;
		size++;
	}
	st->c_signs -= size;
	temp = malloc(size + 1);
	if (!temp)
		return ;
	counter = 0;
	if (fmt[st->c_signs] == '*')
	{
		//printf("\nsign = %c ", fmt[st->c_signs]);
		st->c_signs++;
		st->dot = va_arg(args, int);
		//printf("\nst->dot = %d", st->dot);
		if (st->dot < 0 )
		{
			st->dot *= -1;
			st->negprec = 1;
		}
	}
	else
	{
		while (ft_isdigit(fmt[st->c_signs]))
			temp[counter++] = fmt[st->c_signs++];
		temp[counter] = '\0';
		if (temp != NULL)
			st->dot = ft_atoi(temp);
		//printf("\ntemp = %s", temp);
	}
	//printf("\nst->dot = %d", st->dot);
	//printf("\n size_c = %d , dot = %d\n", st->size_c, st->dot);
	if (st->negprec)
		st->dot = 0;
	free(temp);
}

// Fazer caso especial para se for so 0?
// Se aparecer o (-) entao escrever primeiro o arg e depois as signs
// Verificar se signs existem.
