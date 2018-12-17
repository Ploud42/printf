/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 18:32:15 by jsobel            #+#    #+#             */
/*   Updated: 2018/12/17 16:07:44 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_check_precision(t_data *ap)
{
	while (*ap->format == '.')
		ap->format++;
	if (*ap->format)
	{
		ap->check[PRECISION] = ft_atoi(ap->format);
		while (*ap->format >= '0' && *ap->format <= '9')
			ap->format++;
	}
	ap->precision = ap->check[PRECISION];
}

static void		ft_check_width(t_data *ap)
{
	if (*ap->format >= '1' && *ap->format <= '9')
	{
		ap->check[WIDTH] = ft_atoi(ap->format);
		while (*ap->format >= '0' && *ap->format <= '9')
			ap->format++;
	}
}

static void		ft_check_flag(t_data *ap)
{
	ap->i = 1;
	while (ap->i)
	{
		ap->i = 0;
		ap->index = 0;
		while (ap->index < FLAG_NB)
		{
			while (*ap->format == ap->flag[ap->index])
			{
				ap->check[ap->index]++;
				ap->format++;
				ap->i++;
			}
			if (*ap->format >= '1' && *ap->format <= '9' &&
			ap->check[WIDTH] == -1)
				ft_check_width(ap);
			if (*ap->format == '.')
				ft_check_precision(ap);
			ap->index++;
		}
	}
}

static void		ft_init(t_data *ap)
{
	ap->i = 0;
	ap->d = 0;
	ap->len = 0;
	ap->str = 0;
	ap->check[HASH] = 0;
	ap->check[MINUS] = 0;
	ap->check[PLUS] = 0;
	ap->check[SPACE] = 0;
	ap->check[ZERO] = 0;
	ap->check[LONG] = 0;
	ap->check[SHORT] = 0;
	ap->check[INTMAX] = 0;
	ap->check[SIZE_T] = 0;
	ap->check[LDOUBLE] = 0;
	ap->check[WIDTH] = -1;
	ap->check[PRECISION] = -1;
	ap->width = ' ';
	ap->minus = 0;
	ap->precision = 0;
	ap->nbll = 0;
	ap->unbll = 0;
}

void			ft_check(t_data *ap)
{
	ft_init(ap);
	if (*ap->format)
		ft_check_flag(ap);
	if (ap->check[MINUS] && ap->check[ZERO])
		ap->check[ZERO] = 0;
	if (ap->check[SPACE] && ap->check[PLUS])
		ap->check[SPACE] = 0;
}
