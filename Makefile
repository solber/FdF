# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wnoth <wnoth@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 11:18:55 by wnoth             #+#    #+#              #
#    Updated: 2017/11/27 11:49:25 by wnoth            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf

FILES		= src/build.c \
				src/draw_line.c \
				src/draw.c \
				src/error.c \
				src/keyhook.c \
				src/main.c \
				src/movemap.c \
				src/point_rotation.c \
				src/point.c \
				src/read.c

OBJECTS = $(FILES:.c=.o)

CFLAG = -Wall -Werror -Wextra

ATTACH = -I libft -Llibft/ -lft -I minilibx -Lminilibx/ -lmlx -framework OpenGL -framework AppKit

#Colors
_GREY=\x1b[30m
_RED=\x1b[31m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_BLUE=\x1b[34m
_PURPLE=\x1b[35m
_CYAN=\x1b[36m
_WHITE=\x1b[37m
_END=\x1b[0m

all: $(NAME)

$(NAME):
	@make -C libft/
	@gcc $(CFLAG) -I libft/ -c $(FILES)
	@mv *.o src/
	@gcc $(CFLAG) -o $(NAME) $(OBJECTS) $(ATTACH) 

clean:
	@rm -f $(OBJECTS)
	@echo "clean FDF: $(_GREEN)DONE$(_END)"
	@make -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	@echo "fclean FDF: $(_GREEN)DONE$(_END)"
	@make -C libft/ fclean

re: fclean all
