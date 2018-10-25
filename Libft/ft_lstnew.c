/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 18:10:58 by hben-yah          #+#    #+#             */
/*   Updated: 2018/04/04 18:10:59 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_lstdup(void const *content, size_t content_size)
{
	unsigned char	*r_cont;
	unsigned char	*r_res;
	void			*res;

	if (!(res = ft_memalloc(content_size)))
		return (NULL);
	r_cont = (unsigned char *)content;
	r_res = (unsigned char *)res;
	while (*r_cont)
		*(r_res++) = *(r_cont++);
	return (res);
}

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *list;

	if (!(list = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(list->content = ft_lstdup(content, content_size)))
			return (NULL);
		list->content_size = content_size;
	}
	else
	{
		list->content = NULL;
		list->content_size = 0;
	}
	list->next = NULL;
	return (list);
}
