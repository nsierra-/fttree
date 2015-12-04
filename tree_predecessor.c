/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_predecessor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 15:42:18 by nsierra-          #+#    #+#             */
/*   Updated: 2015/12/04 15:42:18 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fttree.h"

t_tree_node			*tree_predecessor(t_tree *tree, t_tree_node *x)
{
	t_tree_node		*y;
	t_tree_node		*nil;
	t_tree_node		*root;

	nil = tree->nil;
	root = tree->root;
	if (nil != (y = x->left))
	{
		while (y->right != nil)
			y = y->right;
		return (y);
	}
	else
	{
		y = x->parent;
		while (x == y->left)
		{
			if (y == root)
				return (nil);
			x = y;
			y = y->parent;
		}
		return (y);
	}
}
