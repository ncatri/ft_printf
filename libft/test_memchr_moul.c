#include <stdio.h>
#include <string.h>
#include "libft.h"

int main (void)
{
	char *str = "0123456789";
	char c = '7';
	char *ret;
	
	ret = memchr(str, c, 7);
	printf("%s\n", ret);
}	
