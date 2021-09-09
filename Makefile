# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/08 16:19:07 by lpaulo-d          #+#    #+#              #
#    Updated: 2021/09/08 16:19:07 by lpaulo-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH_MLX = ./minilibx-linux/
PATH_LIBFT = ./libft/
PATH_SRCS = ./srcs/
PATH_GNL = ./get_next_line/
LIBFT = $(PATH_LIBFT)libft.a
MLX = $(PATH_MLX)libmlx.a

FILES = $(PATH_SRCS)draw.c $(PATH_SRCS)main.c $(PATH_SRCS)parse.c \
		$(PATH_SRCS)utils.c $(PATH_GNL)get_next_line.c \
		$(PATH_GNL)get_next_line_utils.c
SRC = $(FILES:.c=.o)

NAME = fdf
CC = clang
CFLAGS = -Wall -Werror -Wextra
MFLAGS = -I $(PATH_MLX) -L $(PATH_MLX) -lmlx -Ilmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(SRC)
	make -C $(PATH_LIBFT)
	make -C $(PATH_MLX)
	$(CC) $(CFLAGS) $(MFLAGS) $(FILES) $(LIBFT) $(MLX) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(PATH_LIBFT)
	rm -f $(SRC)

fclean: clean
	rm -f $(NAME)
	make clean -C $(PATH_MLX)
	make fclean -C $(PATH_LIBFT)

re: fclean all


re: fclean all
