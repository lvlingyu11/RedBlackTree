#include "stdafx.h"
#include "bst.h"

int bst_tree_insert(bst_tree *tree, bst_node *node) 
{
    //p是t的父节点

    bst_node * p = NULL;
    bst_node * t = tree;
    
    if(!t) {
        tree = node;
        return 0;
    }
    

    while(t) {

        p =t ;
        if ((node->data) < (t->data))
            t = t->left;
        else 
            t = t->right;
    }
    

    //判断到底是p的左节点还是右节点
    if ((node->data) < (p->data)) 
        p->left = node;
    else
        p->right = node;
        

    return 0;
}

bst_node *bst_tree_init(int a[],int length){
	int i=0;
	bst_node *root = malloc(sizeof(bst_node));
	root->data = a[0];
	root->left = null;
	root->right = null;
	for(i = 1;i<length;i++){
		bst_node *node = malloc(sizeof(bst_node));
		node->data = a[i];
		node->left = null;
		node->right = null;
		bst_tree_insert(root,node);
	}
	return root ;
}
