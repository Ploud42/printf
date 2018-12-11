/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:55:40 by jsobel            #+#    #+#             */
/*   Updated: 2018/12/11 18:59:47 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include<stdio.h>

static void	ft_ftoa(t_data *ap)
{
	int	nb;

	nb = ap->f;
	ap->str = ft_itoa_intmax(nb);
	ft_putstr(ap->str);
	ap->f -= (double)nb;
	write(1, ".", 1);
	while (ap->check[PRECISION]--)
	{
		ap->f *= 10.0;
		nb = ap->f;
		ap->str = ft_itoa_intmax(nb);
		ft_putstr(ap->str);
		ap->f -= nb;
	}
	//printf("%jd  %s\n", ap->nbll, ap->str);
}

void		ft_print_double(t_data *ap)
{
	ap->f = va_arg(ap->arg, double);
	if (ap->check[PRECISION] == -1)
		ap->check[PRECISION] = 6;
	ft_ftoa(ap);
	/*ap->len = ft_strlen(ap->str);
	if (ap->str[0] == '-' && ++ap->minus)
		ap->check[PLUS] = 0;
	ap->count += (ap->len);
	if (!ap->check[MINUS])
		ft_printint_width(ap);
	ft_printint_flag(ap);
	ft_printint_preci(ap);*/
}