#include "stdafx.h"

#include "rbtree.h"
extern rb_tree * rb_root;
int rb_tree_fixup(rb_tree *tree,rb_node *node)
{
	rb_node *y;
	rb_root->left = rb_root->right = tree;
	while (node->pa->color == 'R')
	{
		if(node->pa == node->pa->pa->left)y = node->pa->pa->right;
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
			node->pa->color ='B';
			node->pa->pa->color ='R';
			rbtree_right_rotate(tree,node->pa->pa);
				
		}
				
		else if((node->pa == node->pa->pa->left)&&(node == node->pa->left))
				
		{
			node->pa->color ='B';
			node->pa->pa->color ='R';
			rbtree_right_rotate(tree,node->pa->pa);
		}
	
	
		else if ((node->pa == node->pa->pa->right)&&(node == node->pa->left))
		{
					
			node = node->pa;
					
			rbtree_right_rotate(tree,node);
			node->pa->color ='B';
			node->pa->pa->color ='R';
			rbtree_left_rotate(tree,node->pa->pa);
				
		}
				
		else if((node->pa == node->pa->pa->right)&&(node == node->pa->right))				
		{
			node->pa->color ='B';
			node->pa->pa->color ='R';
			rbtree_left_rotate(tree,node->pa->pa);
		}
	
	}//while
			rb_root->left->color = 'B';
			
			return 0;
}

