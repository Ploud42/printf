/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_per.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:56:46 by jsobel            #+#    #+#             */
/*   Updated: 2018/12/06 16:24:09 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printper_width(t_data *ap)
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

void		ft_printper(t_data *ap)
{
	if (!ap->check[MINUS])
		ft_printper_width(ap);
	write(1, "%", 1);
	ap->count++;
	if (ap->check[MINUS])
		ft_printper_width(ap);
}
