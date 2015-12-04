/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 15:42:19 by nsierra-          #+#    #+#             */
/*   Updated: 2015/12/04 15:42:19 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fttree.h"

static void			print_node(t_tree *tree, t_tree_node *node)
{
	printf("data = ");
	if (tree->print_data)
		tree->print_data(node->data);
	printf("  key = ");
	if (tree->print_key)
		tree->print_key(node->key);
}

static void			print_side_node(
						t_tree *tree,
						t_tree_node *node,
						const char *text)
{
	printf("%s", text);
	if (node == tree->nil)
		printf("NULL");
	else if (tree->print_key)
		tree->print_key(node->key);
}

void				inorder_tree_print(t_tree *tree, t_tree_node *x)
{
	t_tree_node		*nil;
	t_tree_node		*root;

	nil = tree->nil;
	root = tree->root;
	if (x != tree->nil)
	{
		inorder_tree_print(tree, x->left);
		print_node(tree, x);
		print_side_node(tree, x->left, " | l->key = ");
		print_side_node(tree, x->right, " | r->key = ");
		print_side_node(tree, x->parent, " | p->key = ");
		printf(" | red = %i\n", x->red);
		inorder_tree_print(tree, x->right);
	}
}

void				tree_print(t_tree *tree)
{
	inorder_tree_print(tree, tree->root->left);
}
