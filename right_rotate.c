/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 15:42:15 by nsierra-          #+#    #+#             */
/*   Updated: 2015/12/04 15:42:15 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fttree.h"

void				right_rotate(t_tree *tree, t_tree_node *y)
{
	t_tree_node		*x;
	t_tree_node		*nil;

	nil = tree->nil;
	x = y->left;
	y->left = x->right;
	if (nil != x->right)
		x->right->parent = y;
	x->parent = y->parent;
	if (y == y->parent->left)
		y->parent->left = x;
	else
		y->parent->right = x;
	x->right = y;
	y->parent = x;
}
