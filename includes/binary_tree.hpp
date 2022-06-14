/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:13:00 by anifanto          #+#    #+#             */
/*   Updated: 2022/06/11 19:13:03 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_TREE_HPP
# define BINARY_TREE_HPP

#include "containers.hpp"

namespace ft
{
	template <class value_type>
	struct binary_tree
	{
		public:
			value_type		_value;
			binary_tree		*_parent_node;
			binary_tree		*_left_node;
			binary_tree		*_right_node;

			binary_tree() {
				_value = value_type();
				_parent_node = NULL;
				_left_node = NULL;
				_right_node = NULL;
			}

			explicit binary_tree(const value_type &value, binary_tree *parent = NULL, binary_tree *left = NULL, binary_tree *right = NULL) {
				_value = value;
				_left_node = left;
				_right_node = right;
				_parent_node = parent;
			}

			binary_tree(const binary_tree &node) {
				_value = node._value;
				_left_node = node._left_node;
				_right_node = node._right_node;
				_parent_node = node._parent_node;
			}

			~binary_tree() {};

			binary_tree &operator=(const binary_tree &node)
			{
				if (*this == node)
					return (*this);
				_value = node._value;
				_left_node = node._left_node;
				_right_node = node._right_node;
				_parent_node = node._parent_node;
				return (*this);
			}

			bool operator==(const binary_tree& tree) {
				return (_value == tree._value && _left_node == tree._left_node && _right_node == tree._right_node && _parent_node == tree._parent_node);
			}

			bool operator!=(const binary_tree& tree) {
				return (!(this == tree));
			}
	};
	
	template <class Key, class T>
	struct rb_map_tree
	{
		std::pair<Key, T> 	pair;
		rb_map_tree			*_parent_node;
		rb_map_tree			*_left_node;
		rb_map_tree			*_right_node;
		bool				black;
	};
};

#endif