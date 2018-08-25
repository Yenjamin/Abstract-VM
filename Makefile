NAME = avm

CC = g++ -Wall -Werror -Wextra

FILES = main.cpp \
	reader.class.cpp \
	errors.class.cpp \
	run.class.cpp \
	factory.class.cpp

SRC := $(addprefix srcs/, $(FILES))

OBJ = $(SRC:.cpp=.o)

INC = -I includes/

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(INC) -o $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
