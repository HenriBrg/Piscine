# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hberger <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/22 11:14:57 by hberger           #+#    #+#              #
#    Updated: 2019/06/22 13:59:05 by hberger          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02

all: $(NAME)

$(NAME):
	cc -Wall -Wextra -Werror *.c -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
