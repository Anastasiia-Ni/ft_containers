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


// int main()
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

// template <typename T>
// bool	check_iterator(std::set<T> &st_set, ft::set<T> &my_set){ //change param
// 	// typename std::set<Key, T>::iterator it_st = st_set.begin();
// 	// typename ft::set<Key, T>::iterator it_my = my_set.begin();
// 	// while (it_st != st_set.end()){
// 	// 	if (it_st->first != it_my->first || it_st->second != it_my->second)
// 	// 		return false;
// 	// 	++it_st;
// 	// 	++it_my;
// 	// }
// 	// return true;
// }

static void test_constructor() {
	std::cout << "Default constructor test:\t";
	std::cout << "not ready" << std::endl; //DELETE
	// std::set<int> st_set;
	// ft::set<int> my_set;
	// if (st_set.size() != my_set.size()){
	// 	 std::cout << FAIL << std::endl;
	// 	 return ;
	// }
	// if (!check_iterator(st_set, my_set)){
	// 	 std::cout << FAIL << std::endl;
	// 	 return ;
	// }
	// std::set<std::string> st_set1;
	// ft::set<std::string> my_set1;
	// if (st_set1.size() != my_set1.size()){
	// 	 std::cout << FAIL << std::endl;
	// 	 return ;
	// }
	// 	if (!check_iterator(st_set1, my_set1)){
	// 	 std::cout << FAIL << std::endl;
	// 	 return ;
	// }
	// std::set<int> st_set2(st_set.begin(), st_set.end());
	// ft::set<int> my_set2(my_set.begin(), my_set.end());
	// if (st_set2.size() != my_set2.size()){
	// 	 std::cout << FAIL << std::endl;
	// 	 return ;
	// }
	// if (!check_iterator(st_set2, my_set2)){
	// 	 std::cout << FAIL << std::endl;
	// 	 return ;
	// }
	// std::set<int, int> st_set3;
	// ft::set<int, int> my_set3;
	// st_set3 = st_set;
	// my_set3 = my_set;
	// if (st_set3.size() != my_set3.size()){
	// 	 std::cout << FAIL << std::endl;
	// 	 return ;
	// }
	// if (!check_iterator(st_set3, my_set3)){
	// 	 std::cout << FAIL << std::endl;
	// 	 return ;
	// }
	// std::cout << SUCS << std::endl;
}

static void	test_size() {
	std::cout << "Size test:\t\t\t";
	std::cout << "not ready" << std::endl; //DELETE
	// std::set<int> st_set;
	// ft::set<int> my_set;
	// if (st_set.size() != my_set.size()){
	// 	 std::cout << FAIL << std::endl;
	// 	 return ;
	// }
	// for (int i = 0; i < 20; i++)
	// {
	// 	my_set.insert(i * 10);
	// 	st_set.insert(i * 10);
	// }
	// if (st_set.size() != my_set.size()){
	// 	 std::cout << FAIL << std::endl;
	// 	 return ;
	// }
	// std::cout << SUCS << std::endl;
}

static void	test_max_size() {
	std::cout << "Max_size test:\t\t\t";
	std::cout << "not ready" << std::endl; //DELETE
	// std::set<int> st_set;
	// ft::set<int> my_set;
	// if (st_set.max_size() != my_set.max_size()){
	// 	std::cout << FAIL << std::endl;
	// 	std::cout << "std set  " << st_set.max_size() << std::endl; //delete
	// 	std::cout << "my set   " << my_set.max_size() << std::endl; //delete
	// 	return ;
	// }
	//std::cout << SUCS << std::endl;

}

static void	test_begin_end() {
	std::cout << "Begin/end test:\t\t\t";
	std::cout << "not ready" << std::endl; //DELETE
}

static void	test_insert() {
	std::cout << "Insert test:\t\t\t";
	std::cout << "not ready" << std::endl; //DELETE
}

static void	test_empty() {
	std::cout << "Empty test:\t\t\t";
	std::cout << "not ready" << std::endl; //DELETE
	// std::set<int> st_set;
	// ft::set<int> my_set;
	// if (st_set.empty() != my_set.empty()){
	// 	 std::cout << FAIL << std::endl;
	// 	 return ;
	// }
	// std::cout << SUCS << std::endl;
}

static void	test_erase() {
	std::cout << "Erase test:\t\t\t";
	std::cout << "not ready" << std::endl; //DELETE
}

static void	test_swap() {
	std::cout << "Swap test:\t\t\t";
	std::cout << "not ready" << std::endl; //DELETE
}

static void	test_clear() {
	std::cout << "Clear test:\t\t\t";
	std::cout << "not ready" << std::endl; //DELETE
}

static void	test_find() {
	std::cout << "Find test:\t\t\t";
	std::cout << "not ready" << std::endl; //DELETE
}

static void	test_count() {
	std::cout << "Count test:\t\t\t";
	std::cout << "not ready" << std::endl; //DELETE
}

static void	test_bound() {
	std::cout << "Bound test:\t\t\t";
	std::cout << "not ready" << std::endl; //DELETE
}

static void	test_equal_range() {
	std::cout << "Equal range test:\t\t";
	std::cout << "not ready" << std::endl; //DELETE
}

static void	test_compare() {
	std::cout << "Compare test:\t\t\t";
	std::cout << "not ready" << std::endl; //DELETE
	// std::set<int> st_set;
	// ft::set<int> my_set;
	// std::set<int> st_set1;
	// ft::set<int> my_set1;
	// if (st_set.size() != my_set.size()){
	// 	 std::cout << FAIL << std::endl;
	// 	 return ;
	// }
	// if (!check_iterator(st_set, my_set)){
	// 	 std::cout << FAIL << std::endl;
	// 	 return ;
	// }
	// if (st_set1.size() != my_set1.size()){
	// 	 std::cout << FAIL << std::endl;
	// 	 return ;
	// }
	// if (!check_iterator(st_set1, my_set1)){
	// 	 std::cout << FAIL << std::endl;
	// 	 return ;
	// }
	// for (int i = 0; i < 20; i++) {
	// 	st_set.insert(5 + i);
	// 	my_set.insert(5 + i);
	// }
	// if((st_set == st_set1) != (my_set == my_set1)){
	// 	 std::cout << FAIL << std::endl;
	// 	 return ;
	// }
	// if((st_set != st_set1) != (my_set != my_set1)){
	// 	 std::cout << FAIL << std::endl;
	// 	 return ;
	// }
	// if((st_set > st_set1) != (my_set > my_set1)){
	// 	 std::cout << FAIL << std::endl;
	// 	 return ;
	// }
	// if((st_set >= st_set1) != (my_set >= my_set1)){
	// 	 std::cout << FAIL << std::endl;
	// 	 return ;
	// }
	// if((st_set < st_set1) != (my_set < my_set1)){
	// 	 std::cout << FAIL << std::endl;
	// 	 return ;
	// }
	// if((st_set <= st_set1) != (my_set <= my_set1)){
	// 	 std::cout << FAIL << std::endl;
	// 	 return ;
	// }
	// std::cout << SUCS << std::endl;
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