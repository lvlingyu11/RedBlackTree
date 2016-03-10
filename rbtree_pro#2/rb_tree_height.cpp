#include "stdafx.h"

#include "rbtree.h"

extern rb_tree * rb_root;

int getHeight(rb_tree *tree)
{
	int lh,rh;
	if (tree == rb_root)
		return 0;
	else 
	{
		lh = getHeight(tree->left);
		rh = getHeight(tree->right);
	}
	if (lh>=rh)
		return lh+1;
	else
		return rh+1;
}
