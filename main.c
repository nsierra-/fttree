/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 15:41:56 by nsierra-          #+#    #+#             */
/*   Updated: 2015/12/04 15:41:59 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fttree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int					compare_strings(const void *str1, const void *str2)
{
	return (strcmp((const char *)str1, (const char *)str2));
}

void				simple_print(const void *msg)
{
	printf("%s", (const char *)msg);
}

int					main(void)
{
	char			*key1 = strdup("Key 1");
	char			*key2 = strdup("Key 2");
	char			*key3 = strdup("Key 3");
	char			*data1 = strdup("Data 1");
	char			*data2 = strdup("Data 2");
	char			*data3 = strdup("Data 3");
	t_tree_node		*node1 = NULL;
	t_tree_node		*node2 = NULL;
	t_tree_iter		*iter = NULL;
	t_tree			*tree;

	setvbuf(stdout, NULL, _IONBF, 0);
	/* Creation */
	tree = tree_new(compare_strings, free, free); 	/* New tree, using compare_string as comparison fuction and free to delete key and data */
	tree->print_data = simple_print; 				/* Optionnaly set functions to print key and data */
	tree->print_key = simple_print;

	/* Insertion */
	tree_insert(tree, key1, data1);					/* Inserting data1 into tree with key1 as index */
	tree_insert(tree, key2, data2);
	tree_insert(tree, key3, data3);

	/* Accession */
	node1 = tree_get(tree, "Key 3");				/* Asking for node associated with "Key 3" key */
	node2 = tree_predecessor(tree, node1);
	printf("Data for \"Key 3\" is \"%s\"\n", node1->data);
	printf("Predecessor is %s <-> %s\n", node2->key, node2->data);

	/* Iteration */
	puts("Starting iteration...");
	iter = tree_new_iter(tree, node1, node2);		/* Asking a new iterator for tree from node1 to node2 */
	while ((node1 = tree_iter_next(iter)))
		printf("%s <-> %s\n", node1->key, node1->data);
	free(iter);										/* Do not forget to free your iterator after the loop */

	/* Printing */
	tree_print(tree);

	/* Destruction */
	node1 = tree_get(tree, "Key 3");
	tree_delete_node(tree, node1);
	tree_destroy(tree);
	return (0);
}
