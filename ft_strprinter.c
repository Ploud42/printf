/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strprinter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:06:12 by jsobel            #+#    #+#             */
/*   Updated: 2018/10/15 18:06:02 by jsobel           ###   ########.fr       */
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
	int i;

	i = 0;
	ap->str = va_arg(ap->arg, char *);
	ap->i = ft_strlen(ap->str);
	while ((ap->check[PRECISION] < 0 && i < ap->i) || (ap->check[PRECISION] >= 0 && i < ap->check[PRECISION] && i < ap->i))
	{
		write(1, &ap->str[i], 1);
		ap->count++;
		i++;
	}
}