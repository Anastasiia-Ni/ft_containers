NAME = ft_containers

NAME_M = ft_tests

.SILENT:

SRCS = 	main_test.cpp	\
		tests/test_vector.cpp	\
		tests/test_stack.cpp	\
		tests/test_map.cpp		\
		tests/test_set.cpp		\
		tests/test_time.cpp

SRCS_S = main.cpp

HEADERS	= 	includes/vector.hpp		

OBJS = $(SRCS:.cpp=.o)

OBJS_S = $(SRCS_S:.cpp=.o)

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

RESET = "\033[0m"
BLACK = "\033[1m\033[37m"

all: $(NAME)

$(NAME) : $(OBJS) $(OBJS_S) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME_M)
	$(CXX) $(CXXFLAGS) $(OBJS_S) -o $(NAME)
	@echo $(BLACK)ft_containers compiled 🌏 $(RESET)

clean:
		$(RM) $(NAME) $(NAME_M)

fclean: clean
		$(RM) $(OBJS) $(OBJS_S)
		@echo $(BLACK)OBJ files removed $(RESET)

re: 	fclean all

.PHONY: all clean fclean re
