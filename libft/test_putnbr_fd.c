#include "libft.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int file = open("file", O_CREAT | O_WRONLY | O_APPEND, 0644);
	ft_putnbr_fd(-123456789, file);
	close(file);
}
