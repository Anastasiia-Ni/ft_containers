# ifndef TREE_ITERATOR_HPP
#define TREE_ITERATOR_HPP

# include <cstddef>
# include "iterators_traits.hpp"
# include "../utils/node.hpp"

namespace ft
{
    template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator {
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category 	iterator_category;
	};

	template<typename Node_ptr, typename Value>
	class tree_iterator
	{
		public:
			typedef std::bidirectional_iterator_tag		iterator_category;
			typedef Value								value_type;
			typedef ptrdiff_t							difference_type;
			typedef Value*								pointer;
			typedef Value&								reference;
		private:
			Node_ptr _cur_node;
			Node_ptr _nill_node;
		public:
			tree_iterator() : _cur_node(), _nill_node(nullptr) {}

			tree_iterator(const tree_iterator &other) : _cur_node(other._cur_node), _nill_node(other._nill_node) {}

			tree_iterator(const Node_ptr &val) : _cur_node(val), _nill_node(nullptr) {}

			tree_iterator &operator=(const tree_iterator &rhs) {
				if (this != &rhs)
					this->_cur_node = rhs._cur_node;
					this->_nill_node = rhs._nill_node;
				return (*this);
			}

			tree_iterator&	operator=(const Node_ptr& ptr) {
				this->_cur_node = ptr;
				return (*this);
			}

			reference		operator*() const {
				return (_cur_node->_value);
			}
			pointer			operator->() const {
				return (&_cur_node->_value);
			}

			tree_iterator&	operator++() {
				if (_cur_node->_right != _nill_node)
					_cur_node = _cur_node->tree_min(_cur_node->_right);
				else {
					while (_cur_node != _cur_node->_parent->_left) { 
						_cur_node = _cur_node->_parent;
					}
					_cur_node = _cur_node->_parent;
				}
				return (*this);
			}

			tree_iterator	operator++(int) {
				tree_iterator ret(*this);
				++(*this);
				return (ret);
			}

			tree_iterator&	operator--() {
				if (_cur_node->_left != _nill_node)
					_cur_node = _cur_node->tree_max(_cur_node->_left);
				else {
					while (_cur_node == _cur_node->_parent->_left) {	
						_cur_node = _cur_node->_parent;
					}
					_cur_node = _cur_node->_parent;
				}
				return (*this);
			}

			tree_iterator	operator--(int) {
				tree_iterator ret(*this);
				--(*this);
				return (ret);
			}

			Node_ptr	base() const {
				return (this->_cur_node);
			}
	};

	template<typename Node_ptr, typename Value>
	inline bool operator==(const tree_iterator<Node_ptr,Value>& rhs,
				const tree_iterator<Node_ptr,Value>& lhs) {
		return (rhs.base() == lhs.base());
	}

	template<typename Node_ptr, typename Value>
	inline bool operator!=(const tree_iterator<Node_ptr,Value>& rhs,
				const tree_iterator<Node_ptr,Value>& lhs) {
		return (rhs.base() != lhs.base());
	}

	template<typename Const_node_ptr, typename Value>
	class const_tree_iterator
	{
		public: 
			typedef std::bidirectional_iterator_tag		iterator_category;
			typedef Value								value_type;
			typedef ptrdiff_t							difference_type;
			typedef const Value*						pointer;
			typedef const Value&						reference;

		private:
			typedef tree_iterator<typename RBnode<Value>::node_ptr,Value> normal_tree_iterator;
			Const_node_ptr _cur_node;
			Const_node_ptr _nill_node;
		
		public:
			const_tree_iterator() : _cur_node(), _nill_node(nullptr) {}
			const_tree_iterator(const const_tree_iterator& other) : _cur_node(other._cur_node), _nill_node(other._nill_node) {}
			const_tree_iterator(const normal_tree_iterator& other) : _cur_node(other.base()), _nill_node(nullptr) {}
			const_tree_iterator(const Const_node_ptr& val) : _cur_node(val), _nill_node(nullptr) {}
			const_tree_iterator&	operator=(const const_tree_iterator& other) {
				if (this != &other)
					this->_cur_node = other._cur_node;
				return (*this);
			}

			const_tree_iterator&	operator=(const Const_node_ptr& ptr) {
				this->_cur_node = ptr;
				return (*this);
			}

			reference	operator*() const {
				return (_cur_node->_value);
			}

			pointer			operator->() const {
				return (&_cur_node->_value);
			}

			const_tree_iterator&	operator++() {
				if (_cur_node->_right != _nill_node)
					_cur_node = _cur_node->const_tree_min(_cur_node->_right);
				else {
					while (_cur_node != _cur_node->_parent->_left) {
						_cur_node = _cur_node->_parent;
					}
					_cur_node = _cur_node->_parent;
				}
				return (*this);				
			}

			const_tree_iterator	operator++(int) {
				const_tree_iterator ret(*this);
				++(*this);
				return (ret);
			}

			const_tree_iterator&	operator--() {
				if (_cur_node->_left != _nill_node)
					_cur_node = _cur_node->const_tree_max(_cur_node->_left);
				else {
					while (_cur_node == _cur_node->_parent->_left) {
						_cur_node = _cur_node->_parent;
					}
					_cur_node = _cur_node->_parent;
				}
				return (*this);
			}

			const_tree_iterator	operator--(int) {
				const_tree_iterator ret(*this);
				--(*this);
				return (ret);				
			}

			Const_node_ptr	base() const {
				return (this->_cur_node);
			}
	};

	template<typename Const_node_ptr, typename Value>
	inline bool operator==(const const_tree_iterator<Const_node_ptr,Value>& rhs,
				const const_tree_iterator<Const_node_ptr,Value>& lhs) {
		return (rhs.base() == lhs.base());
	}

	template<typename Const_node_ptr, typename Value>
	inline bool operator!=(const const_tree_iterator<Const_node_ptr,Value>& rhs,
				const const_tree_iterator<Const_node_ptr,Value>& lhs) {
		return (rhs.base() != lhs.base());
	}


	template<typename Const_node_ptr, typename Node_ptr, typename Value>
	inline bool operator==(const const_tree_iterator<Const_node_ptr,Value>& rhs,
				const tree_iterator<Node_ptr,Value>& lhs) {
		return (rhs.base() == lhs.base());
	}

	template<typename Const_node_ptr, typename Node_ptr, typename Value>
	inline bool operator!=(const const_tree_iterator<Const_node_ptr,Value>& rhs,
				const tree_iterator<Node_ptr,Value>& lhs) {
		return (rhs.base() != lhs.base());
	}

	template<typename Const_node_ptr, typename Node_ptr, typename Value>
	inline bool operator==(const tree_iterator<Node_ptr,Value>& rhs,
				const const_tree_iterator<Const_node_ptr,Value>& lhs) {
		return (rhs.base() == lhs.base());
	}

	template<typename Const_node_ptr, typename Node_ptr, typename Value>
	inline bool operator!=(const tree_iterator<Node_ptr,Value>& rhs,
				const const_tree_iterator<Const_node_ptr,Value>& lhs) {
		return (rhs.base() != lhs.base());
	}
};

#endif
