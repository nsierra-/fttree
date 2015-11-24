/*
* @Author: Work
* @Date:   2015-11-24 01:04:24
* @Last Modified by:   Work
* @Last Modified time: 2015-11-24 02:40:16
*/

#include "stdlib.h"
#include "fttree.h"

static void			tree_dest_helper(t_tree *tree, t_tree_node *x)
{
	t_tree_node		*nil;

	nil = tree->nil;
	if (x != nil)
	{
		tree_dest_helper(tree, x->left);
		tree_dest_helper(tree, x->right);
		tree->destroy_key(x->key);
		tree->destroy_data(x->data);
		free(x);
	}
}

void 				tree_destroy(t_tree *tree)
{
	tree_dest_helper(tree, tree->root->left);
	free(tree->root);
	free(tree->nil);
	free(tree);
}
