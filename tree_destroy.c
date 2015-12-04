/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 15:15:05 by nsierra-          #+#    #+#             */
/*   Updated: 2015/12/04 15:15:07 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (tree->destroy_key)
			tree->destroy_key(x->key);
		if (tree->destroy_data)
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
