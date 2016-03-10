#include "stdafx.h"

#include "rbtree.h"



bst_node *bst_tree_init(int a[],int length){
	int i=0;
	bst_node * root = (bst_node *)malloc(sizeof(bst_node));
	root->data = a[0];
	root->left = null;
	root->right = null;
	for(i = 1;i<length;i++){
		bst_node *node = (bst_node *)malloc(sizeof(bst_node));
		node->data = a[i];
		node->left = null;
		node->right = null;
		bst_tree_insert(root,node);
	}
	return root ;
}
