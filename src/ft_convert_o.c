/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_o.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 19:06:40 by jsobel            #+#    #+#             */
/*   Updated: 2018/11/13 18:15:48 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_nbrlen_base(intmax_t nbr, int base)
{
	intmax_t	i;
	int			size;

	i = nbr;
	size = 0;
	if (nbr == 0)
		size = 1;
	while (i != 0)
	{
		size++;
		i /= base;
	}
	if (nbr < 0)
		size++;
	return (size);
}

void static	ft_locta(t_data *ap)
{
	ap->nbl = va_arg(ap->arg, long);
	ap->len = ft_nbrlen_base(ap->nbl, 8);
	if (!(ap->str = ft_memalloc(ap->len + 1)))
		exit(EXIT_FAILURE);
	ap->str[ap->len] = 0;
	while (ap->len)
	{
		ap->str[--ap->len] = ap->nbl % 8 + 48;
		ap->nbl /= 8;
	}
}

void static	ft_octa(t_data *ap)
{
	ap->nb = va_arg(ap->arg, int);
	ap->len = ft_nbrlen_base(ap->nb, 8);
	if (!(ap->str = ft_memalloc(ap->len + 1)))
		exit(EXIT_FAILURE);
	ap->str[ap->len] = 0;
	while (ap->len)
	{
		ap->str[--ap->len] = ap->nb % 8 + 48;
		ap->nb /= 8;
	}
}

void	ft_convert_o(t_data *ap)
{
	if (*ap->format == 'o')
		ft_octa(ap);
	else
		ft_locta(ap);
	if (!ap->check[HASH])
		ft_preci_base(ap);
	ft_printint(ap);
}