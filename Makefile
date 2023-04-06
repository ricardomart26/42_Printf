CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS = srcs/convert.o srcs/convert2.o srcs/check_flags.o srcs/ft_printf.o srcs/args.o \
	   srcs/utils.o srcs/validate.o srcs/strconv.o srcs/intconv.o srcs/pconv.o \
	   srcs/negint.o srcs/uint_x.o srcs/utils2.o srcs/negint2.o srcs/intspecial.o \


OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME) : $(OBJS)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)

objs/%.o : src/%.c
	$(CC) $(FLAGS) -c $< -o $@

bonus: $(OBJS)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
