/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:32:29 by anifanto          #+#    #+#             */
/*   Updated: 2022/06/06 18:12:31 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef VECTOR_HPP
#define VECTOR_HPP

#include "containers.hpp"
#include "iterators.hpp"
#include "utils.hpp"

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
			typedef ptrdiff_t								difference_type; // typedef typename ft::iterator_traits<iterator>::difference_type
			typedef ft::random_access_iterator<T>			iterator; // typedef ft::random_access_iterator<value_type>
			typedef ft::random_access_iterator<const T>		const_iterator; // typedef ft::random_access_iterator<const value_type>
			typedef ft::reverse_iterator<T>					reverse_iterator;
			typedef ft::reverse_iterator<const T>			const_reverse_iterator;
			// typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;

		private:
			allocator_type	_alloc;
			pointer			_arr;
			pointer			_end;
			size_type		_capacity;

		public:
			explicit vector (const allocator_type& alloc = allocator_type()) :
				_alloc(alloc),
				_arr(NULL),
				_end(NULL),
				_capacity(0) {}

			explicit vector (size_type n, const value_type& value = value_type(),
						 const allocator_type& alloc = allocator_type()) : _alloc(alloc)
			{
				_arr = _alloc.allocate(n);
				_end = _arr;
				_capacity = n;
				for (size_type i = 0; i < n; i++, _end++)
					_alloc.construct(_end, value);
			}

			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
			{
				difference_type dist = ft::distance(first, last);
				_alloc = alloc;
				_arr = _alloc.allocate(dist);
				_end = _arr;
				_capacity = dist;
				while(size() != _capacity)
				{
					_alloc.construct(_end, *first);
					first++;
					_end++;
				}
			}

			~vector() {
				clear();
				if (capacity() > 0)
					_alloc.deallocate(_arr, capacity());
			}

			vector(const vector& src) : _alloc(src._alloc), _arr(NULL), _end(NULL), _capacity(0)
			{
				this->operator=(src); // ??? было *this = src; //
			}

			vector &operator=(const vector &rhs) {
				if (this == &rhs)
					return (*this);
				clear();
				this->_arr = this->_alloc.allocate(rhs.size());
				this->_end = this->_arr;
				this->_capacity = rhs.size();
				for(const_iterator it = rhs.begin(); it != rhs.end(); it++) {
					this->_alloc.construct(this->_end, *it);
					this->_end++;
				}
				return (*this);
			}

			allocator_type	get_allocator() const {
				return (this->_alloc);
			}

			reference at(size_type pos) {
				if (pos > size())
					throw std::out_of_range("index out of range");
				return (*(this->_arr + pos));
			};

			const_reference at(size_type pos) const {
				if (pos > size())
					throw std::out_of_range("index out of range");
				return (*(this->_arr + pos));
			};

			reference operator[] (size_type pos) {
				return (*(this->_arr + pos));
			}

			const_reference operator[] (size_type pos) const {
				return (*(this->_arr + pos));
			}

			iterator	begin() {
				return (iterator(this->_arr));
			}

			const_iterator begin() const {
				return (const_iterator(this->_arr));
			}

			reference front() {
				return (*(this->_arr));
			}

			const_reference front() const {
				return (*(this->_arr));
			}

			reference back () {
				return (*(this->_end - 1));
			}

			const_reference back() const {
				return (*(this->_end - 1));
			}

			// T *data () {};
			// const T* data() const {};

			iterator end () {
				return (iterator(this->_end));
			}

			const_iterator end() const {
				return (const_iterator(this->_end));
			}

			reverse_iterator rbegin() {
				return (reverse_iterator(this->_end));
			}
			const_reverse_iterator rbegin() const {
				return (const_reverse_iterator(this->_end));
			}

			reverse_iterator rend() {
				return (reverse_iterator(this->_arr));
			}

			const_reverse_iterator rend() const {
				return (const_reverse_iterator(this->_arr));
			}

			bool empty() const {
				return(size() == 0);
			}

			size_type size() const{
				return (this->_end - this->_arr);
			}

			size_type max_size() const {
				return(allocator_type().max_size());
			}

			void	reserve(size_type new_cap) {
				if (new_cap > max_size()) {
					throw std::length_error("error max_size");
					return ;
				}
				if (this->capacity() < new_cap) {
					pointer old_arr = this->_arr;
					pointer old_end = this->_end;
					size_type old_capacity = capacity();
					size_type old_size = size();
					this->_arr = _alloc.allocate(new_cap);
					this->_end = this->_arr;
					this->_capacity = new_cap;
					if (old_end) {
						while (old_arr != old_end) {
							this->_alloc.construct(this->_end, *old_arr);
							this->_end++;
							old_arr++;
						}
						_alloc.deallocate(old_arr - old_size, old_capacity);
					}
				}
			}

			size_type capacity() const {
				return (this->_capacity);
			}

		 	void	clear () {
				for (pointer i = _arr; i != this->_end; i++)
					_alloc.destroy(i);
				this->_end = this->_arr;
			}

			// iterator insert(iterator pos, const T& value) {
			// 	difference_type res = distance(begin(), pos);
			// 	if (size() < capacity()) {
			// 		iterator it = this->_end;
			// 		if (this->_end + 1 != this->capacity) {
			// 			it++;
			// 		}
			// 		while (it != pos) {
			// 			this->_alloc.construct(it.base(), *(it - 1));
			// 			it--;
			// 		}
			// 		this->_alloc.construct(pos.base(), value);
			// 		this->_end++;
			// 	}
			// 	else {

			// 	}
			// }

			// void insert(iterator pos, size_type count, const T& value) {};
				// template< class InputIt >
				//void insert(iterator pos, InputIt first, InputIt last) {};

			iterator erase(iterator pos) {
				pointer ptr = pos.base();
				if (pos == this->_end)
					this->_alloc.destroy(ptr - 1);
				else {
					this->_alloc.destroy(ptr);
					for (pointer tmp = ptr + 1; tmp + 1 <= this->_end; tmp++) {
						this->_alloc.construct(tmp - 1, *tmp);
						this->_alloc.destroy(tmp);
					}
				}
				this->_end--;
				return (pos);
			}

			iterator erase(iterator first, iterator last) {
				for (;first != last; last--)
					erase(first);
				return iterator(first);
				// difference_type dist = ft::distance(first, last);
				// iterator tmp;
				// for (tmp = first; dist > 0; dist--)		//check!!!
				// 	tmp = erase (tmp);
				// return (tmp);
			}

			void	push_back( const T& value){
				if (this->size() == this->_capacity) {
					if (!(this->size()))
						reserve(1);
					else
						reserve(this->_capacity * 2);
				}	
				this->_alloc.construct(_end, value);
				this->_end++;
			}

			// void pop_back() {};
			void resize(size_type count, T value = T()) {
				if (count > max_size()) {
					throw std::length_error("error vector::max_size");
					return ;
				}
				if (count < this->size) {
					while (count < this->size) {
						this->_size--;
						this->_end--;
						this->_alloc.destroy(_end);
					}
				}
				else {
					if (this->_capacity < count)
						reserve(count); // not realize yet
					while (this->_size != count) {
						this->_alloc.construct(_end, value);
						this->_end++;
						this->_size++;
					}
				}
			}

			// void swap(vector& other) {};
    };

	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) // maybe equal??
	{
		if (lhs.size() != rhs.size())
			return (false);
		typename ft::vector<T,Alloc>::const_iterator it_lhs = lhs.begin();
		typename ft::vector<T,Alloc>::const_iterator it_rhs = rhs.begin();
		while (true)
		{
			if (it_rhs == rhs.end() && it_lhs == lhs.end())
				break;
			if (*it_rhs != *it_lhs || (it_rhs == rhs.end() && it_lhs != lhs.end()))
				return (false);
			it_rhs++;
			it_lhs++;
		}
		return (true);
	}

	template <class T, class Alloc>
		bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(lhs == rhs)); }

	template <class T, class Alloc>
		bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
		bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}

	template <class T, class Alloc>
		bool operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Alloc>
		bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}


	// swap() {};
};

#endif


