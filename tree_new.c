/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 15:42:18 by nsierra-          #+#    #+#             */
/*   Updated: 2015/12/04 15:42:18 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "private/misc.h"
#include "fttree.h"

t_tree			*tree_new(int (*comp_fun)(const void *, const void *),
					void (*key_destruction_fun)(void *),
					void (*data_destruction_fun)(void *))
{
	t_tree		*new_tree;

	new_tree = safe_malloc(sizeof(t_tree));
	new_tree->compare = comp_fun;
	new_tree->destroy_key = key_destruction_fun;
	new_tree->destroy_data = data_destruction_fun;
	new_tree->print_key = NULL;
	new_tree->print_data = NULL;
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
