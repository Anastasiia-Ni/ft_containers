
#ifndef SET_HPP
# define SET_HPP
#include <memory>
#include <functional>
#include <iostream>
#include "red_black_tree.hpp"

namespace ft
{
    template <class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
    class set
    {
        public:
    		typedef T                                 									key_type;
    		typedef T		                                 							value_type;
    		typedef Compare                                 							key_compare;
    		typedef Compare                                 							value_compare;
    		typedef Alloc                              									allocator_type;
    		typedef typename allocator_type::reference                           		reference;
    		typedef typename allocator_type::const_reference							const_reference;
			typedef typename allocator_type::pointer									pointer;
			typedef typename allocator_type::const_pointer								const_pointer;
			// typedef typename ft::red_black_tree<value_type, value_compare, allocator_type>	tree;
			// typedef typename tree::node_type											node;
			// typedef typename ft::map_iterator<const value_type, const tree, node>					iterator;
			// typedef typename ft::map_iterator<const value_type, const tree, node>		const_iterator;
			typedef typename allocator_type::size_type									size_type;
			typedef ptrdiff_t															difference_type;
			typedef typename ft::reverse_iterator<iterator>								reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>						const_reverse_iterator;
			//typedef node *node_ptr;

		private:
				size_type									_size;
				value_compare								_comp;
				allocator_type								_alloc;
				rb_tree										_tree;

		public:
			constructor


			~set() { }
			set& operator=( const set& other ) {
				//bla bla
				return (*this);
			}
			allocator_type get_allocator() const {
				return (this->_alloc);
			}

			iterator begin();
			const_iterator begin() const;
			iterator end();
			const_iterator end() const;
			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;
			reverse_iterator rend();
			const_reverse_iterator rend() const;
			
			bool empty() const {
				return (this->_size == 0);
			}

			size_type size() const;
			size_type max_size() const;
			void clear();
			std::pair<iterator,bool> insert( const value_type& value );
			template< class InputIt >
			void insert( InputIt first, InputIt last );
			void erase( iterator pos );
			void erase( iterator first, iterator last );
			size_type erase( const Key& key );
			void swap( set& other );
			size_type count( const Key& key ) const;
			iterator find( const Key& key );
			const_iterator find( const Key& key ) const;
			std::pair<iterator,iterator> equal_range( const Key& key );
			std::pair<const_iterator,const_iterator> equal_range( const Key& key ) const;
			iterator lower_bound( const Key& key );
			const_iterator lower_bound( const Key& key ) const;
			iterator upper_bound( const Key& key );
			const_iterator upper_bound( const Key& key ) const;
			key_compare key_comp() const;
			std::set::value_compare value_comp() const;
    };
	template< class Key, class Compare, class Alloc >
bool operator==( const std::set<Key,Compare,Alloc>& lhs,
                 const std::set<Key,Compare,Alloc>& rhs );

	template< class Key, class Compare, class Alloc >
bool operator!=( const std::set<Key,Compare,Alloc>& lhs,
                 const std::set<Key,Compare,Alloc>& rhs );


	template< class Key, class Compare, class Alloc >
bool operator<( const std::set<Key,Compare,Alloc>& lhs,
                const std::set<Key,Compare,Alloc>& rhs );


	template< class Key, class Compare, class Alloc >
bool operator<=( const std::set<Key,Compare,Alloc>& lhs,
                 const std::set<Key,Compare,Alloc>& rhs );

	template< class Key, class Compare, class Alloc >
bool operator>( const std::set<Key,Compare,Alloc>& lhs,
                const std::set<Key,Compare,Alloc>& rhs );

	template< class Key, class Compare, class Alloc >
bool operator>=( const std::set<Key,Compare,Alloc>& lhs,
                 const std::set<Key,Compare,Alloc>& rhs );

	template< class Key, class Compare, class Alloc >
void swap( std::set<Key,Compare,Alloc>& lhs,
           std::set<Key,Compare,Alloc>& rhs );

	
}

#endif