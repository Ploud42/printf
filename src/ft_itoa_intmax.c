/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_intmax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 16:28:14 by jsobel            #+#    #+#             */
/*   Updated: 2019/03/12 17:01:39 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_double(double n)
{
	char		*str;
	intmax_t	i;

	i = n;
	n = n - i;
	if (n >= 0.5)
		i++;
	str = ft_itoa_intmax(i);
	return (str);
}

char	*ft_itoa_intmax(intmax_t n)
{
	char		*tab;
	intmax_t	i;
	intmax_t	size;

	i = n;
	size = n == 0 ? 1 : 0;
	while (i != 0)
	{
		i /= 10;
		size++;
	}
	i = n;
	size = n < 0 ? size + 1 : size;
	if (!(tab = malloc(size + 1)))
		return (NULL);
	tab[size] = 0;
	tab[0] = n < 0 ? '-' : '0';
	i = n < 0 ? -i : i;
	while (i >= 1)
	{
		tab[size - 1] = (i % 10) + 48;
		i /= 10;
		size--;
	}
	return (tab);
}

char	*ft_itoa_uintmax(uintmax_t n)
{
	char		*tab;
	uintmax_t	i;
	uintmax_t	size;

	i = n;
	size = n == 0 ? 1 : 0;
	while (i != 0)
	{
		i /= 10;
		size++;
	}
	i = n;
	if (!(tab = malloc(size + 1)))
		return (NULL);
	tab[size] = 0;
	tab[0] = '0';
	while (i >= 1)
	{
		tab[size - 1] = (i % 10) + 48;
		i /= 10;
		size--;
	}
	return (tab);
}
