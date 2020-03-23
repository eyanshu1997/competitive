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
int partition (int arr[], int low, int high)  
{  
	int pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++)
		if (arr[j] < pivot)
			swap(&arr[++i], &arr[j]);
	swap(&arr[i + 1], &arr[high]);  
	return (i + 1);  
}  
void quick_sort(int arr[], int low, int high)  
{
	if (low < high)  
	{
		int pi = partition(arr, low, high);  
		quick_sort(arr, low, pi - 1);  
		quick_sort(arr, pi + 1, high);  
	}  
}  
int main()
{
	int a[]={3,10,2,9,5,4,6,8,7,0,1};
	quick_sort(a,0,11);
	print(a,11);
	return 0;
}
