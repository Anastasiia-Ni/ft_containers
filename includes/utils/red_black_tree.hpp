/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:12:17 by anifanto          #+#    #+#             */
/*   Updated: 2022/07/14 14:16:03 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

#include "node.hpp"
#include "utils.hpp"
#include "../containers.hpp"

#define RED "\033[31m"
#define BLACK "\033[30m"

namespace ft {

	template <class T, class Compare = std::less<T>, typename Alloc = std::allocator<T> >
	class rbTree {
		public:
			typedef T																		value_type;
			typedef node<T, Alloc>															node_type;
			typedef Compare																	value_compare;
			typedef node_type*																node_ptr;
			typename Alloc::template rebind<node<T, Alloc> >::other							_node_alloc;
			typedef size_t																	size_type;

		private:
			node_ptr													_root;
			node_ptr													_nil;
			size_type													_size;
			value_compare												_comp;

		public:
			rbTree() : _root(NULL), _nil(NULL), _size(0) {
				this->_nil = _node_alloc.allocate(1);
				this->_node_alloc.construct(_nil, value_type());
				this->_nil->left = NULL;
				this->_nil->right = NULL;
				this->_nil->parent = NULL;
				this->_nil->color = black;
				this->_root = _nil;
			}
			/* !!! dopisat constructory/destructor*/

			// explicit rbTree(const value_comp & comp = value_comp(), const allocator_type & alloc = allocator_type()) :
			// 	alloc_value(alloc), alloc_node(node_allocator()), comp(comp) {
			// 	//initNH();
			// 	root = head;
			// 	allocated = 0;
			// }

			// template<class InputIt>
			// rbTree(InputIt first, InputIt last, const value_comp & comp = value_comp(), const allocator_type & alloc = allocator_type(),
			// 	typename enable_if<!std::numeric_limits<InputIt>::is_specialized>::type * = 0) :
			// 	alloc_value(alloc), alloc_node(node_allocator()), comp(comp) {
			// 		//initNH();
			// 		root = head;
			// 		allocated = 0;
			// 		//insert(first, last);
			// }

			// rbTree(const rbTree &other) : alloc_value(other.alloc_node), alloc_node(other.alloc_node), comp(other.comp) {
			// 	*this = other;
			// }

			// rbTree & operator=(const rbTree &other) {
			// 	if (this != &other) {
			// 		//root ? clearSubTree(root) : initNH();
			// 		if (other.allocated) {
			// 			root = alloc_node.allocate(1);
			// 			alloc_node.construct(root, Node<value_type>());
			// 			root->color = other.root->color;
			// 			//root->isNil = other.root->isNil;
			// 			if (other.root->data) {
			// 				root->data = alloc_value.allocate(1);
			// 				alloc_value.construct(root->data, *other.root->data);
			// 			}
			// 			//copyChildRecursive(root, other.root);
			// 		}
			// 		else
			// 			root = head;
			// 		allocated = other.allocated;
			// 	}
			// 	return *this;
			// }
			~rbTree() {
				//clearSubTree(root);
				//clearList(head);
				//alloc_node.deallocate(nil, 1);
			}
		private:
			node_ptr	maximum_key(node_ptr node) const {
				while (node->right != _nil)
					node = node->right;
				return (node);
			}

			node_ptr	minimum_r(node_ptr node) const {
				while (node->left != _nil)
					node = node->left;
				return (node);
			}

			void	insert_balance(node_ptr new_node) {
				(void) new_node;
				printf ("here will be add a balance after insert\n");
			}

			void	delete_balance(node_ptr x_node) {
				(void)x_node;
				printf ("here will be add a balance after delete\n");
			}

			void	rotateRight(node_ptr n) {
				node_ptr tmp = n->left;
				tmp->parent = n->parent; /* при этом, возможно, tmp становится корнем дерева */
				if (n->parent != NULL) {
					if (n->parent->left == n)
						n->parent->left = tmp;
					else
						n->parent->right = tmp;
				}
				n->left = tmp->right;
				if (tmp->right != NULL)
					tmp->right->parent = n;
				n->parent = tmp;
				tmp->right = n;
			}

			void	rotateLeft(node_ptr n) {
				node_ptr tmp = n->right;
				tmp->parent = n->parent; /* при этом, возможно, tmp становится корнем дерева */
				if (n->parent != NULL) {
					if (n->parent->left == n)
						n->parent->left = tmp;
					else
						n->parent->right = tmp;
				}
				n->right = tmp->left;
				if (tmp->left != NULL)
				tmp->left->parent = n;
				n->parent = tmp;
				tmp->left = n;
			}

			void	transplant(node_ptr a_node, node_ptr b_node) // check where
			{
				if (a_node->parent == NULL)
					this->_root = b_node;
				else if (a_node == a_node->parent->left)
					a_node->parent->left = b_node;
				else
					a_node->parent->right = b_node;
				b_node->parent = a_node->parent;
			}

		public:
			size_type	size() const {
				return (this->_size);
			}

			size_type	max_size() const {
				return (this->_node_alloc.max_size());
			}

			node_ptr	get_root() const {
				return (this->_root);
			}

			node_ptr	root() const {
				return (this->_root);
			}

			bool		empty() const {
				return (this->_size == 0);
			}

			node_ptr	begin() const {
				return (minimum_key(this->_root));
			}

			node_ptr	end() const {
				node_ptr max_k;
				max_k = maximum_key(this->_root);
				return max_k->left;
			}

			// void	clear() {
			// 	clear(this->_root);
			// 	this->_root = _nil;
			// 	this->_size = 0;
			// }

			// void	clear(node_ptr node) {
			// 	if (node != _nil)
			// 	{
			// 		clear(node->left);
			// 		clear(node->right);
			// 		_node_alloc.destroy(node);
			// 	}
			// }

			node_ptr	search_key(const value_type data, node_ptr current) const {
				if (current == this->_nil)
						return (NULL);
				if ((*current->value) == data)
						return current;
				if (_comp(data, *(current->value)))
					return search_key(data, current->left);
				else
					return search_key(data, current->right);
			}

			node_ptr	search(const value_type &data) const {
				return search_key(data, this->_root);
			}

			node_ptr	maximum() const {
				if (this->_root == _nil)
					return (NULL);
				return (maximum_key(this->_root));
			}

			node_ptr	minimum() const {
				if (this->_root == this->_nil)
					return (NULL);
				return (minimum_key(this->_root));
			}

			node_ptr	lower_bound(const value_type &data) const {
				node_ptr res = _root;
				node_ptr tmp = _root;
				while (tmp != _nil)
				{
					if (_comp(data, *tmp->value))
					{
						res = tmp;
						tmp = tmp->left;
					}
					else if (_comp(*tmp->value, data))
						tmp = tmp->right;
					else
						return (tmp);
				}
				return (res);
			}

			node_ptr	upper_bound(const value_type &data) const {
				node_ptr  lb_node = lower_bound(data);
				if (*lb_node->value == data)
					return (inOrderSuccessor(lower_bound(data)));
				return (lb_node);
			}

			bool	insert(value_type const &data) {
				if (search_key(data, this->_root) != NULL) // if key alredy exist will add the function !!
					return (false);
				this->_size++;
				add_node(data);
				return (true);
			}

			bool	remove(value_type data) {
				if (search_key(data, _root) == NULL)
					return false;
				delete_node(this->_root, data);
				this->_size--;
				return true;
			}

			void	add_node(const value_type &data) {
				// napisat'
				(void)data;
				printf ("here will be add a node\n");
			}

			void	delete_node(node_ptr node, value_type data) {
				// napisat'
				(void)data;
				(void)node;
				printf ("here will be delete a node\n");
			}

			node_ptr	successor(node_ptr node) { // след значение
				if (node->right != _nil)
					return (minimum_key(node->right));
				node_ptr tmp = node->parent;
				while (tmp != _nil && node == tmp->right)
				{
					node = tmp;
					tmp = tmp->parent;
				}
				return (tmp);
			}

			node_ptr	predecessor(node_ptr node) { // предыдущее значение
				if (node->left != _nil)
					return (maximum_key(node->left));
				node_ptr tmp = node->parent;
				while (tmp != _nil && node == tmp->left)
				{
					node = tmp;
					tmp = tmp->parent;
				}
				return (tmp);
			}

			node_ptr	next(node_ptr node) {
				return (successor(node));
			}

			node_ptr	prev(node_ptr node) {
				return (predecessor(node));
			}

			node_ptr	next(node_ptr node, size_t n) {
				node_ptr	tmp = node;
				for (size_t i = 0; i < n; i++)
				{
					tmp = next(tmp);
					if (tmp == _nil)
						return (_nil);
				}
				return (tmp);
			}

			node_ptr	prev(node_ptr node, size_t n) {
				node_ptr	tmp = node;
				for (size_t i = 0; i < n; i++)
				{
					tmp = prev(tmp);
					if (tmp == _nil)
						return (_nil);
				}
				return (tmp);
			}

			node_ptr	inOrderSuccessor(node_ptr node) const { // for upper bound
				if (node->right != _nil)
					return (minimum_key(node->right));
				node_ptr	tmp = node->parent;
				while (tmp != NULL && node == tmp->right)
				{
					node = tmp;
					tmp = tmp->parent;
				}
				return (tmp);
			}

			// void		swap(red_black_tree &other) //check
			// {
			// 	std::swap(_root, other._root);
			// 	std::swap(_nil, other._nil);
			// }

			node_ptr in0rderPredecessor(node_ptr node) const {
				if (node->left != _nil)
					return (right_most(node->left)); // will add func
				node_ptr	tmp = node->parent;
				while (tmp != NULL && node == tmp->left)
				{
					node = tmp;
					tmp = tmp->parent;
				}
				return (tmp);
			}

			node_ptr	left_most(node_ptr node) const //check where
			{
				while (node->left != _nil)
					node = node->left;
				return (node);
			}

			node_ptr	right_most(node_ptr node) const //check where
			{
				while (node->right != _nil)
					node = node->right;
				return (node);
			}


			/*for print */
			void	print_tree_root(node_ptr root, std::string indent, bool last) {
				if (root == _nil)
					return ;
				std::cout << indent;
				if (last)
				{
					std::cout << "R----";
					indent += "     ";
				}
				else
				{
					std::cout << "L----";
					indent += "|   ";
				}
				std::cout << " [" <<  (*root->data)  << " ] "<< "("<< ((root->color) ? "RED" : "BLACK") << ")" << std::endl;
				print_tree_r(root->left, indent, false);
				print_tree_r(root->right, indent, true);
			}

			void	preorder() {
				preorder(this->_root);
				std::cout << std::endl;
			}

			void	print_tree() {
				if (this->_root != _nil)
					print_tree_root(_root, "", true);
			}

			void	inorder() {
				inorder(this->_root);
				std::cout << std::endl;
			}

			void	postorder() {
				postorder(this->_root);
				std::cout << std::endl;
			}

			void	preorder(node_ptr node) {
				if (node != _nil)
				{
					std::cout << *node->data << "  " ;
					preorder(node->left);
					preorder(node->right);
				}
			}

			void	inorder(node_ptr root) {
				if (root != _nil)
				{
					inorder(root->left);
					std::cout << *root->data << " ";
					inorder(root->right);
				}
			}

			void	postorder(node_ptr root) {
				if (root != _nil)
				{
					postorder(root->left);
					postorder(root->right);
					std::cout << *root->data << " ";
				}
			}
	};
};


#endif
