/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:08:21 by jsobel            #+#    #+#             */
/*   Updated: 2018/10/10 18:37:59 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include "libft.h"

# define FLAG_NB 15
# define SPEC_NB 14
# define BUFF_SIZE 2048

typedef struct		s_data
{
	const char		*format;
	char			*str;
	char			spec[SPEC_NB];
	void			(*tab[SPEC_NB])(struct s_data *);
	va_list			arg;
	int				nb;
	int				i;
	int				count;
	int				index;
	int				precision;
}					t_data;

void				ft_printstr(t_data *ap);
void				ft_printint(t_data *ap);
void				ft_check_flag(t_data *ap);

#endif