NAME = animaltest
CXX = c++
CXXFLAGS = -std=c++17 -Wall -Werror -Wextra -g -fsanitize=address

SRC = main.cpp \
      Animal.cpp Dog.cpp Cat.cpp \
      WrongAnimal.cpp WrongCat.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
