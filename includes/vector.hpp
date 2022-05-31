/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:32:29 by anifanto          #+#    #+#             */
/*   Updated: 2022/05/24 19:32:30 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef VECTOR_HPP
#define VECTOR_HPP

// #include <iostream>
// #include <limits>
// #include <memory>
// #include <stdexcept>

#include "containers.hpp"

namespace ft
{
    template <class T, class Alloc = std::allocator<T> >
    class vector
    {
    	public:
			typedef T										value_type;
			typedef Alloc									allocator_type;
			typedef	size_t									size_type;
			typedef T&										reference;
			typedef T const &								const_reference;
			typedef T*										pointer;
			typedef	const T*								const_pointer;
			//typedef ptrdiff_t								difference_type; //?
			typedef ft::iterator_vector<T>					iterator;
			// typedef ft::const_iterator_vector<T>			const_iterator;
			// typedef ft::reverse_vector_iterator<T>			reverse_iterator;
			// typedef ft::const_reverse_vector_iterator<T>	const_reverse_iterator;
		private:
			allocator_type	_alloc;
			pointer			_ptr;
			pointer			_end;
			size_type		_size;
			size_type		_capacity;

		public:
			explicit vector (const allocator_type& alloc = allocator_type()) : 
				_alloc(alloc),
				_ptr(NULL),
				_end(NULL),
				_size(0),
				_capacity(0) {}

			explicit vector (size_type n, const value_type& value = value_type(),
						 const allocator_type& alloc = allocator_type()) : _alloc(alloc)
			{
				_ptr = _alloc.allocate(n);
				_end = _ptr;
				_size = n;
				_capacity = n;
				for (size_type i = 0; i < n; i++, _end++)
					_ptr[i] = value;

			}
			~vector() {
				clear();
				if (capacity() > 0)
					_alloc.deallocate(_ptr, capacity());
			}

			vector(const vector& src){
				this->_alloc = src._alloc;
				this->_start = NULL;
				this->_size = 0;
				this->_capacity = 0;
				*this = src;
			}
			vector &operator=(const vector &rhs) {
				this->clear();
				this->_alloc = rhs._alloc;
				this->reserve(rhs._size);
				for(size_type i = 0; i < rhs._size; i++)
					push_back(rhs[i]);
				return (*this);
			}
			allocator_type	get_allocator() const {
				return (this->_alloc);
			}
			// at
			reference operator[] (size_type pos) {
				return (this->_ptr[pos]);
			}
			const_reference operator[] (size_type pos) const {
				return (this->_ptr[pos]);
			}
			iterator	begin() {
				return (iterator(this->_ptr));
			}
			const_iterator begin() const {
				return (iterator(this->_ptr));
			}
			// reference front() {};
			// const_reference front() const {};
			// reference back () {};
			// const_reference back() const {};
			// T *data () {};
			// const T* data() const {};
			iterator end () {				
				return (iterator(this->_end));
			}
			const_iterator end() const {
			return (iterator(this->_ptr));
			}
			// rbegin
			// rend
			// push_back
			bool empty() const {
				return(this->_size == 0);
			}
			size_type size() const{
				return (this->_size);
			}
			size_type max_size() const {
				return(allocator_type().max_size());
			}
			void	reserve(size_type new_cap){
				if (new_cap <= _capacity)
					return ;
				
			}
			size_type capacity() const {
				return (this->_capacity);
			}
			void	clear () {
				for (pointer i = _ptr; i != this->_end; i++)
					_alloc.destroy(i);
				this->_end = this->_ptr;
				this->_size = 0;
			}
			// insert 
			// erase 
			void	push_back( const T& value){
				if (this->_size == 0)
					reserve(1);
				else if (this->_size == this->_capacity)
					reserve(this->_capacity * 2);
				this->_ptr[this->_size++] = value;
			}
			// resize 
			// swap 
			// operator==
			// operator!=
			// operator<
			// operator<=
			// operator>
			// operator>=

    };
};

#endif


