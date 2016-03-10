#include "stdafx.h"

#include "rbtree.h"

bst_node * bst_search(bst_tree *tree,int key)
{	
	bst_node *node;
	node = tree;
	if(node != tree){
		printf("rb_tree error\n");
		return tree;
	}

	while (node != null){
		if(node->data < key)node=node->right;
		else if(node->data > key)node=node->left;
		else if(node->data == key)break;
	}
	if(node == null) 
	{
		printf("No key %d in bstree!\n",key);
		return tree;
	}
	else return node;
}
