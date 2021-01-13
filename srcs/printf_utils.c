/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncatrien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 12:55:14 by ncatrien          #+#    #+#             */
/*   Updated: 2021/01/13 17:42:13 by ncatrien         ###   ########lyon.fr   */
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
