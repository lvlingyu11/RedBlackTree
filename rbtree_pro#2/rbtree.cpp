#include "stdafx.h"
#include "rbtree.h"

int rb_tree_insert(rb_tree *tree, rb_node *node) 
{
    //p是t的父节点
    rb_node * p = NULL;
    rb_node * t = tree;   
    while(t != rb_root) {

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
      
	node->pa = p;
	node->color='R';

    return 0;
}

int rbtree_left_rotate(rb_tree *tree,rb_node *node){
	rb_node *y = node->right;
	rb_node *x = node->pa;
	node->pa = y;
	node->right = y->left;
	y->pa = x;
	y->left = node;
	node->right->pa = node;
	if(x->left == node)x->left = y;
	else if(x->right != tree )x->right = y;
	return 0;
}

int rbtree_right_rotate(rb_tree *tree,rb_node *node){
	rb_node *y = node->right;
	rb_node *x = node->pa;
	node->left = y->right;
	y->pa = x;
	y->right = node;
	node->left->pa = node;
	node->pa = y;
	if((x->left !=tree)&&(x->left == node))x->left = y;
	else if(x->right != tree )x->right = y;
	return 0;
}

int rb_tree_fixup(rb_tree *tree,rb_node *node)
{
	rb_node *y;
	rb_root->left = rb_root->right = tree;
	while (node->pa->color == 'R')
	{
		if(node->pa == node->pa->pa->left)y = node->pa->pa->right;//y指向叔父
		else y = node->pa->pa->left;
		
		if(y->color == 'R')
				
		{
				
			node->pa->color = 'B';
				
			y->color = 'B';
				
			node->pa->pa->color = 'R';
				
			node = node->pa->pa;
			
		}
		
		else if((node->pa == node->pa->pa->left)&&(node==node->pa->right))
				
		{
					
			node = node->pa;
					
			rbtree_left_rotate(tree,node);
				
		}
				
		else if((node->pa == node->pa->pa->left)&&(node == node->pa->left))
				
		{
			node->pa->color ='B';
			node->pa->pa->color ='R';
			rbtree_right_rotate(tree,node->pa);
		}
	
	
		else if ((node->pa == node->pa->pa->right)&&(node == node->pa->left))
		{
					
			node = node->pa;
					
			rbtree_right_rotate(tree,node);
				
		}
				
		else if((node->pa == node->pa->pa->right)&&(node == node->pa->right))				
		{
			node->pa->color ='B';
			node->pa->pa->color ='R';
			rbtree_left_rotate(tree,node->pa);
		}
	
	}//while
			rb_root->left->color = 'B';
			
			return 0;
}

rb_node *rb_tree_init(int a[],int length){
	int i=0;
	rb_node *root = malloc(sizeof(rb_node));
	root->data = a[0];
	root->color = 'B';
	root->left = rb_root;//nil
	root->right = rb_root;
	root->pa = rb_root;
	rb_root->left = rb_root->right = root;
	rb_root->data = null;
	for(i = 1;i<length;i++){
		rb_node *node = malloc(sizeof(rb_node));
		node->data = a[i];
		node->color = 'W';
		node->left = rb_root;
		node->right = rb_root;
		rb_tree_insert(root,node);
		rb_tree_fixup(root,node);
	}
	return root ;
}

int rbtree_output(rb_tree *tree,int level){//LDR中序遍历输出
	//right & left
	int i=0,lev=level;
	printf("(%d%c, \n",tree->data);
	if(tree->left != rb_root){
		for(i=0;i<=level;i++)printf("\t");
		rbtree_output(tree->left,++level);
	}
	else {
		for(i=0;i<=level;i++)printf("\t");
		printf("NIL,\n");
	}
	if(tree->right != rb_root){
		for(i=0;i<=lev;i++)printf("\t");
		rbtree_output(tree->right,++lev);
	}
	else {
		for(i=0;i<=lev;i++)printf("\t");
		printf("NIL)\n");
	}

	return 0;
}