NAME = a.out
HEADER = Animal.hpp	Dog.hpp	Cat.hpp	Brain.hpp

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp	Animal.cpp	Dog.cpp	Cat.cpp	Brain.cpp
OBJ = $(patsubst %.cpp, %.o, $(SRC))

all: $(NAME)
# @make $(NAME) -j4

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $@
	@echo "\033[0;33ma.out\033[0m compiled."

%.o: %.cpp $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
