/*
* @Author: Work
* @Date:   2015-11-24 01:01:17
* @Last Modified by:   Work
* @Last Modified time: 2015-11-24 01:02:18
*/

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
