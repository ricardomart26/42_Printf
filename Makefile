
CC = clang

FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

# SRCS = convert.c convert2.c check_flags.c ft_printf.c args.c \
# 	   utils.c validate.c strconv.c intconv.c pconv.c geral.c xconv.c \

SRCS = src/*.c

OBJS = objs/convert.o objs/convert2.o objs/check_flags.o objs/ft_printf.o objs/args.o \
	   objs/utils.o objs/validate.o objs/strconv.o objs/intconv.o objs/pconv.o objs/geral.o objs/xconv.o \
	   objs/newint.o \

all: $(NAME)

objs/%.o : src/%.c
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
