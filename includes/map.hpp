/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:12:26 by anifanto          #+#    #+#             */
/*   Updated: 2022/06/15 19:22:46 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MAP_HPP
#define MAP_HPP

#include "containers.hpp"
#include "utils/binary_tree.hpp"
#include "iterators/map_iterator.hpp"
#include "iterators/random_access_iterator.hpp"
#include "iterators/reverse_iterator.hpp"
#include "utils/utils.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
 	class map
	{
		public:
			typedef Key										key_type;
			typedef T										mapped_type;
			typedef ft::pair<const key_type, mapped_type>	value_type;
			typedef Compare									key_compare;
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
					bool operator() (const value_type &x, const value_type &y) const {
						return comp(x.first, y.first);
					}
			};
			
			typedef size_t																	size_type;
			typedef Alloc																	allocator_type;
			typedef T&																		reference;
 			typedef T const & 																const_reference;
			typedef T*																		pointer;
			typedef const T*																const_pointer;
			typedef ptrdiff_t																difference_type;
			typedef ft::map_iterator<value_type, ft::binary_tree<value_type> >				iterator;
			typedef ft::map_iterator<const value_type, const ft::binary_tree<value_type> >	const_iterator;
			typedef ft::reverse_iterator<iterator>											reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>									const_reverse_iterator;

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

		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type(),  typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) : 
			_alloc(alloc), _comp(comp), _size(0), _root(), _nl_node() {
				insert(first, last);
		}

		map (const map& other) : _size(0), _root(), _nl_node()
		{
			this->_alloc = other._alloc;
			this->_comp = other._comp;
			this->_alloc_tree = other._alloc_tree;
			insert(other.begin(), other.end());
		}

		~map() {
			clear();
		}

		map& operator=(const map& rhs) {
			if (*this == rhs)
				return (*this);
			clear();
			this->_alloc = rhs._alloc;
			this->_comp = rhs._comp;
			this->_alloc_tree = rhs._alloc_tree;
			insert(rhs.begin(), rhs.end());
			return (*this);
		}

		allocator_type get_allocator() const{
			return(this->_alloc);
		}

		T& at(const Key& key){
			iterator tmp;

			tmp = find(key);
			if (tmp == this->end())
				throw std::length_error("error vector::max_size");
			return (tmp->second);
		}

		const T& at(const Key& key) const {
			iterator tmp;

			tmp = find(key);
			if (tmp == this->end())
				throw std::length_error("error vector::max_size");
			return (tmp->second);
		}

		T& operator[](const Key& key) {
			return (insert(ft::make_pair(key, mapped_type())).first->second);
		}

		iterator begin() {
			b_tree *tmp;

			tmp = this->_root;
			if(tmp != _nl_node) {
				while (tmp->_left_node != _nl_node)
				tmp = tmp->_left_node;
			}
			return (iterator(tmp));
		}

		const_iterator begin() const {
			b_tree *tmp;

			tmp = this->_root;
			if(tmp != _nl_node) {
				while (tmp->_left_node != _nl_node)
				tmp = tmp->_left_node;
			}
			return (const_iterator(tmp));
		}

		iterator end() {
			b_tree *tmp;

			tmp = find_max_node();
			if (tmp != _nl_node)
				return (iterator(tmp->_right_node, tmp)); // check
			return (iterator(tmp));
		}

		const_iterator end() const {
			b_tree *tmp;

			tmp = find_max_node();
			if (tmp != _nl_node)
				return (const_iterator(tmp->_right_node, tmp)); // check
			return (const_iterator(tmp));
		}

		reverse_iterator rbegin() {
			return (reverse_iterator(end()));
		}

		const_reverse_iterator rbegin() const {
			return (reverse_iterator(end()));			
		}

		reverse_iterator rend() {
			return (reverse_iterator(begin()));
		}

		const_reverse_iterator rend() const {
			return (reverse_iterator(begin()));
		}

		bool empty() const {
			return (this->_size == 0);
		}

		size_type size() const {
			return (this->_size);
		}

		size_type max_size() const {
			//return (std::numeric_limits<size_type>::max() / sizeof(rb_map_tree<key_type, mapped_type>));
			return(this->_alloc_tree.max_size());
		}

		void clear() {
			erase(begin(), end());
		}

		ft::pair<iterator, bool> insert(const value_type& value) {
			b_tree		*ret;
			b_tree		tmp;
			bool		f;

			f = true;
			if (this->_root == _nl_node)
			{

				this->_root = _alloc_tree.allocate(1);
				this->_alloc.construct(&tmp._value, value);
				this->_alloc_tree.construct(this->_root, tmp);
				ret = this->_root;
				this->_size++;

			}
			else
			{
				b_tree *input_node;
				input_node = findnode(value.first, this->_root);
				this->_alloc.construct(&tmp._value, value);
				if (value.first == input_node->_value.first)
				{
					ret = input_node;
					f = false;
				}
				else if (!_comp(input_node->_value.first, value.first))
				{
					input_node->_left_node = this->_alloc_tree.allocate(1);
					this->_alloc_tree.construct(input_node->_left_node, tmp);
					input_node->_left_node->_parent_node = input_node;
					ret = input_node->_left_node;
					this->_size++;
				}
				else
				{
					input_node->_right_node = this->_alloc_tree.allocate(1);
					this->_alloc_tree.construct(input_node->_right_node, tmp);
					input_node->_right_node->_parent_node = input_node;
					ret = input_node->_right_node;
					this->_size++;
				}
			}
			return (ft::make_pair(iterator(ret), f));
		}

		iterator insert(iterator hint, const value_type& value) {
			iterator	it;
			b_tree		*input_node;
			b_tree		tmp;

			this->_alloc.construct(&tmp._value, value);
			it = hint;
			if (this->_root == _nl_node)
			{
				insert(value);
				return (this->_root);
			}
			if (hint.base() != NULL && hint.base() != _nl_node && _comp(hint->first, value.first) && _comp(hint.first, (++it)->first))
				input_node = findnode(value.first, hint.base());
			else
				input_node = findnode(value.first, this->_root);
			if (value.first == input_node->_value.first)
				return (input_node);
			if (!_comp(input_node->_value.first, value.first))
			{
				input_node->_left_node = this->_alloc_tree.allocate(1);
				this->_alloc_tree.construct(input_node->_left_node, tmp);
				input_node->_left_node->_parent_node = input_node;
				this->_size++;
				return (input_node->_left_node);
			}
			else
			{
				input_node->_right_node = _alloc_tree.allocate(1);
				this->_alloc_tree.construct(input_node->_right_node, tmp);
				input_node->_right_node->_parent_node = input_node;
				this->_size++;
				return (input_node->_right_node);
			}
		}

		template <class InputIterator>
		void insert(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) {
			while (first != last) {
				insert(*first);
				first++;
			}
		}

		void erase(iterator pos) {
			b_tree *tmp;

			tmp = pos.base();
			if (tmp == this->_root) {
				if (tmp->_right_node != _nl_node) {
					if (tmp->_left_node != _nl_node) {
						b_tree *tmp2;
						tmp2 = tmp->_right_node;
						while (tmp2->_left_node != _nl_node)
							tmp2 = tmp2->_left_node;
						tmp->_left_node->_parent_node = tmp2;
						tmp2->_left_node = tmp->_left_node;
					}
					this->_root = tmp->_right_node;
					this->_root->_parent_node = _nl_node;
				}
				else if (tmp->_left_node != _nl_node) {
					this->_root = tmp->_left_node;
					this->_root->_parent_node = _nl_node;
				}
			}
			else {
				if (tmp->_right_node != _nl_node && tmp->_left_node != _nl_node) {
					b_tree *tmp2;
					tmp2 = tmp->_right_node;
					tmp->_right_node->_parent_node = tmp->_parent_node;
					if (tmp->_parent_node->_left_node == tmp)
						tmp->_parent_node->_left_node = tmp->_right_node;
					else
						tmp->_parent_node->_right_node = tmp->_right_node;
					while (tmp2->_left_node != _nl_node)
						tmp2 = tmp2->_left_node;
					tmp2->_left_node = tmp->_left_node;
					tmp->_left_node->_parent_node = tmp2;
				}
				else if (tmp->_right_node == _nl_node && tmp->_left_node != _nl_node) {
					tmp->_left_node->_parent_node = tmp->_parent_node;
					if (tmp->_parent_node->_left_node == tmp)
						tmp->_parent_node->_left_node = tmp->_left_node;
					else
						tmp->_parent_node->_right_node = tmp->_left_node;
				}
				else if (tmp->_left_node == _nl_node && tmp->_right_node != _nl_node) {
					tmp->_right_node->_parent_node = tmp->_parent_node;
					if (tmp->_parent_node->_left_node == tmp)
						tmp->_parent_node->_left_node = tmp->_right_node;
					else
						tmp->_parent_node->_right_node = tmp->_right_node;
				}
				else if (tmp->_right_node == _nl_node && tmp->_left_node == _nl_node) {
					if (tmp->_parent_node->_left_node == tmp)
						tmp->_parent_node->_left_node = _nl_node;
					else
						tmp->_parent_node->_right_node = _nl_node;
				}
			}
			tmp->_left_node = _nl_node;
			tmp->_right_node = _nl_node;
			tmp->_parent_node = _nl_node;
			this->_alloc_tree.destroy(tmp);
			this->_alloc_tree.deallocate(tmp, 1);
			this->_size--;
			if (this->_size == 0)
				this->_root = _nl_node;
		}

		void erase(iterator first, iterator last) {
			iterator tmp;

			while (first != last) {
				tmp = first;
				first++;
				erase(tmp);
			}
		}

		size_type erase (const Key& key) {
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

		size_type count(const Key& key) const {
			return (find(key) != end());
		}

		iterator find(const Key& key) {
			b_tree *res;

			res = findnode(key, this->_root);
			if (res->_value.first == key)
				return (iterator(res));
			return (end());
		}

		const_iterator find(const Key& key) const {
			b_tree *res;

			res = findnode(key, this->_root);
			if (res->_value.first == key)
				return (const_iterator(res));
			return (end());
		}

		// ft::pair<iterator,iterator> equal_range(const Key& key) {
		// 	return (ft::make_pair(this->lower_bound(key), this->upper_bound(key)));
		// }

		// ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const {

		// }

		iterator lower_bound(const Key& key) {
			iterator it;

			for (it = begin(); it != end(); it++) {
				if (! this->_comp(it->first, key))
					break ;
			}
			return (it);
		}

		const_iterator lower_bound(const Key& key) const {
			const_iterator it;

			for (it = begin(); it != end(); it++) {
				if (! this->_comp(it->first, key))
					break ;
			}
			return (it);
		}

		iterator upper_bound(const Key& key) {
			iterator it;

			for (it = begin(); it != end(); it++) {
				if (this->_comp(key, it->first))
					return (it);
			}
			return (this->end());
		}

		const_iterator upper_bound(const Key& key) const {
			const_iterator it;

			for (it = begin(); it != end(); it++) {
				if (this->_comp(key, it->first))
					return (it);
			}
			return (this->end());
		}

		key_compare key_comp() const {
			return (key_compare());
		}

		// std::map::value_compare value_comp() const {
		// 	return (value_compare(key_compare()));
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
