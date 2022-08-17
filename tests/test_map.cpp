/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:11:45 by anifanto          #+#    #+#             */
/*   Updated: 2022/07/14 13:45:01 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/containers.hpp"
#include "../includes/map.hpp"

template <typename Key, typename T>
bool	check_iterator(std::map<Key, T> &st_map, ft::map<Key, T> &my_map){
	typename std::map<Key, T>::iterator it_st = st_map.begin();
	typename ft::map<Key, T>::iterator it_my = my_map.begin();
	while (it_st != st_map.end()){
		if (it_st->first != it_my->first || it_st->second != it_my->second)
			return false;
		++it_st;
		++it_my;
	}
	return true;
}

static void		test_constructor() {
	std::cout << "Default constructor test:\t";
	std::map<int, int> st_map;
	ft::map<int, int> my_map;
	if (st_map.size() != my_map.size()){
		std::cout << FAIL << std::endl;
		return ;
	}
	if (!check_iterator(st_map, my_map)){
		std::cout << FAIL << std::endl;
		return ;
	}
	std::map<std::string, std::string> st_map1;
	ft::map<std::string, std::string> my_map1;
	if (st_map1.size() != my_map1.size()){
		std::cout << FAIL << std::endl;
		return ;
	}
	if (!check_iterator(st_map1, my_map1)){
		std::cout << FAIL << std::endl;
		return ;
	}
	std::map<int, int> st_map2(st_map.begin(), st_map.end());
	ft::map<int, int> my_map2(my_map.begin(), my_map.end());
	if (st_map2.size() != my_map2.size()){
		std::cout << FAIL << std::endl;
		return ;
	}
	if (!check_iterator(st_map2, my_map2)){
		std::cout << FAIL << std::endl;
		return ;
	}
	std::map<int, int> st_map3;
	ft::map<int, int> my_map3;
	st_map3 = st_map;
	my_map3 = my_map;
	if (st_map3.size() != my_map3.size()){
		std::cout << FAIL << std::endl;
		return ;
	}
	if (!check_iterator(st_map3, my_map3)){
		std::cout << FAIL << std::endl;
		return ;
	}
	std::cout << SUCS << std::endl;
}

static void		test_size() {
	std::cout << "Size test:\t\t\t";
	std::map<int, int> st_map;
	ft::map<int, int> my_map;
	if (st_map.size() != my_map.size()){
		 std::cout << FAIL << std::endl;
		 return ;
	}
	st_map.insert(std::make_pair(5, 0));
	my_map.insert(ft::make_pair(5, 0));
	if (st_map.size() != my_map.size()){
		 std::cout << FAIL << std::endl;
		 return ;
	}
	std::cout << SUCS << std::endl;
}

static void	test_max_size(){
	std::cout << "Max_size test:\t\t\t";
	std::map<int, int> st_map;
	ft::map<int, int> my_map;
	if (st_map.max_size() != my_map.max_size()){
		std::cout << FAIL << std::endl;
		return ;
	}
	std::cout << SUCS << std::endl;
}

static void		test_begin_end() {
	std::cout << "Begin/end test:\t\t\t";
	std::map<int, char> maps;
	ft::map<int, char> mapm;
	std::map<int, char> st_map(maps.begin(), maps.end());
	ft::map<int, char> my_map(mapm.begin(), mapm.end());
	for (int i = 0; i < 26; i++) {
		st_map.insert(std::make_pair(i, i + 'A'));
		my_map.insert(ft::make_pair(i, i + 'A'));
	}
	std::map<int, char>::iterator its = st_map.begin();
	ft::map<int, char>::iterator itm = my_map.begin();
	if (st_map.size() != my_map.size()){
		std::cout << FAIL << std::endl;
		return ;
	}
	if (!check_iterator(st_map, my_map)){
		std::cout << FAIL << std::endl;
		return ;
	}
	if (++its->second != ++itm->second || its->first != itm->first){
		std::cout << FAIL << std::endl;
		return ;
	}
	std::map<int, char>::iterator its1 = st_map.end();
	ft::map<int, char>::iterator itm1 = my_map.end();
	--its1;
	--itm1;
	if ((its1->first != itm1->first) || (its1->second != itm1->second)){
		std::cout << FAIL << std::endl;
		return ;
	}
	std::cout << SUCS << std::endl;
}

static void		test_operators() {
	std::cout << "Operator[] test\t\t\t";
	std::map<char, int> st_map;
	ft::map<char, int> my_map;
	st_map['A'] = 1;
	my_map['A'] = 1;
	st_map['B'] = 2;
	my_map['B'] = 2;
	st_map['C'] = 3;
	my_map['C'] = 3;
	if (st_map['A'] != my_map['A']){
		 std::cout << FAIL << std::endl;
		 return ;
	}
	std::cout << SUCS << std::endl;

	std::cout << "Operator at test\t\t";
	if (st_map.at('A') != my_map.at('A')) {
		 std::cout << FAIL << std::endl;
		 return ;
	}
	try {
		my_map.at('E');
		std::cout << FAIL << std::endl;
	}
	catch (std::exception &e){}
	std::cout << SUCS << std::endl;
}

static void		test_insert() {
	std::cout << "Insert test:\t\t\t";
	std::map<int, int> st_map;
	ft::map<int, int> my_map;
	st_map.insert(std::make_pair(5, 21));
	my_map.insert(ft::make_pair(5, 21));
	if (st_map.size() != my_map.size()){
		std::cout << FAIL << std::endl;
		return ;
	}
	if (!check_iterator(st_map, my_map)){
		std::cout << FAIL << std::endl;
		return ;
	}
	st_map.clear();
	my_map.clear();
	std::map<int, std::string> st_map1;
	ft::map<int, std::string> my_map1;
	for (int i = 0; i < 50; i++) {
		my_map1.insert(ft::pair<int, std::string>(i, "c"));
		st_map1.insert(std::pair<int, std::string>(i, "c"));
	}
	if (st_map1.size() != my_map1.size()){
		std::cout << FAIL << std::endl;
		return ;
	}
	if (!check_iterator(st_map1, my_map1)){
		std::cout << FAIL << std::endl;
		return ;
	}
	std::cout << SUCS << std::endl;
}

static void		test_empty() {
	std::cout << "Empty test:\t\t\t";
	std::map<int, int> st_map;
	ft::map<int, int> my_map;
	if (st_map.empty() != my_map.empty()){
		std::cout << FAIL << std::endl;
		return ;
	}
	std::cout << SUCS << std::endl;
}

static void		test_erase() {
	std::cout << "Erase test:\t\t\t";
	std::map<int, int> st_map;
	ft::map<int, int> my_map;
	st_map['A'] = 1;
	st_map['B'] = 2;
	st_map['C'] = 3;
	my_map['A'] = 1;
	my_map['B'] = 2;
	my_map['C'] = 3;
	if (st_map.size() != my_map.size()){
		std::cout << FAIL << std::endl;
		return ;
	}
	if (!check_iterator(st_map, my_map)){
		std::cout << FAIL << std::endl;
		return ;
	}
	st_map.erase(++st_map.begin());
	my_map.erase(++my_map.begin());
	if (st_map.size() != my_map.size()){
		std::cout << FAIL << std::endl;
		return ;
	}
	if (!check_iterator(st_map, my_map)){
		std::cout << FAIL << std::endl;
		return ;
	}
	st_map.erase(++st_map.begin(), --st_map.end());
	my_map.erase(++my_map.begin(), --my_map.end());
	if (st_map.size() != my_map.size()){
		std::cout << FAIL << std::endl;
		return ;
	}
	if (!check_iterator(st_map, my_map)){
		std::cout << FAIL << std::endl;
		return ;
	}
	st_map.erase('A');
	my_map.erase('A');
	if (st_map.size() != my_map.size()){
		std::cout << FAIL << std::endl;
		return ;
	}
	if (!check_iterator(st_map, my_map)){
		std::cout << FAIL << std::endl;
		return ;
	}
	st_map.erase('F');
	my_map.erase('F');
	if (st_map.size() != my_map.size()){
		std::cout << FAIL << std::endl;
		return ;
	}
	if (!check_iterator(st_map, my_map)){
		std::cout << FAIL << std::endl;
		return ;
	}
	std::cout << SUCS << std::endl;
}

static void		test_swap() {
	std::cout << "Swap test:\t\t\t";
	std::map<int, int> st_map;
	ft::map<int, int> my_map;
	std::map<int, int> st_map1;
	ft::map<int, int> my_map1;
	st_map[0] = 1;
	st_map[1] = 2;
	my_map[0] = 1;
	my_map[1] = 2;
	if (st_map.size() != my_map.size()){
		std::cout << FAIL << std::endl;
		return ;
	}
	if (!check_iterator(st_map, my_map)){
		std::cout << FAIL << std::endl;
		return ;
	}
	st_map.swap(st_map1);
	my_map.swap(my_map1);
	if (st_map.size() != my_map.size()){
		std::cout << FAIL << std::endl;
		return ;
	}
	if (!check_iterator(st_map, my_map)){
		std::cout << FAIL << std::endl;
		return ;
	}
	std::cout << SUCS << std::endl;
}

static void		test_clear() {
	std::cout << "Clear test:\t\t\t";
	std::map<int, int> st_map;
	ft::map<int, int> my_map;
	st_map.insert(std::make_pair(5, 21));
	my_map.insert(ft::make_pair(5, 21));
	if (st_map.size() != my_map.size()){
		std::cout << FAIL << std::endl;
		return ;
	}
	if (!check_iterator(st_map, my_map)){
		std::cout << FAIL << std::endl;
		return ;
	}
	st_map.clear();
	my_map.clear();
	if (st_map.size() != my_map.size()){
		std::cout << FAIL << std::endl;
		return ;
	}
	if (!check_iterator(st_map, my_map)){
		std::cout << FAIL << std::endl;
		return ;
	}
	std::cout << SUCS << std::endl;
}

static void	test_find () {
	std::cout << "Find test:\t\t\t";
	std::map<char, int> st_map;
	ft::map<char, int> my_map;
	std::map<char, int>::iterator it_s;
	ft::map<char, int>::iterator it_m;
	st_map['A'] = 1;
	st_map['B'] = 2;
	st_map['C'] = 3;
	my_map['A'] = 1;
	my_map['B'] = 2;
	my_map['C'] = 3;
	if (st_map.size() != my_map.size()){
		std::cout << FAIL << std::endl;
		return ;
	}
	if (!check_iterator(st_map, my_map)){
		std::cout << FAIL << std::endl;
		return ;
	}
	it_s = st_map.find(1);
	it_m = my_map.find(1);
	if (it_s != st_map.end() || it_m != my_map.end()){
		std::cout << FAIL << std::endl;
		return ;
	}
	std::map<char, int>::iterator it_s1;
	ft::map<char, int>::iterator it_m1;
	it_s1 = st_map.find('A');
	it_m1 = my_map.find('A');
	if ((it_s1->first != it_m1->first) || (it_s1->second != it_m1->second)){
	 std::cout << FAIL << std::endl;
		return ;
	}
	std::cout << SUCS << std::endl;
}

static void	test_count(){
	std::cout << "Count test:\t\t\t";
	std::map<char, int> st_map;
	ft::map<char, int> my_map;
	st_map['A'] = 1;
	st_map['B'] = 2;
	st_map['C'] = 3;
	my_map['A'] = 1;
	my_map['B'] = 2;
	my_map['C'] = 3;
	if (st_map.count('A') != my_map.count('A')){
		std::cout << FAIL << std::endl;
		return ;
	}
	if (st_map.count('T') != my_map.count('T')){
		std::cout << FAIL << std::endl;
		return ;
	}
	std::cout << SUCS << std::endl;
}

static void	test_bound(){
	std::cout << "Bound test:\t\t\t";
	std::map<char, int> st_map;
	ft::map<char, int> my_map;
	st_map['A'] = 1;
	st_map['B'] = 2;
	st_map['C'] = 3;
	my_map['A'] = 1;
	my_map['B'] = 2;
	my_map['C'] = 3;
	std::map<char, int>::iterator it_s = st_map.lower_bound(1);
	ft::map<char, int>::iterator it_m = my_map.lower_bound(1);
	if ((it_s->first != it_m->first) || (it_s->second != it_m->second)){
		std::cout << FAIL << std::endl;
		return ;
	}
	it_s = st_map.lower_bound('A');
	it_m = my_map.lower_bound('A');
	if ((it_s->first != it_m->first) || (it_s->second != it_m->second)){
		std::cout << FAIL << std::endl;
		return ;
	}
	it_s = st_map.upper_bound(1);
	it_m = my_map.upper_bound(1);
	if ((it_s->first != it_m->first) || (it_s->second != it_m->second)){
		std::cout << FAIL << std::endl;
		return ;
	}
	it_s = st_map.upper_bound('A');
	it_m = my_map.upper_bound('A');
	if ((it_s->first != it_m->first) || (it_s->second != it_m->second)){
		std::cout << FAIL << std::endl;
		return ;
	}
	std::cout << SUCS << std::endl;
}

static void	test_equal_range(){
	std::cout << "Equal range test:\t\t";
	std::map<int, int> st_map;
	ft::map<int, int> my_map;
	st_map[0] = 1;
	st_map[1] = 2;
	st_map[2] = 3;
	my_map[0] = 1;
	my_map[1] = 2;
	my_map[2] = 3;
	std::pair<std::map<int, int>::iterator, std::map<int, int>::iterator> it_s;
	ft::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator> it_m;
	it_s = st_map.equal_range(1);
	it_m = my_map.equal_range(1);
	if ((it_s.first->first != it_m.first->first) || (it_s.second->second != it_m.second->second) ||
	(it_s.first->second != it_m.first->second) || (it_s.second->first != it_m.second->first)){
		std::cout << FAIL << std::endl;
		return ;
	}
	std::pair<std::map<int, int>::iterator, std::map<int, int>::iterator> it_s1;
	ft::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator> it_m1;
	it_s1 = st_map.equal_range(1000);
	it_m1 = my_map.equal_range(1000);
	if ((it_s.first->first != it_m.first->first) || (it_s.second->second != it_m.second->second) ||
	(it_s.first->second != it_m.first->second) || (it_s.second->first != it_m.second->first)){
		std::cout << FAIL << std::endl;
		return ;
	}
	std::cout << SUCS << std::endl;
}

static void	test_compare(){
	std::cout << "Compare test:\t\t\t";
	std::map<int, int> st_map;
	ft::map<int, int> my_map;
	std::map<int, int> st_map1;
	ft::map<int, int> my_map1;
	if (st_map.size() != my_map.size()) {
		std::cout << FAIL << std::endl;
		return ;
	}
	if (!check_iterator(st_map, my_map)) {
		std::cout << FAIL << std::endl;
		return ;
	}
	if (st_map1.size() != my_map1.size()) {
		std::cout << FAIL << std::endl;
		return ;
	}
	if (!check_iterator(st_map1, my_map1)) {
		std::cout << FAIL << std::endl;
		return ;
	}
	st_map.insert(std::make_pair(5, 21));
	my_map.insert(ft::make_pair(5, 21));
	if((st_map == st_map1) != (my_map == my_map1)) {
		std::cout << FAIL << std::endl;
		return ;
	}
	if((st_map != st_map1) != (my_map != my_map1)) {
		std::cout << FAIL << std::endl;
		return ;
	}
	if((st_map > st_map1) != (my_map > my_map1)) {
		std::cout << FAIL << std::endl;
		return ;
	}
	if((st_map >= st_map1) != (my_map >= my_map1)) {
		std::cout << FAIL << std::endl;
		return ;
	}
	if((st_map < st_map1) != (my_map < my_map1)) {
		std::cout << FAIL << std::endl;
		return ;
	}
	if((st_map <= st_map1) != (my_map <= my_map1)){
		std::cout << FAIL << std::endl;
		return ;
	}
	std::cout << SUCS << std::endl;
}


int test_map( void ){
	std::cout << MAGENTA << "------------------------------------" << std::endl;
	std::cout << "\tMAP TESTER IS HERE" << std::endl;
	std::cout << "------------------------------------" << RESET << std::endl;

	test_constructor();
	test_size();
	test_max_size();
	test_begin_end();
	test_operators();
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