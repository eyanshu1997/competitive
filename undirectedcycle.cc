#include <bits/stdc++.h>
using namespace std;
class subset 
{ 
	public:
	int parent; 
	int rank; 
};
int find(subset subsets[],int i)
{
	if(subsets[i].parent!=i)
		subsets[i].parent=find(subsets,subsets[i].parent);
	return subsets[i].parent;
}
void Union(subset subsets[],int i,int j)
{
	int x=find(subsets,i);
	int y=find(subsets,j);
	 if (subsets[x].rank < subsets[y].rank) 
		subsets[x].parent = y; 
	else if (subsets[x].rank > subsets[y].rank) 
		subsets[y].parent = x;
	else
	{ 
		subsets[y].parent = x; 
		subsets[x].rank++; 
	}
}

class edge
{
	public:
	int src;
	int dest;
	edge(int s,int d)
	{
		src=s;
		dest=d;
	}
};
class graph
{
	public:
	int ver;
	int edges;
	vector<edge> adj;
	graph(int v)
	{
		ver=v;
		edges=0;
	}
	void addedge(int a,int b)
	{
		edges++;
		edge *ax=new edge(a,b);
		adj.push_back(*ax);
	}
	bool iscyclic()
	{
		int *visited = new int[ver];
		subset *subsets = new subset[ver];
		for(int i=0;i<ver;i++)
		{
			subsets[i].parent=i;
			subsets[i].rank=0;
		}
		for(auto i=adj.begin();i!=adj.end();i++)
		{
			int x=find(subsets,i->src);
			int y=find(subsets,i->dest);
			if(x==y)
				return true; 
			Union(subsets,x,y);
		}
		return false;
	}
};
int main()
{
	graph *g=new graph(4);
	g->addedge(0,1);
	g->addedge(1,2);
	g->addedge(0,2);
	if(g->iscyclic())
		cout<<"graph contains cycle";
	else
		cout<<"graph doesn't contain cycle";  
  
    return 0;  
}

