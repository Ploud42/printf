/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:25:27 by jsobel            #+#    #+#             */
/*   Updated: 2018/12/13 18:39:58 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_case_zero(t_data *ap)
{
	if (!ap->check[MINUS])
		ap->width = '0';
	if (ap->minus)
	{
		write(1, "-", 1);
		ap->str++;
	}
	else if (ap->check[PLUS] && ap->count++)
		write(1, "+", 1);
	else if (ap->check[SPACE] && ap->count++)
		write(1, " ", 1);
	else if (ap->check[HASH] && (*ap->format == 'p' || ap->str[0] != '0'))
	{
		write(1, "0", 1);
		if (*ap->format == 'x' || *ap->format == 'p')
			write(1, "x", 1);
		else if (*ap->format == 'X')
			write(1, "X", 1);
	}
}

void		ft_printint_width(t_data *ap)
{
	ap->i = ap->check[WIDTH];
	if (ap->check[ZERO] && (ap->check[PRECISION] < 0 || *ap->format == 'f'))
	{
		ft_case_zero(ap);
	}
	else if (ap->check[ZERO] && ap->check[PRECISION] < 0 && ap->check[PLUS] &&
	ap->count++)
		write(1, "+", 1);
	else if (ap->check[ZERO] && ap->check[SPACE] && ap->count++)
		write(1, " ", 1);
	while (ap->i > (ap->len + ap->check[PLUS] + ap->check[SPACE]) && ap->i >
	(ap->check[PRECISION] + ap->minus + ap->check[PLUS] + ap->check[SPACE]))
	{
		write(1, &ap->width, 1);
		ap->i--;
		ap->count++;
	}
}

void		ft_printint_flag(t_data *ap)
{
	if (ap->check[SPACE] && !ap->check[ZERO] && !(ap->minus) && ap->count++)
		write(1, " ", 1);
	else if (ap->check[PLUS] && !(ap->minus) && !(ap->check[ZERO] &&
	ap->check[PRECISION] < 0) && ap->count++)
		write(1, "+", 1);
	else if (ap->check[HASH] && (*ap->format == 'p' || ap->str[0] != '0') &&
	(!ap->check[ZERO] || ap->check[PRECISION] >= 0))
	{
		write(1, "0", 1);
		if (*ap->format == 'x' || *ap->format == 'p')
			write(1, "x", 1);
		else if (*ap->format == 'X')
			write(1, "X", 1);
	}
}

void		ft_printint_preci(t_data *ap)
{
	if (ap->str[0] == '-')
	{
		write(1, "-", 1);
		ap->str++;
	}
	while (ap->precision > (ap->len - ap->minus))
	{
		write(1, "0", 1);
		ap->precision--;
		ap->count++;
	}
	ft_putstr(ap->str);
	if (ap->check[MINUS])
		ft_printint_width(ap);
}

void		ft_printint(t_data *ap)
{
	if (*ap->format == 'd' || *ap->format == 'D' || *ap->format == 'i')
	{
		ft_get_nb(ap);
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
	}
	ap->len = ft_strlen(ap->str);
	if (ap->str[0] == '-' && ++ap->minus)
		ap->check[PLUS] = 0;
	ap->count += (ap->len);
	if (!ap->check[MINUS])
		ft_printint_width(ap);
	ft_printint_flag(ap);
	ft_printint_preci(ap);
}
