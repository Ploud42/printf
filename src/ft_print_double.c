/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:55:40 by jsobel            #+#    #+#             */
/*   Updated: 2018/12/06 18:51:39 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include<stdio.h>

static void	ft_double_to_str(t_data *ap)
{
	ap->nbll = ap->f;
	ap->str = ft_itoa_intmax(ap->nbll);
	ft_putstr(ap->str);
	ap->f -= ap->nbll;
	printf("%f\n", ap->f);
	//while (ap->check[PRECISION]--)
	ap->f *= 100;
	printf("%f\n", ap->f);
	ap->nbll = (int)ap->f;
	printf("%jd\n", ap->nbll);
	ap->str = ft_itoa_intmax(ap->nbll);
	write(1, ".", 1);
	ft_putstr(ap->str);
	//printf("%jd  %s\n", ap->nbll, ap->str);
}

void		ft_print_double(t_data *ap)
{
	ap->f = va_arg(ap->arg, double);
	if (ap->check[PRECISION] == -1)
		ap->check[PRECISION] = 5;
	ft_double_to_str(ap);
	/*ap->len = ft_strlen(ap->str);
	if (ap->str[0] == '-' && ++ap->minus)
		ap->check[PLUS] = 0;
	ap->count += (ap->len);
	if (!ap->check[MINUS])
		ft_printint_width(ap);
	ft_printint_flag(ap);
	ft_printint_preci(ap);*/
}