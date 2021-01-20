/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncatrien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:02:51 by ncatrien          #+#    #+#             */
/*   Updated: 2021/01/20 13:27:20 by ncatrien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	print_int(t_format *f, va_list ap)
{
	char	*val0;
	char	*val;
	int		len;
	int		d;

	d = va_arg(ap, int);
	val0 = ft_itoa_base(d, "0123456789");
	val = flag_check(f, val0, d);
	len = ft_strlen(val);
	if (f->minus)
		left_justify(f, val, (int)len);
	else
		right_justify(f, val, (int)len);
	free(val0);
}

void	print_uint(t_format *f, va_list ap)
{
	char			*val0;
	char			*val;
	int				len;
	unsigned int	d;

	d = va_arg(ap, unsigned int);
	val0 = ft_ulltoa_base(d, "0123456789");
	val = flag_check(f, val0, d);
	len = ft_strlen(val);
	if (f->minus)
		left_justify(f, val, (int)len);
	else
		right_justify(f, val, (int)len);
	free(val0);
}

void	print_hexa(t_format *f, va_list ap)
{
	char			*val0;
	char			*val;
	int				len;
	unsigned int	d;

	d = va_arg(ap, unsigned int);
	if (f->format[f->pos] == 'x')
		val0 = ft_ulltoa_base(d, "0123456789abcdef");
	else
		val0 = ft_ulltoa_base(d, "0123456789ABCDEF");
	val = flag_check(f, val0, d);
	len = ft_strlen(val);
	if (f->minus)
		left_justify(f, val, (int)len);
	else
		right_justify(f, val, (int)len);
	free(val0);
}

void	print_octal(t_format *f, va_list ap)
{
	char			*val0;
	char			*val;
	int				len;
	unsigned int	d;

	d = va_arg(ap, unsigned int);
	val0 = ft_ulltoa_base(d, "01234567");
	val = flag_check(f, val0, d);
	len = ft_strlen(val);
	if (f->minus)
		left_justify(f, val, (int)len);
	else
		right_justify(f, val, (int)len);
	free(val0);
}
