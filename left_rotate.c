/*
* @Author: Work
* @Date:   2015-11-24 00:56:34
* @Last Modified by:   Work
* @Last Modified time: 2015-11-24 00:57:10
*/

#include "fttree.h"

void				left_rotate(t_tree *tree, t_tree_node *x)
{
	t_tree_node		*y;
	t_tree_node		*nil;

	nil = tree->nil;
	y = x->right;
	x->right = y->left;
	if (y->left != nil)
		y->left->parent = x;
	y->parent = x->parent;
	if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;
	y->left = x;
	x->parent = y;
}
