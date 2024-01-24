CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = server.c client.c
OBJS = $(SRCS:.c=.o)
NAME = server client

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $@.o -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re