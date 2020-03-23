#include<stdio.h>
int binary_search(int a[],int start,int end,int key)
{
	if(start<=end)
	{
		int mid=(start+end)/2;
		if(a[mid]==key)
			return mid;
		if(a[mid]<key)
			return binary_search(a,mid+1,end,key);
		else
			return binary_search(a,start,mid-1,key);
	}
	return -1;
}
int min(int a,int b)
{
	if(a<b)
		return a;
	return b;
}
int exponential_search(int arr[], int n, int x) 
{ 
    if (arr[0] == x) 
        return 0; 
    int i = 1; 
    while (i < n && arr[i] <= x) 
        i = i*2; 
    return binary_search(arr, i/2, min(i, n), x); 
} 
int main()
{
	int a[]={0,1,2,3,4,5,6,7,8,9,10};
	printf("%d\n",exponential_search(a,11,6));
	return 0;
}
