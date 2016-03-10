#include "stdafx.h"

#include "rbtree.h"
extern rb_tree * rb_root;

int rbtree_left_rotate(rb_tree *tree,rb_node *node){

	rb_node *y = node->right;
	rb_node *x = node->pa;
	if(node != tree)
	{
	node->pa = y;
	node->right = y->left;
	y->pa = x;
	y->left = node;
	node->right->pa = node;
	if(x->left == node)x->left = y;
	else if(x->right != tree )x->right = y;
	}
	else 
	{
		if(x != rb_root) return -1;
		rb_root->left = rb_root->right = y;
		node->pa =y;
		node->right = y->left;
		y->pa = rb_root;
		y->left = node;
		node->right->pa = node;
	}
	
	return 0;
}

int rbtree_right_rotate(rb_tree *tree,rb_node *node){

	rb_node *y = node->left;
	rb_node *x = node->pa;
	if(node != tree)
	{
	node->left = y->right;
	y->pa = x;
	y->right = node;
	node->left->pa = node;
	node->pa = y;
	if((x->left !=tree)&&(x->left == node))x->left = y;
	else if(x->right != tree )x->right = y;
	}
	else
	{
		if(x != rb_root) return -1;
		rb_root->left = rb_root->right = y;
		node->pa =y;
		node->left = y->right;
		y->pa = rb_root;
		y->right = node;
		node->left->pa = node;
	}
	return 0;
}

