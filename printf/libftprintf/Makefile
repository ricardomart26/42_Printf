CC = gcc -Wall -Werror -Wextra

NAME = libftprintf.a

SRC = ft_printf.c \
			buffer.c /
			datatypes.c /


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $@ $^ -o $(NAME)

clean: 
	rm -rf $(OBJ)

fclean: clean 
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

