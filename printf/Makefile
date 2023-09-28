NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_flag.c \
	ft_put_address.c \
	ft_put_hexs.c \
	ft_put_unsint.c \
	ft_printf.c \
	ft_put_char.c \
	ft_put_nbr.c \
	ft_put_hexl.c \
	ft_put_str.c \
	ft_memset.c

OBJ = $(SRC:.c=.o)
RM = rm -f
AR = ar -rc

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(BONUS:.c=.o)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re