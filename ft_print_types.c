/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_types.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncatrien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:04:44 by ncatrien          #+#    #+#             */
/*   Updated: 2020/12/15 12:53:02 by ncatrien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

#include <stdio.h>

int	print_int(int n)
{
	int counter;

	counter = 0;
	ft_putnbr_printf(n, &counter);
	return (counter);
}
