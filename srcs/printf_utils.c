/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncatrien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 12:55:14 by ncatrien          #+#    #+#             */
/*   Updated: 2021/01/14 09:52:01 by ncatrien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	format_init(t_format *flags)
{
	flags->value = NULL;
	flags->len = 0;

	flags->minus = 0;
	flags->zero = 0;
	flags->point = 0;
	flags->star = 0;
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
