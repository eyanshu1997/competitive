#include<stdio.h>
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void print(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
void selection_sort(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		int min_i=i;
		for(int j=i;j<n;j++)
		{
			if(a[min_i]>a[j])
				min_i=j;
		}
		swap(&a[min_i],&a[i]);
	}
}
int main()
{
	int a[]={3,10,2,9,5,4,6,8,7,0,1};
	selection_sort(a,11);
	print(a,11);
	return 0;
}
