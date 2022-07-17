/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:51:13 by anifanto          #+#    #+#             */
/*   Updated: 2022/07/13 20:26:25 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SET_HPP
# define SET_HPP

#include "containers.hpp"
#include "utils/red_black_tree.hpp"
#include "iterators/tree_iterator.hpp"
#include "iterators/reverse_iterator.hpp"
#include "utils/utils.hpp"

namespace ft
{
	template <class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class set
	{
		public:
			typedef T												key_type;
			typedef Compare											key_compare;
			typedef Alloc											allocator_type;
			//typedef Key										key_type;

		private:
			typedef ft::rbTree<T,Compare,Alloc>						tree_type;
		
		public:
			typedef typename tree_type::value_type					value_type;
			typedef typename tree_type::value_compare				value_compare;
			typedef typename tree_type::reference					reference;
			typedef typename tree_type::const_reference				const_reference;
			typedef typename tree_type::pointer						pointer;
			typedef typename tree_type::const_pointer				const_pointer;
			typedef typename tree_type::size_type					size_type;
			typedef typename tree_type::difference_type				difference_type;
			typedef typename tree_type::iterator					iterator;			//typedef typename tree_type::const_iterator
			typedef typename tree_type::const_iterator				const_iterator;
			typedef typename tree_type::reverse_iterator			reverse_iterator;	//typedef typename tree_type::const_reverse_iterator
			typedef typename tree_type::const_reverse_iterator		const_reverse_iterator;
			typedef value_type										Key;

		private:
			tree_type _tree;

		public:

			explicit set(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(comp, alloc) {}

			template<typename InputIterator>
			set(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(comp, alloc) {
				this->insert(first, last);
			}			
			set(const set& other) : _tree(other._tree) {}
			~set() {}

			set& operator=( const set& rhs ) {
				if (this != &rhs)
					this->_tree = rhs._tree;
				return (*this);
			}

			allocator_type get_allocator() const {
				return (this->_tree.get_allocator());
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
				return (std::numeric_limits<size_type>::max() / sizeof(ft::RBnode<key_type>));
				//return (this->_tree.max_size()); // check witn original
			}

			void clear() {
				this->_tree.clear();
			}

			ft::pair<iterator,bool> insert( const value_type& val ) {
				return (this->_tree.insert(val));
			}

			iterator insert( iterator hint, const value_type& val ) {
				(void)hint;		// check another
				return (this->_tree.insert(val).first); 
			}

			template< class InputIt >
			void insert( InputIt first, InputIt last ) {
				this->_tree.insert(first, last);
			}

			void erase( iterator pos ) {
				this->_tree.erase(*pos);
			}

			void erase( iterator first, iterator last ) {
				while (first != last)
					this->_tree.erase(*(first++));
			}

			size_type erase( const Key& key ) {
				return (this->_tree.erase(key));		/// double check
			}

			void swap( set& other ) {
				this->_tree.swap(other._tree);
			}

			size_type count( const Key& key ) const {
				return (this->_tree.count(key));
			}

			iterator find( const Key& key ) {
				return (this->_tree.find(key));
			}

			const_iterator find( const Key& key ) const {
				return (this->_tree.find(key));
			}

			ft::pair<iterator,iterator> equal_range( const Key& key ) {
				return (this->_tree.equal_range(key));
			}

			ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const {
				return (this->_tree.equal_range(key));
			}

			iterator lower_bound( const Key& key ) {
				return (this->_tree.lower_bound(key));
			}

			const_iterator lower_bound( const Key& key ) const {
				return (this->_tree.lower_bound(key));
			}

			iterator upper_bound( const Key& key ) {
				return (this->_tree.upper_bound(key));
			}

			const_iterator upper_bound( const Key& key ) const {
				return (this->_tree.upper_bound(key));
			}

			key_compare key_comp() const {
				return (key_compare());
			}

			value_compare value_comp() const {
				return (this->_tree.value_comp());
			}

			void PrintTree() {		// DELETE
				this->_tree.PrintTree();
			}
    };

	template< class Key, class Compare, class Alloc >
	void swap( ft::set<Key,Compare,Alloc>& lhs, ft::set<Key,Compare,Alloc>& rhs ) {
		lhs.swap(rhs);
	}

	template< class Key, class Compare, class Alloc >
	bool operator==( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs ) {
		if(lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));			
	}

	template< class Key, class Compare, class Alloc >
	bool operator!=( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs ) {
		return (!(lhs == rhs));
	}


	template< class Key, class Compare, class Alloc >
	bool operator<( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs ) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}


	template< class Key, class Compare, class Alloc >
	bool operator<=( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs ) {
		return !(rhs < lhs);
	}

	template< class Key, class Compare, class Alloc >
	bool operator>( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs ) {
		return (rhs < lhs);
	}

	template< class Key, class Compare, class Alloc >
	bool operator>=( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs ) {
		return !(lhs < rhs);
	}
};

#endif