SRCS = srcs/ft_printf.c srcs/printf_utils.c srcs/ft_print_types.c

OBJS = $(SRCS:.c=.o)

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

%.o: %.c
	$(CC) -c $(CFLAGS) -I./libft $< -o $@

$(NAME): $(OBJS) compile_libft
	ar rcs $(NAME) $(OBJS)

compile_libft:
	$(MAKE) -C libft
	cp libft/libft.a $(NAME)

all:	$(NAME)

libft_clean:
	cd libft && make clean

libft_fclean:
	cd libft && make fclean

clean:
	$(RM) $(OBJS)

fclean: clean libft_fclean
	$(RM) libft.a
	$(RM) $(NAME)

re: fclean all 

.PHONY: LIBFT libft_clean libft_fclean clean fclean all