CC = cc
CFLAGS = -Wall -Wextra -Werror
HPATH = headers
SRCS = ./srcs/main.c ./srcs/PipeX.c ./srcs/Utils.c ./srcs/Split.c
OBJS = $(SRCS:.c=.o)
NAME = pipex

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(HPATH) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re