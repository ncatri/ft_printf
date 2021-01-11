#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int ret = 0;
	ret = ft_printf("|Hello %d man|", 42);
	printf("ret: %d\n", ret);
}
