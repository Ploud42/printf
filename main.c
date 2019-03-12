/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 19:51:59 by jsobel            #+#    #+#             */
/*   Updated: 2019/03/12 18:00:32 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include<stdio.h>

int	main()
{
	char	*p;
	int		a, b;
	p = "Salut";

	a = ft_printf("{%s}\n", "salut");
	printf("\n");
	b = printf("{%s}\n", "salut");
	printf("ft_printf = %d et printf = %d\n", a, b);
	return (0);
}
