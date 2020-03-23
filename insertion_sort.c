#include<stdio.h>

void print(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
void insertion_sort(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		int key=a[i];
		int j=i-1;
		while(j>=0&&a[j]>key)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}
int main()
{
	int a[]={3,10,2,9,5,4,6,8,7,0,1};
	insertion_sort(a,11);
	print(a,11);
	return 0;
}
