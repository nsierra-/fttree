/*
* @Author: Work
* @Date:   2015-11-24 01:13:26
* @Last Modified by:   Work
* @Last Modified time: 2015-11-24 01:15:04
*/

#include <stdio.h>
#include "fttree.h"

void				inorder_tree_print(t_tree* tree, t_tree_node* x)
{
	t_tree_node		*nil;
	t_tree_node		*root;

	nil = tree->nil;
	root = tree->root;
	if (!tree->print_info || !tree->print_key)
		return ;
	nil = tree->nil;
	root = tree->root;
	if (x != tree->nil)
	{
		inorder_tree_print(tree, x->left);
		printf("info=");
		tree->print_info(x->info);
		printf("  key=");
		tree->print_key(x->key);
		printf("  l->key=");
		if (x->left == nil)
			printf("NULL");
		else
			tree->print_key(x->left->key);
		printf("  r->key=");
		if (x->right == nil)
			printf("NULL");
		else
			tree->print_key(x->right->key);
		printf("  p->key=");
		if (x->parent == root)
			printf("NULL");
		else
			tree->print_key(x->parent->key);
		printf("  red=%i\n", x->red);
		inorder_tree_print(tree, x->right);
	}
}

void tree_print(t_tree *tree)
{
	inorder_tree_print(tree, tree->root->left);
}
