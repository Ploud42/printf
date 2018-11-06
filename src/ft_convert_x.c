/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:41:25 by jsobel            #+#    #+#             */
/*   Updated: 2018/11/06 19:43:57 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_x(t_data *ap)
{
	if (*ap->format == 'x')
		ft_decimal(ap);
	else
		ft_loctal(ap);
	ft_printint(ap);
}