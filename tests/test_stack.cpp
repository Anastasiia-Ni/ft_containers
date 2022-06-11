/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:11:10 by anifanto          #+#    #+#             */
/*   Updated: 2022/06/11 19:25:52 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/containers.hpp"

static void empty_test() {
	std::cout << "Test empty:\t\t\t";
	std::stack<int, std::vector<int> > std_stack;
	ft::stack<int, ft::vector<int> > my_stack;
	if (std_stack.empty() != my_stack.empty())
	{
		std::cout << FAIL << std::endl;
		return ;
	}
	std_stack.push(42);
	my_stack.push(42);
	if (std_stack.empty() != my_stack.empty())
	{
		std::cout << FAIL << std::endl;
		return ;
	}
	std::cout << SUCS << std::endl;
}

static void size_test() {
	std::cout << "Test size:\t\t\t";
	std::stack<int, std::vector<int> > std_stack;
	ft::stack<int, ft::vector<int> > my_stack;
	if (std_stack.size() != my_stack.size())
	{
		std::cout << FAIL << std::endl;
		return ;
	}
	for(int i = 0; i < 10; i++)
	{
		std_stack.push(11);
		my_stack.push(11);
	}
	if (std_stack.size() != my_stack.size())
	{
		std::cout << FAIL << std::endl;
		return ;
	}
	std::cout << SUCS << std::endl;

}

static void top_test() {
	std::cout << "Test top:\t\t\t";
	std::stack<int, std::vector<int> > std_stack;
	ft::stack<int, ft::vector<int> > my_stack;
	if (std_stack.size() != my_stack.size())
	{
		std::cout << FAIL << std::endl;
		return ;
	}
	std_stack.push(42);
	my_stack.push(42);
	if (std_stack.top() != my_stack.top())
	{
		std::cout << "std stack top - " << std_stack.top() << std::endl; // delete
		std::cout << "my stack top - " << my_stack.top() << std::endl; // delete
		std::cout << FAIL << std::endl;
		return ;
	}
	std::cout << SUCS << std::endl;
}

static void pop_test() {
	std::cout << "Test pop:\t\t\t";
	std::stack<int, std::vector<int> > std_stack;
	ft::stack<int, ft::vector<int> > my_stack;
	std_stack.push(42);
	my_stack.push(42);
	std_stack.push(11);
	my_stack.push(11);
	if (std_stack.size() != my_stack.size())
	{
		std::cout << FAIL << std::endl;
		return ;
	}
	my_stack.pop();
	std_stack.pop();
	my_stack.pop();
	std_stack.pop();
	if (std_stack.empty() != my_stack.empty())
	{
		std::cout << FAIL << std::endl;
		return ;
	}
	std::cout << SUCS << std::endl;

}

static void push_test() {
	std::cout << "Test push:\t\t\t";
	std::stack<int, std::vector<int> > std_stack;
	ft::stack<int, ft::vector<int> > my_stack;
	std_stack.push(42);
	my_stack.push(42);
	if (std_stack.size() != my_stack.size())
	{
		std::cout << FAIL << std::endl;
		return ;
	}
	std_stack.push(11);
	my_stack.push(11);
	if (std_stack.size() != my_stack.size())
	{
		std::cout << FAIL << std::endl;
		return ;
	}
	std::cout << SUCS << std::endl;
}

static void compare_test() {
	std::cout << "Test compare:\t\t\t";
	std::stack<int, std::vector<int> > std_stack1;
	ft::stack<int, ft::vector<int> > my_stack1;
	std::stack<int, std::vector<int> > std_stack2;
	ft::stack<int, ft::vector<int> > my_stack2;
	my_stack1.push(42);
	std_stack1.push(42);
	my_stack2.push(11);
	std_stack2.push(11);
	if ((my_stack1 == my_stack2) != (std_stack1 == std_stack2))
	{
		std::cout << FAIL << std::endl;
		return ;
	}
	if ((my_stack1 != my_stack2) != (std_stack1 != std_stack2))
	{
		std::cout << FAIL << std::endl;
		return ;
	}
	if ((my_stack1 > my_stack2) != (std_stack1 > std_stack2))
	{
		std::cout << FAIL << std::endl;
		return ;
	}
	if ((my_stack1 >= my_stack2) != (std_stack1 >= std_stack2))
	{
		std::cout << FAIL << std::endl;
		return ;
	}
	if ((my_stack1 < my_stack2) != (std_stack1 < std_stack2))
	{
		std::cout << FAIL << std::endl;
		return ;
	}
	if ((my_stack1 <= my_stack2) != (std_stack1 <= std_stack2))
	{
		std::cout << FAIL << std::endl;
		return ;
	}
	std::cout << SUCS << std::endl;
}

static void default_test () {
	std::cout << BLUE << "STD STACK" << RESET << std::endl;
	std::vector<int> std_vec(100);
	std::stack<int, std::vector<int> > std_stack1;
	std::stack<int, std::vector<int> > std_stack2(std_vec);
	std::cout << "Size of first: " << std_stack1.size() << std::endl;
	std::cout << "Size of second: " << std_stack2.size() << std::endl;

	std::cout << BLUE << "MY STACK" << RESET << std::endl;
	ft::vector<int> my_vec(100);
	ft::stack<int, ft::vector<int> > my_stack1; // - leaks, check again
	ft::stack<int, ft::vector<int> > my_stack2(my_vec);
	std::cout << "Size of first: " << my_stack1.size() << std::endl;
	std::cout << "Size of second: " << my_stack2.size() << std::endl;
	std::cout << BLUE << "------------------------------------" << RESET << std::endl;
	std::cout << "Test default constructor:\t";
	if (std_stack2.size() != my_stack2.size())
		std::cout << FAIL << std::endl;
	else
		std::cout << SUCS << std::endl;

}

int test_stack( void ){
	std::cout << MAGENTA << "------------------------------------" << std::endl;
	std::cout << "\tSTACK TESTER IS HERE" << std::endl;
	std::cout << "------------------------------------" << RESET << std::endl;

	default_test ();
	empty_test();
	size_test();
	top_test();
	pop_test();
	push_test();
	compare_test();

	return (0);
}