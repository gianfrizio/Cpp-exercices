CC = g++
SRC = megaphone.cpp
OBJ = ${SRC:.cpp=.o}
CFLAGS = -std=c++17 -Wall -Werror -Wextra -g -fsanitize=address
NAME = megaphone

all: $(NAME)

$(NAME): $(OBJ) Makefile
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
    
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.cpp.o: Makefile
	$(CC) $(CFLAGS) -o $@ -c $<
    
.PHONY: all clean fclean re
