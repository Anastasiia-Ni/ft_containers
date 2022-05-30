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
			// typedef ft::iterator_vector<T>					iterator;
			// typedef ft::const_iterator_vector<T>			const_iterator;
			// typedef ft::reverse_vector_iterator<T>			reverse_iterator;
			// typedef ft::const_reverse_vector_iterator<T>	const_reverse_iterator;
		private:
			allocator_type	_alloc;
			pointer			_ptr;
			size_type		_size;
			size_type		_capacity;

		public:
			explicit vector (const allocator_type& alloc = allocator_type()) : 
				_alloc(alloc),
				_ptr(NULL),
				_size(0),
				_capacity(0) {}

		explicit vector (size_type n, const value_type& value = value_type(),
						 const allocator_type& alloc = allocator_type()) : _alloc(alloc)
		{
			_ptr = _alloc.allocate(n);
			_size = n;
			_capacity = n;
			for (size_type i = 0; i < n; i++)
				_ptr[i] = value;

		}
			~vector(){
				//clear(); //add func clear()
				// if (capacity() > 0)
				// _alloc.deallocate(_ptr, capacity()); //add func capacity
			}

			vector(const vector& src){
				this->_alloc = src._alloc;
				this->_start = NULL;
				this->_size = 0;
				this->_capacity = 0;
				*this = src;
			}
			vector &operator=(const vector &rhs){
				this->clear();
				this->_alloc = rhs._alloc;
				this->reserve(rhs._size);
				for(size_type i = 0; i < rhs._size; i++)
					push_back(rhs[i]);
				return (*this);
			}
			//get_allocator // ???
			// at
			// operator[]
			// front
			// back 
			// data 
			// begin 
			// end
			// rbegin
			// rebind
			// empty 
			size_type size() const{
				return (this->_size);
			}
			// max_size 
			void	reserve(size_type new_cap){
				
			}
			size_type capacity() const{
				return (this->_capacity);
			}
			// clear 
			// insert 
			// erase 
			void	push_back( const T& value){
				if (this->_size == 0)
					reserve(1);
				else if (this->_size == this->_capacity)
					reserve(this->_capacity * 2); //check *2
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


//push_back