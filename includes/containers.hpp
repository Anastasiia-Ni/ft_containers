/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   containers.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:42:47 by anifanto          #+#    #+#             */
/*   Updated: 2022/06/11 15:32:59 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTAINERS_HPP
# define CONTAINERS_HPP

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
#include <stdexcept>
#include <cstddef>

#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#include "iterators.hpp"
#include "utils.hpp"

#define RESET		"\033[0m"
#define BLACK		"\033[30m"
#define RED			"\033[31m"
#define GREEN		"\033[32m"
#define YELLOW		"\033[33m"
#define BLUE		"\033[34m"
#define MAGENTA		"\033[35m"
#define CYAN		"\033[36m"
#define WHITE		"\033[37m"
#define SUCS		"\033[1m\033[32mOK\033[0m"        //✅"
#define FAIL		"\033[1m\033[31mKO\033[0m"        //❌"

int		test_vector();
int		test_map();
int		test_stack();

#endif