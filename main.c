#include <stdio.h>
#include "include/ft_printf.h"

int main(void)
{
	int ret = 0;
	ret = ft_printf("|abc|");
	printf("ret: %d\n", ret);
}
