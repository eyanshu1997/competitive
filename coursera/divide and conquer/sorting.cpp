#include <bits/stdc++.h>
#define ll long long int
#define tr(a,x) for(auto a:x)
#define tri(a,x) for(auto a=x.begin();a!=x.end();a++)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define fo(i,x) for(int i=0;i<x;i++)
#define p_b(x,i) x.push_back(i)
#define printed(x,i) cout<<x<<i<<"\n"
#define printe(i) cout<<i<<" "
#define ip(s) vector <s>vec;for(int i=0;i<n;i++){s tmp;cin>>tmp;vec.push_back(tmp);}
using namespace std;
void print(vector <int>a,int l,int r)
{
	for(int i=l;i<=r;i++)
	printe(a[i]);
cout<<"\n";
}

pair<int,int> partition1(vector<int> &a, int l, int r) 
{
	int x = a[l];
	int j=l;
	int k=l;
	for (int i = l + 1; i <= r; i++) 
	{
		if(a[i]==x)
		{
			k++;
			swap(a[i], a[k]);
		}
		else 
		{
			if(a[i]<x)
			{
 				if(k!=j)
				{
					if(k+1==i)
					{
						j++;k++;
						swap(a[j],a[i]);
					}
					else
					{
						k++;
						swap(a[j+1],a[k]);
						j++;
						swap(a[i], a[j]);
					}
				}
				else
				{
					k++;
					j++;
					swap(a[i],a[j]);
				}
			}
		}
	}
	swap(a[l], a[j]);
	return make_pair(j-1,k);
}


void randomized_quick_sort(vector<int> &a, int l, int r) {

  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  //int k=1;
  swap(a[l], a[k]);
  pair <int,int> m = partition1(a, l, r);

  randomized_quick_sort(a, l, m.first );
  randomized_quick_sort(a,m.second+1, r);
}

int x()
{
 int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
int main() {
x();

}
