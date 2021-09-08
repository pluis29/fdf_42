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
LIBFT = $(PATH_LIBFT)libft.a
MLX = $(PATH_MLX)mlx.a

FILES = $(PATH_SRCS)bresenham.c $(PATH_SRCS)controls.c $(PATH_SRCS)magic.c \
		$(PATH_SRCS)main.c $(PATH_SRCS)parse.c $(PATH_SRCS)utils.c


CC = clang
CFLAGS = -Wall -Werror -Wextra
MFLAGS = -I $(PATH_MLX) -L $(PATH_MLX) -lmlx -Ilmlx -lXext -lX11