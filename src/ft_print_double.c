/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:55:40 by jsobel            #+#    #+#             */
/*   Updated: 2019/03/12 17:02:10 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_inf_nan(t_data *ap)
{
	if (ap->f == 1.0 / 0.0 || ap->f == -1.0 / 0.0)
	{
		if (*ap->format == 'f')
			ap->str = "inf";
		else
			ap->str = "INF";
	}
	else if (ap->f != ap->f)
	{
		ap->check[PLUS] = 0;
		ap->check[SPACE] = 0;
		if (*ap->format == 'f')
			ap->str = "nan";
		else
			ap->str = "NAN";
	}
	else
	{
		if (ap->check[PRECISION] == -1)
			ap->precision = 6;
		return (0);
	}
	ap->check[PRECISION] = 0;
	return (1);
}

static void	ft_ftoa(t_data *ap)
{
	ft_putstr(ap->str + (ap->minus && !((1.0 / ap->f) == (1.0 / -0.0))));
	ft_free_str(ap);
	if (ap->f < 0.0)
		ap->f *= -1.0;
	ap->nbll = ap->f;
	ap->f -= ap->nbll;
	if ((ap->check[PRECISION] || ap->check[HASH]) && !ap->inf && ap->count++)
		write(1, ".", 1);
	while (ap->precision-- && ap->count++)
	{
		ap->f *= 10.0;
		ap->nbll = ap->f;
		ap->unbll += ap->nbll;
		ap->f -= ap->nbll;
		if (ap->precision)
			ap->unbll *= 10;
		else if (ap->f >= 0.5)
			ap->unbll++;
		if (!ap->unbll && ap->precision)
			write(1, "0", 1);
	}
	ap->str = ft_itoa_intmax(ap->unbll);
	if (ap->check[PRECISION])
		ft_putstr(ap->str);
}

static void	ft_printdouble_flag(t_data *ap)
{
	if ((ap->str[0] == '-' || ap->str[0] == '0' || ap->inf) && ap->minus
	&& !(ap->check[ZERO]))
		write(1, "-", 1);
	if (ap->check[SPACE] && (!ap->check[ZERO] || ap->inf) && !ap->minus &&
	!(ap->f != ap->f) && ap->count++)
		write(1, " ", 1);
	else if (ap->check[PLUS] && !(ap->minus) && (!ap->check[ZERO] || ap->inf)
	&& !(ap->f != ap->f) && ap->count++)
		write(1, "+", 1);
}

static void	ft_printdouble_width(t_data *ap)
{
	ap->i = ap->check[WIDTH];
	if (ap->minus)
		ap->check[SPACE] = 0;
	if ((ap->f == (-1.0 / 0.0) || INFMIN) && ap->count++)
		ap->len++;
	if (ap->check[ZERO] && !ap->inf)
	{
		if (!ap->check[MINUS])
			ap->width = '0';
		if (ap->minus && !ap->check[MINUS])
			write(1, "-", 1);
		else if (ap->check[PLUS] && ap->count++)
			write(1, "+", 1);
		else if (ap->check[SPACE] && ap->count++)
			write(1, " ", 1);
	}
	while (ap->i > (ap->len + ap->check[PLUS] + ap->check[SPACE]))
	{
		write(1, &ap->width, 1);
		ap->i--;
		ap->count++;
	}
}

void		ft_print_double(t_data *ap)
{
	if (ap->check[LDOUBLE])
		ap->f = va_arg(ap->arg, long double);
	else
		ap->f = va_arg(ap->arg, double);
	if ((ap->f < 0 || INFMIN) && ++ap->minus)
		ap->check[PLUS] = 0;
	if (!(ft_check_inf_nan(ap) && ++ap->inf))
		ap->str = ft_itoa_double(ap->f);
	if (ap->check[PRECISION] == -1)
		ap->check[PRECISION] = 6;
	ap->len = ft_strlen(ap->str) + ap->check[PRECISION]
	+ ((ap->check[PRECISION] || ap->check[HASH]) && !ap->inf);
	ap->count += ft_strlen(ap->str);
	if (!ap->check[MINUS])
		ft_printdouble_width(ap);
	ft_printdouble_flag(ap);
	if (ap->inf)
		ft_putstr(ap->str);
	else
		ft_ftoa(ap);
	if (ap->check[MINUS])
		ft_printdouble_width(ap);
	if (!ap->inf)
		ft_free_str(ap);
}
