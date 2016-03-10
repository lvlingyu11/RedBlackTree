#include "stdafx.h"

int diff_rand_array(int a[],int length)
{	
	int i=0;
	int m,n,k;
	for(;i<length;i++)
		a[i]=i+1;
	for(i=0;i<length;i++)
	{
		m=i;
		n=(int)(length*rand()/(RAND_MAX+1.0)); 
		while (m = n)
		{
			n=(int)(length*rand()/(RAND_MAX+1.0)); 
		}
		k=a[m];
		a[m]=a[n];
		a[n]=k;
	}
	return 0;
}
	