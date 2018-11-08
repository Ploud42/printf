/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:41:25 by jsobel            #+#    #+#             */
/*   Updated: 2018/11/08 18:18:31 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void static	ft_upper_hexa(t_data *ap)
{
	ap->str[ap->len] = 0;
	while (ap->len)
	{
		if (ap->nbll % 16 <= 9)
			ap->str[--ap->len] = ap->nbll % 16 + 48;
		else
			ap->str[--ap->len] = ap->nbll % 16 + 55;
		ap->nbll /= 16;
	}
}

void static	ft_hexa(t_data *ap)
{
	ap->str[ap->len] = 0;
	while (ap->len)
	{
		if (ap->nbll % 16 <= 9)
			ap->str[--ap->len] = ap->nbll % 16 + 48;
		else
			ap->str[--ap->len] = ap->nbll % 16 + 87;
		ap->nbll /= 16;
	}
}

void		ft_convert_x(t_data *ap)
{
	if (ap->check[LONG] == 0 && ap->check[INTMAX] == 0)
		ap->nbll = va_arg(ap->arg, int);
	else if (ap->check[LONG] == 1)
		ap->nbll = va_arg(ap->arg, long);
	else if (ap->check[LONG] == 2)
		ap->nbll = va_arg(ap->arg, long long);
	else if (ap->check[INTMAX] == 1)
		ap->nbll = va_arg(ap->arg, intmax_t);
	ap->len = ft_nbrlen_base(ap->nbll, 16);
	if (!(ap->str = ft_memalloc(ap->len + 1)))
		exit(EXIT_FAILURE);
	if (*ap->format == 'x')
		ft_hexa(ap);
	else
		ft_upper_hexa(ap);
	ft_printint(ap);
}