/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intprinter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:25:27 by jsobel            #+#    #+#             */
/*   Updated: 2018/10/17 20:02:43 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void static	ft_printint_width(t_data *ap)
{
	if (ap->check[ZERO] && ap->check[PRECISION] < 0)
	{
		ap->width = '0';
		if (ap->str[0] == '-')
		{
			write(1,"-",1);
			ap->count++;
			ap->str++;
		}
	}
	else
		ap->width = ' ';
	while (ap->check[WIDTH] > ap->len &&
	ap->check[WIDTH] > ap->check[PRECISION])
	{
		write(1,&ap->width,1);
		ap->check[WIDTH]--;
		ap->count++;
	}
}

void static	ft_printint_flag(t_data *ap)
{
	if (ap->check[SPACE] && ap->check[WIDTH] <= ap->len && !(ap->str[0] == '-'))
	{
		write(1," ",1);
	}
}

void static	ft_printint_preci(t_data *ap)
{
	if (ap->str[0] == '-')
	{
		write(1,"-",1);
		ap->str++;
		ap->count++;
		ap->len--;
	}
	while (ap->check[PRECISION] > ap->len)
	{
		write(1,"0",1);
		ap->check[PRECISION]--;
		ap->count++;
	}
	ft_putstr(ap->str);
}

void		ft_printint(t_data *ap)
{
	ap->nb = va_arg(ap->arg, int);
	ap->str = ft_itoa(ap->nb);
	ap->len = ft_strlen(ap->str);
	ap->count += ap->len;
	if (!ap->check[MINUS])
		ft_printint_width(ap);
	ft_printint_flag(ap);
	ft_printint_preci(ap);
	if (ap->check[MINUS])
		ft_printint_width(ap);
}