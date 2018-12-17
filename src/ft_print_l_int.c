/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_l_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:30:02 by jsobel            #+#    #+#             */
/*   Updated: 2018/12/17 16:37:18 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_get_lnb(t_data *ap)
{
	if (ap->check[LONG] == 1)
		ap->nbll = va_arg(ap->arg, long);
	else if (ap->check[LONG] == 2)
		ap->nbll = va_arg(ap->arg, long long);
	else if (ap->check[INTMAX] == 1)
		ap->nbll = va_arg(ap->arg, intmax_t);
	else if (ap->check[SHORT] == 1 && !ap->check[SIZE_T])
		ap->nbll = (unsigned short)va_arg(ap->arg, long);
	else if (ap->check[SHORT] == 2 && !ap->check[SIZE_T])
		ap->nbll = (unsigned short)va_arg(ap->arg, long);
	else if (ap->check[SIZE_T])
		ap->nbll = va_arg(ap->arg, size_t);
	else
		ap->nbll = va_arg(ap->arg, long);
}

void		ft_printlint(t_data *ap)
{
	ft_get_lnb(ap);
	if (ap->nbll == (-9223372036854775807 - 1))
	{
		if (!(ap->str = ft_itoa_intmax(ap->nbll + 1)))
			exit(EXIT_FAILURE);
		ap->str[19]++;
	}
	else if (!(ap->str = ft_itoa_intmax(ap->nbll)))
		exit(EXIT_FAILURE);
	if (ap->nbll == 0)
		ft_preci_zero(ap);
	ap->len = ft_strlen(ap->str);
	if (ap->str[0] == '-' && ++ap->minus)
		ap->check[PLUS] = 0;
	ap->count += (ap->len);
	if (!ap->check[MINUS])
		ft_printint_width(ap);
	ft_printint_flag(ap);
	ft_printint_preci(ap);
	ft_free_str(ap);
}
