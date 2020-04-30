#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;
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
	vector<edge> *adj;
	graph(int v)
	{
		ver=v;
		edges=0;
		adj=new vector<edge>[v];
	}
	void addedge(int a,int b,int c)
	{
		edges++;
		edge *ax=new edge(a,b,c);
		adj[a].push_back(*ax);
	}
	void print()
	{
		for(int i=0;i<ver;i++)
			for(auto j=adj[i].begin();j!=adj[i].end();j++)
				(*j).print();
	}
	void dijkstras()
	{
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> h=*(new priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>());
		h.push(make_pair(0,0));
		for(int i=1;i<ver;i++)
		{
			h.push(make_pair(INT_MAX,i));
		}
		vector<int> d(ver,INT_MAX);
		d[0]=0;
		while(!h.empty())
		{
			int u=h.top().second;
			h.pop();
			for(auto i:adj[u])
			{
				int v=i.dest;
				int w=i.weight;
				if(d[v]>d[u]+w)
				{
					//cout<<v<<" "<<u<<"\n";
					d[v]=d[u]+w;
					h.push(make_pair(d[v],v));
				}
			}
		}
		for(auto i:d)
			cout<<i <<" ";
		cout<<"\n";
		
	}
};
int main() {
	//code
	graph g=*(new graph(4));
	g.addedge(0,1,5);
	g.addedge(1,2,2);
	g.addedge(0,2,5);
	g.addedge(0,3,4);
	g.print();
	g.dijkstras();
	return 0;
}
