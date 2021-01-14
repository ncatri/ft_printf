/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncatrien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 12:55:14 by ncatrien          #+#    #+#             */
/*   Updated: 2021/01/14 14:17:12 by ncatrien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	format_init(t_format *f, const char *fmt)
{
	f->format = fmt;
	f->pos = 0;

	f->nprinted = 0;
}

void	format_zero(t_format *f)
{
	f->width = 0;
	f->precision = 0;

	f->minus = 0;
	f->zero = 0;
	f->point = 0;
	f->star = 0;
}

int		padding(char c, int n)
{
	int i;
	int ret;

	i = -1;
	ret = 0;
	while (++i < n)
	{
		ft_putchar_fd(c, 1);
		ret++;
	}
	return (ret);
}

int		number_len(int n)
{
	int i;

	i = 1;
	while (n/= 10)
		i++;
	return (i);
}
