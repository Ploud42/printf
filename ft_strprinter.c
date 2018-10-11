/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strprinter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:06:12 by jsobel            #+#    #+#             */
/*   Updated: 2018/10/11 18:52:33 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*void	ft_putstr(char const *s)
{
	size_t i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}*/

void	ft_printstr(t_data *ap)
{

	ap->str = va_arg(ap->arg, char *);
	ap->i = ft_strlen(ap->str);
	if (ap->check[PRECISION] >= 0 && ap->i >= ap->check[PRECISION])
		//ap->str[ap->check[PRECISION]] = 0;
		printf("OK\n");
	ap->count += ft_strlen(ap->str);
	ft_putstr(ap->str);
}