#ifndef TREE_INTERNALS_H
# define TREE_INTERNALS_H

void	right_rotate(t_tree *tree, t_tree_node *y);
void	left_rotate(t_tree *tree, t_tree_node *x);
void	tree_delete_fixup(t_tree *tree, t_tree_node *x);

#endif
