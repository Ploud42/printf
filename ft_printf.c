/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 18:26:33 by jsobel            #+#    #+#             */
/*   Updated: 2018/10/16 19:27:18 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

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
	else
		return ;
}

static void	ft_reader_format(t_data *ap)
{
	while (*(*ap).format)
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
	ap->tab[3] = &ft_printint;
	ap->tab[5] = &ft_printint;
}

static void	ft_set_index(t_data *ap)
{
	ap->flag[0] = '-';
	ap->flag[1] = '+';
	ap->flag[2] = ' ';
	ap->flag[3] = '0';
	ap->flag[4] = '#';
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

/*
int	ft_printf(const char *format, ...)
{
	char *str;
	va_list arg;

	va_start(arg, format);
	str = va_arg(arg, char *);
	ft_putstr(str);
	va_end(arg);
	return (0);
}*/

int	main()
{
	int ret;

	ret = ft_printf("Hey j'ai envie de te dire %-7s, et cela %5d fois, %s %i fois\n", "salut", 15, "ou alors", 0);
	printf("ret = %d\n", ret);
	ft_printf("%8.3s\n", "abcde");
	printf("%.8d\n", 123);
	return (0);
}