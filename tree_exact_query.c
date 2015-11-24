/*
* @Author: Work
* @Date:   2015-11-24 01:05:42
* @Last Modified by:   Work
* @Last Modified time: 2015-11-24 01:05:56
*/

#include "fttree.h"

t_tree_node			*tree_exact_query(t_tree *tree, void *q)
{
	t_tree_node		*x;
	t_tree_node		*nil;
	int				comp_val;

	x = tree->root->left;
	nil = tree->nil;
	if (x == nil)
		return(0);
	comp_val = tree->compare(x->key, (int *)q);
	while (0 != comp_val)
	{
		if (1 == comp_val)
			x = x->left;
		else
			x = x->right;
		if (x == nil)
			return(0);
		comp_val = tree->compare(x->key, (int *)q);
	}
	return(x);
}
