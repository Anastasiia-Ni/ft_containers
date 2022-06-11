/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:42:39 by anifanto          #+#    #+#             */
/*   Updated: 2022/06/11 15:25:51 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MAP_HPP
#define MAP_HPP

#include "containers.hpp"
#include "binary_tree.hpp"
namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
 	class map
	{
		public:
			typedef Key										key_type;
			typedef T										mapped_type;
			typedef ft::pair<const key_type, mapped_type>	value_type;
			typedef size_t									size_type;
			typedef Alloc									allocator_type;
			typedef Compare									key_compare;
			typedef T&										reference;
 			typedef T const & 								const_reference;
			typedef T*										pointer;
			typedef const T*								const_pointer;
			//typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
			//iterator
			//const_iterator
			//reverse_iterator
			//const_reverse_iterator

			class value_compare : public std::binary_function<value_type, value_type, bool> // in C++98, it is required to inherit binary_function ....
			{
				friend class map;

				protected:
					Compare		comp;
					value_compare(Compare c) : comp(c) {}

				public:
					typedef bool		result_type;
					typedef value_type	first_argument_type;
					typedef value_type	second_argument_type;
					bool operator() (const value_type &x, const value_type &y) const
					{
						return comp(x.first, y.first);
					}
			};

		private:
			typedef binary_tree<value_type>	b_tree;
			allocator_type					_alloc;
			key_compare						_comp;
			size_type						_size;
			std::allocator<b_tree>			_alloc_tree;
			b_tree							*_root;
			b_tree							*_nl_node;

			b_tree *findnode (const key_type& k, b_tree *start) const {
				b_tree *tmp;

				tmp = start;
				(void)k;
				return (_nl_node);
			}

			// b_tree	*find_max_node() const {

			// }

		public:

			// map() {

			// }

			// ~map() {

			// }

			// map& operator=(const map& other) {

			// }

			// allocator_type get_allocator() const{

			// }

			// T& at(const Key& key){

			// }

			// const T& at(const Key& key) const {

			// }

			// T& operator[](const Key& key) {

			// }

			// iterator begin() {

			// }

			// const_iterator begin() const {

			// }

			// iterator end() {

			// }

			// const_iterator end() const {

			// }

			// reverse_iterator rbegin() {

			// }

			// const_reverse_iterator rbegin() const {

			// }

			// reverse_iterator rend() {

			// }

			// const_reverse_iterator rend() const {

			// }

			// bool empty() const {

			// }

			// size_type size() const {

			// }

			// size_type max_size() const {

			// }

			// void clear() {

			// }
			// ft::pair<iterator, bool> insert(const value_type& value) {

			// }

			// iterator insert(iterator hint, const value_type& value) {

			// }

			// template <class InputIt>
			// void insert( InputIt first, InputIt last ){

			// }

			// void erase(iterator pos) {

			// }

			// void erase(iterator first, iterator last) {

			// }

			// size_type erase( const Key& key ) {

			// }

			// void swap(map& other) {

			// }

			// size_type count(const Key& key) const {

			// }

			// iterator find(const Key& key) {

			// }

			// const_iterator find(const Key& key) const {

			// }

			// ft::pair<iterator,iterator> equal_range(const Key& key) {

			// }

			// ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const {

			// }

			// iterator lower_bound(const Key& key) {

			// }

			// const_iterator lower_bound(const Key& key) const {

			// }

			// iterator upper_bound(const Key& key) {

			// }

			// const_iterator upper_bound(const Key& key) const {

			// }

			// key_compare key_comp() const {

			// }

			// std::map::value_compare value_comp() const {

			// }
	};
	// template <class Key, class T, class Compare, class Alloc>
	// bool operator==(const std::map<Key,T,Compare,Alloc>& lhs,
	// 				const std::map<Key,T,Compare,Alloc>& rhs) {

	// }

	// template <class Key, class T, class Compare, class Alloc>
	// bool operator!=(const std::map<Key,T,Compare,Alloc>& lhs,
	// 				const std::map<Key,T,Compare,Alloc>& rhs){

	// }

	// template <class Key, class T, class Compare, class Alloc>
	// bool operator<(const std::map<Key,T,Compare,Alloc>& lhs,
	// 				const std::map<Key,T,Compare,Alloc>& rhs){

	// }

	// template <class Key, class T, class Compare, class Alloc>
	// bool operator<=(const std::map<Key,T,Compare,Alloc>& lhs,
	// 				const std::map<Key,T,Compare,Alloc>& rhs){

	// }

	// template <class Key, class T, class Compare, class Alloc>
	// bool operator>(const std::map<Key,T,Compare,Alloc>& lhs,
	// 				const std::map<Key,T,Compare,Alloc>& rhs){

	// }

	// template <class Key, class T, class Compare, class Alloc>
	// bool operator>=(const std::map<Key,T,Compare,Alloc>& lhs,
	// 				const std::map<Key,T,Compare,Alloc>& rhs){

	// }
};

//swap()*/


#endif
