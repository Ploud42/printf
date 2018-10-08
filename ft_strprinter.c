/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strprinter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:06:12 by jsobel            #+#    #+#             */
/*   Updated: 2018/10/08 17:05:55 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printstr(t_data *ap)
{
	ap->str = va_arg(ap->arg, char *);
	ap->count += ft_strlen(ap->str);
	ft_putstr(ap->str);
	//ft_bzero(ap->str, ft_strlen(ap->str));
}