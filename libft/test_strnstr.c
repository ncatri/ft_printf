#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len);

char *test(size_t n)
{
	const char *str = "Voici donc une grande phrase dans laquelle faut aller chercher.";
	const char *to_find = "dans";

	return (ft_strnstr(str, to_find, n));
}

int	main(void)
{
	size_t l = ft_strlen("Voici donc une grande phrase dan");
	size_t val[3] = {50, 5, l};
	for (int i = 0; i < 3; i++)
	{
		printf("%s\n", test(val[i]));
	}
	const char *s2 = "MZIRIBMZIRIBMZE123";
	const char *f2 = "MZIRIBMZE";
	char *res = ft_strnstr(s2, f2, 9);
	if (!res)
		printf("NULL\n");
	else
		printf("%s\n", res);
	printf("***\n");

	char *s3 = "MZIRIBMZIRIBMZE123";
	char *f3 = "MZIRIBMZE";
	printf("%s\n", strnstr(s3, f3, strlen(f3)));

	printf("***\n");
	char *s4 = "A";
	printf("std:%s\n", strnstr(s4, s4, strlen(s4)));
	printf("ft_:%s\n", ft_strnstr(s4, s4, strlen(s4)));

	printf("*** test moulinette ***\n");
	char *s5 = "abcdefg";
	char *f5 = "abcdefg\0hijklmnopqrstuvwxyz";
	printf("std:%s\n", strnstr(s5, f5, 100));
	printf("ft_:%s\n", ft_strnstr(s5, f5, 100));

}
