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
#include "../iterators/tree_iterator.hpp"

#define RED "\033[31m"
#define BLACK "\033[30m"

namespace ft {

	template<typename T, typename Compare, typename Alloc>
	class rbTree {
		private:
			typedef ft::RBnode<T>												node_type;
		public:
			typedef T															value_type;
			typedef Compare														value_compare;
			typedef Alloc														allocator_type;
			typedef typename allocator_type::template rebind<node_type>::other	node_allocator_type;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer						const_pointer;
			typedef typename allocator_type::reference							reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef typename allocator_type::size_type							size_type;
			typedef typename allocator_type::difference_type					difference_type;
			typedef typename node_type::node_ptr								node_ptr;
			typedef typename node_type::const_node_ptr							const_node_ptr;

			typedef ft::tree_iterator<node_ptr,value_type>						iterator;
			typedef ft::const_tree_iterator<const_node_ptr,value_type>			const_iterator;
			typedef ft::reverse_iterator<iterator>								reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;

	 	private:
			size_type			_size;
			node_type			_parent;
			node_ptr			_begin_node;
			value_compare		_comp;
			allocator_type		_allocator;
			node_allocator_type	_node_allocator;


			node_ptr&	_root() {
				return (this->_parent._left);
			}

			const_node_ptr&	_root() const {
				return (const_cast<const_node_ptr&>(this->_parent._left));
			}

			node_ptr		_end_node() {
				return (&this->_parent);
			}

			const_node_ptr	_end_node() const {
				return (const_cast<const_node_ptr>(&this->_parent));
			}

			node_ptr		_get_sibling(node_ptr node) const;
			node_color		_get_node_color(node_ptr node) const;
			void			_rotate_right(node_ptr node);
				//node_ptr tmp = n->left;
				// tmp->parent = n->parent; /* при этом, возможно, tmp становится корнем дерева */
				// if (n->parent != NULL) {
				// 	if (n->parent->left == n)
				// 		n->parent->left = tmp;
				// 	else
				// 		n->parent->right = tmp;
				// }
				// n->left = tmp->right;
				// if (tmp->right != NULL)
				// 	tmp->right->parent = n;
				// n->parent = tmp;
				// tmp->right = n;

			void			_rotate_left(node_ptr node);

				// node_ptr tmp = n->right;
				// tmp->parent = n->parent; /* при этом, возможно, tmp становится корнем дерева */
				// if (n->parent != NULL) {
				// 	if (n->parent->left == n)
				// 		n->parent->left = tmp;
				// 	else
				// 		n->parent->right = tmp;
				// }
				// n->right = tmp->left;
				// if (tmp->left != NULL)
				// tmp->left->parent = n;
				// n->parent = tmp;
				// tmp->left = n;

			// insertion

			node_ptr	_construct_node(const value_type& data) {
				node_ptr new_node = this->_node_allocator.allocate(1);
				this->_allocator.construct(&new_node->_value, data);
				new_node->_color = red;
				new_node->_parent = nullptr;
				new_node->_left = nullptr;
				new_node->_right = nullptr;
				if (this->empty() || this->_comp(data, this->_begin_node->_value))
					this->_begin_node = new_node;
				++this->_size;
				return new_node;
			}

			node_ptr		_insert(node_ptr node, node_ptr new_node, bool& inserted, iterator& pos);
			void			_rebalance_after_insertion(node_ptr node);

			node_ptr	_copy(const_node_ptr node) {
				if (node == nullptr)
					return (nullptr);
				node_ptr new_node = this->_construct_node(node->_value);
				new_node->_left = _copy(node->_left);
				if (new_node->_left != nullptr)
					new_node->_left->_parent = new_node;
				new_node->_right = _copy(node->_right);
				if (new_node->_right != nullptr)
					new_node->_right->_parent = new_node;
				return (new_node);
			}

			// deletion

			void	_destroy_node(node_ptr node) {
				this->_allocator.destroy(&node->_value);
				this->_node_allocator.deallocate(node, 1);
				this->_size--;				
			}
			
			void	_destroy(node_ptr node) {
				if (node != nullptr) {
					_destroy(node->_left);
					_destroy(node->_right);
					this->_destroy_node(node);
				}
			}

			void			_erase(node_ptr root, node_ptr node);
			void			_rebalance_before_erasion(node_ptr root, node_ptr node, node_ptr sibling);
			node_ptr		_replacement_node(node_ptr node) const;
	 	
		 public:
			explicit rbTree(const value_compare& comp, const allocator_type& alloc) : _size(), _parent(), _begin_node(&_parent), _comp(comp), _allocator(alloc), _node_allocator(alloc) {}
			
			rbTree(const rbTree& other) : _size(), _parent(), _begin_node(&_parent), _comp(other._comp), _allocator(other._allocator), _node_allocator(other._node_allocator) {
				if (other._root() != nullptr) {
					this->_root() = this->_copy(other._root());
					this->_root()->_parent = &this->_parent;
				}
			}

			~rbTree() {
				if (this->_root() != nullptr) {
					this->_destroy(this->_root());
					this->_root() = nullptr;
					this->_begin_node = this->_end_node();
				}
			}

			rbTree& operator=(const rbTree& other) {
				if (this != &other) {
					this->clear();
					this->_comp = other._comp;
					if (other._root() != nullptr) {
						this->_root() = this->_copy(other._root());
						this->_root()->_parent = &this->_parent;
					}
				}
				return *this;
			}

			iterator	begin() {
				return (iterator(this->_begin_node));
			}

			const_iterator	begin() const {
					return (const_iterator(this->_begin_node));
			}

			iterator	end() {
				return (iterator(&this->_parent));
			}

			const_iterator	end() const {
				return (const_iterator(&this->_parent));
			}

			reverse_iterator	rbegin() {
				return (reverse_iterator(this->end()));
			}

			const_reverse_iterator	rbegin() const {
				return (const_reverse_iterator(this->end()));
			}

			reverse_iterator	rend() {
				return (reverse_iterator(this->begin()));
			}

			const_reverse_iterator	rend() const {
				return (const_reverse_iterator(this->begin()));
			}

			bool	empty() const {
				return (this->_size == 0);
			}

			size_type	size() const {
				return(this->_size);
			}

			size_type	max_size() const {	// if don't good for set, no need
				return (this->_allocator.max_size());
			}

			ft::pair<iterator,bool>		insert(const value_type& val);
			iterator					insert(iterator position, const value_type& val);
			template<typename InputIterator>
			void	insert(InputIterator first, InputIterator last);
			void						erase(iterator position);
			size_type					erase(const value_type& val);
			void						erase(iterator first, iterator last);
			void						swap(rbTree& other);
			
			void	clear() {
				if (this->_root() != nullptr)
				{
					this->_destroy(this->_root());
					this->_root() = nullptr;
					this->_begin_node = this->_end_node();
				}
			}

			value_compare	value_comp() const;

			iterator									find(const value_type& val);
			const_iterator								find(const value_type& val) const;
			size_type									count(const value_type& val) const;
			iterator									lower_bound(const value_type& val);
			const_iterator								lower_bound(const value_type& val) const;
			iterator									upper_bound(const value_type& val);
			const_iterator								upper_bound(const value_type& val) const;
			ft::pair<iterator,iterator>					equal_range(const value_type& val);
			ft::pair<const_iterator,const_iterator>		equal_range(const value_type& val) const;

			allocator_type	get_allocator() const;

 	};

	template<typename T, typename Compare, typename Alloc>
	void swap(rbTree<T,Compare,Alloc>& first, rbTree<T,Compare,Alloc>& second) {
		first.swap(second);
	}
};


#endif
