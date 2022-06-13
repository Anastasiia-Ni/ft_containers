/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:12:26 by anifanto          #+#    #+#             */
/*   Updated: 2022/06/12 14:20:39 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MAP_HPP
#define MAP_HPP

#include "containers.hpp"
#include "binary_tree.hpp"
#include "iterators.hpp"


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
			typedef ft::map_iterator<value_type, ft::binary_tree<value_type> >				iterator;
			typedef ft::map_iterator<const value_type, const ft::binary_tree<value_type> >	const_iterator;
			typedef ft::reverse_iterator<iterator>											reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>									const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type					difference_type;

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

				//SEARCH(T,k):
				// ЕСЛИ T == NIL ИЛИ k == T.KEY
				//     ВЫВОД T
				// ИНАЧЕ
				//     ЕСЛИ k < T.KEY
				//         ВЫВОД SEARCH(T.LEFT, k)
				//     ИНАЧЕ
				//         ВЫВОД SEARCH(T.RIGHT, k)
				if (tmp != _nl_node && tmp->_value.first == k)
					return tmp;
				while (tmp != _nl_node) {
					if (!_comp(tmp->_value.first, k) && tmp->_value.first != k) {
						if ( tmp->_left_node == _nl_node)
							return tmp;
						tmp = tmp->_left_node;
						continue;
					}
					else if (_comp(tmp->_value.first, k)) {
						if ( tmp->_right_node == _nl_node)
							return tmp;
						tmp = tmp->_right_node;
						continue;
					}
					else {
						return tmp;
					}
				}
				return (_nl_node);
			}

			b_tree	*find_max_node() const {
				b_tree	*tmp;

				tmp = _root;
				if (tmp != _nl_node){
					while (tmp->_right_node != _nl_node)
						tmp = tmp->_right_node;
				}
				return (tmp);
			}

		public:

		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
					_alloc(alloc), _comp(comp), _size(0), _root(), _nl_node() {}

		// template <class InputIterator>
		// map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
		// 	const allocator_type& alloc = allocator_type()) : _alloc(alloc), _comp(comp), _size(0), _root(), _null_node()
		// {
		// 	insert(first, last);
		// }

		// map (const map& other) : _size(0), _root(), _nl_node()
		// {
		// 	_alloc = other._alloc;
		// 	_comp = other._comp;
		// 	_alloc_tree = other._alloc_tree;
		// 	insert(other.begin(), other.end());
		// }

			~map() {
				clear();
			}

		// 	map& operator=(const map& rhs) {
		// 		if (*this == rhs)
		// 			return (*this);
		// 		clear();
		// 		_alloc = rhs._alloc;
		// 		_comp = rhs._comp;
		// 		_alloc_tree = rhs._alloc_tree;
		// 		insert(rhs.begin(), rhs.end());
		// 		return (*this);
		// 	}

		// 	allocator_type get_allocator() const{
		// 		return(this->_alloc);
		// 	}

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
			// 	return (this->_size == 0);
			// }

			// size_type size() const {
			// 	return (this->_size);
			// }

			// size_type max_size() const {
			// 	return(this->_alloc_tree.max_size());
			// }

			void clear() {
				erase(begin(), end());
			}

			// ft::pair<iterator, bool> insert(const value_type& value) {

			// }

			// iterator insert(iterator hint, const value_type& value) {

			// }

			// template <class InputIt>
			// void insert( InputIt first, InputIt last ){

			// }

			// void erase(iterator pos) {

			// }

			void erase(iterator first, iterator last) {
				iterator tmp;

				while (first != last) {
					tmp = first;
					first++;
					erase(tmp);
				}
			}

			size_type erase( const Key& key ) {
				b_tree *tmp;

				tmp = findnode(key, this->_root);
				if (tmp->_value.first == key) {
					erase(tmp);
					return (1);
				}
				return (0);
			}

			void swap(map& other) {
				allocator_type		  tmp_alloc;
				key_compare				tmp_comp;
				size_type				tmp_size;
				std::allocator<b_tree> 	tmp_alloc_tree;
				b_tree					*tmp_root;
				b_tree					*tmp_nl_node;

				tmp_alloc = other._alloc;
				tmp_comp = other._comp;
				tmp_size = other._size;
				tmp_alloc_tree = other._alloc_tree;
				tmp_root = other._root;
				tmp_nl_node = other._nl_node;
				other._alloc = this->_alloc;
				other._comp = this->_comp;
				other._size = this->_size;
				other._alloc_tree = this->_alloc_tree;
				other._root = this->_root;
				other._nl_node = this->_nl_node;
				this->_alloc = tmp_alloc;
				this->_comp = tmp_comp;
				this->_size = tmp_size;
				this->_alloc_tree = tmp_alloc_tree;
				this->_root = tmp_root;
				this->_nl_node = tmp_nl_node;
			}

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
