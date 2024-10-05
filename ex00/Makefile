NAME = megaphone
HEADER = 

CC = c++
# -g -fsanitize=thread
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = megaphone.cpp
OBJ = $(patsubst %.cpp, %.o, $(SRC))

all:
	@make $(NAME) -j4

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $@
	@echo "\033[0;33mmegaphone\033[0m compiled."

%.o: %.cpp $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
