#include "stdafx.h"

#include "rbtree.h"

extern rb_tree * rb_root;
int rb_tree_insert(rb_tree *tree, rb_node *node) 
{
    //p是t的父节点
    rb_node * p = NULL;
    rb_node * t = tree;   
    while(t != rb_root) {

        p =t ;
        if ((node->data) < (t->data))
            t = t->left;
        else if((node->data) > (t->data))
            t = t->right;
		else
			return -1;
    }
    //判断到底是p的左节点还是右节点
    if ((node->data) < (p->data)) 
        p->left = node;
    else
        p->right = node;
      
	node->pa = p;
	node->color='R';

    return 0;
}
