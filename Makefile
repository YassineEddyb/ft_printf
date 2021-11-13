SRCS		= ft_putchar.c	ft_putnbr.c	ft_tounsigned.c ft_puthex.c	ft_putstr.c
OBJS		= ${SRCS:.c=.o}
NAME		= libftprintf.a
GG			= gcc
GFLAGS		= -Wall -Wextra -Werror

all: $(NAME)

%.o; %.c
	$(GG) $(GFLAGS) -c $< -o $@ 

$(NAME): $(OBJS)
	ar -rcs $(NAME) $^

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
