SRCS		= ft_printf.c ft_putchar.c	ft_putnbr.c	ft_tounsigned.c ft_puthex.c	ft_putstr.c ft_atoi.c
OBJS		= ${SRCS:.c=.o}
NAME		= libftprintf.a
GG			= gcc
GFLAGS		= -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	$(GG) $(GFLAGS) -c $< -o $@ 

$(NAME): $(OBJS)
	ar -rcs $(NAME) $^

bonus: $(OBJS)
	ar -rcs $(NAME) $^

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
