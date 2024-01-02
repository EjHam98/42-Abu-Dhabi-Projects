GCC = c++
GCCFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = megaphone.cpp
OBJS = megaphone.o
NAME = megaphone

all: $(NAME)

$(NAME): $(OBJS)
	$(GCC) $(GCCFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(GCC) $(GCCFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re