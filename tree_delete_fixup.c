/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_delete_fixup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 15:14:52 by nsierra-          #+#    #+#             */
/*   Updated: 2015/12/04 15:14:54 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fttree.h"
#include "private/tree_internals.h"

static void			is_red_1(t_tree *tree, t_tree_node *x, t_tree_node *w)
{
	w->red = 0;
	x->parent->red = 1;
	left_rotate(tree, x->parent);
	w = x->parent->right;
}

static void			is_red_2(t_tree *tree, t_tree_node *x, t_tree_node *w)
{
	w->red = 0;
	x->parent->red = 1;
	right_rotate(tree, x->parent);
	w = x->parent->left;
}

static void			tree_delete_fixup_1(
						t_tree *tree,
						t_tree_node *root,
						t_tree_node *x,
						t_tree_node *w)
{
	if ((!w->right->red) && (!w->left->red))
	{
		w->red = 1;
		x = x->parent;
	}
	else
	{
		if (!w->right->red)
		{
			w->left->red = 0;
			w->red = 1;
			right_rotate(tree, w);
			w = x->parent->right;
		}
		w->red = x->parent->red;
		x->parent->red = 0;
		w->right->red = 0;
		left_rotate(tree, x->parent);
		x = root;
	}
}

static void			tree_delete_fixup_2(
						t_tree *tree,
						t_tree_node *root,
						t_tree_node *x,
						t_tree_node *w)
{
	if ((!w->right->red) && (!w->left->red))
	{
		w->red = 1;
		x = x->parent;
	}
	else
	{
		if (!w->left->red)
		{
			w->right->red = 0;
			w->red = 1;
			left_rotate(tree, w);
			w = x->parent->left;
		}
		w->red = x->parent->red;
		x->parent->red = 0;
		w->left->red = 0;
		right_rotate(tree, x->parent);
		x = root;
	}
}

void				tree_delete_fixup(t_tree *tree, t_tree_node *x)
{
	t_tree_node		*root;
	t_tree_node		*w;

	root = tree->root->left;
	while ((!x->red) && (root != x))
	{
		if (x == x->parent->left)
		{
			w = x->parent->right;
			if (w->red)
				is_red_1(tree, x, w);
			tree_delete_fixup_1(tree, root, x, w);
		}
		else
		{
			w = x->parent->left;
			if (w->red)
				is_red_2(tree, x, w);
	    	tree_delete_fixup_2(tree, root, x, w);
		}
	}
	x->red = 0;
}
