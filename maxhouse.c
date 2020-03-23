#include<stdio.h>
#include<stdlib.h>	
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int l=0;l<n;l++)
	{
		
		int no;
		long int b;
		scanf("%d %ld",&no,&b);
		int *a=(int *)malloc(no*sizeof(int));
		for(int i=0;i<no;i++)
		{
			scanf("%d",&a[i]);
			for(int k=i;k>0;k--)
			if(a[k]<a[k-1])
			{
				swap(&a[k-1],&a[k]);
			}
		}
		if(a[0]>b)
			printf("CASE #%d: %d\n",l+1,0);
		else
		{
			int i=0;
			while((b-a[i])>=0&&i<n)
			{
				b=b-a[i++];
			}
			printf("CASE #%d: %d\n",l+1,i);
		}
	}
	return 0;
}
