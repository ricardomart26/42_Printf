/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:48:11 by rimartin          #+#    #+#             */
/*   Updated: 2021/03/10 20:58:44 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	ft_putstr_fd(char *s, int fd, sign_t *st)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		st->words++;
		s++;
	}
}

void	ft_putchar(char c, sign_t *st)
{
	write(1, &c, 1);
	st->words++;
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	if ((dest = malloc(ft_strlen(src) * sizeof(char) + 1)) == NULL)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}



int	ft_strlen(const char *str)
{
	int c;

	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}


int	ft_atoi(char *str)
{
	int			sign;
	long long	res;

	sign = 1;
	res = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		res *= 10;
		res += (sign * (*(str++) - '0'));
		if (res > 2147483647)
			return (-1);
		if (res < -2147483648)
			return (0);
	}
	return (res);
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
