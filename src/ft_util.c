/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:47:51 by jsobel            #+#    #+#             */
/*   Updated: 2018/12/13 18:42:10 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_get_nb(t_data *ap)
{
	if (ap->check[LONG] == 1)
		ap->nbll = va_arg(ap->arg, long);
	else if (ap->check[LONG] == 2)
		ap->nbll = va_arg(ap->arg, long long);
	else if (ap->check[INTMAX] == 1)
		ap->nbll = va_arg(ap->arg, intmax_t);
	else if (ap->check[SHORT] == 1 && !ap->check[SIZE_T])
		ap->nbll = (short)va_arg(ap->arg, int);
	else if (ap->check[SHORT] == 2 && !ap->check[SIZE_T])
		ap->nbll = (char)va_arg(ap->arg, int);
	else if (ap->check[SIZE_T])
		ap->nbll = va_arg(ap->arg, size_t);
	else
		ap->nbll = va_arg(ap->arg, int);
}

int			ft_nbrlen_base(uintmax_t nbr, int base)
{
	uintmax_t	i;
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
	return (size);
}

void		ft_preci_zero(t_data *ap)
{
	if (ap->check[PRECISION] == 0)
	{
		ap->str[0] = 0;
		if (!(*ap->format == 'p'))
			ap->check[HASH] = 0;
	}
}

void		ft_set_new_index(t_data *ap)
{
	ap->flag[LDOUBLE] = 'L';
	ap->spec[15] = 'f';
	ap->spec[16] = 'F';
}
