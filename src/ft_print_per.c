/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_per.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:56:46 by jsobel            #+#    #+#             */
/*   Updated: 2018/10/31 18:01:38 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void static	ft_printper_width(t_data *ap)
{
	while (ap->check[WIDTH] > 1)
	{
		write(1," ",1);
		ap->check[WIDTH]--;
		ap->count++;
	}
}

void	ft_printper(t_data *ap)
{
	if (!ap->check[MINUS])
		ft_printper_width(ap);
	write(1, "%", 1);
	ap->count++;
	if (ap->check[MINUS])
		ft_printper_width(ap);
}