NAME = sudoku

SRC = sources/main.c \
	sources/grid.c \
	sources/utils.c \
	sources/valid.c


all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -Iincludes $(SRC) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
