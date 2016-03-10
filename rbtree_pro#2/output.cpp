#include "stdafx.h"

#include "rbtree.h"
extern FILE * result;
extern rb_tree * rb_root;
int rbtree_output(rb_tree *tree){//LDR
	//right & left
	if(tree->left != rb_root){//rb_root = nil
		rbtree_output(tree->left);
	}
	
	fprintf(result,"%d%c, \n",tree->data,tree->color);
	printf("%d%c, \n",tree->data,tree->color);
//	system("pause");
	if(tree->right != rb_root){
		rbtree_output(tree->right);
	}

	return 0;
}