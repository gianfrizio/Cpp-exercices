CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Werror -Wextra -g -fsanitize=address

SRCS = main.cpp Bureaucrat.cpp Form.cpp 
OBJS = $(SRCS:.cpp=.o)
NAME = bureaucratformup

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp Bureaucrat.hpp Form.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
