/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:06:12 by jsobel            #+#    #+#             */
/*   Updated: 2018/12/05 18:31:54 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include<stdio.h>

void	ft_printstr_width(t_data *ap)
{
	if (ap->check[ZERO])
		ap->width = '0';
	while ((ap->check[WIDTH] > ap->len || (ap->check[PRECISION] >= 0 &&
	ap->check[WIDTH] > ap->check[PRECISION])))
	{
		write(1,&ap->width,1);
		ap->check[WIDTH]--;
		ap->count++;
	}
}

void	ft_printstr_preci(t_data *ap)
{
	ap->i = 0;
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
	if (!ap->str)
		ap->str = va_arg(ap->arg, char *);
	if (!ap->str && ap->check[PRECISION] == -1)
	{
		ft_putstr("(null)");
		ap->count += 6;
		return ;
	}
	else if (!ap->str && !(ap->str = ft_memalloc(1)))
		exit(EXIT_FAILURE);
	ap->len = ft_strlen(ap->str);
	if (!ap->check[MINUS])
		ft_printstr_width(ap);
	ft_printstr_preci(ap);
	if (ap->check[MINUS])
		ft_printstr_width(ap);
}
