/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:21:56 by jsobel            #+#    #+#             */
/*   Updated: 2018/11/29 17:43:54 by juliensobel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void static	ft_printchar_width(t_data *ap)
{
	if (ap->check[ZERO])
		ap->width = '0';
	while ((ap->check[WIDTH] > 1 || (ap->check[PRECISION] > 0 &&
	ap->check[WIDTH] > ap->check[PRECISION])))
	{
		write(1,&ap->width,1);
		ap->check[WIDTH]--;
		ap->count++;
	}
}

void static	ft_printchar_preci(t_data *ap)
{
	while ((ap->check[PRECISION] < 0 && ap->i < 1) ||
	(ap->check[PRECISION] >= 0 && ap->i < ap->check[PRECISION]
	&& ap->i < 1))
	{
		write(1, &ap->c, 1);
		ap->count++;
		ap->i++;
	}
}

void		ft_printchar(t_data *ap)
{
	ap->c = va_arg(ap->arg, int);
	if (!ap->check[MINUS])
	ft_printchar_width(ap);
	if (!ap->c)
	{
		ft_putstr("^@");
		ap->count += 1;
		return ;
	}
	ft_printchar_preci(ap);
	if (ap->check[MINUS])
		ft_printchar_width(ap);
}
