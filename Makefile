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

all: $(NAME_C) $(NAME_S)

$(NAME_C):$(SRC_C) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(SRC_C) $(PRINTF_LIB) -o $(NAME_C)

$(NAME_S):$(SRC_S) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(SRC_S) $(PRINTF_LIB) -o $(NAME_S)

$(PRINTF_LIB):
	make -C $(PRINTF_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C printf clean
	$(RM) $(OBJ)

fclean: clean
	make -C printf fclean

re: fclean all

.PHONY: all clean fclean re