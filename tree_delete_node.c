/*
* @Author: Work
* @Date:   2015-11-24 01:06:30
* @Last Modified by:   Work
* @Last Modified time: 2015-11-24 01:45:42
*/

#include <stdlib.h>
#include "fttree.h"
#include "private/tree_internals.h"

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
		tree->destroy_key(z->key);
		tree->destroy_data(z->data);
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
	tree->destroy_key(y->key);
	tree->destroy_data(y->data);
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
