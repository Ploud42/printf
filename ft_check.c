/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 18:32:15 by jsobel            #+#    #+#             */
/*   Updated: 2018/10/16 15:51:51 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_check_precision(t_data *ap)
{
	if (*ap->format == '.')
	{
		ap->format++;
		ap->check[PRECISION] = ft_atoi(ap->format);
		while (*ap->format >= '0' && *ap->format <= '9')
			ap->format++;
	}
}

static void		ft_check_width(t_data *ap)
{
	if (*ap->format >= '0' && *ap->format <= '9')
	{
		ap->check[WIDTH] = ft_atoi(ap->format);
		while (*ap->format >= '0' && *ap->format <= '9')
			ap->format++;
	}
}

static void		ft_check_flag(t_data *ap)
{
	ap->index = 0;
	while (ap->index < FLAG_NB)
	{
		if (*ap->format == ap->flag[ap->index])
		{
			ap->check[ap->index] = 1;
			ap->format++;
		}
		ap->index++;
	}
}

static void		ft_init(t_data *ap)
{
	ap->i = 0;
	ap->check[MINUS] = 0;
	ap->check[PLUS] = 0;
	ap->check[SPACE] = 0;
	ap->check[ZERO] = 0;
	ap->check[HASH] = 0;
	ap->check[WIDTH] = -1;
	ap->check[PRECISION] = -1;
	ap->width = 0;
}

void			ft_check(t_data *ap)
{
	ft_init(ap);
	ft_check_flag(ap);
	ft_check_width(ap);
	ft_check_precision(ap);
}