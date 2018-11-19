/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:41:25 by jsobel            #+#    #+#             */
/*   Updated: 2018/11/19 17:35:52 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	ft_get_nb(ap);
	if (ap->nbll < 0)
		ap->nbll = 4294967296 + ap->nbll;
	ap->len = ft_nbrlen_base(ap->nbll, 16);
	if (!(ap->str = ft_memalloc(ap->len + 1)))
		exit(EXIT_FAILURE);
	if (*ap->format == 'x')
		ft_hexa(ap);
	else
		ft_upper_hexa(ap);
	ft_preci_zero(ap);
	ft_printint(ap);
}