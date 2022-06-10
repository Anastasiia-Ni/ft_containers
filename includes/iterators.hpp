/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:42:42 by anifanto          #+#    #+#             */
/*   Updated: 2022/06/06 16:55:53 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ITERATORS_HPP
#define ITERATORS_HPP

#include "containers.hpp"

namespace ft
{
	struct input_iterator_tag { };
	struct output_iterator_tag { };
	struct forward_iterator_tag : public input_iterator_tag { };
	struct bidirectional_iterator_tag : public forward_iterator_tag { };
	struct random_access_iterator_tag : public bidirectional_iterator_tag { };

	template <class iterator>
	struct iterator_traits {
		typedef typename iterator::difference_type		difference_type;
		typedef typename iterator::value_type			value_type;
		typedef typename iterator::pointer				pointer;
		typedef typename iterator::reference			reference;
		typedef typename iterator::iterator_category	iterator_category;
	};

	template <class T>
	struct iterator_traits <T*> {
		typedef ft::random_access_iterator_tag	iterator_category;
		typedef T								value_type;
		typedef ptrdiff_t						difference_type;
		typedef T*								pointer;
		typedef T&								reference;
	};
	template <class T>
	struct iterator_traits <const T*> {
		typedef ft::random_access_iterator_tag	iterator_category;
		typedef T								value_type;
		typedef ptrdiff_t						difference_type;
		typedef const T*						pointer;
		typedef const T&						reference;
	};

	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator {
		typedef T        	value_type;
		typedef Distance 	difference_type;
		typedef Pointer  	pointer;
		typedef Reference	reference;
		typedef Category 	iterator_category;
	};

	template <class T>
	class random_access_iterator : public iterator<std::random_access_iterator_tag, T>
	{
	public:
		typedef typename iterator<ft::random_access_iterator_tag, T>::value_type			value_type;
		typedef typename iterator<ft::random_access_iterator_tag, T>::difference_type		difference_type;
		typedef typename iterator<ft::random_access_iterator_tag, T>::iterator_category		iterator_category;
		typedef T*																			pointer;
		typedef T&																			reference;

	private:
		pointer	_i;

	public:
		random_access_iterator (void) : _i(0) {}
		random_access_iterator (pointer element) : _i(element) {}
		random_access_iterator (const random_access_iterator& it) : _i(it._i){}
		virtual ~random_access_iterator () {}

		random_access_iterator& operator=(const random_access_iterator& it)
		{
			this->_i = it._i;
			return (*this);
		}

		random_access_iterator& operator++ (void) 	//prefix
		{
			this->_i++;
			return (*this);
		}

		random_access_iterator operator++ (int)	//postfix
		{
			random_access_iterator tmp(*this);
			this->_i++;
			return (tmp);
		}

		random_access_iterator& operator-- (void) 	//prefix
		{
			this->_i--;
			return (*this);
		}

		random_access_iterator operator-- (int)	//postfix
		{
			random_access_iterator tmp(*this);
			this->_i--;
			return (tmp);
		}
		reference operator* (void) const {
			return (*this->_i);
		}

		random_access_iterator& operator+= (difference_type n) {
			this->_i += n;
			return (*this);
		}

		random_access_iterator operator+ (difference_type n) const {
			return (this->_i + n);
		}
		//operator+ 2 parametrs 

		random_access_iterator& operator-= (difference_type n) {
			this->_i -= n;
			return (*this);
		}

		pointer operator->(void) const {
			return (this->_i);
		}

		random_access_iterator operator- (difference_type n) const {
			return (this->_i + n);
		}
		//operator- 2 parametrs

		reference operator[] (difference_type n) const {
			return (*(this->_i + n));
		}

		pointer base() const {
			return (this->_i);
		}

		// ... to be continue
		operator ft::random_access_iterator<const T>() const {
			return ft::random_access_iterator<const T>(_i);
		}


/* ниже переписать функцию !!! без friends*/
		friend bool operator==(const random_access_iterator& lhs, const random_access_iterator& rhs) { 
			return (lhs.base() == rhs.base()); 
		}

		friend bool operator!=(const random_access_iterator& lhs, const random_access_iterator& rhs) { 
			return (lhs.base() != rhs.base()); 
		}

		friend bool operator>=(const random_access_iterator& lhs, const random_access_iterator& rhs) { 
			return (lhs.base() >= rhs.base()); 
		}

	};


	template<typename ItLrs, typename ItRhs>
	typename random_access_iterator<ItLrs>::difference_type
	operator-(const random_access_iterator<ItLrs> &lhs, const random_access_iterator<ItRhs> &rhs) { 
		return (lhs.base() - rhs.base()); 
	}

	template<typename It>
	typename random_access_iterator<It>::difference_type
	operator-(const random_access_iterator<It> &lhs, const random_access_iterator<It> &rhs) { 
		return (lhs.base() - rhs.base()); 
	}

	template<typename It>
	random_access_iterator<It>
	operator+(typename random_access_iterator<It>::difference_type n, const random_access_iterator<It> &i) {
		return (random_access_iterator<It>(i.base() + n)); 
	}

	template <class iterator>
	class reverse_iterator {
	public:
		typedef iterator												iterator_type;
		typedef typename iterator_traits<iterator>::difference_type		difference_type;
		typedef typename iterator_traits<iterator>::value_type			value_type;
		typedef typename iterator_traits<iterator>::pointer				pointer;
		typedef typename iterator_traits<iterator>::reference			reference;
		typedef typename iterator_traits<iterator>::iterator_category	iterator_category;
	private:
		iterator_type	_ri;
	public:
		reverse_iterator () : _ri() {}
		explicit reverse_iterator (iterator_type it) : _ri(it) {}

		template <class Iterator>
		reverse_iterator (const reverse_iterator<iterator> & it) : _ri(it.base()) {}

		virtual ~reverse_iterator() {}
		iterator_type base() const {
			return (_ri);
		}

		//current

		reverse_iterator &operator++(void) //pre_fix
		{
			this->_ri--;
			return(*this);
		}

		reverse_iterator operator++(int) //post_fix
		{
			reverse_iterator tmp(*this);
			this->_ri--;
			return(tmp);
		}

		reverse_iterator &operator--(void) //pre_fix
		{
			this->_ri++;
			return(*this);
		}

		reverse_iterator operator--(int) //post_fix
		{
			reverse_iterator tmp(*this);
			this->_ri++;
			return(tmp);
		}
		// to be continue...
	};




	template <class Iterator> // maybe move to utils
	typename iterator_traits<Iterator>::difference_type distance (Iterator first, Iterator last)
	{
		typename iterator_traits<Iterator>::difference_type n;
		n = 0;
		while (first != last)
		{
			first++;
			n++;
		}
		return (n);
	}
};

#endif