/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:10:39 by jsobel            #+#    #+#             */
/*   Updated: 2018/12/05 15:58:53 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_get_nb_u(t_data *ap)
{
	if (*ap->format == 'U')
		ap->unbll = (unsigned long)va_arg(ap->arg, long long);
	else if (ap->check[LONG] == 1)
		ap->unbll = va_arg(ap->arg, unsigned long);
	else if (ap->check[LONG] == 2)
		ap->unbll = va_arg(ap->arg, unsigned long long);
	else if (ap->check[SHORT] == 1 && !ap->check[SIZE_T])
		ap->unbll = (unsigned short)va_arg(ap->arg, unsigned int);
	else if (ap->check[SHORT] == 2 && !ap->check[SIZE_T])
		ap->unbll = (unsigned char)va_arg(ap->arg, unsigned int);
	else if (ap->check[INTMAX] == 1)
		ap->unbll = va_arg(ap->arg, intmax_t);
	else if (ap->check[SIZE_T])
		ap->unbll = va_arg(ap->arg, size_t);
	else
		ap->unbll = va_arg(ap->arg, unsigned int);
}

void static	ft_case_u_zero(t_data *ap)
{
	if (!ap->check[MINUS])
		ap->width = '0';
	else if (ap->check[PLUS] && ap->count++)
		write(1,"+",1);
}

void static	ft_printint_u_width(t_data *ap)
{
	if (ap->check[ZERO] && ap->check[PRECISION] < 0)
	{
		ft_case_u_zero(ap);
	}
	else if (ap->check[ZERO] && ap->check[PLUS] && ap->count++)
		write(1,"+",1);
	while (ap->check[WIDTH] > (ap->len + ap->check[PLUS]) &&
	ap->check[WIDTH] > (ap->check[PRECISION] + ap->check[PLUS]))
	{
		write(1,&ap->width,1);
		ap->check[WIDTH]--;
		ap->count++;
	}
}

void static	ft_printint_u_preci(t_data *ap)
{
	while (ap->precision > (ap->len - ap->minus))
	{
		write(1,"0",1);
		ap->precision--;
		ap->count++;
	}
	ft_putstr(ap->str);
	if (ap->check[MINUS])
		ft_printint_u_width(ap);
}

void		ft_print_u_int(t_data *ap)
{
	ft_get_nb_u(ap);
	if (!(ap->str = ft_itoa_uintmax(ap->unbll)))
		exit(EXIT_FAILURE);
	if (ap->unbll == 0)
		ft_preci_zero(ap);
	ap->len = ft_strlen(ap->str);
	ap->count += (ap->len);
	if (!ap->check[MINUS])
		ft_printint_u_width(ap);
	ft_printint_u_preci(ap);
}
