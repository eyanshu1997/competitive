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
void bubble_sort(int a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		int flag=0;
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				swap(&a[j],&a[j+1]);
				flag=1;
			}
		}
		if(flag==0)
			break;
	}
}
int main()
{
	int a[]={3,10,2,9,5,4,6,8,7,0,1};
	bubble_sort(a,11);
	print(a,11);
	return 0;
}
