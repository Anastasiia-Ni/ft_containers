/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:42:05 by anifanto          #+#    #+#             */
/*   Updated: 2022/06/06 18:18:33 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/containers.hpp"

template <typename T>
static bool check_iterator(std::vector<T> &std_vec, ft::vector<T> &my_vec) {
    typename std::vector<T>::iterator it_st1 = std_vec.begin();
    typename std::vector<T>::iterator it_st2 = std_vec.end();
    typename ft::vector<T>::iterator it_my1 = my_vec.begin();
    typename ft::vector<T>::iterator it_my2 = my_vec.end();
    while (it_st1 != it_st2)
    {
        if (*it_st1 != *it_my1)
		{
			std::cout  << *it_st1 << "\n" << *it_my1 << std::endl;
            return false;
		}
		++it_st1;
		++it_my1;
    }
    // typename std::vector<T>::reverse_iterator it_rst1 = std_vec.rbegin();
    // typename std::vector<T>::reverse_iterator it_rst2 = std_vec.rend();
    // typename ft::vector<T>::reverse_iterator it_rmy1 = my_vec.rbegin();
    // typename ft::vector<T>::reverse_iterator it_rmy2 = my_vec.rend();
    // while (it_rst1 != it_rst2)
    // {
    //     if (*it_rst1 != *it_rmy1)
	// 	{
	// 		std::cout  << *it_rst1 << "\n" << *it_rmy1 << std::endl;
    //         return false;
	// 	}
    //     ++it_rst1;
    //     ++it_rmy1;
    // }
    return true;
}

static void	test_constructor(){
	std::cout << "Default constructor test:\t";

	size_t n = 10;
	std::vector<int>std_vec(n);
	ft::vector<int>my_vec(n);
	if (std_vec.size() != my_vec.size()) {
		std::cout << FAIL << std::endl;
		return ;
	}
	if (!check_iterator(std_vec, my_vec)){
		std::cout << FAIL << std::endl;
		return ;
	}
	std::vector<int>std_vec1(5, 21);
	ft::vector<int>my_vec1(5, 21);
	if (std_vec1.size() != my_vec1.size()) {
		std::cout << FAIL << std::endl;
		return ;
	}
	if (!check_iterator(std_vec1, my_vec1)){
		std::cout << FAIL << std::endl;
		return ;
	}
	std::vector<std::string>std_vec2(5, "A");
	ft::vector<std::string>my_vec2(5, "A");
	if (std_vec2.size() != my_vec2.size()) {
		std::cout << FAIL << std::endl;
		return ;
	}
    if (!check_iterator(std_vec2, my_vec2)){
        std::cout << FAIL << std::endl;
        return ;
	}
	std::vector<int> std_vec3(std_vec);
	ft::vector<int> my_vec3(my_vec);
	if (std_vec3.size() != my_vec3.size()) {
		std::cout << FAIL << std::endl;
		return ;
	}
    if (!check_iterator (std_vec3, my_vec3)){
        std::cout << FAIL << std::endl;
        return ;
	}
	std::cout << SUCS << std::endl;
}

 
static void	test_iterator() {
	std::cout << "Iterator test:\t\t\t";
    std::vector<int> std_vec(10);
    std::vector<int> std_vec1(10);
    ft::vector<int> my_vec(10);
    ft::vector<int> my_vec1(10);
    std::vector<int>::iterator it_s1 = std_vec1.begin();
    std::vector<int>::iterator it_s2 = std_vec1.end();
    ft::vector<int>::iterator it_m1 = my_vec1.begin();
    ft::vector<int>::iterator it_m2 = my_vec1.end();
    *it_s1 = 12345;
    *it_m1 = 12345;
    *(--it_s2) = 54321;
    *(--it_m2) = 54321;
    if (!check_iterator(std_vec, my_vec)){
        std::cout << FAIL << std::endl;
        return ;
	}
	std::vector<int> std_vec3(10);
    std::vector<int> std_vec4(10);
    ft::vector<int> my_vec3(10);
    ft::vector<int> my_vec4(10);
    // std::vector<int>::reverse_iterator it_s3 = ++std_vec3.rbegin();
    // std::vector<int>::reverse_iterator it_s4 = std_vec3.rend();
    // ft::vector<int>::reverse_iterator it_m3 = ++my_vec3.rbegin();
    // ft::vector<int>::reverse_iterator it_m4 = my_vec3.rend();
    // ++(*it_s3) = 12345;
    // --(*it_s4) = 54321;
    // ++(*it_m3) = 12345;
    // --(*it_m4) = 54321;
    if (!check_iterator(std_vec4, my_vec4)){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!check_iterator(std_vec4, my_vec4)){
        std::cout << FAIL << std::endl;
        return ;
	}
    std::cout << SUCS << std::endl;  
}

static void test_assign() {
	std::cout << "Assign test:\t\t\t";
	std::vector<int>st_vec;
	ft::vector<int>my_vec;
    st_vec.assign(10, 42);
    my_vec.assign(10, 42);
	if (st_vec.size() != my_vec.size()){
        std::cout << FAIL << std::endl;
        return ;
	}
    if (!check_iterator(st_vec, my_vec)){
        std::cout << FAIL << std::endl;
        return ;
	}
	// std::vector<int>st_vec1;
	// ft::vector<int>my_vec1;
    // std::vector<int>::iterator it_s = st_vec.begin();
    // ft::vector<int>::iterator it_m = my_vec.begin();
    // st_vec1.assign(it_s, st_vec.end());
    // my_vec1.assign(it_m, my_vec.end());
	// if (st_vec1.size() != my_vec1.size()){
    //     std::cout << FAIL << std::endl;
    //     return ;
	// }
    // if (!check_iterator(st_vec1, my_vec1)){
    //     std::cout << FAIL << std::endl;
    //     return ;
	// }
    std::cout << SUCS << std::endl;  
}

static void	test_size() {
	std::cout << "Size test:\t\t\t";
	size_t n = 42;
	std::vector<int>std_vec(n);
	ft::vector<int>my_vec(n);
	if (std_vec.size() != my_vec.size()){
		std::cout << FAIL << std::endl;
		return ;
	}
	std::vector<int>std_vec1;
	ft::vector<int>my_vec1;
	if (std_vec1.size() != my_vec1.size()){
		std::cout << FAIL << std::endl;
		return ;
	}
	std::cout << SUCS << std::endl;
}

static void	test_begin_end() {
	std::cout << "Begin/end test:\t\t\t";
    std::vector<int> std_vec(10);
    std::vector<int> std_vec1(10);
    ft::vector<int> my_vec(10);
    ft::vector<int> my_vec1(10);
    std::vector<int>::iterator it_s1 = std_vec1.begin();
    std::vector<int>::iterator it_s2 = std_vec1.end();
    ft::vector<int>::iterator it_m1 = my_vec1.begin();
    ft::vector<int>::iterator it_m2 = my_vec1.end();
    *it_s1 = 12345;
    *it_m1 = 12345;
    *(--it_s2) = 54321;
    *(--it_m2) = 54321;
    if (!check_iterator(std_vec, my_vec)){
        std::cout << FAIL << std::endl;
        return ;
	}
	std::cout << SUCS << std::endl; 
}

static void	test_capacity() {
    std::cout << "Capacity test:\t\t\t";
	size_t n = 142;
	std::vector<int>std_vec(n);
	ft::vector<int>my_vec(n);
	if (std_vec.capacity() != my_vec.capacity()){
		std::cout << FAIL << std::endl;
		return ;
	}
	std::vector<int>std_vec1;
	ft::vector<int>my_vec1;
	if (std_vec1.size() != my_vec1.size()){
		std::cout << FAIL << std::endl;
		return ;
	}
	std::cout << SUCS << std::endl;
}

static void	test_at(){
	std::cout << "At test:\t\t\t";
	std::vector<int>std_vec;
	ft::vector<int>my_vec;
	size_t n = 20;
	for (size_t i = 0; i < n; i++) {
		std_vec.push_back(i);
		my_vec.push_back(i);
	}
	try{
		std_vec.at(n * 2);
		std::cout << FAIL << std::endl;
	}
	catch (std::exception &e){ }
	try{
		my_vec.at(n * 2);
		std::cout << FAIL << std::endl;
	}
	catch (std::exception &e){}

	if (std_vec.at(2) != my_vec.at(2)) {
		std::cout << FAIL << std::endl;
		return ;
	}
	std::cout << SUCS << std::endl;
}

static void	test_operator(){
	std::cout << "Operator test\t\t\t";
	std::vector<int>std_vec;
	ft::vector<int>my_vec;
    int count = 0;
	for (int i = 0; i < 5; i++) {
		std_vec.push_back(i + 1);
		my_vec.push_back(i + 1);
	}
    try{
        std_vec[0];
    }
    catch(std::out_of_range &ex){
        count++;
    }
    try{
        my_vec[0];
    }
    catch(std::out_of_range &ex){
        count--;
    }
    if (!count){
        std::cout << SUCS << std::endl;
        return;
    }
    std::cout << FAIL << std::endl;
    return ;
}

static void test_reserve() {
	std::cout << "Reserve test\t\t\t";
	std::vector<int>st_vec(1);
	ft::vector<int>my_vec(1);
	if (st_vec.capacity() != my_vec.capacity()){
        std::cout << FAIL << std::endl;
        return ;
	}
    st_vec.reserve(5);
    my_vec.reserve(5);
	if (st_vec.capacity() != my_vec.capacity()){
        std::cout << FAIL << std::endl;
        return ;
	}
    std::cout << SUCS << std::endl; 
}

static void	test_push_back(){
	std::cout << "Push_back test:\t\t\t";
	size_t n = 42;
	std::vector<int>std_vec;
	ft::vector<int>my_vec;
	for (size_t i = 0; i < n / 2; i++) {
		std_vec.push_back(i);
		my_vec.push_back(i);
	}
	if (std_vec.size() != my_vec.size()){
		std::cout << FAIL << std::endl;
		return ;
	}
	std_vec.push_back(n);
	my_vec.push_back(n);
	if (std_vec.size() != my_vec.size()){
		std::cout << FAIL << std::endl;
		return ;
	}
	std::cout << SUCS << std::endl;
}

static void	test_pop_back(){
	std::cout << "Pop_back test:\t\t\t";
	std::vector<int>st_vec;
	ft::vector<int>my_vec;
    st_vec.push_back(42);
    my_vec.push_back(42);
    st_vec.push_back(11);
    my_vec.push_back(11);
    st_vec.push_back(100);
    my_vec.push_back(100); 
    if (st_vec.size() != my_vec.size()) 
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    st_vec.pop_back();
    my_vec.pop_back();
    if (st_vec.size() != my_vec.size()) 
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    std::cout << SUCS << std::endl; 
}

static void	test_insert() {
	std::cout << "Insert test:\t\t\t";
	std::vector<int>st_vec(10);
    ft::vector<int>my_vec(10);
    std::vector<int>::iterator it_st = st_vec.begin();
    ft::vector<int>::iterator it_my = my_vec.begin();
    st_vec.insert(++it_st, 42);
    my_vec.insert(++it_my, 42);
    if (st_vec.size() != my_vec.size()){
        std::cout << FAIL << std::endl;
        return ;
    }
    if (!check_iterator(st_vec, my_vec)){
        std::cout << FAIL << std::endl;
        return ;        
    }
	//std::cout << "\nstd cap " << st_vec.capacity() << " size " << st_vec.size() << std::endl; // delete
	//std::cout << "my cap  " << my_vec.capacity() << " size " << my_vec.size() << std::endl;	//delete
	// st_vec.insert(++it_st, 12, 11);
	// my_vec.insert(++it_my, 12, 11);
    // if (st_vec.size() != my_vec.size()){
    //     std::cout << FAIL << std::endl;
    //     return ;
    // }
    // if (!check_iterator(st_vec, my_vec)){
    //     std::cout << FAIL << std::endl;
    //     return ;        
    // }
    // std::vector<int> st_vec2;
    // ft::vector<int> my_vec2;
    // std::vector<int>::iterator it_st1 = st_vec2.end();
    // ft::vector<int>::iterator it_my1 = my_vec2.end();   
    // st_vec.insert(--it_st1, st_vec2.begin(), st_vec2.end());
    // my_vec.insert(--it_my1, my_vec2.begin(), my_vec2.end());
    // if (st_vec.size() != my_vec.size()){
    //     std::cout << FAIL << std::endl;
    //     return ;
    // }
    // if (!check_iterator(st_vec, my_vec)){
    //     std::cout << FAIL << std::endl;
    //     return ;        
    // }        
    std::cout << SUCS << std::endl; 
}

static void	test_emty() {
	std::cout << "Empty test:\t\t\t";
	std::vector<int>st_vec;
	ft::vector<int>my_vec;
	if (st_vec.empty() != my_vec.empty()){
        std::cout << FAIL << std::endl;
        return ;
	}
	std::vector<int>st_vec1(11);
	ft::vector<int>my_vec1(11);
	if (st_vec1.empty() != my_vec1.empty()){
        std::cout << FAIL << std::endl;
        return ;
	}
    std::cout << SUCS << std::endl;
}

static void	test_erase(){
	std::cout << "Erase test:\t\t\t";
	std::vector<int>st_vec(10);
	ft::vector<int>my_vec(10);
	std::vector<int>::iterator it_st = st_vec.begin();
	ft::vector<int>::iterator it_my = my_vec.begin();
    st_vec.erase(++it_st);
    my_vec.erase(++it_my);
    if (st_vec.size() != my_vec.size()){
        std::cout << FAIL << std::endl;
        return ;
    }
    if (!check_iterator(st_vec, my_vec)){
        std::cout << FAIL << std::endl;
        return ;        
    }
    st_vec.erase(++it_st, st_vec.end());
    my_vec.erase(++it_my, my_vec.end());
    if (st_vec.size() != my_vec.size()){
        std::cout << FAIL << std::endl;
        return ;
    }
    if (!check_iterator(st_vec, my_vec)){
        std::cout << FAIL << std::endl;
        return ;        
    }
    std::cout << SUCS << std::endl;
}

static void	test_swap(){
	std::cout << "Swap test:\t\t\t";
    std::vector<int> st_vec;
    std::vector<int> st_vec1;
    ft::vector<int> my_vec;
    ft::vector<int> my_vec1;
	for (int i = 0; i < 5; i++) {
		st_vec.push_back(1);
		my_vec.push_back(1);
	}
	for (int i = 0; i < 5; i++) {
		st_vec1.push_back(42);
		my_vec1.push_back(42);
	}
    st_vec.swap(st_vec1);
    my_vec.swap(my_vec1);
    if (st_vec.size() != my_vec.size()){
        std::cout << FAIL << std::endl;
        return ;
    }
    if (!check_iterator(st_vec, my_vec)){
        std::cout << FAIL << std::endl;
        return ;        
    }
    if (st_vec1.size() != my_vec1.size()){
        std::cout << FAIL << std::endl;
        return ;
    }
    if (!check_iterator(st_vec1, my_vec1)){
        std::cout << FAIL << std::endl;
        return ;        
    }
    std::cout << SUCS << std::endl;
}

static void	test_clear() {
	std::cout << "Clear test:\t\t\t";
	std::vector<int>st_vec;
	ft::vector<int>my_vec;
	for (int i = 0; i < 5; i++) {
		st_vec.push_back(i * 5);
		my_vec.push_back(i * 5);
	}
    my_vec.clear();
    st_vec.clear();
    if (st_vec.size() != my_vec.size()) 
    {
        std::cout << FAIL << std::endl;
        return ;
    }   
    st_vec.push_back(1);
    my_vec.push_back(1);
    st_vec.push_back(42);
    my_vec.push_back(42);
    if (st_vec.size() != my_vec.size()) 
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    std::cout << SUCS << std::endl; 
}

static void test_compare() {
	std::cout << "Compare test:\t\t\t";
	std::vector<int> st_vec;
	std::vector<int> st_vec1;
	ft::vector<int> my_vec;
	ft::vector<int> my_vec1;
	for (int i = 0; i < 5; i++) {
		st_vec.push_back(i * 5);
		my_vec.push_back(i * 5);
	}
	for (int i = 0; i < 5; i++) {
		st_vec1.push_back(i * 3);
		my_vec1.push_back(i * 3);
	}
    if ((my_vec == my_vec1) != (st_vec == st_vec1))
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    if ((my_vec != my_vec1) != (st_vec != st_vec1))
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    if ((my_vec > my_vec1) != (st_vec > st_vec1))
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    if ((my_vec >= my_vec1) != (st_vec >= st_vec1))
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    if ((my_vec < my_vec1) !=  (st_vec < st_vec1))
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    if ((my_vec <= my_vec1) !=  (st_vec <= st_vec1))
    {
        std::cout << FAIL << std::endl;
        return ;
    }
    std::cout << SUCS << std::endl; 
}


int test_vector( void ){
	std::cout << MAGENTA << "------------------------------------" << std::endl;
	std::cout << "\tVECTOR TESTER IS HERE" << std::endl;
	std::cout << "------------------------------------" << RESET << std::endl;

	test_constructor();
	test_iterator();
	test_assign();
	test_size();
	test_begin_end();
	test_capacity();
	test_at();
	test_operator();
	test_reserve();
	test_push_back();
	test_pop_back();
	test_insert();
	test_emty();
	test_erase();
	test_swap();
	test_clear();
	test_compare();
	// test_front();
	// test_back();
	return (0);
}