/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 18:26:33 by jsobel            #+#    #+#             */
/*   Updated: 2018/12/05 18:25:31 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include<stdio.h>

static void	ft_printer(t_data *ap)
{
	ap->index = 0;
	while ((*(*ap).format != (*ap).spec[ap->index]) && ap->index < SPEC_NB)
		ap->index++;
	if (ap->index < SPEC_NB)
	{
		ap->tab[ap->index](ap);
		ap->format++;
	}
	else if (ap->check[WIDTH] != -1)
	{
		if (!(ap->str = ft_memalloc(2)))
			exit(EXIT_FAILURE);
		ap->str[0] = ap->format[0];
		ap->check[PRECISION] = -1;
		ft_printstr(ap);
		ap->format++;
	}
	else
		return ;
}

static void	ft_reader_format(t_data *ap)
{
	while (*(*ap).format && ap->count != -1)
	{
		if (*(*ap).format == '%')
		{
			ap->format++;
			ft_check(ap);
			ft_printer(ap);
		}
		else
		{
			write(1, ap->format, 1);
			ap->count++;
			ap->format++;
		}
	}
}

static void	ft_set_specifiers(t_data *ap)
{
	ap->tab[0] = &ft_printstr;
	ap->tab[1] = &ft_printstr;
	ap->tab[2] = &ft_convert_x;
	ap->tab[3] = &ft_printint;
	ap->tab[4] = &ft_printlint;
	ap->tab[5] = &ft_printint;
	ap->tab[6] = &ft_convert_o;
	ap->tab[7] = &ft_convert_o;
	ap->tab[8] = &ft_print_u_int;
	ap->tab[9] = &ft_print_u_int;
	ap->tab[10] = &ft_convert_x;
	ap->tab[11] = &ft_convert_x;
	ap->tab[12] = &ft_printchar;
	ap->tab[13] = &ft_printchar;
	ap->tab[14] = &ft_printper;
}

static void	ft_set_index(t_data *ap)
{
	ap->flag[MINUS] = '-';
	ap->flag[PLUS] = '+';
	ap->flag[SPACE] = ' ';
	ap->flag[ZERO] = '0';
	ap->flag[HASH] = '#';
	ap->flag[LONG] = 'l';
	ap->flag[SHORT] = 'h';
	ap->flag[INTMAX] = 'j';
	ap->flag[SIZE_T] = 'z';
	ap->spec[0] = 's';
	ap->spec[1] = 'S';
	ap->spec[2] = 'p';
	ap->spec[3] = 'd';
	ap->spec[4] = 'D';
	ap->spec[5] = 'i';
	ap->spec[6] = 'o';
	ap->spec[7] = 'O';
	ap->spec[8] = 'u';
	ap->spec[9] = 'U';
	ap->spec[10] = 'x';
	ap->spec[11] = 'X';
	ap->spec[12] = 'c';
	ap->spec[13] = 'C';
	ap->spec[14] = '%';
}

int			ft_printf(const char *format, ...)
{
	t_data	ap;

	ap.i = 0;
	ap.count = 0;
	ap.format = format;
	ft_set_specifiers(&ap);
	ft_set_index(&ap);
	va_start(ap.arg, format);
	ft_reader_format(&ap);
	va_end(ap.arg);
	return (ap.count);
}