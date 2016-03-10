#include "stdafx.h"

#include "rbtree.h"

extern rb_tree * rb_root;
int left_tree_num(rb_node *node)
{
	int left,right,leftnum;
	if(node == rb_root)return 0;
	else if(node->left != rb_root)
	{
		left = left_tree_num(node->left);
		right = right_tree_num(node->left);
		leftnum = left + right + 1;
	}
	else return 0;
	return leftnum;

}

int right_tree_num(rb_node *node)
{
	int left,right,rightnum;
	if(node == rb_root)return 0;
	else if(node->right != rb_root)
	{
		left = left_tree_num(node->right);
		right = right_tree_num(node->right);
		rightnum = left + right + 1;
	}
	else return 0;
	return rightnum;

}


int os_rank(rb_tree *tree,rb_node *node)
{
	rb_node *y;
	int rank;
	rank = left_tree_num(node) + 1;
	y = node;
	while (y!=rb_root->left)
	{
		if (y == y->pa->right)
			rank = rank + left_tree_num(y->pa) + 1;
		y = y->pa;
	}
	return rank;
}

int os_key_rank(rb_tree * tree , unsigned int key)
{
	int num;
	rb_node * node;
	node = tree;
	while(node ->data != key)
	{
		if (node->data >key)
			node = node ->left;
		else node = node ->right;
	}
	if (node == rb_root)return -1;
	num = os_rank(tree,node);
	return num;
}

rb_tree* OS_select(rb_tree *tree, int r)
{
	int k=left_tree_num(tree)+1;
	if (r==k)
		return tree;
	else if (r<k)
		return OS_select(tree->left,r);
	else
		return OS_select(tree->right,r-k);
}