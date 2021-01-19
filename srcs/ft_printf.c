/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncatrien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 08:00:38 by ncatrien          #+#    #+#             */
/*   Updated: 2021/01/18 10:05:37 by ncatrien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	dispatcher(t_format *f, va_list ap)
{
	if (f->format[f->pos] == 'c')
		print_char(f, ap);
	else if (f->format[f->pos] == 's')
		print_string(f, ap);
	else if (f->format[f->pos] == 'd' || f->format[f->pos] == 'i')
		print_int(f, ap);
}

void	flag_parser(t_format *f, va_list ap)
{
	format_zero(f);
	(f->pos)++;
	while (ft_strchr(ALLSYMBS, f->format[f->pos]))
	{
		if (ft_strchr("cspdiuxX%", f->format[f->pos]))
		{
			dispatcher(f, ap);
			break;
		}
		else if (ft_strchr(FLAGS, f->format[f->pos]))
		{
			modifiers(f, ap);
		}
	}
}

void	fmt_parser(t_format *f, va_list ap)
{
	while (f->format[f->pos])
	{
		if (f->format[f->pos] != '%')
		{
			ft_putchar_fd(f->format[f->pos], 1);
			(f->nprinted)++;
		}
		else
			flag_parser(f, ap);
		(f->pos)++;
	}
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_format	f;

	va_start(ap, format);
	format_init(&f, format);

	fmt_parser(&f, ap);

	va_end(ap);
	return (f.nprinted);
}
