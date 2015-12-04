/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 15:15:13 by nsierra-          #+#    #+#             */
/*   Updated: 2015/12/04 15:15:14 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fttree.h"

t_tree_node			*tree_get(t_tree *tree, void *q)
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
