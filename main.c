#include <stdio.h>
#include "include/ft_printf.h"

#define TEST "|%3.5d|",-1 

int main(void)
{
	int ret = 0;
	ret = ft_printf(TEST);
	printf("ret: %d\n", ret);
	ret = printf(TEST);
	printf("ret: %d\n", ret);
}
