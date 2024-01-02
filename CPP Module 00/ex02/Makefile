GCC = c++
GCCFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = tests.cpp Account.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = globalbank

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