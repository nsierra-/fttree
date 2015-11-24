/*
* @Author: Work
* @Date:   2015-11-24 01:07:31
* @Last Modified by:   Work
* @Last Modified time: 2015-11-24 01:07:57
*/

#include "fttree.h"

t_stack				*tree_enumerate(t_tree *tree, void *low, void *high)
{
	t_stack			*enum_result_stack;
	t_tree_node		*nil;
	t_tree_node		*x;
	t_tree_node		*last_best;

	nil = tree->nil;
	x = tree->root->left;
	last_best = nil;
	enum_result_stack = stack_new();
	while (nil != x)
	{
		if (1 == (tree->compare(x->key, high)))
			x = x->left;
		else
		{
			last_best = x;
			x = x->right;
		}
	}
	while ((last_best != nil) && (1 != tree->compare(low, last_best->key)))
	{
		stack_push(enum_result_stack, last_best);
		last_best = tree_predecessor(tree, last_best);
	}
	return (enum_result_stack);
}
