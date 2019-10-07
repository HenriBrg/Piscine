# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hberger <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/21 13:22:20 by hberger           #+#    #+#              #
#    Updated: 2019/06/25 21:42:55 by hberger          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file
SRCS = ft_display_file.c
OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): ${OBJS}
	gcc -Wall -Wextra -Werror ${SRCS} -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
