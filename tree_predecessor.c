/*
* @Author: Work
* @Date:   2015-11-24 01:02:38
* @Last Modified by:   Work
* @Last Modified time: 2015-11-24 01:02:48
*/

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
