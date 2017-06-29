#include <bits/stdc++.h>
using namespace std;

vector< pair < int, int> > pi;

int sol[2000005];
int n,k,q;

int tt[2000005];

int main()
{

cin>>n>>k>>q;
int i,j,l;
memset(sol,0,sizeof(sol));
memset(tt,0,sizeof(tt));
for(i=0;i<n;i++)
{
	int a,b;
	cin>>a>>b;
	tt[a]=tt[a]+1;
	tt[b+1]=tt[b+1]-1;
}
for(i=1;i<2000005;i++)
{
	tt[i]=tt[i]+tt[i-1];

}
for(i=0;i<2000005;i++)
{
    if((tt[i])>=k)
       sol[i]=1;
}
for(i=1;i<2000005;i++)
	sol[i]=sol[i-1]+sol[i];

for(j=0;j<q;j++)
{
  int a,b;
  cin>>a>>b;
  if(a!=0)
  cout<<sol[b]-sol[a-1]<<endl;
else
	cout<<sol[b]<<endl;
}

	return 0;
}