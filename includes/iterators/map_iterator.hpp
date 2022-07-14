# ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

# include <cstddef> // ptrdiff_t
//# include "iterators_traits.hpp"

namespace ft
{
    template <class Category, class T, class Distance = ptrdiff_t,
			class Pointer = T*, class Reference = T&>
	struct iterator {
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category 	iterator_category;
	};

	template <class T, class U>
	class map_iterator : public iterator<std::bidirectional_iterator_tag, T>
	{
		public:
			typedef typename iterator<std::bidirectional_iterator_tag, T>::value_type			value_type;
			typedef typename iterator<std::bidirectional_iterator_tag, T>::difference_type		difference_type;
			typedef typename iterator<std::bidirectional_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename iterator<std::bidirectional_iterator_tag, T>::pointer				pointer;
			typedef typename iterator<std::bidirectional_iterator_tag, T>::reference			reference;
		private:
			U	*node;
			U	*last;
			U	*nl_node;
		public:
			map_iterator () : node(NULL), last(NULL), nl_node(NULL) {}
			map_iterator (U *elem) : node(elem), last(elem), nl_node(NULL) {}
			map_iterator (U *_node, U *_last) : node(_node), last(_last), nl_node(NULL) {}
			virtual ~map_iterator () {}

			map_iterator(const map_iterator& it) {
				this->node = it.node;
				this->last = it.last;
				this->nl_node = it.nl_node;
			}

			map_iterator & operator=(const map_iterator& it) {
				if (*this == it)
					return (*this);
				this->node = it.node;
				this->last = it.last;
				this->nl_node = it.nl_node;
				return (*this);
			}

			map_iterator &operator++ (void) {	//pre fix
				if (node == nl_node)
					return (*this);
				if (node->_right_node != nl_node)
				{
					node = node->_right_node;
					while (node->_left_node != nl_node)
						node = node->_left_node;
					last = node;
					return (*this);
				}
				while (true)
				{
					if (node->_parent_node == nl_node)
					{
						node = node->_parent_node;
						return (*this);
					}
					if (node->_parent_node->_left_node == node)
					{
						node = node->_parent_node;
						last = node;
						return (*this);
					}
					node = node->_parent_node;
				}
			}

			map_iterator operator++ (int) {		//post fix
				map_iterator tmp(*this);
				if (node == nl_node)
					return (tmp);
				if (node->_right_node != nl_node)
				{
					node = node->_right_node;
					while (node->_left_node != nl_node)
						node = node->_left_node;
					last = node;
					return (tmp);
				}
				while (true)
				{
					if (node->_parent_node == nl_node)
					{
						node = node->_parent_node;
						return (tmp);
					}
					if (node->_parent_node->_left_node == node)
					{
						node = node->_parent_node;
						last = node;
						return (tmp);
					}
					node = node->_parent_node;
				}
			}

			map_iterator &operator-- (void) {	//pre fix
				if (node == nl_node) {
					node = last;
					return (*this);
				}
				if (node->_left_node != nl_node) {
					node = node->_left_node;
					while (node->_right_node != nl_node)
						node = node->_right_node;
					return (*this);
				}
				while (true)
				{
					if (node->_parent_node == nl_node)
					{
						node = node->_parent_node;
						return (*this);
					}
					if (node->_parent_node->_right_node == node)
					{
						node = node->_parent_node;
						return (*this);
					}
					node = node->_parent_node;
				}
			}

			map_iterator operator-- (int) {		//post fix
				map_iterator tmp(*this);
				if (node == nl_node)
				{
					node = last;
					return (tmp);
				}
				if (node->_left_node != nl_node)
				{
					node = node->_left_node;
					while (node->_right_node != nl_node)
						node = node->_right_node;
					return (tmp);
				}
				while (true)
				{
					if (node->_parent_node == nl_node)
					{
						node = node->_parent_node;
						return (tmp);
					}
					if (node->_parent_node->_right_node == node)
					{
						node = node->_parent_node;
						return (tmp);
					}
					node = node->_parent_node;
				}
			}

			bool operator== (const map_iterator& it) const {
				return (this->node == it.node && this->nl_node == it.nl_node);
			}

			bool operator!= (const map_iterator& it) const {
				return (!(*this == it));
			}

			U *base() const {
				return (node);
			}

			reference operator*() const {
				return (node->_value);
			}

			pointer operator->() const {
				return (&(node->_value));
			}

			operator ft::map_iterator<const T, const U> () const {
				return (ft::map_iterator<const T, const U>(node, last));
			}
	};
};

#endif
