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
	int weight;
	edge(int s,int d,int w)
	{
		src=s;
		dest=d;
		weight=w;
	}
	void print()
	{
		cout<<src<<"--->"<<dest<<" === "<<weight<<"\n";
	}
};
bool cmp(edge a,edge b)
{
	return (a.weight<b.weight);
}
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
	void addedge(int a,int b,int c)
	{
		edges++;
		edge *ax=new edge(a,b,c);
		adj.push_back(*ax);
	}
	void krushkals()
	{
		int *visited = new int[ver];
		subset *subsets = new subset[ver];
		for(int i=0;i<ver;i++)
		{
			subsets[i].parent=i;
			subsets[i].rank=0;
		}
		sort(adj.begin(),adj.end(),cmp);
		int j=0;
		vector<edge> result;
		for(auto i=adj.begin();i!=adj.end()&&j<ver-1;i++)
		{
			int x=find(subsets,i->src);
			int y=find(subsets,i->dest);
			if(x!=y)
			{
				result.push_back(*i);
				Union(subsets,x,y);
			}
		}
		for(auto i=result.begin();i!=result.end();i++)
			i->print();
	}
};
int main()
{
	graph *g=new graph(4);
	g->addedge(0,1,10);
	g->addedge(0,2,6);
	g->addedge(0,3,5);
	g->addedge(1,3,15);
	g->addedge(2,3,4);
	g->krushkals();
  
    return 0;  
}

