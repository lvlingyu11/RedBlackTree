#include "stdafx.h"
#include "rbtree.h"

extern rb_tree * rb_root;

int free_bstree(bst_tree *tree)
{

	if(tree->left != null)
	{
		free_bstree(tree->left);
	}
	
	if(tree->right != null){
		free_bstree(tree->right);
	}

	free (tree);
	return 0;

}

int free_rbtree(rb_tree *tree)
{

	if(tree->left != rb_root)
	{
		free_rbtree(tree->left);
	}
	
	if(tree->right != rb_root){
		free_rbtree(tree->right);
	}

	free (tree);
	return 0;

}