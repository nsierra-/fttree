/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fttree_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 15:41:41 by nsierra-          #+#    #+#             */
/*   Updated: 2015/12/04 15:41:43 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fttree.h"
#include "private/misc.h"

t_tree_iter				*tree_iter_new(void)
{
	t_tree_iter			*new_stack;

	new_stack = safe_malloc(sizeof(t_tree_iter));
	new_stack->tail = NULL;
	new_stack->top = NULL;
	return (new_stack);
}

void					tree_iter_push(t_tree_iter *stack, void *new_data_ptr)
{
	t_tree_iter_node	*new_node;

	if (!stack->top)
	{
		new_node = safe_malloc(sizeof(t_tree_iter_node));
		new_node->data = new_data_ptr;
		new_node->next = stack->top;
		stack->top = new_node;
		stack->tail = new_node;
	}
	else
	{
		new_node = safe_malloc(sizeof(t_tree_iter_node));
		new_node->data = new_data_ptr;
		new_node->next = stack->top;
		stack->top = new_node;
	}
}

void					*tree_iter_next(t_tree_iter *stack)
{
	void				*pop_data;
	t_tree_iter_node	*old_node;

	if (stack->top)
	{
		pop_data = stack->top->data;
		old_node = stack->top;
		stack->top = stack->top->next;
		free(old_node);
		if (!stack->top)
			stack->tail = NULL;
	}
	else
		pop_data = NULL;
	return (pop_data);
}
