#include <stdio.h>
#include <string.h>
#include "libft.h"

void test(int size)
{
    char string[] = "Hello there, Venus";
    char buffer[19];
    int r;

//    r = ft_strlcpy(buffer,string,size);
    r = strlcpy((void *)0, string,size);

    printf("Copied '%s' into '%s', return value: %d\n",
            string,
            buffer,
            r
          );
}

int main()
{
    test(19);
    test(10);
    test(1);
    test(0);

    return(0);
}
