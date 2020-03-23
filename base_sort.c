#include<stdio.h>

void print(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
void sort(int a[],int n)
{


}
int main()
{
	int a[]={3,10,2,9,5,4,6,8,7,0,1};
	sort(a,11);
	print(a,11);
	return 0;
}
