#include <stdio.h>
#include "include/ft_printf.h"
#include <limits.h>

#define TEST "|%0*d|", 10, INT_MIN 

int main(void)
{
	int ret = 0;
	ret = ft_printf(TEST);
	printf("ret: %d\n", ret);
	ret = printf(TEST);
	printf("ret: %d\n", ret);
}
