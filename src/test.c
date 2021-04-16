/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:23:00 by rimartin          #+#    #+#             */
/*   Updated: 2021/04/16 20:25:38 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int main(void)
{
	int i;
	char *str;

	i = printf(" %-3.s ", NULL);
	printf("\n i = %d", i);
	i = printf("\n %-3.s ", NULL);
	printf("\n i = %d", i);
}
