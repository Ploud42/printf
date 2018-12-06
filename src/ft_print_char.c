/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:21:56 by jsobel            #+#    #+#             */
/*   Updated: 2018/12/06 16:24:43 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printchar_width(t_data *ap)
{
	if (ap->check[ZERO])
		ap->width = '0';
	while (ap->check[WIDTH] > 1)
	{
		write(1, &ap->width, 1);
		ap->check[WIDTH]--;
		ap->count++;
	}
}

static void	ft_printchar_preci(t_data *ap)
{
	write(1, &ap->nbll, 1);
	ap->count++;
}

void		ft_printchar(t_data *ap)
{
	ft_get_nb(ap);
	if (!ap->check[MINUS])
		ft_printchar_width(ap);
	ft_printchar_preci(ap);
	if (ap->check[MINUS])
		ft_printchar_width(ap);
}
