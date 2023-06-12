/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_test.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:51:02 by anifanto          #+#    #+#             */
/*   Updated: 2022/07/12 15:51:03 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_TEST_HPP
#define TIME_TEST_HPP

#include <ctime>
#include <iostream>
#include <map>
#include <stack>
#include <vector>
#include <set>

class time_test
{
	private:
		std::clock_t _start;

	public:
		time_test() {
			_start = 0;
		}

		time_test(const time_test &other) {
			this->_start = other._start;
		}

		time_test &operator=(const time_test &rhs) {
			this->_start = rhs._start;
			return (*this);
		}

		~time_test() {}

		void start() {
			this->_start = std::clock();
		}

		std::clock_t stop() {
			return (std::clock() - this->_start);
		}
};

template <typename vector_type>
std::clock_t vector_insert(size_t count, vector_type vector)
{
	time_test	t;
	int			tmp;

	t.start();
	tmp = 0;
	for (size_t i = 0; i < count; i++)
	{
		vector.push_back(i);
		tmp = vector[i];
	}
	vector_type new_vec(vector);
	(void)tmp;
	vector.erase(vector.begin(), vector.end());
	return (t.stop());
}

template <typename stack_type>
std::clock_t stack_insert(size_t count, stack_type stack)
{
	time_test t;
	t.start();

	int tmp = 0;

	for (size_t i = 0; i < count; i++)
	{
		stack.push(i);
	}
	{
		stack_type new_st(stack);
	}

	for (size_t i = 0; i < count; i++)
	{
		tmp = stack.top();
		stack.pop();
	}
	(void)tmp;
	return (t.stop());
}

template <typename map_type>
std::clock_t map_insert(size_t count, map_type map)
{
	time_test t;
	t.start();

	for (size_t i = 0; i < count; i++)
	{
		map[i] = true;
		map.find(i);
	}
	{
		map_type new_map(map);
	}

	return (t.stop());
}

template <typename set_type>
std::clock_t set_insert(size_t count, set_type set)
{
	time_test t;
	t.start();

	for (size_t i = 0; i < count; i++)
	{
		set.insert(i);
		set.find(i);
	}
	{
		set_type new_set(set);
	}

	return (t.stop());
}

void	time_test_vector(int n);
void	time_test_stack(int n);
void	time_test_map(int n);
void	time_test_set(int n);

#endif
