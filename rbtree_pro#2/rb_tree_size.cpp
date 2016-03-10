#include "stdafx.h"

#include "rbtree.h"

extern rb_tree * rb_root;

int giveSize(rb_tree *tree)
{
	rb_tree *node = tree;
	
	if ((node->left == rb_root) && (node->right == rb_root))
	{
		node->size = 1;
		return 1;
	}
	else if ((node->left == rb_root) && (node->right != rb_root))
	{
		node->size = 1+giveSize(node->right);
	}
	else if ((node->left != rb_root) && (node->right == rb_root))
		node->size = 1+giveSize(node->left);
	else
		node->size = 1+giveSize(node->left)+giveSize(node->right);
	return node->size;
}

int getSize(rb_tree *tree)
{
	if (tree == NULL)
		return 0;
	else
	{
		giveSize(tree);
		return tree->size;
	}
}