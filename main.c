#include <stdio.h>
#include "include/ft_printf.h"
#include <limits.h>

#define TEST "%*.*u", 5, -7, 10 

int main(void)
{

	int ret = 0;
	ret = ft_printf(TEST);
	printf("ret: %d\n", ret);
	ret = printf(TEST);
	printf("ret: %d\n", ret);
}
