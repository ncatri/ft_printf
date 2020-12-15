#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int main(void)
{
	char *s0 = "684";
	char *s1 = "   987  ";
	char *s2 = " -58p75";
	char *s3 = "\t\n \f\r42\v78af";
	char *s4 = " +-7";
	char *s5 = "0";
	char *s6 = "+684+12";

	char *tests[7] = {s0, s1, s2, s3, s4, s5, s6};
	int i = 0;
	printf("tests atoi libc:\n");
	while (i < 7)
		printf("%d\n", atoi(tests[i++]));
	i = 0;
	printf("tests ft_atoi libft:\n");
	while (i < 7)
		printf("%d\n", ft_atoi(tests[i++]));
	printf("**** benchmark atoi ****\n");
	printf("int min: %d\n", atoi("-2147483648"));
	printf("int min - 1: %d\n", atoi("-2147483649"));
	printf("int min * 10: %d\n", atoi("-21474836480"));
	printf("int min ---: %d\n", atoi("-911111111111111111"));
	printf("long min: %d\n", atoi("-9223372036854775808"));
	printf("long min +1: %d\n", atoi("-9223372036854775807"));
	printf("long min -1: %d\n", atoi("-9223372036854775809"));
	printf("\n");
	printf("int max: %d\n", atoi("2147483647"));
	printf("int max + 1: %d\n", atoi("2147483648"));
	printf("int max * 10: %d\n", atoi("21474836470"));
	printf("int max +++: %d\n", atoi("911111111111111111"));
	printf("long max: %d\n", atoi("9223372036854775807"));
	printf("long max -1: %d\n", atoi("9223372036854775806"));
	printf("long max +1: %d\n", atoi("9223372036854775808"));
	printf("long max: %d\n", atoi("1111111111111111111"));

	printf("**** comparing with ft_atoi ****\n");
	printf("int min: %d\n", ft_atoi("-2147483648"));
	printf("int min - 1: %d\n", ft_atoi("-2147483649"));
	printf("int min * 10: %d\n", ft_atoi("-21474836480"));
	printf("int min ---: %d\n", ft_atoi("-911111111111111111"));
	printf("long min: %d\n", ft_atoi("-9223372036854775808"));
	printf("long min +1: %d\n", ft_atoi("-9223372036854775807"));
	printf("long min -1: %d\n", ft_atoi("-9223372036854775809"));
	printf("\n");
	printf("int max: %d\n", ft_atoi("2147483647"));
	printf("int max + 1: %d\n", ft_atoi("2147483648"));
	printf("int max * 10: %d\n", ft_atoi("21474836470"));
	printf("int max +++: %d\n", ft_atoi("911111111111111111"));
	printf("long max: %d\n", ft_atoi("9223372036854775807"));
	printf("long max -1: %d\n", ft_atoi("9223372036854775806"));
	printf("long max +1: %d\n", ft_atoi("9223372036854775808"));
	printf("long max: %d\n", ft_atoi("1111111111111111111"));
}
