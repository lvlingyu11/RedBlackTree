#include "stdafx.h"


#define null 0
#ifndef N
#define N 100000	//数据300000太大，堆栈溢出了，改用100000比较
#define KEY 15000	//由于建立红黑树时采用malloc分配内存，故建树较慢
#endif
/*
#ifndef N
#define N 1000	//测试用数据N=1000
#define KEY 150	//KEY = 150
#endif
*/


typedef struct bst_node
{   
    int data;               	
    struct bst_node *left;      
    struct bst_node *right;      

}bst_node,bst_tree;

typedef struct rb_node
{   
    unsigned int data; 
	int size;
	char color;//R,B--red,black
	struct rb_node *pa;//parent
    struct rb_node *left;    
    struct rb_node *right;      

}rb_node,rb_tree;





int bst_tree_insert(bst_tree *tree, bst_node *node);
bst_node *bst_tree_init(int a[],int length);
int rb_tree_insert(rb_tree *tree, rb_node *node);
int rbtree_left_rotate(rb_tree *tree,rb_node *node);
int rbtree_right_rotate(rb_tree *tree,rb_node *node);
int rb_tree_fixup(rb_tree *tree,rb_node *node);
rb_node *rb_tree_init(unsigned int a[],int length);
int rbtree_output(rb_tree *tree);
int rb_tree_delete(rb_tree *tree, unsigned int key) ;
int rbtree_del_fixup(rb_tree *tree,rb_node *node);
int diff_rand_array(int a[],int length);
bst_node * bst_search(bst_tree *tree,int key);
rb_node * rbtree_search(rb_tree *tree,unsigned int key);
int free_bstree(bst_tree*);
int free_rbtree(rb_tree*);
int os_key_rank(rb_tree * tree , unsigned int key);
int os_rank(rb_tree *tree,rb_node *node);
int right_tree_num(rb_node *node);
int left_tree_num(rb_node *node);
int getSize(rb_tree *tree);
int giveSize(rb_tree *tree);
rb_tree* os_Select(rb_tree *tree, int r);
rb_tree* OS_select(rb_tree *tree, int r);
int getHeight(rb_tree *tree);
