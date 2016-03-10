#include "stdafx.h"
#include "rbtree.h"

extern rb_tree * rb_root;

int rbtree_del_fixup(rb_tree *tree,rb_node *node)
{
	rb_node *w;
	while ((node != rb_root->left)&&(node->color =='B'))
	{
		if (node == node->pa->left)
		{
			w = node->pa->right;
			if(w->color == 'R')
			{
				w->color ='B';
				w->pa->color ='R';
				rbtree_left_rotate(rb_root->left,node->pa);
				w = node->pa->right;
			}
			else if((w->left->color == 'B')&&(w->right->color =='B'))
			{
				w->color ='R';
				node = node->pa;
			}
			else if(w->right->color == 'B')
			{
				w->left->color ='B';
				w->color = 'R';
				rbtree_right_rotate(rb_root->left,w);
				w=node->pa->right;
			}
			else if(w->right->color =='R')
			{
				w->color = node->pa->color;
				node->pa->color = 'B';
				w->right->color = 'B';
				rbtree_left_rotate(rb_root->left,node->pa);
				node = rb_root->left;
			}
		}

		else if (node == node->pa->right)
		{
			w = node->pa->left;
			if(w->color == 'R')
			{
				w->color ='B';
				w->pa->color ='R';
				rbtree_right_rotate(rb_root->left,node->pa);
				w = node->pa->left;
			}
			else if((w->right->color == 'B')&&(w->left->color =='B'))
			{
				w->color ='R';
				node = node->pa;
			}
			else if(w->left->color == 'B')
			{
				w->right->color ='B';
				w->color = 'R';
				rbtree_left_rotate(rb_root->left,w);
				w=node->pa->left;
			}
			else if(w->left->color =='R')
			{
				w->color = node->pa->color;
				node->pa->color = 'B';
				w->left->color = 'B';
				rbtree_right_rotate(rb_root->left,node->pa);
				node = rb_root->left;
			}
		}
	}
	node->color = 'B';
	return 0;
}