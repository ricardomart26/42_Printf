CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS = convert.c convert2.c check_flags.c ft_printf.c args.c \
	   utils.c validate.c strconv.c intconv.c pconv.c geral.c xconv.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
