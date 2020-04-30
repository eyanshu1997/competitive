#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

struct Segment {
  int start, end;
};
void prints(Segment s)
{
		cout<<s.start<<" == >>"<<s.end<<"\n";
}
void print(vector <Segment> s)
{
	//cout<<"size is "<<s.size()<<"\n";
	for(auto i=s.begin();i<s.end();i++)
	{
		cout<<(*i).start<<" == >>"<<(*i).end<<" ";
	}
	cout<<"\n";
}
bool cmp(Segment a,Segment b)
{ return a.end<b.end;}

vector<int> optimal_points(vector<Segment> &s) 
{
	vector<int> points;
	sort(s.begin(),s.end(),cmp);
	while(s.size())
	{
		Segment se=*s.begin();
		s.erase(s.begin());
		int x=se.end;
		points.push_back(x);
		//cout<<"selected ";
		//prints(se);
		//print(s);	
		auto i=s.begin();
		while(i!=s.end())
		{
			if(((*i).start<=x)&&((*i).end>=x))
			{
				//prints(*i);
				i++;
			}
			else
				break;
		}
		vector<Segment> t;
		copy(i,s.end(),back_inserter(t));
		//cout<<"after removing selected poinyt\n";
		s=t;
		//print(s);		
	}	
	return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
