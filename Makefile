NAME = ft_containers

NAME_M = ft_tests

#.SILENT:

SRCS = main_test.cpp	tests/test_vector.cpp	tests/test_map.cpp	\
						tests/test_stack.cpp	tests/test_time.cpp	tests/test_set.cpp

SRCS_S = main.cpp

HEADERS	= 	includes/vector.hpp		includes/stack.hpp	includes/map.hpp includes/set.hpp\
			includes/containers.hpp includes/iterators/tree_iterator.hpp  includes/utils/node.hpp\
			includes/iterators/iterators_traits.hpp	includes/iterators/random_access_iterator.hpp \
			includes/iterators/reverse_iterator.hpp	includes/utils/utils.hpp			\
			includes/utils/time_test.hpp		includes/utils/red_black_tree.hpp		\

OBJS = $(SRCS:.cpp=.o)

OBJS_S = $(SRCS_S:.cpp=.o)

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

RESET = "\033[0m"
BLACK = "\033[1m\033[37m"
CUT = "\033[K"
DOWN = "\033[B"
UP = "\033[A"
SAVE = "\033[s"

all: $(NAME)

$(NAME) : $(OBJS) $(OBJS_S) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME_M)
	$(CXX) $(CXXFLAGS) $(OBJS_S) -o $(NAME)
	@echo $(BLACK)-ft_containers compiled 🌏 $(RESET)

clean:
		$(RM) $(NAME) $(NAME_M)

fclean: clean
		$(RM) $(OBJS) $(OBJS_S)
		@echo OBJ files removed

re: 	fclean all

.PHONY: all clean fclean re
