#include "stdafx.h"

#include "rbtree.h"

extern rb_tree * rb_root;

rb_node *rb_tree_init(unsigned int a[],int length){
	int i=0;
	rb_node *root = (rb_node *)malloc(sizeof(rb_node));
	root->data = a[0];
	root->color = 'B';
	root->left = rb_root;//nil
	root->right = rb_root;
	root->pa = rb_root;
	rb_root->left = rb_root->right = root;
	rb_root->data = length ;//the rank of all;
	rb_root->color = 'B';
	for(i = 1;i<length;i++){
		rb_node *node = (rb_node *)malloc(sizeof(rb_node));
		node->data = a[i];
		node->color = 'W';
		node->left = rb_root;
		node->right = rb_root;
		int flag=rb_tree_insert(rb_root->left,node);
		if (flag!=-1)
		    rb_tree_fixup(rb_root->left,node);
	}
	return rb_root->left;
}

