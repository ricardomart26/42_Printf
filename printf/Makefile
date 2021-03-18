
NAME = libftprintf.a

CCFLAGS = gcc -Wall -Werror -Wextra -I.

GDB = -g

SRC = check.c \
			convert.c \
			ft_printf.c \
			utils.c \
			validate.c \

OBJ = $(SRC:.c=.o)

HEADER = printf.h

all: (NAME)

$(NAME): $(HEADER) $(OBJ)
	$(CCFLAGS) $(SRC) -o $@
	ranlib $(NAME)

gdb: $(HEADER) $(OBJ)
	$(CCFLAGS) $(GDB) $(SRC) -o $@ 

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf printf

re: fclean compile

regdb: fclean gdb

.PHONY: all compile clean fclean re gdb regdb