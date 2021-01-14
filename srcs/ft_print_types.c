/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_types.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncatrien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:04:44 by ncatrien          #+#    #+#             */
/*   Updated: 2021/01/14 15:42:00 by ncatrien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	print_char(t_format *f, va_list ap)
{
	int		pad;
	char	c;

	if (f->star)
		f->width = va_arg(ap, int);
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
