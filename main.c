/*
* @Author: Work
* @Date:   2015-11-23 19:59:50
* @Last Modified by:   Work
* @Last Modified time: 2015-11-24 02:57:17
*/

#include "fttree.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void IntDest(void* a) {
  free((int*)a);
}



int IntComp(const void* a,const void* b) {
  if( *(int*)a > *(int*)b) return(1);
  if( *(int*)a < *(int*)b) return(-1);
  return(0);
}

void IntPrint(const void* a) {
  printf("%i",*(int*)a);
}

void dataPrint(void*a) {
  (void)a;
}

void dataDest(void *a){
  (void)a;
}

int				main(void)
{
  t_tree_iter		*enumResult;
  int			*newInt;
  int			option = 0;
  int			newKey,newKey2;
  t_tree_node	*newNode;
  t_tree		*tree;

setvbuf(stdout, NULL, _IONBF, 0);
  tree = tree_new(IntComp,IntDest,dataDest);
  tree->print_data = dataPrint;
  tree->print_key = IntPrint;
  while(option!=8)
  {
    printf("choose one of the following:\n");
    printf("(1) add to tree\n(2) delete from tree\n(3) query\n");
    printf("(4) find predecessor\n(5) find sucessor\n(6) enumerate\n");
    printf("(7) print tree\n(8) quit\n");
    do
    	option = fgetc(stdin);
    while (-1 != option && isspace(option));
    option -= '0';
    switch(option)
	{
		case 1:
		{
			printf("type key for new node\n");
			scanf("%i", &newKey);
			newInt = malloc(sizeof(int));
			*newInt = newKey;
			tree_insert(tree, newInt, "KEK");
		}
		break;

		case 2:
		{
			printf("type key of node to remove\n");
			scanf("%i",&newKey);
			if ((newNode = tree_exact_query(tree,&newKey)))
				tree_delete_node(tree, newNode);/*assignment*/
			else
				printf("key not found in tree, no action taken\n");
		}
		break;

		case 3:
		{
			printf("type key of node to query for\n");
			scanf("%i",&newKey);
			if ((newNode = tree_exact_query(tree,&newKey)))
				printf("data found in tree at location %s\n", (char *)newNode->data);
			else
				printf("data not in tree\n");
		}
		break;

		case 4:
		{
			printf("type key of node to find predecessor of\n");
			scanf("%i",&newKey);
			if ((newNode = tree_exact_query(tree,&newKey)))
			{/*assignment*/
				newNode=tree_predecessor(tree,newNode);
				if(tree->nil == newNode)
					printf("there is no predecessor for that node (it is a minimum)\n");
				else
					printf("predecessor has key %i\n",*(int*)newNode->key);
			}
			else
			printf("data not in tree\n");
		}
		break;

		case 5:
		{
			printf("type key of node to find successor of\n");
			scanf("%i",&newKey);
			if ((newNode = tree_exact_query(tree,&newKey)))
			{
				newNode=tree_successor(tree,newNode);
				if (tree->nil == newNode)
					printf("there is no successor for that node (it is a maximum)\n");
				else
				printf("successor has key %i\n",*(int*)newNode->key);
			}
			else
			printf("data not in tree\n");
		}
		break;

		case 6:
		{
			printf("type low and high keys to see all keys between them\n");
			scanf("%i %i",&newKey,&newKey2);
			enumResult=tree_enumerate(tree,&newKey,&newKey2);
			while ((newNode = tree_iter_next(enumResult)))
			{
				tree->print_key(newNode->key);
				printf("\n");
			}
			free(enumResult);
		}
		break;

		case 7:
		{
			tree_print(tree);
		}
		break;

		case 8:
		{
			tree_destroy(tree);
			return 0;
		}
		break;

		default:
			printf("Invalid input; Please try again.\n");
		}
  }
  return 0;
}
