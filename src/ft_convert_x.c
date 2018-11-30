/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:41:25 by jsobel            #+#    #+#             */
/*   Updated: 2018/11/30 18:50:53 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include<stdio.h>

void		ft_preci_zero(t_data *ap)
{
	if (ap->check[PRECISION] == 0)
	{
		ap->str[0] = 0;
		ap->check[HASH] = 0;
	}
}

void static	ft_upper_hexa(t_data *ap)
{
	ap->str[ap->len] = 0;
	while (ap->len)
	{
		if (ap->unbll % 16 <= 9)
			ap->str[--ap->len] = ap->unbll % 16 + 48;
		else
			ap->str[--ap->len] = ap->unbll % 16 + 55;
		ap->unbll /= 16;
	}
}

void static	ft_hexa(t_data *ap)
{
	ap->str[ap->len] = 0;
	while (ap->len)
	{
		if (ap->unbll % 16 <= 9)
			ap->str[--ap->len] = ap->unbll % 16 + 48;
		else
			ap->str[--ap->len] = ap->unbll % 16 + 87;
		ap->unbll /= 16;
	}
}

void		ft_convert_x(t_data *ap)
{
	if (*ap->format == 'p' && ++ap->check[HASH])
		ap->unbll = va_arg(ap->arg, unsigned long);
	else
		ft_get_nb_u(ap);
	ap->len = ft_nbrlen_base(ap->unbll, 16);
	if (!(ap->str = ft_memalloc(ap->len + 1)))
		exit(EXIT_FAILURE);
	if (*ap->format == 'x' || *ap->format == 'p')
		ft_hexa(ap);
	else
		ft_upper_hexa(ap);
	if (ap->check[HASH] && (*ap->format == 'p' || ap->str[0] != '0')
	&& ++ap->count && ap->check[WIDTH]-- && ap->count++)
		ap->check[WIDTH]--;
	ft_preci_zero(ap);
	ft_printint(ap);
}
