#include<stdio.h>

void print(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
void merge(int a[],int l,int mid,int r)
{
	int i=0,j=0,k=l,n1=mid-l+1,n2=r-mid;
	int la[n1];
	int ra[n2];
	for(int p=0;p<n1;p++)
			la[p]=a[l+p];
	for(int p=0;p<n2;p++)
			ra[p]=a[mid+p+1];
	while(i<n1&&j<n2)
	{
		if(la[i]<ra[j])
			a[k++]=la[i++];
		else
			a[k++]=ra[j++];
	}
	while(i<n1)
		a[k++]=la[i++];
	while(j<n2)
		a[k++]=ra[j++];
}
void mergesort(int a[],int l,int r)
{
	if(l<r)
	{
		int mid=(l+r)/2;
		mergesort(a,l,mid);
		mergesort(a,mid+1,r);
		merge(a,l,mid,r);
	}
}
int main()
{
	int a[]={3,10,2,9,5,4,6,8,7,0,1};
	mergesort(a,0,10);
	print(a,11);
	return 0;
}
