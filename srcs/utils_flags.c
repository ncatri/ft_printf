/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncatrien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 13:47:32 by ncatrien          #+#    #+#             */
/*   Updated: 2021/01/20 13:52:37 by ncatrien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ifpoint(t_format *f)
{
	if (f->format[f->pos] == '.')
	{
		f->point = 1;
		(f->pos)++;
		if (f->format[f->pos] == '0')
			(f->pos)++;
		if (ft_isdigit(f->format[f->pos]))
		{
			f->precision = ft_atoi(&f->format[f->pos]);
			f->pos += number_len(f->precision);
		}
	}
}

void	ifstar(t_format *f, va_list ap)
{
	int p;

	if (f->format[f->pos] == '*')
	{
		p = va_arg(ap, int);
		if (p < 0)
		{
			f->neg_precision = 1;
			f->precision = -p;
		}
		else
			f->precision = p;
		(f->pos)++;
	}
}
