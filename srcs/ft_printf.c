/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncatrien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 08:00:38 by ncatrien          #+#    #+#             */
/*   Updated: 2021/01/14 15:42:05 by ncatrien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	modifier(t_format *f, char c)
{
	if (c == '-')
		f->minus = 1;
	else if (c == '.')
		f->point = 1;
	else if (c == '*')
		f->star = 1;
	else if (c != '0' && ft_isdigit(c) && !f->point)
	{
		f->width = ft_atoi(&(f->format[f->pos]));
		f->pos += (number_len(f->width) - 1);
	}
	else if (c != '0' && ft_isdigit(c) && f->point)
	{
		f->precision = ft_atoi(&(f->format[f->pos]));
		f->pos += (number_len(f->width) - 1);
	}
	else if (c == '0' && !f->point)
		f->zero = 1;
	else if (c == '*')
		f->star = 1;

}

void	dispatcher(t_format *f, va_list ap)
{
	if (f->format[f->pos] == 'c')
		print_char(f, ap);
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
			modifier(f, f->format[f->pos]);
		}
		(f->pos)++;
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
