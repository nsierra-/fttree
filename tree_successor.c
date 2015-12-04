/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_successor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 15:42:19 by nsierra-          #+#    #+#             */
/*   Updated: 2015/12/04 15:42:19 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fttree.h"

t_tree_node			*tree_successor(t_tree *tree, t_tree_node *x)
{
	t_tree_node		*y;
	t_tree_node		*nil;
	t_tree_node		*root;

	nil = tree->nil;
	root = tree->root;
	if (nil != (y = x->right))
	{
		while (y->left != nil)
			y = y->left;
		return (y);
	}
	else
	{
		y = x->parent;
		while (x == y->right)
		{
			x = y;
			y = y->parent;
		}
		if (y == root)
			return (nil);
		return (y);
	}
}
