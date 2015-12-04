/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 15:15:33 by nsierra-          #+#    #+#             */
/*   Updated: 2015/12/04 15:15:34 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "private/misc.h"
#include "fttree.h"

t_tree			*tree_new(int (*comp_fun)(const void *, const void *),
					void (*dest_fun)(void *),
					void (*data_dest_fun)(void *))
{
	t_tree		*new_tree;

	new_tree = safe_malloc(sizeof(t_tree));
	new_tree->compare = comp_fun;
	new_tree->destroy_key = dest_fun;
	new_tree->destroy_data = data_dest_fun;
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
