/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncatrien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 08:23:11 by ncatrien          #+#    #+#             */
/*   Updated: 2021/01/12 09:20:39 by ncatrien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		number_len(long long n, int base_len)
{
	int i;

	i = 1;
	while (n /= base_len)
		i++;
	return (i);
}

static	long	abs_l(long long n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

int				check_base(char *base)
{
	int	i;
	int j;

	i = 0;
	while (base[i])
	{
		if ((base[i] == '+' || base[i] == '-')
				|| (base[i] >= 9 && base[i] <= 13) || base[i] == 32)
			return (0);
		i++;
	}
	i = 0;
	while (base[i])
	{
		j = i;
		while (base[j++])
			if (base[j] == base[i])
				return (0);
		i++;
	}
	return (i);
}

char			*ft_itoa_base(int n, char *base)
{
	int			l;
	int			is_neg;
	char		*str;
	long long	n_ll;
	int			base_len;

	n_ll = abs_l((long long)n);
	is_neg = 0;
	if (n < 0)
		is_neg = 1;
	base_len = check_base(base);
	l = number_len(n_ll, base_len) + is_neg;
	if (!(str = (char*)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	str[l] = '\0';
	while (n_ll)
	{
		str[--l] = base[n_ll % base_len];
		n_ll /= base_len;
	}
	if (is_neg)
		str[--l] = '-';
	if (n == 0)
		str[--l] = base[0];
	return (str);
}
