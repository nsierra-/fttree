/*
* @Author: Work
* @Date:   2015-11-24 00:44:49
* @Last Modified by:   Work
* @Last Modified time: 2015-11-24 00:46:54
*/

#include <stdlib.h>
#include "private/misc.h"
#include "fttree.h"

t_tree			*tree_new(int (*comp_fun)(const void *, const void *),
					void (*dest_fun)(void *),
					void (*info_dest_fun)(void *))
{
	t_tree		*new_tree;

	new_tree = safe_malloc(sizeof(t_tree));
	new_tree->compare = comp_fun;
	new_tree->destroy_key = dest_fun;
	new_tree->destroy_info = info_dest_fun;
	new_tree->print_key = NULL;
	new_tree->print_info = NULL;
	new_tree->nil = safe_malloc(sizeof(t_tree_node));
	new_tree->nil->right = new_tree->nil;
	new_tree->nil->left = new_tree->nil;
	new_tree->nil->parent = new_tree->nil;
	new_tree->nil->red = 0;
	new_tree->nil->key = 0;
	new_tree->root = safe_malloc(sizeof(t_tree_node));
	new_tree->root->right = new_tree->nil;
	new_tree->root->left = new_tree->nil;
	new_tree->root->parent = new_tree->nil;
	new_tree->root->key = 0;
	new_tree->root->red = 0;
	return (new_tree);
}
