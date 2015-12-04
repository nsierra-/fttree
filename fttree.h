/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fttree.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 15:42:22 by nsierra-          #+#    #+#             */
/*   Updated: 2015/12/04 15:42:24 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTTREE_H
# define FTTREE_H

# include "fttree_iter.h"

typedef struct			s_tree_node
{
	void				*key;
	void				*data;
	int					red;
	struct s_tree_node	*left;
	struct s_tree_node	*right;
	struct s_tree_node	*parent;
}						t_tree_node;

typedef struct			s_tree
{
	int					(*compare)(const void *a, const void *b);
	void				(*destroy_key)(void *a);
	void				(*destroy_data)(void *a);
	void				(*print_key)(const void *a);
	void				(*print_data)(const void *a);
	t_tree_node			*root;
	t_tree_node			*nil;
}						t_tree;

t_tree					*tree_new(
							int (*comp_fun)(const void *, const void *),
							void (*key_destruction_fun)(void *),
							void (*data_destruction_fun)(void *));
t_tree_iter				*tree_new_iter(t_tree *tree, void *low, void *high);
t_tree_node				*tree_insert(t_tree *tree, void *key, void *data);
t_tree_node				*tree_predecessor(t_tree *tree, t_tree_node *node);
t_tree_node				*tree_successor(t_tree *tree, t_tree_node *node);
t_tree_node				*tree_get(t_tree *tree, void *query);
void					tree_print(t_tree *tree);
void					tree_destroy(t_tree *tree);
void					tree_delete_node(t_tree *tree, t_tree_node *node);

#endif
