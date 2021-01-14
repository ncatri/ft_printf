#include <stdio.h>
#include "include/ft_printf.h"

int main(void)
{
	int ret = 0;
	ret = ft_printf("|abc%*c|", -2, 'x');
	printf("ret: %d\n", ret);
	ret = printf("|abc%*c|", -2, 'x');
	printf("ret: %d\n", ret);
}
