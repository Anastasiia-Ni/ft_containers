#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include <cstddef> // ptrdiff_t
# include "iterators_traits.hpp"

namespace ft
{
    template <typename T>
	class random_access_iterator {
	public:
		typedef T							value_type;
		typedef T*							pointer;
		typedef T&							reference;
		typedef ptrdiff_t					difference_type;
		typedef std::random_access_iterator_tag	iterator_category;
	
	private:
		pointer	_p;
	
	public:
		random_access_iterator() : _p(NULL) {}
		random_access_iterator(pointer ptr) : _p(ptr) {}
		~random_access_iterator() {}

		template<typename Iter>
		random_access_iterator(const random_access_iterator <Iter>&other) : _p(other.base()) {}
		
		
		template<typename Iter>
		random_access_iterator &operator=(const random_access_iterator <Iter>&rhs) {
			this->_p = rhs._p;
			return (*this);
		}

		pointer base() const {
			return (this->_p);
		}

		reference operator*() const {
			return (*_p);
		}

		pointer operator->() const {
			return (_p);
		}

		random_access_iterator &operator++() {		//pre_fix
			_p++;
			return (*this);
		}

		random_access_iterator operator++(int) {	//post_fix
			random_access_iterator tmp(*this);
			++_p;
			return (tmp);
		}

		random_access_iterator &operator--() {		//pre_fix
			_p--;
			return *this;
		}

		random_access_iterator operator--(int) {	//post_fix
			random_access_iterator tmp(*this);
			--_p;
			return tmp;
		}

		random_access_iterator &operator+=(difference_type n) {
			this->_p += n;
			return (*this);
		}

		random_access_iterator &operator-=(difference_type n) {
			this->_p -= n;
			return (*this);
		}

		bool operator==(const random_access_iterator &rhs) const {
			return (_p == rhs._p);
		}

		bool operator!=(const random_access_iterator &rhs) const {
			return (_p != rhs._p);
		}

		bool operator>(const random_access_iterator &rhs) const {
			return (_p > rhs._p);
		}

		bool operator<(const random_access_iterator &rhs) const {
			return (_p < rhs._p);
		}

		bool operator>=(const random_access_iterator &rhs) const {
			return (_p >= rhs._p);
		}
		
		bool operator<=(const random_access_iterator &rhs) const {
			return (_p <= rhs._p);
		}

		reference operator[](difference_type n) const {
			return *(*this + n);
		}

		random_access_iterator operator+(difference_type n) const {
			return _p + n;
		}

		random_access_iterator operator-(difference_type n) const {
			return _p - n;
		}

		difference_type operator-(const random_access_iterator &rhs) const {
			return _p - rhs._p;
		}
	};

	// template <typename T>
	// ft::random_access_iterator<T> operator+(typename ft::random_access_iterator<T>::difference_type n, const ft::random_access_iterator<T> &it) {
	// 	return it + n;
	// }

}

#endif
