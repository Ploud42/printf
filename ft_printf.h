/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:08:21 by jsobel            #+#    #+#             */
/*   Updated: 2018/10/11 18:37:10 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include "libft.h"

# define FLAG_NB 6
# define CHECK_NB 8
# define SPEC_NB 15
# define MINUS 0
# define PLUS 1
# define SPACE 2
# define ZERO 3
# define HASH 4
# define WIDTH 5
# define PRECISION 6
# define BUFF_SIZE 2048

typedef struct		s_data
{
	const char		*format;
	char			*str;
	char			flag[FLAG_NB];
	char			spec[SPEC_NB];
	int				check[CHECK_NB];
	void			(*tab[SPEC_NB])(struct s_data *);
	va_list			arg;
	int				nb;
	int				i;
	int				count;
	int				index;
	int				minus;
	int				plus;
	int				space;
	int				zero;
	int				hash;
	int				width;
	int				precision;
}					t_data;

void				ft_printstr(t_data *ap);
void				ft_printint(t_data *ap);
void				ft_check(t_data *ap);

#endif