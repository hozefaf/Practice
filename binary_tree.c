#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//Global Variables
#define SIZEOFSTRING 8
int string[SIZEOFSTRING] = {1,3,7,8,5,4,9,6};
typedef struct node {
	int value;
	struct node * left_node;
	struct node * right_node;
} node_t;

struct node * root_node = NULL;

void find_node( int value, struct node ** node_to_delete, struct node ** previous_node)
{
	printf("\nEnter Find Node node_to_delete = %p, previous_node = %p\n", *node_to_delete, *previous_node );
	while(value != (*node_to_delete)->value)
	{
		printf("Value to find = %d\n", value);
		printf("Node Value = %d\n",(*node_to_delete)->value);
		if(value > (*node_to_delete)->value)
		{
			*previous_node = *node_to_delete;
			*node_to_delete = (*node_to_delete)->right_node;
			printf("Greater Iteration node_to_delete = %p, previous_node = %p\n", *node_to_delete, *previous_node );
		}
		else if(value < (*node_to_delete)->value)
		{
			*previous_node = *node_to_delete;
			*node_to_delete = (*node_to_delete)->left_node;
			printf("Lesser Iteration node_to_delete = %p, previous_node = %p\n", *node_to_delete, *previous_node );
		}
	}
	
	printf("\nnode_to_delete = %p, previous_node = %p\n", *node_to_delete, *previous_node );
}

int delete_node ( int node_value)
{
	struct node *node_to_delete = NULL;
	struct node *previous_node = NULL;
	struct node *leftmost_node = NULL ;
	struct node *beforeleftmost_node = NULL;
	node_to_delete = root_node;
	find_node(node_value, &node_to_delete, &previous_node);

	//1st case node to be deleted is a left node
	if(node_to_delete->right_node == NULL && node_to_delete->left_node == NULL)
	{
		if(previous_node->left_node == node_to_delete)
			previous_node->left_node = NULL;
		else
			previous_node->right_node = NULL;
		printf("deleting leaf node, value = %d\n", node_value);
		free(node_to_delete);
	}
	// 2nd case if there is a left node but no right node
	else if(node_to_delete->right_node == NULL)
	{
		if(previous_node->left_node == node_to_delete)
	 		previous_node->left_node = node_to_delete;
		else 
		 	previous_node->right_node = node_to_delete;
		printf("deleting  node with no right, value = %d\n", node_value);
		free(node_to_delete);
	}
	//3rd case, has both child( right child has no left)
	else if((node_to_delete->right_node != NULL) )
	{
		printf("Right node Available, value = %d\n", node_value);
		//case 3a child of deleted node has to left node
		if(((node_to_delete->right_node)->left_node) == NULL)
		{
			// promote the left node or right node in the place of the deleted node
			if(previous_node->right_node == node_to_delete)
				previous_node->right_node = node_to_delete->right_node;
			else
				previous_node->left_node = node_to_delete->left_node;
			((node_to_delete->right_node))->left_node = node_to_delete->left_node;
			free(node_to_delete);
			printf("deleteing special case node 1, value = %d\n", node_value);
		}
		// case 3b child of the node to be deleted has a left node
		else
		{
			leftmost_node = ((node_to_delete->right_node)->left_node);
			printf("deleting special case node 2, value = %d\n", node_value);
			printf("leftnode value = %d\n", leftmost_node->value);
			while(leftmost_node->left_node != NULL)
			{
				beforeleftmost_node = leftmost_node;
				leftmost_node = leftmost_node->left_node;
			}
			// find the leftmost and replace that with the node to be deleted
			printf("leftnode value = %d\n", leftmost_node->value);
			if(previous_node->left_node == node_to_delete)
			{
		 		previous_node->left_node = leftmost_node;
				printf("\n left leftmost_node, value = %p\n", leftmost_node);
			}
			else 
			{
		 		previous_node->right_node = leftmost_node;
				printf("\n right leftmost_node, value = %p\n", leftmost_node);
			}
			beforeleftmost_node->left_node = leftmost_node->right_node;
			leftmost_node->left_node = node_to_delete->left_node;
			leftmost_node->right_node = node_to_delete->right_node;

			printf("\n check leftmost_node, value = %p\n",
			leftmost_node->left_node);
			printf("\n check leftmost_node, value = %p\n",
			leftmost_node->right_node);



			free(node_to_delete);	
		}
	}
}

int add_node(struct node ** relative_root_node, struct node * temp_node)
{
	printf("starting add node\n");
	printf("check root_node,root_node = %p\n", *relative_root_node);
	if(* relative_root_node == NULL)
	{
		* relative_root_node = temp_node;
		printf("no root node starting over,root_node = %p\n", *relative_root_node);
		return 0 ;
	}
	if (temp_node->value < (*relative_root_node)->value)
	{
		printf("Going Left, value = %d\n", temp_node->value);
		add_node(&((*relative_root_node)->left_node), temp_node);
		return 0;
	}
	else if(temp_node->value >= (*relative_root_node)->value)
	{
		printf("Going Right, value = %d\n", temp_node->value);
		add_node(&((*relative_root_node)->right_node), temp_node);
		return 0;
	}
	return 0;
}

struct node * get_leftmost_node(struct node * node_a)
{
	struct node * temp_node;
	temp_node = node_a;
	
	while(temp_node != NULL)
	{
		temp_node = temp_node->left_node;
	}

	return temp_node;
}

void process_node(struct node * node_a)
{
	if(node_a->left_node != NULL)
		process_node(node_a->left_node);

	printf("\n\n Found Node = %d\n\n", node_a->value);

	if(node_a->right_node != NULL)
		process_node(node_a->right_node);
}
		
void process_node_to_right(struct node * node_a)
{
	struct node * temp_node;
	temp_node = node_a->right_node;
	while(node_a != NULL)
	{
		printf("\n\n Found Node = %d\n\n", node_a->value);
	}
}

void transverse_tree()
{
	//find the last location
	process_node(root_node);

}

int main(int argc, char * argv[])
{
	int i;
	struct node * new_node = NULL;
	for( i = 0; i < SIZEOFSTRING; i++)
	{
		printf("starting, value = %d\n", string[i]);
		new_node = malloc(sizeof(node_t));
		new_node->value = string[i];
		add_node(&root_node, new_node);
	}

	printf("Root Node = %p\n",root_node);
	transverse_tree();
	delete_node(5);
	transverse_tree();
}
