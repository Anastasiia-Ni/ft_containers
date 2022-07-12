/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_tree.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:50:53 by anifanto          #+#    #+#             */
/*   Updated: 2022/07/12 15:50:54 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_TREE_HPP
# define BASE_TREE_HPP

#include "../containers.hpp"

namespace ft
{
	template <typename value_type>
	struct bNode
	{
		value_type		_value;
		bNode			*_left;
		bNode			*_right;
		bNode			*_parent;
		bool			_black;				// black = 1, red = 0

		bNode() : _value(), _left(NULL), _right(NULL), _parent(NULL) { }
		bNode(const value_type _value, bNode *_parent = NULL) : _value(_value), _left(NULL), _right(NULL), _parent(_parent), _black(false) {} // check _value
		~bNode() {
			_left = NULL;
			_right = NULL;
			_parent = NULL;
		}
		bNode(bNode const &other) : _value(other.value), _left(other._left), _right(other._right), _parent(other._parent), _black(other._black) {}

		bNode *max_node(bNode *nd) { //for root
			while (nd && nd->_right)
				nd = nd->_right;
			return (nd);
		}

		bNode *next() {
			if (this->_parent == NULL)
				return (max_node(this)); //this->_right?
			bNode *tmp;
			if (this->_right) {
				tmp = this->_right;
				while (tmp->_left)
					tmp = tmp->_left;
			}
			else {
				tmp = this;
				while (tmp->_parent && tmp->_parent->_right == tmp)
					tmp = tmp->_parent;
				if (tmp->_parent)
					tmp = tmp->_parent;
			}
			return (tmp);
		}

		bNode *prev() {
			if (this->_parent == NULL)
				return (max_node(this)); //this->_right?
			bNode *tmp;
			if (this->_left) {
				tmp = this->_left;
				while (tmp->_right)
					tmp = tmp->_right;
			}
			else {
				tmp = this;
				while (tmp->_parent && tmp->_parent->_left == tmp)
					tmp = tmp->_parent;
				if (tmp->_parent)
					tmp = tmp ->_parent;
			}
			return (tmp);
		}

		//private:
		bNode &operator=(bNode const &rhs) { (void)rhs; }
	};

	template <typename value_type, typename Compare, typename Alloc>
	class baseTree {
		protected:
			typedef bNode <value_type>								node;
			node*													_end;
			node*													_root;
			size_t													_size;
			Compare													_comp;
			typedef typename Alloc::template rebind<node>::other	NodeAlloc;		//from C++ reference -> allocator ->note for node befor C++11
			NodeAlloc												_alloc;

		private:
			baseTree() {}
			baseTree &operator=(baseTree const &rhs) { (void) rhs; } //check

			void clearBaseTree (node *nd) {
				if (nd != NULL) {
					clearBaseTree(nd->_left);
					clearBaseTree(nd->_right);
					this->_alloc.destroy(nd);
					this->_alloc.deallocate(nd, 1);
					this->_size--;
				}
			}

			node *copyBNode(node *nd, node *dst_parent) {
				if (nd) {
					node *tmp = this->_alloc.allocate(1);
					this->_alloc.construct(tmp, node(nd->_value, dst_parent));
					tmp->_black = nd->_black;
					tmp->_left = copyBNode(nd->_left, tmp);
					tmp->_right = copyBNode(nd->_right, tmp);
					return (tmp);
				}
				return (NULL);
			}
		public:
			baseTree(Compare comp, Alloc alloc) : _root(NULL), _size(0), _comp(comp), _alloc(NodeAlloc(alloc)) {
				this->_end = this->_alloc.allocate(1);
				this->_alloc.construct(this->_end, node());
			}

			virtual ~baseTree() {
				clearBaseTree(this->_root);
				this->_alloc.destroy(this->_end);
				this->_alloc.deallocate(this->_end, 1);
			}

			// void clearBaseTree(clearBaseTree const &other) : _root(NULL), _size(other._size), _comp(other._comp), _alloc(other._alloc) {
			// 	this->_end = _alloc.allocate(1);
			// 	this->_alloc.construct(this->_end, node());
			// 	this->_root = copyBNode(other._root, this->_end);
			// }

			node *findNode(value_type value) {
				node *tmp; // = вставить функцию из каждого дерева (this->_root, value)
				(void)value;
				return (tmp == NULL ? this->_end : tmp);
			}

			node *insertNode(value_type value) {	//общая функция для вставки корня если его нет
				if (this->_root != NULL)
					return (NULL); // вставить инсерт для каждого дерева (this->_root, value)
				else {
					this->_root = this->_alloc.allocate(1);
					this->_alloc.construct(this->_root, node(value, this->_end));
					this->_end->right = this->_root;
					this->_size++;
					this->_root->_black = true;
					return (this->_root);
				}
			}

		// 	node* insertNode(node* hint, value_type value) {
		// 		return (_insert(hint, value));  //  вставить инсерт для каждого дерева как выше
		// 	}

		// 			void erase(ValueType value) {
		// 	_erase(_root, value);
		// }
		// void erase(node* pos) {
		// 	_erase(pos, pos->value);
		// }

		// node* begin() const {
		// 	if (_root == NULL)
		// 		return _end;
		// 	node* tmp = _root;
		// 	while (tmp->left)
		// 		tmp = tmp->left;
		// 	return tmp;
		// }
		// 		node*	end() const { return _end; }

		// size_t	getSize() const { return _size; }

		// void	clear() { _deleteTree(_root); _root = NULL; }

		// void	swap(baseTree& x) {
		// 	std::swap(_end, x._end);
		// 	std::swap(_root, x._root);
		// 	std::swap(_size, x._size);
		// 	std::swap(_comp, x._comp);
		// 	std::swap(_alloc, x._alloc);
		// }

		// virtual node* _insert(node* cur, value_type value) = 0;
		// virtual node* _find(node* cur, value_type value) = 0;
		// virtual void _erase(node* cur, value_type value) = 0;

	};

};

#endif