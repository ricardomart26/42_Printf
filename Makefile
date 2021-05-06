CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS = src/*.c

OBJS = objs/convert.o objs/convert2.o objs/check_flags.o objs/ft_printf.o objs/args.o \
	   objs/utils.o objs/validate.o objs/strconv.o objs/intconv.o objs/pconv.o \
	   objs/negint.o objs/uint_x.o objs/utils2.o objs/negint2.o objs/intspecial.o \

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
