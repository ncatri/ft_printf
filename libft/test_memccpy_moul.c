#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"


int main( void )
{
	printf("*** test moul 1: ***\n");
	char dst1[80] = "";
	char* src1 = "";
	printf("ft_:|%s|\n", ft_memccpy(dst1, src1, ' ', 0));
	printf("std:|%s|\n", memccpy(dst1, src1, ' ', 0));

	printf("*** test moul 2: ***\n");
	char dst2[80] = "8KkvgtSb9oWz";
	char* src2 = "4kpaMWHm81PC";
	printf("ft_:|%s|\n", ft_memccpy(dst2, src2, 'H', 6));
	printf("std:|%s|\n", memccpy(dst2, src2, 'H', 6));

	printf("*** test moul 3: ***\n");
	char dst3[80] = "P9ERVBvuLyc";
	char* src3 = "1U9NPwWKLM";
	printf("ft_:|%s|\n", ft_memccpy(dst3, src3, 'K', 7));
	printf("std:|%s|\n", memccpy(dst3, src3, 'K', 7));

    return EXIT_SUCCESS;
}
