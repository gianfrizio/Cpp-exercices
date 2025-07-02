CXX = g++
CXXFLAGS = -std=c++17 -Wall -Werror -Wextra -g -fsanitize=address
SRC = Account.cpp tests.cpp
OBJ = $(SRC:.cpp=.o)
NAME = tests

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
