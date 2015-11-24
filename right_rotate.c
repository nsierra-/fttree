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
