#include <stdlib.h>
#include "ftstack.h"
#include "private/misc.h"

t_stack				*stack_join(t_stack *stack1, t_stack *stack2)
{
	if (!stack1->tail)
	{
		free(stack1);
		return (stack2);
	}
	else
	{
		stack1->tail->next = stack2->top;
		stack1->tail = stack2->tail;
		free(stack2);
		return (stack1);
	}
}

t_stack				*stack_new(void)
{
	t_stack	*new_stack;

	new_stack = safe_malloc(sizeof(t_stack));
	new_stack->top = new_stack->tail = NULL;
	return (new_stack);
}


void				stack_push(t_stack *stack, void *new_info_pointer)
{
	t_stack_node	*new_node;

	if (!stack->top)
	{
		new_node = safe_malloc(sizeof(t_stack_node));
		new_node->info = new_info_pointer;
		new_node->next = stack->top;
		stack->top = new_node;
		stack->tail = new_node;
	}
	else
	{
		new_node = safe_malloc(sizeof(t_stack_node));
		new_node->info = new_info_pointer;
		new_node->next = stack->top;
		stack->top = new_node;
	}
}

void				*stack_pop(t_stack *stack)
{
	void			*pop_info;
	t_stack_node	*old_node;

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

void				stack_destroy(t_stack *stack, void dest_fun(void *a))
{
	t_stack_node	*x;
	t_stack_node	*y;

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

