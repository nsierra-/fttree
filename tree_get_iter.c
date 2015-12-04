/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_get_iter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 15:15:19 by nsierra-          #+#    #+#             */
/*   Updated: 2015/12/04 15:15:21 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fttree.h"

t_tree_iter			*tree_get_iter(t_tree *tree, void *low, void *high)
{
	t_tree_iter		*enum_result_stack;
	t_tree_node		*nil;
	t_tree_node		*x;
	t_tree_node		*last_best;

	nil = tree->nil;
	x = tree->root->left;
	last_best = nil;
	enum_result_stack = tree_iter_new();
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
		tree_iter_push(enum_result_stack, last_best);
		last_best = tree_predecessor(tree, last_best);
	}
	return (enum_result_stack);
}
