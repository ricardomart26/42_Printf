/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:48:19 by rimartin          #+#    #+#             */
/*   Updated: 2021/03/20 19:18:31 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_uni_hexa(unsigned long long adress)
{
	int	counter;

	counter = 0;
	if (adress == 0)
		return (3);
	while (adress > 0)
	{
		adress /= 16;
		counter++;
	}
	return (counter);
}

char	*ft_convhexa(unsigned int n, int control)
{
	char	*res;
	unsigned int	len;

	if (n == 0)
		return (ft_strdup("0"));
	len = count_uni_hexa(n);
	res = (char *)malloc(sizeof(char) * len + 1);
	//printf(" res = %s \n", res);
	if (!res)
		return (0);
	res[len--] = '\0';
	while (n > 0)
	{
		if ((n % 16) < 10)
			res[len] = (n % 16) + '0';
		else if (control == 1)
			res[len] = (n % 16) + 55;
		else if (control == 0)
			res[len] = (n % 16) + 87;
		n = n / 16;
		len--;
	}
	//printf(" res = %s \n", res);
	return (res);
}

char	*ft_convadress(unsigned long long adress)
{
	char	*res;
	unsigned int	len;

	if (adress == 0)
		return (ft_strdup("0"));
	len = count_uni_hexa(adress);
	res = (char *)malloc(sizeof(char) * len + 1);
	if (!res)
		return (0);
	res[len--] = '\0';
	while (adress > 0)
	{
		if ((adress % 16) < 10)
			res[len] = (adress % 16) + '0';
		else
			res[len] = (adress % 16) + 87;
		adress = adress / 16;
		len--;
	}
	return (res);
}
