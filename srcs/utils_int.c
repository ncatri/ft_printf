/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncatrien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 09:24:22 by ncatrien          #+#    #+#             */
/*   Updated: 2021/01/20 16:06:05 by ncatrien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*flag_check(t_format *f, char *val0, int d)
{
	char *val;

	if (val0[0] == '-')
	{
		sign_changer(f, 1, '-');
		val = val0 + 1;
	}
	else
	{
		val = val0;
		if (f->space)
			sign_changer(f, 1, ' ');
		else
			f->sign_symb = '+';
	}
	if (f->neg_precision)
	{
		f->precision = 0;
		f->point = 0;
	}
	if (d == 0 && f->point)
		val = "";
	return (val);
}

void	sign_changer(t_format *f, int sign, char symb)
{
	f->sign = sign;
	f->sign_symb = symb;
}

void	left_justify(t_format *f, char *val, int len)
{
	int pad_prec;
	int pad_width;

	pad_prec = f->precision - len;
	if (!f->point || pad_prec < 0)
		pad_prec = 0;
	if (f->sign)
		f->nprinted += putchar_pf(f->sign_symb);
	pad_width = f->width - len - pad_prec - f->sign;
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
	pad_width = f->width - len - pad_prec - f->sign;
	if (!f->zero || (f->zero && f->point))
	{
		f->nprinted += padding(' ', pad_width);
		if (f->sign)
			f->nprinted += putchar_pf(f->sign_symb);
	}
	else
	{
		if (f->sign)
			f->nprinted += putchar_pf(f->sign_symb);
		f->nprinted += padding('0', pad_width);
	}
	f->nprinted += padding('0', pad_prec);
	f->nprinted += putstr_n(val, len);
}
