# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/01 15:06:48 by lpaulo-d          #+#    #+#              #
#    Updated: 2021/06/01 23:20:07 by lpaulo-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
		ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRC = $(FILES:.c=.o)

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
		ft_lstmap.c
BONUS_SRC = $(BONUS:.c=.o)

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RE = rm -f

all: $(NAME)

$(NAME): $(SRC)
	ar -rcs $(NAME) $(SRC)

$(SRC): $(FILES)
	$(CC) $(FLAGS) -c $(FILES)

bonus: $(BONUS_SRC)
	ar -rcs $(NAME) $(BONUS_SRC)

$(BONUS_SRC): $(BONUS)
	$(CC) $(FLAGS) -c $(BONUS)

clean:
	$(RM) $(SRC) $(BONUS_SRC)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
