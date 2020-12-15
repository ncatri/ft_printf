/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmarkprintf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncatrien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 13:05:06 by ncatrien          #+#    #+#             */
/*   Updated: 2020/12/15 14:22:24 by ncatrien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

#ifndef OUTPUT_STREAM
# define OUTPUT_STREAM	stdout 
#endif

void test_d_flags(int val)
{
	int ret;

	printf("* 1 *\t");
	ret = printf("%d", val);
	printf("|-->%d\n", ret);

	printf("* 2 *\t");
	ret = printf("%2d", val);
	printf("|-->%d\n", ret);

	printf("* 3 *\t");
	ret = printf("%5d", val);
	printf("|-->%d\n", ret);

	printf("* 4 *\t");
	ret = printf("%10d", val);
	printf("|-->%d\n", ret);

	printf("* 5 *\t");
	ret = printf("%0d", val);
	printf("|-->%d\n", ret);

}

void	test_di_noflags(int val)
{
	int ret;

	printf("* 1 *\n");
	ret = printf("%dabc", val);
	printf("|-->%d\n", ret);
	ret = ft_printf("%dabc", val);
	printf("|-->%d\n", ret);

	printf("* 2 *\n");
	ret = printf("ab%dc", val);
	printf("|-->%d\n", ret);
	ret = ft_printf("ab%dc", val);
	printf("|-->%d\n", ret);

	printf("* 3 *\n");
	ret = printf("abc%d", val);
	printf("|-->%d\n", ret);
	ret = ft_printf("abc%d", val);
	printf("|-->%d\n", ret);

	printf("* 4 *\n");
	ret = printf("ab%dcdef%dghij", val, 2*val);
	printf("|-->%d\n", ret);
	ret = ft_printf("ab%dcdef%dghij", val, 2*val);
	printf("|-->%d\n", ret);

	printf("* 5 *\n");
	ret = printf("%dabcd%defghij%d", val, 2*val, 3*val);
	printf("|-->%d\n", ret);
	ret = ft_printf("%dabcd%defghij%d", val, 2*val, 3*val);
	printf("|-->%d\n", ret);
}

void	test_no_conversion(void)
{
	int ret;

	printf("* 1 *\n");
	ret = printf("abc");
	printf("|-->%d\n", ret);
	ret = ft_printf("abc");
	printf("|-->%d\n", ret);

	printf("* 2 *\t");
	ret = printf("");
	printf("|-->%d\n", ret);
	ret = ft_printf("");
	printf("|-->%d\n", ret);
}

int main(void)
{
	test_d_flags(12);
}
