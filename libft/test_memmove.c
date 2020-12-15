#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

int main( void )
{
    char buffer[80];

    strcpy( buffer, "World");
    ft_memmove( buffer+1, buffer, 79 );
    printf ("%s\n", buffer);
	printf("memmove with two null params:\n");
	printf("std:%s\n", memmove((void*)0, (void*)0, 8));
	printf("std:%s\n", ft_memmove(buffer, (void*)0, 8));
	printf("std:%s\n", memmove((void*)0, buffer, 8));
	printf("ft_:%s\n", ft_memmove((void*)0, (void*)0, 8));
    
    return EXIT_SUCCESS;
}
