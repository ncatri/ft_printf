#include "include/ft_printf.h"
#include <stdio.h>

int main (void)
{
	unsigned int x;
	char *s;

	x = -1;
	s = ft_ulltoa_base(x, "0123456789abcdef");

	printf("|%s|", s);
}
