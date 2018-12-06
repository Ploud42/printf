/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_o.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 19:06:40 by jsobel            #+#    #+#             */
/*   Updated: 2018/12/06 16:48:54 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_locta(t_data *ap)
{
	ap->unbll = va_arg(ap->arg, long);
	ap->len = ft_nbrlen_base(ap->unbll, 8);
	if (ap->check[PRECISION] > ap->len)
		ap->check[HASH] = 0;
	if (!(ap->str = ft_memalloc(ap->len + 1)))
		exit(EXIT_FAILURE);
	ap->str[ap->len] = 0;
	while (ap->len)
	{
		ap->str[--ap->len] = ap->unbll % 8 + 48;
		ap->unbll /= 8;
	}
}

static void	ft_octa(t_data *ap)
{
	ft_get_nb_u(ap);
	ap->len = ft_nbrlen_base(ap->unbll, 8);
	if (ap->check[PRECISION] > ap->len)
		ap->check[HASH] = 0;
	if (!(ap->str = ft_memalloc(ap->len + 1)))
		exit(EXIT_FAILURE);
	ap->str[ap->len] = 0;
	while (ap->len)
	{
		ap->str[--ap->len] = ap->unbll % 8 + 48;
		ap->unbll /= 8;
	}
}

void		ft_convert_o(t_data *ap)
{
	ap->check[PLUS] = 0;
	ap->check[SPACE] = 0;
	if (*ap->format == 'o')
		ft_octa(ap);
	else
		ft_locta(ap);
	if (ap->check[HASH] && ap->str[0] != '0' && ++ap->count)
		ap->check[WIDTH]--;
	else if (!ap->check[HASH])
		ft_preci_zero(ap);
	ft_printint(ap);
}
