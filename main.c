#include <stdio.h>
#include "include/ft_printf.h"

#define TEST " %.09s ", "hi low" 

int main(void)
{
	int ret = 0;
	ret = ft_printf(TEST);
	printf("ret: %d\n", ret);
	ret = printf(TEST);
	printf("ret: %d\n", ret);
}
