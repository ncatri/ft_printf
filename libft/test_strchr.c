#include <stdio.h>
#include <string.h>
#include "libft.h"

int main () {
   const char str[] = "http://www.tutorialspoint.com";
   char ch = '.';
   char *ret;

   ret = ft_strchr(str, ch);

   printf("String after |%c| is - |%s|\n", ch, ret);

   ch = '\0';
   ret = ft_strchr(str, ch);
   printf("String after |%c| is - |%s|\n", ch, ret);

   
   return(0);
}
