#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include <cstddef>
#include "iterators_traits.hpp"

namespace   ft
{
    template <class T>
    class   Iterator
    {
        public:
            typedef  T value_type;
            typedef  T* pointer;
            typedef  T& reference;
            typedef  std::ptrdiff_t difference_type;
            typedef  std::random_access_iterator_tag iterator_category;

            Iterator(void): _ptr(NULL){}
            Iterator(pointer ptr): _ptr(ptr){}
            
			template <typename U>
            Iterator(const Iterator<U>& other): _ptr(other.base()){}
            
			Iterator&   operator=(const Iterator& rhs)
            {
                this->_ptr = rhs._ptr;
                return (*this);
            }

            
            pointer base() const { return (this->_ptr); }

            reference operator*() const { return *_ptr; }

            pointer operator->() { return _ptr; }

            Iterator& operator++() { _ptr++; return *this; }  

            Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
            
            Iterator& operator--() { _ptr--; return *this; }  
            
            Iterator operator--(int) { Iterator tmp = *this; --(*this); return tmp; }

            Iterator    operator+(difference_type n) const { return (_ptr + n); }

            Iterator    operator-(difference_type n) const { return (_ptr - n); }
            
			Iterator& operator+=(difference_type num) {
				_ptr = _ptr + num;
				return (*this);
			}	
			
			Iterator& operator-=(difference_type num) {
				_ptr = _ptr - num;
				return (*this);
			}

            value_type& operator[](difference_type num) {
				return (*(_ptr + num));
			}

        private:
            pointer    _ptr;
    };

    template<typename T>
    typename ft::Iterator<T>::difference_type  operator==(const ft::Iterator<T> lhs, const ft::Iterator<T> rhs){ return (lhs.base() == rhs.base()); }
    template<typename T1, typename T2>
    typename ft::Iterator<T1>::difference_type operator==(const ft::Iterator<T1> lhs, const ft::Iterator<T2> rhs){ return (lhs.base() == rhs.base()); }

    template<typename T>
    bool  operator!=(const ft::Iterator<T> lhs, const ft::Iterator<T> rhs){ return (lhs.base() != rhs.base()); }
    template<typename T1, typename T2>
    bool operator!=(const ft::Iterator<T1> lhs, const ft::Iterator<T2> rhs){ return (lhs.base() != rhs.base()); }
    
    template<typename T>
    bool  operator>(const ft::Iterator<T> lhs, const ft::Iterator<T> rhs){ return (lhs.base() > rhs.base()); }
    template<typename T1, typename T2>
    bool operator>(const ft::Iterator<T1> lhs, const ft::Iterator<T2> rhs){ return (lhs.base() > rhs.base()); }

    template<typename T>
    bool  operator<(const ft::Iterator<T> lhs, const ft::Iterator<T> rhs){ return (lhs.base() < rhs.base()); }
    template<typename T1, typename T2>
    bool operator<(const ft::Iterator<T1> lhs, const ft::Iterator<T2> rhs){ return (lhs.base() < rhs.base()); }

    template<typename T>
    bool  operator>=(const ft::Iterator<T> lhs, const ft::Iterator<T> rhs){ return (lhs.base() >= rhs.base()); }
    template<typename T1, typename T2>
    bool operator>=(const ft::Iterator<T1> lhs, const ft::Iterator<T2> rhs){ return (lhs.base() >= rhs.base()); }

    template<typename T>
    bool  operator<=(const ft::Iterator<T> lhs, const ft::Iterator<T> rhs){ return (lhs.base() <= rhs.base()); }
    template<typename T1, typename T2>
    bool operator<=(const ft::Iterator<T1> lhs, const ft::Iterator<T2> rhs){ return (lhs.base() <= rhs.base()); }

    template<typename T>
    typename ft::Iterator<T>::difference_type operator-(const ft::Iterator<T> lhs, const ft::Iterator<T> rhs)
    { return (lhs.base() - rhs.base()); }

    template<typename T1, typename T2>
    typename ft::Iterator<T1>::difference_type operator-(const ft::Iterator<T1> lhs, const ft::Iterator<T2> rhs)
    { return (lhs.base() - rhs.base()); }

    template<typename T>
    typename ft::Iterator<T>::difference_type operator+(const ft::Iterator<T> lhs, const ft::Iterator<T> rhs)
    { return (lhs.base() + rhs.base()); }

    template<typename T1, typename T2>
    typename ft::Iterator<T1>::difference_type operator+(const ft::Iterator<T1> lhs, const ft::Iterator<T2> rhs)
    { return (lhs.base() + rhs.base()); }

    template<typename T> ft::Iterator<T> operator+(typename ft::Iterator<T>::difference_type x, typename ft::Iterator<T>& rhs)
    { return (&(*rhs) + x); }
}

#endif
