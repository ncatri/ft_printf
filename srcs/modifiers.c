/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncatrien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 08:48:20 by ncatrien          #+#    #+#             */
/*   Updated: 2021/01/20 14:58:37 by ncatrien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	modifiers(t_format *f, va_list ap)
{
	flags(f);
	width(f, ap);
	precision(f, ap);
}

void	flags(t_format *f)
{
	while (ft_strchr("-0 +#", f->format[f->pos]))
	{
		if (f->format[f->pos] == '-')
			f->minus = 1;
		else if (f->format[f->pos] == '0')
			f->zero = 1;
		else if (f->format[f->pos] == '#')
			f->hashtag = 1;
		else if (f->format[f->pos] == ' ')
			f->space = 1;
		else if (f->format[f->pos] == '+')
			f->sign = 1;
		(f->pos)++;
	}
}

void	width(t_format *f, va_list ap)
{
	int w;

	if (ft_isdigit(f->format[f->pos]))
	{
		f->width = ft_atoi(&f->format[f->pos]);
		f->pos += number_len(f->width);
	}
	else if (f->format[f->pos] == '*')
	{
		w = va_arg(ap, int);
		if (w < 0)
		{
			f->width = -w;
			f->minus = 1;
		}
		else
			f->width = w;
		(f->pos)++;
	}
}

void	precision(t_format *f, va_list ap)
{
	ifpoint(f);
	ifstar(f, ap);
}
