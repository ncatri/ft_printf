/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncatrien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 08:32:13 by ncatrien          #+#    #+#             */
/*   Updated: 2021/01/14 09:52:08 by ncatrien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

# define FLAGS "-0.*123456789"
# define ALLSYMBS "-0.*123456789cspdiuxX%"

typedef	struct	s_format
{
	char	*value;
	int		len;

	int		field; //numbers before '.'
	int		precision; //numbers after '.'

	int		minus;
	int		zero;
	int		point;
	int		star;
}				t_format;

int				ft_printf(const char *format, ...);
int				parser(const char *str, va_list args, int *i_ptr);
void			modifier(t_format *f, char c);
int				dispatcher(char c, t_format *f, va_list ap);

void			format_init(t_format *flags);
int				padding(char c, int n);

int				print_char(t_format *f, char c);

#endif
