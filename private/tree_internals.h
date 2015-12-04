/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_internals.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:15:32 by nsierra-          #+#    #+#             */
/*   Updated: 2015/12/04 16:15:34 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_INTERNALS_H
# define TREE_INTERNALS_H

void	right_rotate(t_tree *tree, t_tree_node *y);
void	left_rotate(t_tree *tree, t_tree_node *x);
void	tree_delete_fixup(t_tree *tree, t_tree_node *x);

#endif
