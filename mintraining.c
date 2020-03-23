#include<stdio.h>
#include<stdlib.h>	

void print(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void bubble_sort(int a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		int flag=0;
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]<a[j+1])
			{
				swap(&a[j],&a[j+1]);
				flag=1;
			}
		}
		if(flag==0)
			break;
	}
}
int solve(int a[],int n,int b)
{
	int i=0;
	int t=n;
	for(i=0;i<b;i++)
	{
		int max_i=i;
		for(int j=0;j<t;j++)
		{
			if(a[max_i]<a[j])
				max_i=j;
		}
		swap(&a[max_i],&a[i]);
		//printf("before change\n");
		//print(a,t);
		if(a[i]%2==0)
		{
			int y=a[i]/2;
			a[t++]=y;
			a[i]=y;
		}
		else
		{
			int y=a[i]/2+1;
			a[t++]=y;
			a[i]=y-1;
		}
		//printf("after iteration %d \n",i);
		//print(a,t);
	}
	int max=0;
	for(int i=0;i<t;i++)
		if(max<a[i])
			max=a[i];
	return max;
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
		int *a=(int *)malloc((no+b)*sizeof(int));
		int prev,now;
		for(int i=0;i<no;i++)
		{
			scanf("%d",&now);
			if(i!=0)		
				a[i-1]=now-prev;
			prev=now;
		}		
		//print(a,no-1);	

		printf("CASE #%d: %d\n",l+1,		solve(a,no-1,b));
	}
	return 0;
}
