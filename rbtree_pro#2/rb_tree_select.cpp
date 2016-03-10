#include "stdafx.h"

#include "rbtree.h"

extern rb_tree * rb_root;

rb_tree* os_Select(rb_tree *tree, int r)
{
	int k = tree->left->size+1;
	if (r == k)
		return tree;
	else if (r < k)
		return os_Select(tree->left, r);
	else if(r > k)
		return os_Select(tree->right, r-k);
}