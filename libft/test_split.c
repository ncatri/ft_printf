#include <stdio.h>
#include "libft.h"

int main(void)
{
	char *str = "extrem xspace extra";
	char c = 'x';
//	printf("%d\n", words_count(str, ' '));
	char **test = ft_split(str, c);
	int i = 0;
	while (test[i])
	{
		printf("%s\n", test[i]);
		i++;
	}
}
