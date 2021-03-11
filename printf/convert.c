/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:48:19 by rimartin          #+#    #+#             */
/*   Updated: 2021/03/10 20:55:12 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_unsignedlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char		*ft_unsigneditoa(unsigned int n)
{
	char	*res;
	size_t	len;

	len = ft_unsignedlen(n);
	res = (char *)malloc(len + 1 * sizeof(char));
	if (!res)
		return (0);
	res[len] = '\0';
	len--;
	if (n == 0)
		res[0] = '0';
	else if (n < 0)
	{
		res[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		res[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (res);
}

char		*ft_itoa(int n)
{
	char	*res;
	size_t	len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_intlen(n);
	res = (char *)malloc(len + 1 * sizeof(char));
	if (!res)
		return (0);
	res[len] = '\0';
	len--;
	if (n == 0)
		res[0] = '0';
	else if (n < 0)
	{
		res[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		res[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (res);
}

char	*ft_convhexa(unsigned int decimal, int control)
{
	char	hexa[1000];
	int		temp;
	int		i;

	i = 0;
	while (decimal != 0)
	{
		temp = decimal % 16;
		if (temp < 10)
			temp += 48;
		else if (control == 1)
			temp += 55;
		else
			temp += 87;
		hexa[i] = temp;
		i++;
		decimal = decimal / 16;
	}
	hexa[i] = '\0';
	ft_revstr(hexa);
	return (hexa);
}

char	*ft_convaddr(void *ptr)
{
	uintptr_t conv;
	size_t i;

	conv = (uintptr_t)ptr;
	char str[(2 + sizeof(conv) * 2) + 1];

	i = 2;
	str[0] = '0';
	str[1] = 'x';
	while (i < sizeof(conv) * 2)
	{
		str[i] = "0123456789abcdef"[(conv >> ((sizeof(conv) * 2 - 1 - i) * 4)) & 0xf];
		i++;
	}
	str[i] = '\0';
  return (str);
}

char *ft_convert_char(int inteiro)
{
	char c;
	char *temp;

	temp = malloc(2);
	c = (char)inteiro;
	temp[0] = c;
	temp[1] = '\0';

	return (temp);
}
