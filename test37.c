#include <stdio.h>
#include "include/ft_printf.h"
#include <limits.h>

#define TEST "%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d

int main(void)
{
	int		a = -4;
//	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
//	int		f = 42;
//	int		g = 25;
//	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;

	int ret = 0;
	ret = ft_printf(TEST);
	printf("ret: %d\n", ret);
	ret = printf(TEST);
	printf("ret: %d\n", ret);
}
