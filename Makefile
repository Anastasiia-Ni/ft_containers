NAME = ft_containers

SRCS = main_test.cpp	tests/test_vector.cpp	tests/test_map.cpp	\
						tests/test_stack.cpp	tests/test_time.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

compile : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all: compile

clean:
		rm -rf $(NAME)

fclean: clean
		rm -rf $(OBJS)

re: 	fclean all

.PHONY: all clean fclean re
