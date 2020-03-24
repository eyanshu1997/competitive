#include <bits/stdc++.h>
 
using namespace std;
class Qnode
{
	public:
	int data;
	Qnode *next;
	Qnode(int d)
	{
		data=d;
		next=NULL;
	}
};

class Queue
{
	public:
	Qnode *front ,*rear;
	Queue()
	{
		front =rear=NULL;
	}
	void enqueue(int x)
	{
		Qnode *temp=new Qnode(x);
		if(rear==NULL)
		{
			front=rear=temp;
			return;
		}
		rear->next=temp;
		rear=temp;
	}
	int deQueue()
	{
		if(front==NULL)
			return INT_MIN;
		Qnode* temp=front;
		front=front->next;
		if(front ==NULL)
			rear=NULL;
		delete(temp);
	}
};
int main()
{
	Queue q;
	q.enqueue(10); 
	q.enqueue(20); 
	q.deQueue(); 
	q.deQueue(); 
	q.enqueue(30); 
	q.enqueue(40); 
	q.enqueue(50); 
	cout << "Queue Front : " << (q.front)->data << endl; 
	cout << "Queue Rear : " << (q.rear)->data; 
}
