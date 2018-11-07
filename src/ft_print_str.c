/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:06:12 by jsobel            #+#    #+#             */
/*   Updated: 2018/11/07 18:34:03 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printstr_width(t_data *ap)
{
	while ((ap->check[WIDTH] > ap->len || (ap->check[PRECISION] > 0 &&
	ap->check[WIDTH] > ap->check[PRECISION])))
	{
		write(1," ",1);
		ap->check[WIDTH]--;
		ap->count++;
	}
}

void	ft_printstr_preci(t_data *ap)
{
	while ((ap->check[PRECISION] < 0 && ap->i < ap->len) ||
	(ap->check[PRECISION] >= 0 && ap->i < ap->check[PRECISION]
	&& ap->i < ap->len))
	{
		write(1, &ap->str[ap->i], 1);
		ap->count++;
		ap->i++;
	}
}

void	ft_printstr(t_data *ap)
{
	ap->str = va_arg(ap->arg, char *);
	ap->len = ft_strlen(ap->str);
	if (!ap->check[MINUS])
		ft_printstr_width(ap);
	ft_printstr_preci(ap);
	if (ap->check[MINUS])
		ft_printstr_width(ap);
}