#include <stdio.h>
#include <string.h>
#include "libft.h"

int main () {
   char str1[15];
   char str2[15];
   int ret;

   strcpy(str1, "abcdef");
   strcpy(str2, "ABCDEF");

   ret = ft_strncmp(str1, str2, 4);

   if(ret < 0) {
      printf("str1 is less than str2");
   } else if(ret > 0) {
      printf("str2 is less than str1");
   } else {
      printf("str1 is equal to str2");
   }
   printf("\n");
   printf("%d\n", ft_strncmp("bonjour", "bonjourno", 7));
   printf("%d\n", ft_strncmp("abcdefgh", "abcdwxyz", 4));
   printf("%d\n", ft_strncmp("abcdefgh", "abcdwxyz", 0));
   printf("%d\n", strncmp("abcdefgh", "abcdwxyz", 0));
   printf("%d\n", ft_strncmp("test\200", "test\0", 6));
   printf("%d\n", strncmp("test\200", "test\0", 6));
   printf("%c\n", '\200');
   printf("%d\n", ft_strncmp("a", "z", 1));
   printf("%d\n", strncmp("bon\0jour", "bon\0journo", 9));
   printf("%d\n", ft_strncmp("bon\0jour", "bon\0journo", 9));
   
   return(0);
}
