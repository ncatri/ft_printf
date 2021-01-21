SRCS = srcs/ft_printf.c \
	   srcs/utils.c \
	   srcs/utils2.c \
	   srcs/utils_flags.c \
	   srcs/utils_int.c \
	   srcs/print_char_str.c \
	   srcs/modifiers.c \
	   srcs/print_u_int.c \
	   srcs/print_pointer.c

OBJS = $(SRCS:.c=.o)

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

NAME = libftprintf.a

INCLUDE = include/ft_printf.h

%.o: %.c
	$(CC) -c $(CFLAGS) -I./libft $< -o $@

$(NAME): $(OBJS) compile_libft $(INCLUDE) 
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

.PHONY: LIBFT libft_clean libft_fclean clean fclean all re
