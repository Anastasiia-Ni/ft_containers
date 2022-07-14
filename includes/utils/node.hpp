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
	enum RB_color {black = true, red = false};

	template <typename T, class Alloc = std::allocator<T> >
	struct node
	{
		typedef T			value_type;
		typedef node		*node_ptr;
		typedef Alloc		allocator_type;

		value_type			*value;
		node_ptr			left;
		node_ptr			right;
		node_ptr			parent;
		bool				color;
		allocator_type		alloc;
		//bool			isNl;

		node() : value(NULL), left(NULL), right(NULL), parent(NULL), color(black) { }
		node(const value_type &val) : left(NULL), right(NULL), parent(NULL), color(red) {
			value = alloc.allocate(1);
			alloc.construct(value, val);
		}

		~node() {
			if (value) {
				alloc.destroy(value);
				alloc.deallocate(value, 1);
			}
			left = NULL;
			right = NULL;
			parent = NULL;
		}
		//Node(Node const &other) : value(other.value), left(other.left), right(other.right), parent(other.parent), color(other.color), isNl(other.isNl) {}
		node(const node &other) { *this = other; } // maybe no need

		node &operator=(const node<T, Alloc> &rhs) {
			if (this != &rhs) {
				if (this->value)
					alloc.destroy(this->value);
				this->value = rhs.value;
				this->parent = rhs.parent;
				this->right = rhs.right;
				this->left = rhs.left;
				this->color = rhs.color;
			}
			return *this;
		}

		// node *max_node(node *nd) {
		// 	while (!nd->isNl && !nd->right->isNl)
		// 		nd = nd->right;
		// 	return (nd);
		// }

		// node *min_node(node *nd) {
		// 	while (!nd->isNl && !nd->left->isNl)
		// 		nd = nd->left;
		// 	return (nd);
		// }

		// node *findNext() {	//check
		// 	node *tmp = this;
		// 	if (this->parent == NULL)
		// 		return (max_node(this));
		// 	if (!this->right->isNl) {
		// 		tmp = this->right;
		// 		while (!tmp->left->isNl)
		// 			tmp = tmp->left;
		// 	}
		// 	else {
		// 		tmp = this;
		// 		while (tmp->parent && tmp->parent->right == tmp)
		// 			tmp = tmp->parent;
		// 		if (tmp->parent)
		// 			tmp = tmp->parent;
		// 	}
		// 	return (tmp);
		// }

		// node *findPrev() { //check
		// 	node *tmp = this;
		// 	if (tmp->parent == NULL)
		// 		return (max_node(tmp));
		// 	if (!tmp->left->isNl) {
		// 		return (max_node(tmp->left));
		// 	}
		// 	else {
		// 		while (!tmp->parent->isNl && tmp->parent->left == tmp)
		// 			tmp = tmp->parent;
		// 		if (tmp->parent)
		// 			tmp = tmp ->parent;
		// 	}
		// 	return (tmp);
		// }
	};
};


#endif
