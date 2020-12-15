#include "libft.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int file = open("file", O_CREAT | O_WRONLY | O_APPEND, 0644);
	ft_putstr_fd("This is a test string", file);
	close(file);
}
