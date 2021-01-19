/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncatrien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 10:03:52 by ncatrien          #+#    #+#             */
/*   Updated: 2021/01/19 08:26:50 by ncatrien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	print_int(t_format *f, va_list ap)
{
	char	*val;
	int		len;
	int		d;

	d = va_arg(ap, int);
	if (d < 0)
	{
		d = -d;
		f->negative = 1;
	}
	val = ft_itoa_base(d, "0123456789");
	if (d == 0 && f->point)
		val = "";
	len = ft_strlen(val);
	if (f->minus)
		left_justify(f, val, (int)len);
	else
		right_justify(f, val, (int)len);
}

void	left_justify(t_format *f, char *val, int len)
{
	int pad_prec;
	int pad_width;

	pad_prec = f->precision - len; 
	if (!f->point || pad_prec < 0)
		pad_prec = 0;
	if (f->negative)
		f->nprinted += write(1, "-", 1);
	pad_width = f->width - len - pad_prec - f->negative;
	f->nprinted += padding('0', pad_prec);
	f->nprinted += putstr_n(val, len);
	f->nprinted += padding(' ', pad_width);
}

void	right_justify(t_format *f, char *val, int len)
{
	int pad_prec;
	int pad_width;

	pad_prec = f->precision - len; 
	if (!f->point || pad_prec < 0)
		pad_prec = 0;
	pad_width = f->width - len - pad_prec - f->negative;
	f->nprinted += padding(' ', pad_width);
	if (f->negative)
		f->nprinted += write(1, "-", 1);
	f->nprinted += padding('0', pad_prec);
	f->nprinted += putstr_n(val, len);
}
