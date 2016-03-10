#include "stdafx.h"
#include "rbtree.h"


rb_tree * rb_root;
FILE *result;


void main()
{

	rb_root = (rb_node *)malloc(sizeof(rb_node));
	double start,finish;
	result = fopen("result.txt","w");
	
	
	rb_tree *TREE;
	FILE *fp;

   unsigned int list[100000];
	int j=0;
	if (!(fp=fopen("read.txt","r")))
	{
		printf("Cannot open the file. \n");
		return;
	}
    while (j<100000)
	{
		fscanf(fp,"%u",&list[j]);
		j++;
	}
	fclose(fp);



	TREE = rb_tree_init(list,100000);
	int height;
	height = getHeight(TREE);
	printf("The height of the tree is %d\n",height);
	fprintf(result,"The height of the tree is: %d\n",height);
	printf("The rbtree is : \n");
	fprintf(result,"The initial tree is:\n");
	rbtree_output(TREE);
	int size1=getSize(TREE);
	fprintf(result,"The size of the initial tree is: %d \n",size1);
    //select the node according to the rank
	rb_tree *select_node;
	fprintf(result,"EXPERIMENT1: OS_select Operation\n");
	int r;
	for (int k=0; k<10; k++)
	{
	    printf("Please input the rank of the element to find the data:\n");
	    scanf("%d", &r);
	    select_node=OS_select(TREE,r);
        fprintf(result,"The element of rank %d is: %u\n",r,select_node->data);
	}
	
	//search
	fprintf(result,"EXPERIMENT2: Search Operation\n");
	rb_tree* search_node;
	fprintf(result,"We try to find the first ten elements in the input file\n");
	for (int k=0; k<10; k++)
	{
		search_node=rbtree_search(TREE,list[k]);
		if(search_node != rb_root)
			fprintf(result,"The %dth element is FOUND!\n",k+1);
	}
    //rank
	fprintf(result,"EXPERIMENT3: Find the rank of the element\n");
	int rank,rank_p;
	for(int k=0; k<10; k++)
	{
		fprintf(result,"We try to find the rank of the %dth element of the input file: \n",k);
		rank=os_key_rank(TREE,list[k]);
		fprintf(result,"The rank of the %dth element is: %d\n",k,rank);
	}
	
	unsigned int insert_list[100];
	unsigned int del_list[100];
	if (!(fp=fopen("insert.txt","r")))
	{
		printf("Cannot open the file. \n");
		return;
	}
	j=0;
	while(j<100)
	{
		fscanf(fp, "%u", &insert_list[j]);
		j++;
	}
	fclose(fp);
	if (!(fp=fopen("remove.txt","r")))
	{
		printf("Cannot open the file. \n");
		return;
	}
	j=0;
	while(j<100)
	{
		fscanf(fp, "%u", &del_list[j]);
		j++;
	}
	
	fclose(fp);
	//insert
	fprintf(result,"EXPERIMENT4:Insert Operation\n");
	for (j=0; j<100; j++)
	{
		rb_node *insert_node=(rb_node *)malloc(sizeof(rb_node));
		insert_node->data=insert_list[j];
		insert_node->left=rb_root;
		insert_node->right=rb_root;
		insert_node->color='W';
		int flag=rb_tree_insert(TREE,insert_node);
		if (flag == 0)
		{
               rb_tree_fixup(TREE,insert_node);
			   fprintf(result,"The insertion of %dth element has successed!\n",j);
			   height = getHeight(TREE);
			   fprintf(result,"After insertion of %dth element the height of the tree is: %d\n",j,height);
		}
		else
			fprintf(result,"The insertion of %dth element has failed!\n",j);
		
	}
	int size2=getSize(TREE);
	fprintf(result,"The size of the tree after insertion is: %d\n",size2);
	
	//remove
	fprintf(result,"EXPERIMENT5:Deletion Operation\n");
	for(j=0; j<100; j++)
	{
		int flag_del=rb_tree_delete(TREE,del_list[j]);
		if (flag_del == 0)
		{
			fprintf(result,"The deletion of %dth element has successed!\n",j);
			height = getHeight(TREE);
			fprintf(result,"After deletion of %dth element the height of the tree is: %d\n",j,height);
		}
		else
			fprintf(result,"The deletion of %dth element has failed!\n",j);
	}
	int size3=getSize(TREE);
    fprintf(result,"The size of the tree after deletion is: %d\n",size3);
	fprintf(result,"Successful! \n");
	



free_rbtree (TREE);


}
