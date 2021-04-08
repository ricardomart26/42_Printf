/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 02:51:43 by marvin            #+#    #+#             */
/*   Updated: 2021/03/19 18:36:03 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_intlen(int n)
{
	int len;

	len = 0;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static	int	ft_unsignedlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
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
	res = (char *)malloc(len + 1);
	if (!res)
		return (0);
	res[len] = '\0';
	len--;
	if (n == 0)
		res[0] = '0';
	while (n > 0)
	{
		res[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (res);
}

char		*ft_itoa(int n, int cminus)
{
	char	*str;
	int		size;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	size = ft_intlen(n);
	str = (char *)malloc(size + 1);
	if (!str)
		return (NULL);
	str[size] = '\0';
	if (n < 0)
	{
		cminus = 1;
		n *= -1;
	}
	while (n > 0)
	{
		str[size - 1] = (n % 10) + '0';
		n /= 10;
		size--;
	}
	return (str);
}

char *ft_convert_char(int inteiro)
{
	char c;
	char *temp;

	temp = (char *)malloc(2);
	if (!temp)
		return (NULL);
	c = (char)inteiro;
	temp[0] = c;
	temp[1] = '\0';
	//printf("temp = %c", temp[0]);
	return (temp);
}


