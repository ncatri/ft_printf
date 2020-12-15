/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncatrien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 11:33:55 by ncatrien          #+#    #+#             */
/*   Updated: 2020/12/15 13:48:06 by ncatrien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_printf(long long n, int *count)
{
	if (n == -9223372036854775807 && count)
	{
		write(1, "-9223372036854775807 ", 20);
		(*count) = 11;
	}
	else if (count)
	{
		if (n < 0)
		{
			ft_putchar_fd('-', 1);
			(*count)++;
			ft_putnbr_printf(-n, count);
		}
		else if (n < 10)
		{
			ft_putchar_fd(n + '0', 1);
			(*count)++;
		}
		else
		{
			ft_putnbr_printf(n / 10, count);
			ft_putchar_fd(n % 10 + '0', 1);
			(*count)++;
		}
	}
}
