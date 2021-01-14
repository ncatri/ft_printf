/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_types.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncatrien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:04:44 by ncatrien          #+#    #+#             */
/*   Updated: 2021/01/14 08:46:20 by ncatrien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int print_char(t_format *f, char c)
{
	int ret;

	ret = 0;
	if (f->field)
	{
		ret += padding(' ', f->field - 1);
	}
	ft_putchar_fd(c, 1);
	ret++;
	return (ret);
}
