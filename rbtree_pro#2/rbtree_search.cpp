#include "stdafx.h"

#include "rbtree.h"

extern rb_tree * rb_root;
rb_node * rbtree_search(rb_tree *tree,unsigned int key)
{	
	rb_node *node;
	node = rb_root->left;
	if(node != tree)
	{
		printf("rb_tree error\n");
		return tree;
	}

	while (node != rb_root){
		if(node->data < key)node=node->right;
		else if(node->data > key)node=node->left;
		else if(node->data == key)break;
	}
	if(node == rb_root)
	{
		printf("No key %d in rbtree!\n",key);
		return tree;
	}
	else return node;
}
