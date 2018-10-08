/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intprinter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:25:27 by jsobel            #+#    #+#             */
/*   Updated: 2018/10/08 18:42:36 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printint(t_data *ap)
{
	ap->nb = va_arg(ap->arg, int);
	ft_putnbr(ap->nb);
	if (ap->nb <= 0)
	{
		ap->nb *= -1;
		ap->count++;
	}
	while (ap->nb != 0)
	{
		ap->nb /= 10;
		ap->count++;
	}
	//ft_bzero(ap->str, ft_strlen(ap->str));
}