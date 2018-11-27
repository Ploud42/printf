/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:08:21 by jsobel            #+#    #+#             */
/*   Updated: 2018/11/27 18:24:26 by juliensobel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include "../libft/includes/libft.h"

# define FLAG_NB	9
# define CHECK_NB	11
# define SPEC_NB	15
# define HASH		0
# define MINUS		1
# define PLUS		2
# define SPACE		3
# define ZERO		4
# define LONG		5
# define SHORT		6
# define INTMAX		7
# define SIZE_T		8
# define WIDTH		9
# define PRECISION	10
# define BUFF_SIZE	2048

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
	uintmax_t		unbll;
	intmax_t		nbll;
	char			c;
	int				i;
	int				count;
	int				index;
	int				minus;
	char			width;
	int				len;
	int				precision;
}					t_data;

int					ft_printf(const char *format, ...);

char				*ft_itoa_uintmax(uintmax_t n);
char				*ft_itoa_intmax(intmax_t n);

void				ft_get_nb_u(t_data *ap);
void				ft_print_u_int(t_data *ap);

void				ft_printchar(t_data *ap);

void				ft_preci_zero(t_data *ap);
void				ft_convert_x(t_data *ap);

void				ft_get_nb(t_data *ap);
int					ft_nbrlen_base(uintmax_t nbr, int base);
void				ft_convert_o(t_data *ap);

void				ft_printstr_width(t_data *ap);
void				ft_printstr_preci(t_data *ap);
void				ft_printstr(t_data *ap);

void				ft_printint(t_data *ap);

void				ft_printper(t_data *ap);

void				ft_check(t_data *ap);

#endif
