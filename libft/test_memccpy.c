#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"


int main( void )
{
	char* msg = "This is the string, not copied";
    char buffer[80];

    memset( buffer, '\0', 80 );
    char *res = ft_memccpy( buffer, msg, ',', 80 );
	printf("dest:\n");
    printf( "%s\n", buffer );
	printf("return value:\n");
	printf("%s\n", res);
    
    return EXIT_SUCCESS;
}
