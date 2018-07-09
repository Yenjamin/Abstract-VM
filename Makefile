NAME = avm

SRC = main.cpp \

FLAGS = -Wall -Werror -Wextra

INCLUDE = *.hpp

all: $(NAME)

$(NAME):
	clang++ -o $(NAME) $(SRC)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all
