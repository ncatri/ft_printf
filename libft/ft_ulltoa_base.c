/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncatrien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:38:02 by ncatrien          #+#    #+#             */
/*   Updated: 2021/01/19 13:47:57 by ncatrien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		number_len(unsigned long long n, int base_len)
{
	int i;

	i = 1;
	while (n /= base_len)
		i++;
	return (i);
}

static int		check_base(char *base)
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

char			*ft_ulltoa_base(unsigned long long n, char *base)
{
	int			l;
	char		*str;
	int			base_len;

	base_len = check_base(base);
	l = number_len(n, base_len);
	if (!(str = (char*)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	str[l] = '\0';
	while (n)
	{
		str[--l] = base[n % base_len];
		n /= base_len;
	}
	if (n == 0)
		str[--l] = base[0];
	return (str);
}
