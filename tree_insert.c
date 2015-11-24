/*
* @Author: Work
* @Date:   2015-11-24 00:58:54
* @Last Modified by:   Work
* @Last Modified time: 2015-11-24 02:45:14
*/

#include "fttree.h"
#include "private/misc.h"
#include "private/tree_internals.h"

static void			tree_insert_help(t_tree *tree, t_tree_node *z)
{
	t_tree_node		*x;
	t_tree_node		*y;
	t_tree_node		*nil;

	nil = tree->nil;
	z->right = nil;
	z->left = nil;
	y=tree->root;
	x=tree->root->left;
	while (x != nil)
	{
		y = x;
		if (1 == tree->compare(x->key, z->key))
			x = x->left;
		else
	    	x = x->right;
	}
	z->parent = y;
	if ((y == tree->root) || (1 == tree->compare(y->key, z->key)))
		y->left = z;
	else
		y->right = z;
}

static void		tree_insert_1(t_tree *tree, t_tree_node *x, t_tree_node *y)
{
	y = x->parent->parent->right;
	if (y->red)
	{
		x->parent->red = 0;
		y->red = 0;
		x->parent->parent->red = 1;
		x = x->parent->parent;
	}
	else
	{
		if (x == x->parent->right)
		{
			x = x->parent;
			left_rotate(tree, x);
		}
		x->parent->red = 0;
		x->parent->parent->red = 1;
		right_rotate(tree, x->parent->parent);
	}
}

static void		tree_insert_2(t_tree *tree, t_tree_node *x, t_tree_node *y)
{
	y = x->parent->parent->left;
	if (y->red)
	{
		x->parent->red = 0;
		y->red = 0;
		x->parent->parent->red = 1;
		x = x->parent->parent;
	}
	else
	{
		if (x == x->parent->left)
		{
			x = x->parent;
			right_rotate(tree, x);
		}
		x->parent->red = 0;
		x->parent->parent->red = 1;
		left_rotate(tree, x->parent->parent);
	}
}

t_tree_node		*tree_insert(t_tree *tree, void *key, void *info)
{
	t_tree_node *y;
	t_tree_node *x;
	t_tree_node *new_node;

	x = safe_malloc(sizeof(t_tree_node));
	x->key = key;
	x->info = info;
	y = NULL;
	tree_insert_help(tree, x);
	new_node = x;
	x->red = 1;
	while (x->parent->red)
	{
		if (x->parent == x->parent->parent->left)
			tree_insert_1(tree, x, y);
		else
			tree_insert_2(tree, x, y);
	}
	tree->root->left->red = 0;
	return (new_node);
}
