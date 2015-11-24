#ifndef FTSTACK_H
# define FTSTACK_H

# include <stddef.h>

typedef struct			s_stack_node
{
	void				*info;
	struct s_stack_node	*next;
}						t_stack_node;

typedef struct			s_stack
{
	t_stack_node		*top;
	t_stack_node		*tail;
}						t_stack;

t_stack		*stack_join(t_stack *stack1, t_stack *stack2);
t_stack		*stack_new(void);
void		*stack_pop(t_stack *stack);
void		stack_push(t_stack *stack, void *new_data_pointer);

#endif
