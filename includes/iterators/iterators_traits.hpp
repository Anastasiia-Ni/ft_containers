#ifndef ITERATORS_TRAITS_HPP
#define ITERATORS_TRAITS_HPP

#include <cstddef>
#include <iostream>

namespace ft
{
	/* Iterator Categorie Tags */
    struct input_iterator_tag{};
    struct output_iterator_tag{};
    struct forward_iterator_tag: public input_iterator_tag{};
    struct bidirectional_iterator_tag: public forward_iterator_tag{};
    struct random_access_iterator_tag: public bidirectional_iterator_tag{};
	
	template <class Iterator>
	class iterator_traits {
		public:
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::iterator_category	iterator_category;
	};

	template <typename T>
	class iterator_traits<T*> {
		public:
			typedef T										value_type;
			typedef T*										pointer;
			typedef T&										reference;
			typedef ptrdiff_t								difference_type;
			typedef random_access_iterator_tag				iterator_category;
	};

	template <typename T>
	class iterator_traits<const T*> {
		public:
			typedef T										value_type;
			typedef const T*								pointer;
			typedef const T&								reference;
			typedef ptrdiff_t								difference_type;
			typedef random_access_iterator_tag				iterator_category;
	};
}

#endif
