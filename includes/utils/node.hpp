/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:42:08 by anifanto          #+#    #+#             */
/*   Updated: 2022/07/14 14:13:16 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

#include "../containers.hpp"


namespace ft
{
	enum node_color {black = true, red = false};

	template <typename T>
	struct RBnode
	{
		typedef T							value_type;
		typedef RBnode<value_type>*			node_ptr;
		typedef RBnode<value_type>*			const_node_ptr; // тут был  const typedef RBnode<value_type>*			const_node_ptr; с перегруженными min and max в методах

		value_type	_value;
		node_ptr	_parent;
		node_ptr	_left;
		node_ptr	_right;
		node_color	_color;

		RBnode() : _value(), _parent(), _left(), _right(), _color(black) {}
		RBnode(const RBnode& other) : _value(other._value), _parent(other._parent), _left(other._left), _right(other._right), _color(other._color) {}

		~RBnode() {}

		RBnode& operator=(const RBnode& other) {
			if (this != &other) {
				this->_value = other._value;
				this->_parent = other._parent;
				this->_left = other._left;
				this->_right = other._right;
				this->_color = other._color;
			}
			return *this;
		}

		void flip_color() {
			this->_color = (this->_color == red ? black : red);
		}


		node_ptr	tree_min(node_ptr root) {
			while (root->_left != nullptr)
				root = root->_left;
			return root;
		}

		// const_node_ptr tree_min(const_node_ptr root) {
		// 	while (root->_left != nullptr)
		// 		root = root->_left;
		// 	return root;
		// }

		node_ptr tree_max(node_ptr root) {
			while (root->_right != nullptr)
				root = root->_right;
			return root;
		}

		// const_node_ptr tree_max(const_node_ptr root) {
		// 	while (root->_right != nullptr)
		// 		root = root->_right;
		// 	return root;
		// }

	};

};


#endif
