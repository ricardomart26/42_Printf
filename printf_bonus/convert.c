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

#include "ft_printf.h"

static int count_uni_hexa(long int adress)
{
  int counter;

  counter = 0;
  while (adress > 0)
  {
    adress /= 16;
    counter++;
  }
  return (counter + 2);
}

char	*ft_convhexa(unsigned int decimal, int control)
{
	char	*hexa;
	int		index;
	char 	strx[16] = "0123456789abcdef";
	char 	strX[16] = "0123456789ABCDEF";
	int		uni;

	uni = count_uni_hexa(decimal) - 2;
	hexa = malloc(uni + 1);
	hexa[uni] = '\0';
	while (decimal > 0)
	{
		index = decimal % 16;
		if (control == 1)
			hexa[--uni] = strX[index];
		else
			hexa[--uni] = strx[index];
		decimal /= 16;
	}
	return (hexa);
}

char  *ft_convadress(long int adress)
{
  int index;
  char str[16] = "0123456789abcdef";
  char *ret;
  int uni;

  uni = count_uni_hexa(adress);
  ret = malloc(uni + 1);
  ret[0] = '0';
  ret[1] = 'x';
  ret[uni] = '\0';
  while (adress > 0)
  {
    index = adress % 16;
    ret[--uni] = str[index];
    adress /= 16;
  }
  return (ret);
}

