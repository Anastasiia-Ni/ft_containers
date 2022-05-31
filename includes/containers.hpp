#ifndef CONTAINERS_HPP
# define CONTAINERS_HPP

//#pragma once

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <memory>
#include <iostream>
#include <limits>
#include <utility>
#include <functional>

#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"
//#include "list.hpp"
//#include "Queue.hpp"

#define RESET		"\033[0m"
#define BLACK		"\033[30m"
#define RED			"\033[31m"
#define GREEN		"\033[32m"
#define YELLOW		"\033[33m"
#define BLUE		"\033[34m"
#define MAGENTA		"\033[35m"
#define CYAN		"\033[36m"
#define WHITE		"\033[37m"
#define SUCS        "\033[1m\033[32mOK\033[0m"        //✅"
#define FAIL        "\033[1m\033[31mKO\033[0m"        //❌"

int     test_vector();
// int     test_list();
int     test_map();
// int     test_queue();
int     test_stack();

#endif