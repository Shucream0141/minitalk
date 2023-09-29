CC = CC
CFLAGS = -Wall -Wextra -Werror

NAME_S = server
NAME_C = client

SRC_C = client.c
SRC_S = server.c

OBJ = client.o \
	server.o

RM = rm -f
PRINTF_PATH = ./printf
PRINTF_LIB = ./printf/libftprintf.a
LIBFT_PATH = ./libft
LIBFT_LIB = ./libft/libft.a

all: $(NAME_C) $(NAME_S)

$(NAME_C):$(SRC_C) $(PRINTF_LIB) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(SRC_C) $(PRINTF_LIB) $(LIBFT_LIB) -o $(NAME_C)

$(NAME_S):$(SRC_S) $(PRINTF_LIB) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(SRC_S) $(PRINTF_LIB) $(LIBFT_LIB) -o $(NAME_S)

$(PRINTF_LIB):
	make -C $(PRINTF_PATH)

$(LIBFT_LIB):
	make -C $(LIBFT_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C printf clean
	make -C libft clean
	$(RM) $(OBJ)

fclean: clean
	make -C printf fclean
	make -C libft fclean
	$(RM) $(NAME_C) $(NAME_S)

re: fclean all

.PHONY: all clean fclean re