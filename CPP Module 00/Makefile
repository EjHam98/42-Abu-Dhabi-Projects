# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/26 09:28:37 by ehammoud          #+#    #+#              #
#    Updated: 2024/03/06 21:03:10 by ehammoud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		  = cc
CFLAGS	  = -Wall -Wextra -Werror
SRCS	  = main.c map_utils.c hook_handles.c render_utils.c extra_utils.c\
		    get_next_line.c get_next_line_utils.c animation.c utils.c
OBJS	  = $(SRCS:.c=.o)
SRCSBONUS = main.c map_utils.c hook_handles.c render_utils.c extra_utils.c\
		    get_next_line.c get_next_line_utils.c animation.c utils_bonus.c
OBJSBONUS = $(SRCSBONUS:.c=.o)
NAME	  = so_long
MLX		  = mlx
OGLFLAGS  = -L$(MLX) -lmlx -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(MLX)
	$(CC) $(CFLAGS) $(OGLFLAGS) $(OBJS) -o $(NAME)

bonus: $(OBJSBONUS)
	make -C $(MLX)
	$(CC) $(CFLAGS) $(OGLFLAGS) $(OBJSBONUS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	make clean -C $(MLX)
	rm -rf so_long

re: fclean all

.PHONY: all clean fclean re
