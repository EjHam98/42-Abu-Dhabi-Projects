CC		= cc
CFLAGS	= -Wall -Wextra -Werror
MAINC	= push_swap.c
SRCS	= stack_essentials.c stack_utils.c extra_utils.c algorithm.c\
		  algorithm_ltf.c str_split_util.c string_utils.c main_utils.c
MAINO	= push_swap.o
OBJS 	= $(SRCS:.c=.o)
NAME 	= push_swap

SRCSB	= checker.c checker_utils.c get_next_line.c get_next_line_utils.c
OBJSB	= $(SRCSB:.c=.o)
NAMEB	= checker

all: $(NAME)

$(NAME): $(OBJS) $(MAINO)
	$(CC) $(CFLAGS) $(MAINO) $(OBJS) -o $(NAME)

bonus: $(OBJS) $(OBJSB)
	$(CC) $(CFLAGS) $(OBJSB) $(OBJS) -o $(NAMEB)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(MAINO)
	rm -rf $(OBJS)
	rm -rf $(OBJSB)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAMEB)

re: fclean all

.PHONY: all clean fclean re