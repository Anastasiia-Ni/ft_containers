/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:41:57 by anifanto          #+#    #+#             */
/*   Updated: 2022/06/06 14:38:38 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/containers.hpp"

#include<iostream>
#include<iterator> // for iterators
#include<vector> // for vectors

int main(void)
{
	std::string input;
	std::cout << MAGENTA << "\n\t\tEnter the name of the container:" << std::endl;
	std::cout << "\t\tVECTOR, STACK, MAP, SET, ALL" << std::endl;
	std::cout << "\n>>  ";
	std::cin >> input;
	for (unsigned int i = 0; i < input.size(); i++)
		input[i] = (char)toupper(input[i]);
	//std::cout << input << std::endl << std::endl; // delete
	while (1){
		if (input == "VECTOR"){
			test_vector();
			break ;
		}
		else if (input == "STACK"){
			test_stack();
			break ;
		}
		else if (input == "SET"){
			//test_set();
			break ;
		}
		else if (input == "MAP"){
			test_map();
			break ;
		}
		else if (input == "ALL"){
			test_vector();
			test_stack();
			test_map();
			// test_set();
			break ;
		}
		else{
			std::cout << RED << "ERROR COMMAND" << std::endl;
			break ;
		}
	}
	//run_tests();

	std::cout << MAGENTA << "\nTIME TEST:" << std::endl << std::endl;
	// time_tests_map();
	// time_tests_vector();
	// time_tests_stack();
	//sleep(10);
	//std::vector<int> ar = {1, 2, 3, 4, 5};
	std::vector<int>::reverse_iterator ptr;
	//ptr.current
	return (0);
}
