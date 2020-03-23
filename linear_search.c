#include<stdio.h>
int linear_search(int a[],int key)
{
	for(int i=0;a[i];i++)
		if(a[i]==key)
			return i;
	return -1;
}
int main()
{
	int a[]={0,1,2,3,4,5,6,7,8,9,10};
	printf("%d\n",linear_search(a,6));
	return 0;
}
