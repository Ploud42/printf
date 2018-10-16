/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intprinter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:25:27 by jsobel            #+#    #+#             */
/*   Updated: 2018/10/16 18:29:33 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printint(t_data *ap)
{
	ap->nb = va_arg(ap->arg, int);
	ap->str = ft_itoa(ap->nb);
	ap->len = ft_strlen(ap->str);
	ap->count += ap->len;
	while (ap->check[WIDTH] > ap->len && !ap->check[MINUS])
	{
		write(1," ",1);
		ap->check[WIDTH]--;
		ap->count++;
	}
	ft_putstr(ap->str);
	while (ap->check[WIDTH] > ap->len && ap->check[MINUS])
	{
		write(1," ",1);
		ap->check[WIDTH]--;
		ap->count++;
	}
}