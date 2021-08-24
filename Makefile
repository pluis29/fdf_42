# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/24 15:48:22 by lpaulo-d          #+#    #+#              #
#    Updated: 2021/08/24 15:48:22 by lpaulo-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

F_PATH = ./src

FILES = $(F_PATH)/main.c

CC = clang
CFLAGS = 
RM = rm -rf

all:
	clang $(FILES) -o fdf

clean:
	$(RM) fdf
