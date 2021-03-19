/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_signs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:48:25 by rimartin          #+#    #+#             */
/*   Updated: 2021/03/18 18:17:18 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void init_struct(sign_t *st)
{
	st->align = 0;
	st->zero = 0;
	st->dot = 0;
	st->width = 0;
	st->c = 48;
	st->conv = 0;
	st->size_c = 0;
	st->temp_dot = 0;
	st->c_dot = 0;
	st->c_signs = 1;
	st->words = 0;
	st->edge_s = 0;
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

void signs(sign_t *st, char *fmt, va_list args)
{
	if (fmt[st->c_signs] == '-')
		st->align = st->c_signs++;

	if (fmt[st->c_signs] == '0' && fmt[st->c_signs - 1] != '-')
		st->zero = st->c_signs++;
	else if (fmt[st->c_signs] == '0' && st->c != 's')
		st->c_signs++;
	
	if (ft_isdigit(fmt[st->c_signs]) || fmt[st->c_signs] == '*')
		width(st, fmt, args);
	if (fmt[st->c_signs] == '.')
		precision(st, fmt, args);

	handle_signs(st, args);
}

void	width(sign_t *st, char *fmt, va_list args)
{
	char *temp;
	int counter;
	int size;

	size = 0;
	counter = 0;
	while (ft_isdigit(fmt[size]))
		size++;
	temp = malloc(size);
	// if (!temp)
	// 	return (NULL);
	if (ft_isdigit(fmt[st->c_signs]))
	{
		while (ft_isdigit(fmt[st->c_signs]))
			temp[counter++] = fmt[(st->c_signs)++];
		temp[counter] = '\0';
		st->width = ft_atoi(temp);
		free(temp);
	}
	else if (fmt[st->c_signs] == '*')
		st->width = va_arg(args, int);
				
}

// default . e 6 sem certezas
void	precision(sign_t *st, char *fmt, va_list args)
{
	char *temp; 
	int counter;
	int size;

	size = 0;
	while (ft_isdigit(fmt[size]))
		size++;
	temp = malloc(size + 1);
	// if (!temp)
	// 	return (NULL);
	st->c_signs++;
	counter = 0;
	if (fmt[st->c_signs] == '*')
		st->dot = va_arg(args, int);
	while (ft_isdigit(fmt[st->c_signs]))
	{
		temp[counter++] = fmt[st->c_signs++];
	}	
	temp[counter] = '\0';
	if (temp != NULL)
	{
		st->dot = ft_atoi(temp);	
		if (st->c == 's')
			st->edge_s = 1;
	}
	free(temp);
}

// Fazer caso especial para se for so 0?
// Se aparecer o (-) entao escrever primeiro o arg e depois as signs
// Verificar se signs existem.
