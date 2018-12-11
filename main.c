/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 19:51:59 by jsobel            #+#    #+#             */
/*   Updated: 2018/12/11 18:55:23 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include<stdio.h>

int	main()
{
	char	*p;
	int		a, b;
	p = "Salut";

	a = ft_printf("%f\n", 233.0070);
	printf("\n");
	b = printf("%f\n", 0.05);
	printf("ft_printf = %d et printf = %d\n", a, b);
	return (0);
}
