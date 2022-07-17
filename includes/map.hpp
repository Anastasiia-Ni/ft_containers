/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:12:26 by anifanto          #+#    #+#             */
/*   Updated: 2022/07/14 14:07:23 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MAP_HPP
#define MAP_HPP

#include "containers.hpp"
#include "iterators/tree_iterator.hpp"
#include "iterators/reverse_iterator.hpp"
#include "utils/utils.hpp"
#include "utils/red_black_tree.hpp"

namespace ft
{
	// template<typename Arg1, typename Arg2, typename Result>
	// struct binary_function
	// {
	// 	typedef Arg1	frist_argument_type;
	// 	typedef Arg2	second_argument_type;
	// 	typedef Result	result_type;
	// };
	
	// template<typename T>
	// struct less: binary_function<T,T,bool>
	// {
	// 	bool operator()(const T& x, const T& y) const
	// 	{
	// 		return x < y;
	// 	}
	// };
	
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
 	class map
	{
		public:
			typedef Key										key_type;
			typedef T										mapped_type;
			typedef ft::pair<const key_type, mapped_type>	value_type;
			typedef Compare									key_compare;
 			typedef Alloc									allocator_type;

			class value_compare : public std::binary_function<value_type, value_type, bool> // in C++98, it is required to inherit binary_function ....
			{
				friend class map;
				protected:
					key_compare		comp;
					value_compare(key_compare c) : comp(c) {}
				public:	
				// 	typedef bool		result_type;
				// 	typedef value_type	first_argument_type;
				// 	typedef value_type	second_argument_type;
					bool operator() (const value_type &x, const value_type &y) const {
						return comp(x.first, y.first);
					}
			};

		private:
			typedef ft::rbTree<value_type,value_compare,allocator_type>	tree_type;


		public:
// 			typedef map::value_compare												value_compare;
			typedef typename allocator_type::reference								reference;
			typedef typename allocator_type::const_reference						const_reference;
			typedef typename allocator_type::pointer								pointer;
			typedef typename allocator_type::const_pointer							const_pointer;
			typedef typename allocator_type::size_type								size_type;
			typedef typename allocator_type::difference_type						difference_type;
			typedef typename tree_type::iterator									iterator;
			typedef typename tree_type::const_iterator								const_iterator;
			typedef typename tree_type::reverse_iterator							reverse_iterator;
			typedef typename tree_type::const_reverse_iterator						const_reverse_iterator;

		private:
			tree_type _tree;

 		public:

		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(value_compare(comp), alloc) {}

		template <typename InputIterator>
		map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(), 
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) : _tree(value_compare(comp), alloc) {
				this->insert(first, last);
		}

		map (const map& other) : _tree(other._tree) {}

		~map() {}

		map& operator=(const map& rhs) {
			if (this != &rhs)
				this->_tree = rhs._tree;
			return (*this);
		}

		T& operator[](const Key& key) {
			return (insert(ft::make_pair(key, mapped_type())).first->second);	//check немного отличается
		}

		allocator_type get_allocator() const{
			return (this->_tree.get_allocator());
		}

		T& at(const Key& key){
			iterator tmp;

			tmp = find(key);
			if (tmp == this->end())
				throw std::length_error("error vector::max_size");
			return (tmp->second);
		}

		const T& at(const Key& key) const {
			const_iterator tmp;

			tmp = find(key);
			if (tmp == this->end())
				throw std::length_error("error vector::max_size");
			return (tmp->second);
		}

		iterator begin() {
			return (this->_tree.begin());
		}

		const_iterator begin() const {
			return (this->_tree.begin());
		}

		iterator end() {
			return (this->_tree.end());
		}

		const_iterator end() const {
			return (this->_tree.end());
		}

		reverse_iterator rbegin() {
			return (this->_tree.rbegin());
		}

		const_reverse_iterator rbegin() const {
			return (this->_tree.rbegin());
		}

		reverse_iterator rend() {
			return (this->_tree.rend());
		}

		const_reverse_iterator rend() const {
			return (this->_tree.rend());
		}

		bool empty() const {
			return (this->_tree.empty());
		}

		size_type size() const {
			return (this->_tree.size());
		}

		size_type max_size() const {
			return (std::numeric_limits<size_type>::max() / sizeof(ft::RBnode<mapped_type>));
			//return (this->_tree.max_size());
		}

		void clear() {
			this->_tree.clear();
		}

		ft::pair<iterator, bool> insert(const value_type& val) {
			return (this->_tree.insert(val));
		}

		iterator insert(iterator hint, const value_type& val) {
			return (this->_tree.insert(hint, val));
		}

		template <class InputIterator>
		void insert(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) {
			this->_tree.insert(first, last);
		}

		void erase(iterator pos) {
			this->_tree.erase(pos);
		}

		void erase(iterator first, iterator last) {
			this->_tree.erase(first, last);
		}

		size_type erase (const Key& key) {
			return (this->_tree.erase(ft::make_pair(key, mapped_type())));
		}

		void swap(map& other) {
			this->_tree.swap(other._tree);
		}

		size_type count(const Key& key) const {
			return (this->_tree.count(ft::make_pair(key, mapped_type())));
		}

		iterator find(const Key& key) {
			return (this->_tree.find(ft::make_pair(key, mapped_type())));
		}

		const_iterator find(const Key& key) const {
			return (this->_tree.find(ft::make_pair(key, mapped_type())));
		}

		ft::pair<iterator,iterator> equal_range(const Key& key) {
			return (this->_tree.equal_range(ft::make_pair(key, mapped_type())));
		}

		ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const {
			return (this->_tree.equal_range(ft::make_pair(key, mapped_type())));
		}

		iterator lower_bound(const Key& key) {
			return (this->_tree.lower_bound(ft::make_pair(key, mapped_type())));
		}

		const_iterator lower_bound(const Key& key) const {
			return (this->_tree.lower_bound(ft::make_pair(key, mapped_type())));
		}

		iterator upper_bound(const Key& key) {
			return (this->_tree.upper_bound(ft::make_pair(key, mapped_type())));
		}

		const_iterator upper_bound(const Key& key) const {
			return (this->_tree.upper_bound(ft::make_pair(key, mapped_type())));
		}

		key_compare key_comp() const {
			return key_compare();
		}

		value_compare value_comp() const {
			return (this->_tree.value_comp());
		}
 	};

	template <typename Key, typename T, typename Compare, typename Alloc>
	void  swap(ft::map<Key, T, Compare, Alloc>& lhs, ft::map<Key, T, Compare, Alloc>& rhs) {
		lhs.swap(rhs);
	}

	template <typename Key, typename T, typename Compare, typename Alloc>
	bool operator==(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs) {
		if(lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <typename Key, typename T, typename Compare, typename Alloc>
	bool operator!=(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs) {
		return (!(lhs == rhs));
	}

	template <typename Key, typename T, typename Compare, typename Alloc>
	bool operator<(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <typename Key, typename T, typename Compare, typename Alloc>
	bool operator<=(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs) {
		return (!(rhs < lhs));
  }

	template <typename Key, typename T, typename Compare, typename Alloc>
	bool operator>(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs) {
		return (rhs < lhs);
  }

	template <typename Key, typename T, typename Compare, typename Alloc>
	bool operator>=(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs) {
		return (!(lhs < rhs));
	}
};

#endif
