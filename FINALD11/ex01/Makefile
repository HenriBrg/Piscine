# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hberger <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/20 19:36:31 by hberger           #+#    #+#              #
#    Updated: 2019/06/21 12:04:17 by hberger          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = srcs/ft_putchar.c srcs/ft_swap.c \
	  srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS = ${SRCS:.c=.o}
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

.c.o:
	${CC} ${CFLAGS} -I ./includes/ -c $< -o $@

$(NAME): ${OBJS}
	ar rcs $(NAME) $(OBJS)

clean:
	${RM} $(OBJS)

fclean: clean
	${RM} $(NAME)

re: fclean all

.PHONY: all clean fclean re
