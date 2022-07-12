/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:12:17 by anifanto          #+#    #+#             */
/*   Updated: 2022/07/12 15:48:33 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

#include "base_tree.hpp"

namespace ft {

	template <typename value_type, typename Compare, typename Alloc>
	class rbTree : public  baseTree<value_type, Compare, Alloc> {
		public:
			using baseTree<value_type, Compare, Alloc>::_comp;
			using baseTree<value_type, Compare, Alloc>::_alloc;
			using baseTree<value_type, Compare, Alloc>::_end;
			using baseTree<value_type, Compare, Alloc>::_root;
			using baseTree<value_type, Compare, Alloc>::_size;
			typedef bNode<value_type>					node;

			rbTree(Compare comp, Alloc alloc) : baseTree<value_type, Compare, Alloc>(comp, alloc) { }

			rbTree(const rbTree& other) : baseTree<value_type, Compare, Alloc>(other) { }

			virtual ~rbTree() { }
		private:
			rbTree() { }
			rbTree& operator=(const rbTree& rhs);

			virtual node* findNodeTree(node* nd, value_type value) {
				while (nd != NULL) {
					if (this->_comp(value, nd->value))
						nd = nd->left;
					else if (this->_comp(nd->value, value))
						nd = nd->right;
					else
						return (nd);
				}
				return (nd);
			}
	};
};


#endif
