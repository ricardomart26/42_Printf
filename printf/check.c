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

#include "printf.h"

sign_t *put_value_struct(sign_t *signs)
{
	signs->p_align = 0;
	signs->p_dot = 0;
	signs->p_star = 0;
	signs->p_zero = 0;
	signs->p_width = 0;
	signs->c = 48;
	return (signs);
}

// Nao esquecer de chamar as funcoes width e sign
// Precisao %5.4d (10) sao 5 espacos, mas 3 numeros, exemplo ( 0010);
// Precisao das strings %10.4s (      olai)a esquerda sao os espacos e a direita os caracteres
// Width .carateres
// if (width menor que a string ignorar, se for maior acrescentar espacos.)
// if (width menor que a string ignorar, se for maior acrescentar espacos.)
// if (menos entao print string e acrescentar espacos a direita)

// Funcao para saber o tamanho, para onde mandar mos o tamanho?

// void see_signs(char *format, sign_t *signs, char c, va_list args)
// {
// 	int i;
// 	int save_number;
// 	i = 1;
// 	while (!(type(format[i])))
// 	{
// 		if (format[i] == '.')
// 			signs->p_dot = i;
// 		if (format[i] == '*')
// 			signs->p_star = i;
// 		if (format[i] == '0')
// 			signs->p_zero = i;
// 		else if (ft_isdigit(format[i]))
// 			signs->p_zero = i;
// 		i++;
// 	}
// 	return (signs_trasnform(format, signs, c, args));
// }

void	flags(sign_t *signs, char *format, va_list args)
{
	int i;

	i = 1;
	if (format[i] == '-')
		signs->p_align = i++;
	else if (format[i + 1] == '-')
	{
		signs->p_align = i;
		i += 2;
	}
	else if (format[i] == '0')
		signs->p_zero = i++;
	if (ft_isdigit(format[i]))
		return (width(signs, format, &i, args));
	else if (format[i] == '.')
		return (period(signs, format, &i, args));
}

void	width(sign_t *signs, char *format, int *i, va_list args)
{
	char *temp;
	int counter;
	int i_before;

	i_before = *i;
	counter = 0;
	while (ft_isdigit(format[*i]))
		temp[counter++] = format[(*i)++]; // Tenho medo disto!
	if (i_before == *i && format[*i] == '*')
		return (star_before_precision(signs, format, i, args));
	if (temp != NULL)
		signs->v_width = ft_atoi(temp);
	if (format[*i] == '*')
	if (format[*i] == '.')
		return (precision(signs, format, i, args));
}


void	star_before_precision(sign_t *signs, char *format, int *i, va_list args)
{
	int counter;
	char *temp;

	counter = 0;
	if (format[*i] == '.')
	{
		(*i)++;
		if (format[*i] == '*')
			signs->v_star = va_arg(args, int);
		while (ft_isdigit(format[*i]))
			temp[counter++] = format[(*i)++]; // Tenho medo disto!
		if (temp != NULL)
			signs->v_dot = ft_atoi(temp);
	}
}

// default . e 6 sem certezas
void	precision(sign_t *signs, char *format, int *i, va_list args)
{
	char *temp;
	int counter;

	counter = 0;
	if (format[*i] == '.')
	{
		(*i)++;
		if (format[*i] == '*')
			signs->v_star = va_arg(args, int);
		while (ft_isdigit(format[*i]))
			temp[counter++] = format[(*i)++]; // Tenho medo disto!
		if (temp != NULL)
			signs->v_dot = ft_atoi(temp);
	}
}

void	star_after_precision(sign_t *signs, char *format, int *i, va_list args)
{

}

void	handle_signs(char *format, sign_t signs, va_list args)
{
	if (signs.c == 'd' || signs.c == 'i')
	{
		// if (signs.p_align != '0')
		// {
		// 	align_int(signs, format, args);
		// }
		if (signs.p_width)
		{
			do_width(format, signs, args);
		}
	}
}

void	align_int(sign_t signs, char *format, va_list args)
{
	char *temp;

	temp = ft_letter(args, format, signs.c);
	ft_putstr_fd(temp, 1);
}

void	do_width(char *format, sign_t signs, va_list args)
{
	while (signs.v_width > 0)
	{

		if (signs.p_zero != 0)
			write(1, '0', 1);
		else
			write(1, ' ', 1);
		signs.v_width--;
	}
}

// Fazer caso especial para se for so 0?
// Se aparecer o (-) entao escrever primeiro o arg e depois as flags
// Verificar se flags existem.


// void	signs_transform(char *format, sign_t *signs, char c)
// {
// 	if (signs->)
// }
