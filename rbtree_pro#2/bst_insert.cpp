#include "stdafx.h"

#include "rbtree.h"


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
