/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_time.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:51:26 by anifanto          #+#    #+#             */
/*   Updated: 2022/07/13 17:36:04 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/containers.hpp"
#include "../includes/utils/time_test.hpp"

void	time_test_vector(int n) {
	if (!n)
		std::cout << MAGENTA << "------------------------------------";
	std::cout << MAGENTA << "\n\tTIME TEST:" << RESET <<std::endl;
	if (!n)
		std::cout << MAGENTA << "------------------------------------" << RESET << std::endl;
	std::cout << std::endl;
	if (!n)
		std::cout << BLUE << "Vector time:" << RESET << std::endl;
	std::clock_t std;
	std::clock_t ft;

	std::vector<int> sv1;
	ft::vector<int> mv1;

	std = vector_insert(200000, sv1);			//200000
	std::cout << "Std: " << std << std::endl;

	ft = vector_insert(200000, mv1);
	std::cout << "Ft : " << ft << std::endl;

	std::cout << "Our vector is " << GREEN << (double)ft / (double)std << RESET << " times slower." << std::endl;

	std::cout << "\nTime test:\t\t\t";
	if (((double)ft / (double)std) < 20.0)
		std::cout << SUCS << std::endl;
	else
		std::cout << FAIL << std::endl;
	std::cout << std::endl;
	return ;
}

void time_test_stack(int n) {
	if (n)
		std::cout << MAGENTA << "\n\tTIME TEST:" << RESET << std::endl << std::endl;
	if (!n)
		std::cout << BLUE << "Stack time" << RESET << std::endl;

	std::clock_t std;
	std::clock_t ft;

	std::stack<int> st1;
	ft::stack<int> ms1;

	std = stack_insert(200000, st1);
	std::cout << "Std: " << std << std::endl;

	ft = stack_insert(200000, ms1);
	std::cout << "Ft : " << ft << std::endl;

	std::cout << "Our stack is " << GREEN << (double)ft / (double)std << RESET << " times slower." << std::endl;

	std::cout << "\nTime test:\t\t\t";
	if (((double)ft / (double)std) < 20.0)
		std::cout << SUCS << std::endl;
	else
		std::cout << FAIL << std::endl;

	std::cout << std::endl;

}

void time_test_map(int n) {
	if (n)
		std::cout << MAGENTA << "\n\tTIME TEST:" << RESET << std::endl << std::endl;
	if (!n)
		std::cout << BLUE << "Map time" << RESET << std::endl;

	// std::clock_t std;
	// std::clock_t ft;

	// std::map<int, bool> sm1;
	// ft::map<int, bool> m1;

	// std = map_insert(200, sm1);
	// std::cout << "Std: " << std << std::endl;

	// ft = map_insert(200, m1);
	// std::cout << "Ft : " << ft << std::endl;

	// std::cout << "Our map is " << GREEN << (double)ft / (double)std << RESET << " times slower." << std::endl;

	// std::cout << "\nTime test:\t\t\t";
	// if (((double)ft / (double)std) < 20.0)
	// 	std::cout << SUCS << std::endl;
	// else
	// 	std::cout << FAIL << std::endl;
	std::cout << std::endl;
}

void	time_test_set(int n)
{
	if (n)
		std::cout << MAGENTA << "\n\tTIME TEST:" << RESET << std::endl << std::endl;
	if (!n)
		std::cout << BLUE << "Set time" << RESET << std::endl;

	// std::clock_t std;
	// std::clock_t ft;

	// std::set<int, bool> sm1;
	// ft::set<int, bool> m1;

	//std = map_insert(200, sm1);
	//std::cout << "Std: " << std << std::endl;

	//ft = map_insert(200, m1);
	//std::cout << "Ft : " << ft << std::endl;

	//std::cout << "Our map is " << GREEN << (double)ft / (double)std << RESET << " times slower." << std::endl;

	std::cout << "\nTime test:\t\t";
	// if (((double)ft / (double)std) < 20.0)
	// 	std::cout << SUCS << std::endl;
	// else
	// 	std::cout << FAIL << std::endl;
	std::cout << std::endl;
}