#include "stdafx.h"
#include "rbtree.h"

extern rb_tree * rb_root;

rb_node * tree_successor(rb_node *node)
{
	rb_node * p;
	p = node->right;
	while(p->left != rb_root)
		p = p->left;
	return p;
}

int rb_tree_delete(rb_tree *tree, unsigned int key) 
{	
	rb_node *node;
	node = rb_root->left;
	if(node != tree){
		printf("rb_tree error\n");
		return -1;
	}

	while (node != rb_root){
		if(node->data < key)node=node->right;
		else if(node->data > key)node=node->left;
		else if(node->data == key)break;
	}
	if(node == rb_root)
		return -1;
	rb_node *x;
	rb_node *y;
	if ((node->left == rb_root)||(node->right == rb_root)) 
		y = node;
	else y = tree_successor(node);
	//case2
    if ((y->left != rb_root)&&(y->pa->right == y)){
		y->left->pa = y->pa;
		y->pa->right = y->left;
		x = y->left;
	}
	else if((y->left != rb_root)&&(y->pa->left == y)){
		y->left->pa = y->pa;
		y->pa->left = y->left;
		x = y->left;
	}
	else if((y->right != rb_root)&&(y->pa->right == y)){
		y->right->pa = y->pa;
		y->pa->right = y->right;
		x = y->right;
	}
	else if((y->right != rb_root)&&(y->pa->left == y)){
		y->right->pa = y->pa;
		y->pa->left = y->right;
		x = y->right;
	}
	//case 1
	if ((y->left == rb_root)&&(y->right == rb_root))
	{
		if(y->pa->left == y)
		{
			y->pa->left = rb_root;//nil

		}
		else if (y->pa->right == y)
		{
			y->pa->right = rb_root;

		}
		x = rb_root;
		
	}
	x->pa = y->pa;
	node->data = y->data;
	if (y->color == 'B') 
		rbtree_del_fixup(rb_root->left,x);
    return 0;
}