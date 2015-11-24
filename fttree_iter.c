#include <stdlib.h>
#include "fttree.h"
#include "private/misc.h"

t_tree_iter				*tree_iter_new(void)
{
	t_tree_iter	*new_stack;

	new_stack = safe_malloc(sizeof(t_tree_iter));
	new_stack->top = new_stack->tail = NULL;
	return (new_stack);
}


void				tree_iter_push(t_tree_iter *stack, void *new_info_pointer)
{
	t_tree_iter_node	*new_node;

	if (!stack->top)
	{
		new_node = safe_malloc(sizeof(t_tree_iter_node));
		new_node->info = new_info_pointer;
		new_node->next = stack->top;
		stack->top = new_node;
		stack->tail = new_node;
	}
	else
	{
		new_node = safe_malloc(sizeof(t_tree_iter_node));
		new_node->info = new_info_pointer;
		new_node->next = stack->top;
		stack->top = new_node;
	}
}

void				*tree_iter_next(t_tree_iter *stack)
{
	void			*pop_info;
	t_tree_iter_node	*old_node;

	if (stack->top)
	{
		pop_info = stack->top->info;
		old_node = stack->top;
		stack->top = stack->top->next;
		free(old_node);
		if (!stack->top)
			stack->tail = NULL;
	}
	else
		pop_info = NULL;
	return (pop_info);
}

void				stack_destroy(t_tree_iter *stack, void dest_fun(void *a))
{
	t_tree_iter_node	*x;
	t_tree_iter_node	*y;

	x = stack->top;
	if (stack)
	{
		while (x)
		{
			y = x->next;
			dest_fun(x->info);
			free(x);
			x=y;
		}
		free(stack);
	}
}

