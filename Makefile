NAME = ft_containers

SRCS = main_test.cpp	tests/test_vector.cpp	tests/test_map.cpp	\
						tests/test_stack.cpp	tests/test_time.cpp	tests/test_set.cpp

HEADERS	= 	includes/vector.hpp		includes/stack.hpp	includes/map.hpp includes/set.hpp\
			includes/containers.hpp includes/iterators/tree_iterator.hpp  includes/utils/node.hpp\
			includes/iterators/iterators_traits.hpp	includes/iterators/random_access_iterator.hpp \
			includes/iterators/reverse_iterator.hpp	includes/utils/utils.hpp			\
			includes/utils/time_test.hpp		includes/utils/red_black_tree.hpp		\

OBJS = $(SRCS:.cpp=.o)

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

all: $(NAME)

$(NAME) : $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
		$(RM) $(NAME)

fclean: clean
		$(RM) $(OBJS)

re: 	fclean all

.PHONY: all clean fclean re
