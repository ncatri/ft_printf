#include "libft.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int file = open("file", O_CREAT | O_WRONLY | O_APPEND, 0644);
	ft_putchar_fd('x', file);
	ft_putchar_fd('\n',file);
	close(file);
}
