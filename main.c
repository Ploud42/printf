/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 19:51:59 by jsobel            #+#    #+#             */
/*   Updated: 2018/12/12 18:18:59 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include<stdio.h>

int	main()
{
	char	*p;
	int		a, b;
	p = "Salut";

	a = ft_printf("%-0.7f\n", 5.0500004);
	printf("\n");
	b = printf("%-0.7f\n", 5.0500004);
	printf("ft_printf = %d et printf = %d\n", a, b);
	return (0);
}
