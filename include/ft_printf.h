/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncatrien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 08:32:13 by ncatrien          #+#    #+#             */
/*   Updated: 2021/01/20 16:02:14 by ncatrien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

# define FLAGS "-0.* +#123456789"
# define ALLSYMBS "-0.* +#123456789cspdiuxXo%"

typedef	struct	s_format
{
	const char	*format;
	int			pos;

	int			nprinted;

	int			minus;
	int			zero;
	int			point;
	int			hashtag;
	int			space;
	int			plus;

	int			width;
	int			precision;
	int			neg_precision;
	int			sign;
	char		sign_symb;

}				t_format;

int				ft_printf(const char *format, ...);
void			fmt_parser(t_format *f, va_list ap);
void			flag_parser(t_format *f, va_list ap);
void			dispatcher(t_format *f, va_list ap);

void			modifiers(t_format *f, va_list ap);
void			flags(t_format *f);
void			width(t_format *f, va_list ap);
void			precision(t_format *f, va_list ap);

void			ifpoint(t_format *f);
void			ifstar(t_format *f, va_list ap);

void			format_init(t_format *flags, const char *format);
void			format_zero(t_format *flags);
int				padding(char c, int n);
int				number_len(int n);
int				putstr_n(char *str, int n);

int				putchar_pf(char c);

void			print_char(t_format *f, va_list ap);
void			print_string(t_format *f, va_list ap);
void			print_percent(t_format *f);

void			print_int(t_format *f, va_list ap);
void			print_uint(t_format *f, va_list ap);
void			print_hexa(t_format *f, va_list ap);
void			print_octal(t_format *f, va_list ap);

char			*flag_check(t_format *f, char *val0, int d);
void			left_justify(t_format *f, char *val, int len);
void			right_justify(t_format *f, char *val, int len);
void			sign_changer(t_format *f, int sign, char symb);

void			print_pointer(t_format *f, va_list ap);
void			print_pointer2(t_format *f, char *val);

#endif
