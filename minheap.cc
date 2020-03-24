#include<bits/stdc++.h>
using namespace std;
void swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}
class Minheap
{
	int *harr;
	int capacity;
	int heap_size;
	public:
	Minheap(int cap)
	{
		harr=new int[cap];
		heap_size=0;
		capacity=cap;
	}
	int parent(int i)
	{
		return (i-1)/2;
	}
	int left(int i)
	{
		return 2*i+1;
	}
	int right(int i)
	{
		return 2*i+2;
	}
	void minheapify(int i)
	{
		int l=left(i);
		int r=right(i);
		int smallest=i;
		if(harr[l]<harr[i]&&l<heap_size)
			smallest=l;
		if(harr[r]<harr[smallest]&&r<heap_size)
			smallest=r;
		if(smallest!=i)
		{	
			swap(&harr[i],&harr[smallest]);
			minheapify(smallest);
		}
	}
	int getmin()
	{
		return harr[0];
	}
	int extractmin()
	{
		if(heap_size<0)
			return INT_MAX;
		if(heap_size==1)
		{
			heap_size--;
			return harr[0];
		}
		int root=harr[0];
		harr[0]=harr[heap_size-1];
		heap_size--;		
		minheapify(0);
		return root;
	}
	int decreasekey(int i,int val)
	{
		harr[i]=val;
		while(i!=0&&harr[parent(i)]>harr[i])
		{
			swap(&harr[i],&harr[parent(i)]);
			i=parent(i);
		}
	}
	void deletekey(int i)
	{
		decreasekey(i,INT_MIN);
		extractmin();
	}
	void insertkey(int k)
	{
		if(heap_size==capacity)
		{
			cout<<"overflow\n";
			return;
		}
		heap_size++;
		int i=heap_size-1;
		harr[i]=k;
		while(i!=0&&harr[parent(i)]>harr[i])
		{
			swap(&harr[parent(i)],&harr[i]);
			i=parent(i);
		}
	}
	void print()
	{
		for(int i=0;i<heap_size;i++)
			cout<<" "<<harr[i];
		cout<<"\n";
	}
};
int main()
{
	Minheap h(11);
	h.insertkey(3);
	h.insertkey(2);
	h.insertkey(1);
	h.insertkey(15);
	h.insertkey(5);
	h.insertkey(4);
	h.insertkey(45);
	h.insertkey(17);
	h.insertkey(70);
	h.print();
	cout << h.extractmin() << " \n"; 
	h.print();
	cout << h.getmin() << " "; 
	h.decreasekey(2, 1); 
 	cout << h.getmin(); 
	return 0; 
}
