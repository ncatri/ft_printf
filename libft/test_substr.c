#include <stdio.h>
#include "libft.h"

int main(void)
{
	char *str = "a big string we want to extract something from.";

	int index = 15;
	int length = 50;

	printf("|%s|\n", ft_substr(str, index, length));
	printf("|%s|\n", ft_substr(str, 150, length));
}
