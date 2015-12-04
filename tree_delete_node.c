/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_delete_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 15:14:59 by nsierra-          #+#    #+#             */
/*   Updated: 2015/12/04 15:15:00 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "fttree.h"
#include "private/tree_internals.h"

static void			delete_if_needed(t_tree *tree, t_tree_node *node)
{
	if (tree->destroy_key)
		tree->destroy_key(node->key);
	if (tree->destroy_data)
		tree->destroy_data(node->data);
}

static void			delete_node(
						t_tree *tree,
						t_tree_node *x,
						t_tree_node *y,
						t_tree_node *z)
{
	if (y != z)
	{

		if (!(y->red))
			tree_delete_fixup(tree, x);
		delete_if_needed(tree, z);
		y->left = z->left;
		y->right = z->right;
		y->parent = z->parent;
		y->red = z->red;
		z->right->parent = y;
		z->left->parent = y;
		if (z == z->parent->left)
			z->parent->left = y;
		else
			z->parent->right = y;
		free(z);
		return ;
	}
	delete_if_needed(tree, y);
	if (!(y->red))
		tree_delete_fixup(tree, x);
	free(y);
}

void				tree_delete_node(t_tree *tree, t_tree_node *z)
{
	t_tree_node		*y;
	t_tree_node		*x;

	y = ((z->left == tree->nil) || (z->right == tree->nil)) ? z : tree_successor(tree, z);
	x = (y->left == tree->nil) ? y->right : y->left;
	if (tree->root == (x->parent = y->parent))
		tree->root->left = x;
	else
	{
		if (y == y->parent->left)
			y->parent->left = x;
		else
			y->parent->right = x;
	}
	delete_node(tree, x, y, z);
}
