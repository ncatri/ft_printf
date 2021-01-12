#include <stdio.h>
#include "libft.h"

int main(void)
{
	int n = 256;
	printf("%s\n", ft_itoa_base(n, "0123456789abcdef"));
}
