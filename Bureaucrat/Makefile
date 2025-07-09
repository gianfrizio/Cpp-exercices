CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Werror -Wextra -g -fsanitize=address

SRCS = main.cpp Bureaucrat.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = bureaucrat

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp Bureaucrat.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
