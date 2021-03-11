/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:48:31 by rimartin          #+#    #+#             */
/*   Updated: 2021/03/11 18:30:37 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void exit(int status);

int size_per(char *format, sign_t *signs)
{
	int counter;

	counter = 0;
	if (format[counter + 1] = '%')
	{
		counter = 2;
		signs->c = '%';
		return (counter);
	}
	while (!type(format[counter]))
		counter++;
	if (counter == 0)
		return (0);
	if (type(format[counter]))
	{
		signs->c = format[counter];
 		counter++;
		return (counter);
	}
	return (0);
}



int invalid_per(char *str, int i, int size)
{
	if (str[i + 1] == ' ' && !(type(str[size - 1])))
	{
		//printf("Espaco no meio ou nao acaba num tipo de dado compativel");
		return (0);
	}
	//printf("%d", size);
	while (size - 2)
	{
		if (sign(str[i]))
			i++;
		else
		{
			//printf("Sinal invalido %c\n", str[i]);
			exit (0);
		}
		size--;
	}
	return (0);
}

int number_per(char *format, int size)
{
	int counter;
	int c;

	c = 0;
	counter = 0;

	while (format[c] != '\0')
	{
		if (format[c] == '%')
		{
			c++;
			if ((invalid_per((char *)format, c, size)))
			{
				//printf("e invalido %c\n", format[c]);
				return (0);
			}
			counter++;
		}
		c++;
	}
	return (counter);
}

int type(char c)
{
	if (c == 'c' || c == 'd' || c == 's' || c == 'i'
		|| c == 'x' || c == 'X' || c == 'p' || c == 'u') // Ver se falta algum
		return (1);
	return (0);
}

int sign(char c)
{
	if (c == '.' || c == '-' || ft_isdigit(c) || c == '*')
		return (1);
	else
		return (0);
}

int	ft_checkvalid(const char *format)
{
	int i;
	int size;
	char c;

	size = size_per((char *)format, &c);
	i = 0;
	if (!(type(format[size - 1])))
		return (1);
	while (format[i] != '\0')
	{
		while (format[i] != '%')
			i++;
		if (format[i] == '%')
		{
			i++;
			if (valid_strchr(format, &i) != 0)
				return (-1);
		}
		else if(format[i] == '\0')
			break ;
		i++;
	}
	return (0);

}

int	valid_strchr(const char *s, int *i)
{
	while (s[*i] != '\0')
	{
		if (s[*i] == '-' || s[*i] == '0' || s[*i] == '.' || s[*i] == '*')
			continue ;
		else if(s[*i] == 'c' || s[*i] == 's' || s[*i] == 'p' || s[*i] == 'd' ||
			s[*i] == 'i' || s[*i] == 'u' || s[*i] == 'x' || s[*i] == 'X' || s[*i] == '%')
		{
			(*i)++;
			return (0);
		}
		else
			break ;
		(*i)++;
	}
	return (-1);
}
