#include <bits/stdc++.h>

using namespace std;

int sol[2000005];
int main()
{
int n,k,q;
cin>>n>>k>>q;
int i,j,l;
vector< pair < int, int> > pi;
for(i=0;i<n;i++)
{
	int a,b;
	cin>>a>>b;
	pi.push_back(make_pair(a,b));
}
sort(pi.begin(), pi.end());
for(i=0;i<2000005;i++)
{
  int lo=0, hi= n, ans=0;
  while(lo<=hi)
  {
    int mid= (lo+hi)/2;
    


  }



sol[i]=ans;
}






	return 0;
}