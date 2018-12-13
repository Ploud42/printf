/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:55:40 by jsobel            #+#    #+#             */
/*   Updated: 2018/12/13 18:42:34 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_inf_nan(t_data *ap)
{
	if (ap->f == 1.0 / 0.0 || ap->f == -1.0 / 0.0)
	{
		if (*ap->format == 'f')
			ft_putstr("inf");
		else
			ft_putstr("INF");
		ap->count += 3;
		return (1);
	}
	else if (ap->f != ap->f)
	{
		if (*ap->format == 'f')
			ft_putstr("nan");
		else
			ft_putstr("NAN");
		ap->count += 3;
		return (1);
	}
	return (0);
}

static void	ft_ftoa(t_data *ap)
{
	intmax_t	nb;

	ft_putstr(ap->str);
	if (ap->f < 0.0)
		ap->f *= -1.0;
	nb = ap->f;
	ap->f -= nb;
	if (ap->check[PRECISION] && ap->count++)
		write(1, ".", 1);
	while (ap->precision-- && ap->count++)
	{
		ap->f *= 10.0;
		nb = ap->f;
		ap->nbll += nb;
		ap->f -= nb;
		if (ap->precision)
			ap->nbll *= 10;
		else if (ap->f >= 0.5)
			ap->nbll++;
		if (!ap->nbll && ap->precision)
			write(1, "0", 1);
	}
	ap->str = ft_itoa_intmax(ap->nbll);
	if (ap->check[PRECISION])
		ft_putstr(ap->str);
}

void		ft_print_double(t_data *ap)
{
	if (ap->check[LDOUBLE])
		ap->f = va_arg(ap->arg, long double);
	else
		ap->f = va_arg(ap->arg, double);
	if (ft_check_inf_nan(ap))
		return ;
	if (ap->check[PRECISION] == -1)
	{
		ap->check[PRECISION] = 6;
		ap->precision = 6;
	}
	if (ap->check[HASH])
		ap->check[HASH] = 0;
	ap->str = ft_itoa_intmax(ap->f);
	ap->len = ft_strlen(ap->str);
	ap->count += (ap->len);
	ap->len += ap->precision + 1;
	if (ap->str[0] == '-' && ++ap->minus)
		ap->check[PLUS] = 0;
	if (!ap->check[MINUS])
		ft_printint_width(ap);
	ft_printint_flag(ap);
	ft_ftoa(ap);
	if (ap->check[MINUS])
		ft_printint_width(ap);
}
