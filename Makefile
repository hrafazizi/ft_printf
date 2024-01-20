
NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_print.c ft_putnbr.c 


OBJS = $(SRCS:.c=.o)



all: $(NAME)

$(NAME): $(OBJS) 
	ar -rc $(NAME) $(OBJS)
%.o: %.c ft_printf.h
	cc $(FLAGS) -c $< -o $@


clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all