#include <stdio.h>
#include "include/ft_printf.h"
#include <limits.h>

#define TEST "|%10x|", -1

int main(void)
{
	int ret = 0;
	ret = ft_printf(TEST);
	printf("ret: %d\n", ret);
	ret = printf(TEST);
	printf("ret: %d\n", ret);
}
