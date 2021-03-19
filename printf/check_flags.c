/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:48:25 by rimartin          #+#    #+#             */
/*   Updated: 2021/03/18 18:17:18 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void init_struct(sign_t *signs)
{
	signs->p_align = 0;
	signs->p_zero = 0;
	signs->v_precision = 0;
	signs->v_width = 0;
	signs->c = 48;
	signs->conv = 0;
	signs->size_conv = 0;
	signs->new_precision = 0;
	signs->counter_precision = 0;
	signs->counter_flags = 1;
	signs->counter_words = 0;
	signs->precision_s = 0;
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

void flags(sign_t *signs, char *format, va_list args)
{
	printf("\nc = %c\n ", format[signs->counter_flags]);
	printf("\nc = %d\n ", signs->counter_flags);

	if (format[signs->counter_flags] == '-')
		signs->p_align = signs->counter_flags++;
	if (format[signs->counter_flags] == '0' && format[signs->counter_flags - 1] != '-')
		signs->p_zero = signs->counter_flags++;
	else if (format[signs->counter_flags] == '0' && signs->c != 's')
		signs->counter_flags++;
	//printf("\nc = %c\n ", format[signs->counter_flags]);
	
	if (ft_isdigit(format[signs->counter_flags]) || format[signs->counter_flags] == '*')
		width(signs, format, args);
	//printf("\nc = %c\n ", format[signs->counter_flags]);
	if (format[signs->counter_flags] == '.')
	{
		//printf("Teste\n");
		precision(signs, format, args);
	}
	//printf("precision %d\n",signs->v_precision);
	handle_signs(signs, args);
}

void	width(sign_t *signs, char *format, va_list args)
{
	char *temp;
	int counter;
	int size;

	size = 0;
	counter = 0;
	while (ft_isdigit(format[size]))
		size++;
	temp = malloc(size);
	// if (!temp)
	// 	return (NULL);
	if (ft_isdigit(format[signs->counter_flags]))
	{
		while (ft_isdigit(format[signs->counter_flags]))
			temp[counter++] = format[(signs->counter_flags)++];
		temp[counter] = '\0';
		signs->v_width = ft_atoi(temp);
		printf("\nwidth = %d\n", signs->v_width);
		free(temp);
	}
	else if (format[signs->counter_flags] == '*')
		star(signs, args);
}

void star(sign_t *signs, va_list args)
{
	signs->v_width = va_arg(args, int);
	// printf("width = %d", signs->v_width);
}

// default . e 6 sem certezas
void	precision(sign_t *signs, char *format, va_list args)
{
	char *temp; 
	int counter;
	int size;

	size = 0;
	while (ft_isdigit(format[size]))
		size++;
	temp = malloc(size + 1);
	// if (!temp)
	// 	return (NULL);
	signs->counter_flags++;
	counter = 0;
	if (format[signs->counter_flags] == '*')
		signs->v_precision = va_arg(args, int);
	while (ft_isdigit(format[signs->counter_flags]))
	{
		//printf("format = %c", format[signs->counter_flags]);
		temp[counter++] = format[signs->counter_flags++];
	}	
	temp[counter] = '\0';
	if (temp != NULL)
	{
		signs->v_precision = ft_atoi(temp);	
		if (signs->c == 's')
			signs->precision_s = 1;
		//printf("str = %c\n", signs->c);
		//printf("str = %d\n", signs->precision_s);
	}
	free(temp);
}

// Fazer caso especial para se for so 0?
// Se aparecer o (-) entao escrever primeiro o arg e depois as flags
// Verificar se flags existem.

// void	signs_transform(char *format, sign_t *signs, char c)
// {
// 	if (signs->)
// }
