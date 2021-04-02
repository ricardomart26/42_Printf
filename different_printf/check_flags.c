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
		see_width(st, fmt, args);
	//printf("\nfmt = %c", *fmt);
	//printf("\nsign = %c", fmt[st->c_signs]);
	//printf("\nc_signs = %d", st->c_signs);
	fmt += st->c_signs;
	//printf("\nfmt = %c", *fmt);

	if (*fmt == '.')
		see_precision(st, fmt + 1, args);
	
	if (st->zero && (st->dot != -1 || st->align))
		st->zero = 0;

	// printf("\nalign = %d", st->align);
	// printf("\ndot = %d", st->dot);
	// printf("\nzero = %d\n", st->zero);
	// printf("\nwidth = %d ", st->width);
	do_arg(args, st);
}

void	see_width(sign_t *st, char *fmt, va_list args)
{
	if (fmt[st->c_signs] == '-')
	{
		st->c_signs++;
		st->cminus = 1;
	}
	if (ft_isdigit(fmt[st->c_signs]))
	{
		st->width = ft_atoi(fmt + st->c_signs);
		st->c_signs += ft_intlen(st->width);
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
}

// default . e 6 sem certezas
void	see_precision(sign_t *st, char *fmt, va_list args)
{
	//printf("\nsign = %c", *fmt);
	if (type(*fmt))
		st->dot = 0;
	else if (*fmt == '-')
	{
		fmt++;
		st->negprec = 1;
	}
	else if (*fmt == '*')
	{
		//printf("\nsign = %c ", fmt[st->c_signs]);
		st->dot = va_arg(args, int);
		//printf("\nst->dot = %d", st->dot);
		if (st->dot < 0 )
		{
			st->dot *= -1;
			st->negprec = 1;
		}
	}
	if (ft_isdigit(*fmt))
		st->dot = ft_atoi(fmt);
	//printf("\nst->dot = %d", st->dot);
	//printf("\n size_c = %d , dot = %d\n", st->size_c, st->dot);
	if (st->negprec)
		st->dot = 0;
}

// Fazer caso especial para se for so 0?
// Se aparecer o (-) entao escrever primeiro o arg e depois as signs
// Verificar se signs existem.
