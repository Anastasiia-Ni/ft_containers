/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:12:17 by anifanto          #+#    #+#             */
/*   Updated: 2022/06/11 19:12:21 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

#include "containers.hpp"

namespace ft
{
	template <class value_type>
	struct rb_tree
	{
		value_type		_value;
		rb_tree			*_parent_node;
		rb_tree			*_left_node;
		rb_tree			*_right_node;
		bool			black;
	};
};

#endif
