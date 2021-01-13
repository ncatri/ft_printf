/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncatrien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 08:00:38 by ncatrien          #+#    #+#             */
/*   Updated: 2021/01/13 17:09:30 by ncatrien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	modifier(t_format *f, char c)
{
	if (c == '-')
		f->minus = 1;
	else if (c == '.')
		f->point = 1;
	else if (c == '*')
		f->star = 1;

}

int	parser(const char *str, va_list ap, int *i_ptr)
{
	int			i;
	int			ret;
	t_format	mold;

	i = 1; // starts at 1 bc *str points to '%'
	ret = 0;
	format_init(&mold);
	while (ft_strchr(ALLSYMBS, str[i]))
	{
		if (ft_strchr("cspdiuxX%", str[i]))
		{
//			ret += dispatcher(str[i], &mold, ap);
			(void)ap;
			break;
		}
		else if (ft_strchr(FLAGS, str[i]))
		{
			modifier(&mold, str[i]);
			(*i_ptr)++;
		}
		i++;
	}
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
