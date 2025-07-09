# Compiler
CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Werror -Wextra -g -fsanitize=address

# Files
SRCS = main.cpp \
       AMateria.cpp Ice.cpp Cure.cpp \
       Character.cpp MateriaSource.cpp

OBJS = $(SRCS:.cpp=.o)

HEADERS = AMateria.hpp Ice.hpp Cure.hpp \
          ICharacter.hpp Character.hpp \
          IMateriaSource.hpp MateriaSource.hpp

# Executable name
NAME = materia

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
