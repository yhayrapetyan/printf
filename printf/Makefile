SRC =	ft_print_char.c \
		ft_print_str.c \
		ft_print_int.c \
		ft_print_precent.c \
		ft_print_hex.c \
		ft_print_unsigned.c \
		ft_print_ptr.c \
		ft_printf.c

OBJS = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME =libftprintf.a
RM = rm -r
AR = ar rc
LIB_INDEX = ranlib

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@$(LIB_INDEX) $(NAME)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
