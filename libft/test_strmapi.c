#include "libft.h"
#include <stdio.h>

char	func(unsigned int n, char c)
{
	printf("int: %d, char: %c\n", n, c);
	return (c);
}

int		main(void)
{
	char *str = "lorem ipsum";
	char *test;

	test = ft_strmapi(str, &func);
	printf("test: %s\n", test);
}
