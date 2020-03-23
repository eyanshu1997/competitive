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
int main()
{
	int a[]={0,1,2,3,4,5,6,7,8,9,10};
	printf("%d\n",binary_search(a,0,11,6));
	return 0;
}
