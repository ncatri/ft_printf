#include <stdio.h>
#include <string.h>
#include "libft.h"

int main () {
   const char str[] = "http://www.tutorialspoint.com";
   const char ch = '.';
   char *ret;

   ret = memchr(str, ch, strlen(str));

   printf("String after |%c| is - |%s|\n", ch, ret);
   const char *test = ft_memchr("bonjourno", 'n' , 2);
   if (!test)
	   printf("NULL\n");
   else
	   printf("%s\n", test);

   return(0);
}
