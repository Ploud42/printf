/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 13:32:04 by jsobel            #+#    #+#             */
/*   Updated: 2018/11/07 17:50:44 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bzero(void *s, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		*((char *)s + i) = '\0';
		i++;
	}
}

void	*ft_memalloc(size_t size)
{
	void	*temp;

	if (!(temp = malloc(sizeof(void) * size)))
		return (NULL);
	ft_bzero(temp, size + 1);
	return (temp);
}
