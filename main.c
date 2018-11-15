/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 19:51:59 by jsobel            #+#    #+#             */
/*   Updated: 2018/11/15 18:13:58 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include<stdio.h>

int	main()
{
	/*int ret;

	ret = ft_printf("Hey j'ai envie de te dire %-7s, et cela %+5d fois, %s %i fois\n", "salut", 15, "ou alors", 0);
	printf("ret = %d\n", ret);
	ret = printf("Hey j'ai envie de te dire %-7s, et cela %+5d fois, %s %i fois\n", "salut", 15, "ou alors", 0);
	printf("ret = %d\n", ret);*/
	ft_printf("%lld\n", -9223372036854775808);
	printf("%lld\n", -9223372036854775808);
	return (0);
}