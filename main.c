/*
* @Author: Work
* @Date:   2015-11-23 19:59:50
* @Last Modified by:   Work
* @Last Modified time: 2015-11-24 02:57:17
*/

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
	char			key1[] = "Key 1";
	char			key2[] = "Key 2";
	char			key3[] = "Key 3";
	char			data1[] = "Data 1";
	char			data2[] = "Data 2";
	char			data3[] = "Data 3";
	t_tree_node		*node1 = NULL;
	t_tree_node		*node2 = NULL;
	t_tree_iter		*iter = NULL;
	t_tree			*tree;

	setvbuf(stdout, NULL, _IONBF, 0);
	/* Creation */
	tree = tree_new(compare_strings, free, free);
	tree->print_data = simple_print;
	tree->print_key = simple_print;

	/* Insertion */
	tree_insert(tree, key1, data1);
	tree_insert(tree, key2, data2);
	tree_insert(tree, key3, data3);

	/* Accession */
	node1 = tree_get(tree, "Key 3");
	node2 = tree_predecessor(tree, node1);
	printf("Data for \"Key 3\" is \"%s\"\n", node1->data);
	printf("Predecessor is %s <-> %s\n", node2->key, node2->data);

	/* Iteration */
	printf("Starting iteration...");
	iter = tree_get_iter(tree, node1, node2);
	while ((node1 = tree_iter_next(iter)))
		printf("%s <-> %s\n", node1->key, node1->data);
	free(iter);

	/* Destruction */
	tree_delete_node(tree, node1);
	tree_destroy(tree);

	while (42)
		;
	return 0;
}
