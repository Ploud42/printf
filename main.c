/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 19:51:59 by jsobel            #+#    #+#             */
/*   Updated: 2018/11/27 18:46:47 by juliensobel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include<stdio.h>

int	main()
{
	char	*p;
	int		a, b;
	p = "Salut";
	/*int ret;

	ret = ft_printf("Hey j'ai envie de te dire %-7s, et cela %+5d fois, %s %i fois\n", "salut", 15, "ou alors", 0);
	printf("ret = %d\n", ret);
	ret = printf("Hey j'ai envie de te dire %-7s, et cela %+5d fois, %s %i fois\n", "salut", 15, "ou alors", 0);
	printf("ret = %d\n", ret);*/
	//ft_printf("%lld\n", -9223372036854775808);
	a = ft_printf("%x\n", -42);
	b = printf("%x\n", -42);
	printf("ft_printf = %d et printf = %d\n", a, b);
	return (0);
}
