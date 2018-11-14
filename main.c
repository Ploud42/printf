/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 19:51:59 by jsobel            #+#    #+#             */
/*   Updated: 2018/11/14 19:05:08 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include<stdio.h>

int	main()
{
	int ret;

	ret = ft_printf("Hey j'ai envie de te dire %-7s, et cela %+5d fois, %s %i fois\n", "salut", 15, "ou alors", 0);
	printf("ret = %d\n", ret);
	ret = printf("Hey j'ai envie de te dire %-7s, et cela %+5d fois, %s %i fois\n", "salut", 15, "ou alors", 0);
	printf("ret = %d\n", ret);
	ft_printf("%ld\n", 2147483648);
	printf("%05d\n", -257);
	return (0);
}