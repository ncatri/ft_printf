/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_types.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncatrien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:04:44 by ncatrien          #+#    #+#             */
/*   Updated: 2021/01/15 16:03:05 by ncatrien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	print_char(t_format *f, va_list ap)
{
	int		pad;
	char	c;

	c = (char)va_arg(ap, int);
	pad = f->width - 1;
	if (f->width)
	{
		if (!f->minus)
		{
			padding(' ', pad);
			ft_putchar_fd(c, 1);
		}
		else
		{
			ft_putchar_fd(c, 1);
			padding(' ', pad);
		}
		f->nprinted += pad + 1;
	}
	else
	{
		ft_putchar_fd(c, 1);
		f->nprinted += 1;
	}
}

void	print_string(t_format *f, va_list ap)
{
	char	*str;
	int		len;

	str = va_arg(ap, char*);
	if (!f->point || (f->point && (size_t)f->precision >= ft_strlen(str)))
		len = ft_strlen(str);
	else
		len = f->precision;
	if (f->width)
	{
		if (!f->minus)
		{
			f->nprinted += padding(' ', f->width - len);
			f->nprinted += putstr_n(str, len);
		}
		else
		{
			f->nprinted += putstr_n(str, len);
			f->nprinted += padding(' ', f->width - len);
		}
	}
	else
	{
		f->nprinted += putstr_n(str, len);
	}
}
