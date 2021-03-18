/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:48:25 by rimartin          #+#    #+#             */
/*   Updated: 2021/03/11 18:54:13 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Ligar o put_value ao programa

void init_struct(sign_t *signs)
{
	signs->p_align = 0;
	signs->p_zero = 0;
	signs->v_precision = 0;
	signs->v_width = 0;
	signs->c = 48;
	signs->conv = NULL;
	signs->size_conv = 0;
	signs->counter_precision = 0;
	signs->new_precision = 0;
	signs->counter_flags = 1;
	signs->counter_words = 0;

}

// Nao funciona com dois width -5d -*d

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

void flags(sign_t *signs, char *format, va_list args)
{
	if (format[signs->counter_flags] == '-')
		signs->p_align = signs->counter_flags++;
	if (format[signs->counter_flags] == '0' && format[signs->counter_flags - 1] != '-')
		signs->p_zero = signs->counter_flags++;
	else if (format[signs->counter_flags] == '0')
		signs->counter_flags++;
	if (ft_isdigit(format[signs->counter_flags]) || format[signs->counter_flags] == '*')
		width(signs, format, args);
	if (format[signs->counter_flags] == '.')
		precision(signs, format, args);

	handle_signs(signs, args);
}

void width(sign_t *signs, char *format, va_list args)
{
	char *temp = malloc(2);
	int counter;

	counter = 0;
	if (ft_isdigit(format[signs->counter_flags]))
	{
		while (ft_isdigit(format[signs->counter_flags]))
			temp[counter++] = format[(signs->counter_flags)++];
		temp[counter] = '\0';
		signs->v_width = ft_atoi(temp);
	}
	else if (format[signs->counter_flags] == '*')
		star(signs, format, args);

	free(temp);
}

void star(sign_t *signs, char *format, va_list args)
{
	signs->v_width = va_arg(args, int);
	printf("width = %d", signs->v_width);
	if (format[signs->counter_flags + 1] == '.')
	{
		signs->counter_flags++;
		precision(signs, format, args);
	}
}

// default . e 6 sem certezas
void precision(sign_t *signs, char *format, va_list args)
{
	char *temp = malloc(2);
	int counter;
	
	signs->counter_flags++;
	counter = 0;
	if (format[signs->counter_flags] == '*')
		signs->v_precision = va_arg(args, int);
	while (ft_isdigit(format[signs->counter_flags]))
		temp[counter++] = format[signs->counter_flags++];
	temp[counter] = '\0';
	if (temp != NULL)
		signs->v_precision = ft_atoi(temp);
	free(temp);
}

// Fazer caso especial para se for so 0?
// Se aparecer o (-) entao escrever primeiro o arg e depois as flags
// Verificar se flags existem.

// void	signs_transform(char *format, sign_t *signs, char c)
// {
// 	if (signs->)
// }
