/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:51:21 by anifanto          #+#    #+#             */
/*   Updated: 2022/07/12 20:20:31 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/containers.hpp"
#include "../includes/set.hpp"


// int setn()
// {
//     std::set<int> mySet;

//     mySet.insert(5);
//     mySet.insert(1);
//     mySet.insert(12);
//     mySet.insert(4);
//     mySet.insert(-1);


//     for (int i = 0; i < 20; i++)
//     {
//         mySet.insert(rand() % 20);
//     }

//     for (auto &item : mySet)
//     {
//         std::cout << item << std::endl;
//     }
//}

template <typename T>
bool	check_iterator(std::set<T> &st_set, ft::set<T> &my_set) {
	typename std::set<T>::iterator it_st = st_set.begin();
	typename ft::set<T>::iterator it_my = my_set.begin();
	while (it_st != st_set.end()){
		if (*it_st != *it_my)
			return false;
		++it_st;
		++it_my;
	}
	return true;
}

static void test_constructor() {
	std::cout << "Default constructor test:\t";
	//std::cout << "not ready" << std::endl; //DELETE
	std::set<int> st_set;
	ft::set<int> my_set;
	if (st_set.size() != my_set.size()){
		 std::cout << FAIL << std::endl;
		 return ;
	}
	if (!check_iterator(st_set, my_set)){
		 std::cout << FAIL << std::endl;
		 return ;
	}
	std::set<std::string> st_set1;
	ft::set<std::string> my_set1;
	if (st_set1.size() != my_set1.size()){
		 std::cout << FAIL << std::endl;
		 return ;
	}
		if (!check_iterator(st_set1, my_set1)){
		 std::cout << FAIL << std::endl;
		 return ;
	}
	std::set<int> st_set2(st_set.begin(), st_set.end());
	ft::set<int> my_set2(my_set.begin(), my_set.end());
	if (st_set2.size() != my_set2.size()){
		 std::cout << FAIL << std::endl;
		 return ;
	}
	if (!check_iterator(st_set2, my_set2)){
		 std::cout << FAIL << std::endl;
		 return ;
	}
	std::set<int> st_set3;
	ft::set<int> my_set3;
	st_set3 = st_set;
	my_set3 = my_set;
	if (st_set3.size() != my_set3.size()){
		 std::cout << FAIL << std::endl;
		 return ;
	}
	if (!check_iterator(st_set3, my_set3)){
		 std::cout << FAIL << std::endl;
		 return ;
	}
	std::cout << SUCS << std::endl;
}

static void	test_size() {
	std::cout << "Size test:\t\t\t";
	std::set<int> st_set;
	ft::set<int> my_set;
	if (st_set.size() != my_set.size()){
		 std::cout << FAIL << std::endl;
		 return ;
	}
	for (int i = 0; i < 20; i++)
	{
		my_set.insert(i * 10);
		st_set.insert(i * 10);
	}
	if (st_set.size() != my_set.size()){
		 std::cout << FAIL << std::endl;
		 return ;
	}
	std::cout << SUCS << std::endl;
}

static void	test_max_size() {
	std::cout << "Max_size test:\t\t\t";
	//std::cout << "not ready" << std::endl; //DELETE
	std::set<int> st_set;
	ft::set<int> my_set;
	if (st_set.max_size() != my_set.max_size()){
		std::cout << FAIL << std::endl;
		std::cout << "std set  " << st_set.max_size() << std::endl; //delete   461168601842738790 - from setual 
		std::cout << "my set   " << my_set.max_size() << std::endl; //delete
		return ;
	}
	std::cout << SUCS << std::endl;

}

static void	test_begin_end() {
	std::cout << "Begin/end test:\t\t\t";
	std::set<int> sets;
	for (int i = 0; i < 20; i++)
		sets.insert(i * 10);

	//попробовать распечатать дерево
	std::set<int> st_set(sets.begin(), sets.end());
	ft::set<int> my_set(sets.begin(), sets.end());
	std::set<int>::iterator its = st_set.begin();
	ft::set<int>::iterator itm = my_set.begin();
	if (st_set.size() != my_set.size()){
		std::cout << FAIL << std::endl;
		return ;
	}
	if (!check_iterator(st_set, my_set)){
		std::cout << FAIL << std::endl;
		return ;
	}
	if (*its != *itm) {
		std::cout << FAIL << std::endl;
		return ;
	}
	std::set<int, int>::iterator its1 = st_set.end();
	ft::set<int, int>::iterator itm1 = my_set.end();
	if (*its1 != *itm1){
		std::cout << FAIL << std::endl;
		return ;
	}
	std::cout << SUCS << std::endl;
}

static void	test_insert() {
	std::cout << "Insert test:\t\t\t";
	//попробовать распечатать дерево
	std::set<int> st_set;
	ft::set<int> my_set;
	for (int i = 5; i < 20; i++)
	{
		st_set.insert(i);
		my_set.insert(i);
	}
	if (st_set.size() != my_set.size()){
		 std::cout << FAIL << std::endl;
		 return ;
	}
	if (!check_iterator(st_set, my_set)){
		 std::cout << FAIL << std::endl;
		 return ;
	}
	st_set.clear();
	my_set.clear();
	if (st_set.size() != my_set.size()){
		 std::cout << FAIL << std::endl;
		 return ;
	}
	if (!check_iterator(st_set, my_set)){
		 std::cout << FAIL << std::endl;
		 return ;
	}
	std::cout << SUCS << std::endl;
}

static void	test_empty() {
	std::cout << "Empty test:\t\t\t";
	std::set<int> st_set;
	ft::set<int> my_set;
	if (st_set.empty() != my_set.empty()){
		 std::cout << FAIL << std::endl;
		 return ;
	}
	std::cout << SUCS << std::endl;
}

static void	test_erase() {
	std::cout << "Erase test:\t\t\t";
	//std::cout << "not ready" << std::endl; //DELETE
	
	const int arr_size = 8;
	int arr[arr_size] = {1, 1, 2, 2, 1, 3, 2, 3};
	std::set<int> st_set(arr, arr + arr_size);
	ft::set<int> my_set(arr, arr + arr_size);
	if (st_set.size() != my_set.size()){
		std::cout << FAIL << std::endl;
		return ;
	}
	if (!check_iterator(st_set, my_set)){
		std::cout << FAIL << std::endl;
		return ;
	}
	st_set.erase(++st_set.begin());
	my_set.erase(++my_set.begin());
	if (st_set.size() != my_set.size()){
		std::cout << FAIL << std::endl;
		return ;
	}
	if (!check_iterator(st_set, my_set)){
		std::cout << FAIL << std::endl;
		return ;
	}
	st_set.erase(++st_set.begin(), --st_set.end());
	my_set.erase(++my_set.begin(), --my_set.end());
	if (st_set.size() != my_set.size()){
		std::cout << FAIL << std::endl;
		return ;
	}
	if (!check_iterator(st_set, my_set)){
		std::cout << FAIL << std::endl;
		return ;
	}
	st_set.erase(1);
	my_set.erase(1);
	if (st_set.size() != my_set.size()){
		 std::cout << FAIL << std::endl;
		 return ;
	}
	if (!check_iterator(st_set, my_set)){
		 std::cout << FAIL << std::endl;
		 return ;
	}
	st_set.erase(3);
	my_set.erase(3);
	if (st_set.size() != my_set.size()){
		 std::cout << FAIL << std::endl;
		 return ;
	}
	if (!check_iterator(st_set, my_set)){
		 std::cout << FAIL << std::endl;
		 return ;
	}
	std::cout << SUCS << std::endl;
}

static void	test_swap() {
	std::cout << "Swap test:\t\t\t";	
	std::set<int> st_set;
	ft::set<int> my_set;
	std::set<int> st_set1;
	ft::set<int> my_set1;
	for (int i = 5; i < 20; i++)
	{
		st_set.insert(i);
		my_set.insert(i);
	}
	if (st_set.size() != my_set.size()){
		 std::cout << FAIL << std::endl;
		 return ;
	}
	if (!check_iterator(st_set, my_set)){
		 std::cout << FAIL << std::endl;
		 return ;
	}
	st_set.swap(st_set1);
	my_set.swap(my_set1);
	if (st_set.size() != my_set.size()){
		 std::cout << FAIL << std::endl;
		 return ;
	}
	if (!check_iterator(st_set, my_set)){
		 std::cout << FAIL << std::endl;
		 return ;
	}
	std::cout << SUCS << std::endl;
}

static void	test_clear() {
	std::cout << "Clear test:\t\t\t";
	//std::cout << "not ready" << std::endl; //DELETE
	std::set<int> st_set;
	ft::set<int> my_set;
	for (int i = 10; i < 20; i++)
	{
		st_set.insert(i);
		my_set.insert(i);
	}
	if (st_set.size() != my_set.size()){
		std::cout << FAIL << std::endl;
		return ;
	}
	if (!check_iterator(st_set, my_set)){
		std::cout << FAIL << std::endl;
		return ;
	}
	st_set.clear();
	my_set.clear();
	if (st_set.size() != my_set.size()){
		std::cout << FAIL << std::endl;
		return ;
	}
	if (!check_iterator(st_set, my_set)){
		std::cout << FAIL << std::endl;
		return ;
	}
	std::cout << SUCS << std::endl;
}

static void	test_find() {
	std::cout << "Find test:\t\t\t";
	//std::cout << "not ready" << std::endl; //DELETE
	std::set<int> st_set;
	ft::set<int> my_set;
	std::set<int>::iterator its;
	ft::set<int>::iterator itm;
	std::set<int>::iterator its1;
	ft::set<int>::iterator itm1;
	for (int i = 1; i < 20; i++)
	{
		st_set.insert(i);
		my_set.insert(i);
	}
	if (st_set.size() != my_set.size()){
		std::cout << FAIL << std::endl;
		return ;
	}
	if (!check_iterator(st_set, my_set)){
		std::cout << FAIL << std::endl;
		return ;
	}
	its = st_set.find(15);
	itm = my_set.find(15);
	its1 = st_set.find(25);
	itm1 = my_set.find(25);
	if (*my_set.end() != *st_set.end()) {
		std::cout << FAIL << std::endl;
		return ;
	}
	// if (*its1 != *itm1 || *its != *itm) {
	// 	std::cout << FAIL << std::endl;
	// 	return ;
	// }
	std::cout << SUCS << std::endl;
}

static void	test_count() {
	std::cout << "Count test:\t\t\t";
	//std::cout << "not ready" << std::endl; //DELETE
	std::set<int> st_set;
	ft::set<int> my_set;
	for (int i = 1; i < 20; i++)
	{
		st_set.insert(i);
		my_set.insert(i);
	}
	if (st_set.size() != my_set.size()){
		std::cout << FAIL << std::endl;
		return ;
	}
	if (!check_iterator(st_set, my_set)){
		std::cout << FAIL << std::endl;
		return ;
	}
	if (st_set.count(5) != my_set.count(5)) {
		std::cout << FAIL << std::endl;
		return ;
	}
	if (st_set.count(25) != my_set.count(25)) {
		std::cout << FAIL << std::endl;
		return ;
	}
	std::cout << SUCS << std::endl;
}

static void	test_bound() {
	std::cout << "Bound test:\t\t\t";
	//std::cout << "not ready" << std::endl; //DELETE
	std::set<int> st_set;
	ft::set<int> my_set;
	std::set<int>::iterator its;
	ft::set<int>::iterator itm;
	std::set<int>::iterator its1;
	ft::set<int>::iterator itm1;
	for (int i = 1; i < 20; i++)
	{
		st_set.insert(i);
		my_set.insert(i);
	}
	if (st_set.size() != my_set.size()){
		std::cout << FAIL << std::endl;
		return ;
	}
	if (!check_iterator(st_set, my_set)){
		std::cout << FAIL << std::endl;
		return ;
	}
	its = st_set.lower_bound(15);
	itm = my_set.lower_bound(15);
	if (*its != *itm) {
		std::cout << FAIL << std::endl;
		return ;
	}
	its1 = st_set.upper_bound(15);
	itm1 = my_set.upper_bound(15);
	if (*its1 != *itm1) {
		std::cout << FAIL << std::endl;
		return ;
	}
	std::cout << SUCS << std::endl;
}

static void	test_equal_range() {
	std::cout << "Equal range test:\t\t";
	std::cout << "not ready" << std::endl; //DELETE
	// std::set<int> st_set;
	// ft::set<int> my_set;
	// std::set<int>::iterator its;
	// ft::set<int>::iterator itm;
	// std::set<int>::iterator its1;
	// ft::set<int>::iterator itm1;
	// for (int i = 1; i < 20; i++)
	// {
	// 	st_set.insert(i);
	// 	my_set.insert(i);
	// }
	// if (st_set.size() != my_set.size()){
	// 	std::cout << FAIL << std::endl;
	// 	return ;
	// }
	// if (!check_iterator(st_set, my_set)){
	// 	std::cout << FAIL << std::endl;
	// 	return ;
	// }
	// its = st_set.equal_range(15);
	// itm = my_set.equal_range(15);
	// if (*its != *itm) {
	// 	std::cout << FAIL << std::endl;
	// 	return ;
	// }
	// its1 = st_set.equal_range(150);
	// itm1 = my_set.equal_range(150);
	// if (*its1 != *itm1) {
	// 	std::cout << FAIL << std::endl;
	// 	return ;
	// }
	// std::cout << SUCS << std::endl;
}

static void	test_compare() {
	std::cout << "Compare test:\t\t\t";
	//std::cout << "not ready" << std::endl; //DELETE
	std::set<int> st_set;
	ft::set<int> my_set;
	std::set<int> st_set1;
	ft::set<int> my_set1;
	if (st_set.size() != my_set.size()){
		 std::cout << FAIL << std::endl;
		 return ;
	}
	if (!check_iterator(st_set, my_set)){
		 std::cout << FAIL << std::endl;
		 return ;
	}
	if (st_set1.size() != my_set1.size()){
		 std::cout << FAIL << std::endl;
		 return ;
	}
	if (!check_iterator(st_set1, my_set1)){
		 std::cout << FAIL << std::endl;
		 return ;
	}
	for (int i = 0; i < 20; i++) {
		st_set.insert(5 + i);
		my_set.insert(5 + i);
	}
	if((st_set == st_set1) != (my_set == my_set1)){
		 std::cout << FAIL << std::endl;
		 return ;
	}
	if((st_set != st_set1) != (my_set != my_set1)){
		 std::cout << FAIL << std::endl;
		 return ;
	}
	if((st_set > st_set1) != (my_set > my_set1)){
		 std::cout << FAIL << std::endl;
		 return ;
	}
	if((st_set >= st_set1) != (my_set >= my_set1)){
		 std::cout << FAIL << std::endl;
		 return ;
	}
	if((st_set < st_set1) != (my_set < my_set1)){
		 std::cout << FAIL << std::endl;
		 return ;
	}
	if((st_set <= st_set1) != (my_set <= my_set1)){
		 std::cout << FAIL << std::endl;
		 return ;
	}
	std::cout << SUCS << std::endl;
}

int test_set( void ){
	std::cout << MAGENTA << "------------------------------------" << std::endl;
	std::cout << "\tSET TESTER IS HERE" << std::endl;
	std::cout << "------------------------------------" << RESET << std::endl;

	test_constructor();
	test_size();
	test_max_size();
	test_begin_end();
	test_insert();
	test_empty();
	test_erase();
	test_swap();
	test_clear();
	test_find();
	test_count();
	test_bound();
	test_equal_range();
	test_compare();
	return (0);
}