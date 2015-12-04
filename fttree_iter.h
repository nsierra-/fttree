/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fttree_iter.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 15:42:25 by nsierra-          #+#    #+#             */
/*   Updated: 2015/12/04 15:42:26 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTTREE_ITER_H
# define FTTREE_ITER_H

# include <stddef.h>

typedef struct				s_tree_iter_node
{
	void					*data;
	struct s_tree_iter_node *next;
}							t_tree_iter_node;

typedef struct				s_tree_iter
{
	t_tree_iter_node		*top;
	t_tree_iter_node		*tail;
}							t_tree_iter;

t_tree_iter					*tree_iter_new(void);
void						*tree_iter_next(t_tree_iter *stack);
void						tree_iter_push(
								t_tree_iter *stack,
								void *new_data_pointer);

#endif
