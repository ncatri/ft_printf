#include <stdio.h>
#include <string.h>
#include "libft.h"

int main () {
   const char src[50] = "http://www.tutorialspoint.com";
   char dest[50];
   strcpy(dest,"Heloooo!!");
   printf("Before memcpy dest = %s\n", dest);
   ft_memcpy(dest, src, strlen(src)+1);
   printf("After memcpy dest = %s\n", dest);

   printf("test with NULL strings\n");
   printf("std: %s\n", memcpy((void*)0, (void*)0, 3));
   printf("std: %s\n", memcpy(dest, (void*)0, 3));
   printf("std: %s\n", memcpy((void*)0, src, 3));
   printf("ft_: %s\n", ft_memcpy((void*)0, (void*)0, 3));

   
   return(0);
}
