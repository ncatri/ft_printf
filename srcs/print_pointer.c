/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncatrien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 12:37:45 by ncatrien          #+#    #+#             */
/*   Updated: 2021/01/19 14:05:39 by ncatrien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	print_pointer(t_format *f, va_list ap)
{
	char				*val;
	unsigned long long	pval;

	pval = va_arg(ap, unsigned long long);
	val = ft_ulltoa_base(pval, "0123456789abcdef");
	print_pointer2(f, val);
	free(val);
}

void	print_pointer2(t_format *f, char *val)
{
	int	pad;
	int len;

	len = ft_strlen(val);
	pad = f->width - len - 2;
	if (f->minus)
	{
		f->nprinted += write(1, "0x", 2);
		f->nprinted += putstr_n(val, len);
		f->nprinted += padding(' ', pad);
	}
	else
	{
		f->nprinted += padding(' ', pad);
		f->nprinted += write(1, "0x", 2);
		f->nprinted += putstr_n(val, len);
	}
}
