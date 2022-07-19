/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:11:26 by anifanto          #+#    #+#             */
/*   Updated: 2022/07/14 13:44:02 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/containers.hpp"
#include "includes/utils/time_test.hpp"
#include "includes/set.hpp"	//delete this for test tree

#include <unistd.h>


void test_tree() {
	std::set<int> st_set;
	ft::set<int> my_set;
	for (int i = 65; i > 10; i--)
	{
		st_set.insert(i);
		my_set.insert(i * 2);
	}
	my_set.insert(53);

	for (int i = 5; i < 20; i++)
	{
		st_set.insert(i);
		my_set.insert(i * 2);
	}
	my_set.insert(53);
	my_set.insert(63);
	my_set.insert(60);
	my_set.insert(166);
	my_set.insert(167);
	my_set.insert(168);
	my_set.insert(169);
	my_set.insert(170);
	my_set.insert(113);
	my_set.insert(67);
	my_set.insert(68);
	my_set.insert(69);
	my_set.insert(78);
	my_set.insert(114);
	my_set.insert(127);
	my_set.insert(129);
	my_set.erase(53);
	my_set.erase(114);
	my_set.erase(113);
	my_set.erase(68);
	my_set.erase(82);
	my_set.PrintTree();
}

int main(void)
{
	std::string input;
	std::cout << MAGENTA << "\n\t\tEnter the name of the container:" << std::endl;
	std::cout << "\t\tVECTOR, STACK, MAP, SET, ALL" << RESET << std::endl;
	std::cout << "\n>>  ";
	std::cin >> input;
	for (unsigned int i = 0; i < input.size(); i++)
		input[i] = (char)toupper(input[i]);
	while (1){
		if (input == "VECTOR"){
			test_vector();
			time_test_vector(1);
			break ;
		}
		else if (input == "STACK"){
			test_stack();
			time_test_stack(1);
			break ;
		}
		else if (input == "SET"){
			test_set();
			time_test_set(1);
			break ;
		}
		else if (input == "MAP"){
			test_map();
			time_test_map(1);
			break ;
		}
		else if (input == "TREE"){			//DELETE
			test_tree();
			break ;
		}
		else if (input == "ALL"){
			test_vector();
			test_stack();
			test_map();
			test_set();
			time_test_vector(0);
			time_test_stack(0);
			time_test_map(0);
			time_test_set(0);
			break ;
		}
		else{
			std::cout << RED << "ERROR COMMAND" << RESET << std::endl;
			break ;
		}
	}

	usleep(10);
	return (0);
}
