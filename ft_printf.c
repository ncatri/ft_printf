/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncatrien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 08:00:38 by ncatrien          #+#    #+#             */
/*   Updated: 2020/12/15 14:22:30 by ncatrien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parser(const char *str, va_list ap, int *i_ptr)
{
	int i;
	int ret;

	i = 1;
	ret = 0;
	if (str[i] == '%')
		write(1, "%", 1);
	else if (str[i] == 'd' || str[i] == 'i')
		ret += print_int(va_arg(ap, int));
	(*i_ptr)++;
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			ret++;
		}
		else
			ret += parser(&format[i], ap, &i);
		i++;
	}
	va_end(ap);
	return (ret);
}
