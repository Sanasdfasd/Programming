#include <bits/stdc++.h>
using namespace std;

int n,m,t;
vector< pair < int, int > > vs[5005];
int dp[5005][5005];
int sol[5005][5005];
 int main()
 {
 	cin>>n>>m>>t;
 	int i,j;
 	for(i=0;i<m;i++)
 	{
 		int a,b,c;
 		cin>>a>>b>>c;
 		vs[a].push_back( make_pair(b,c));
 	}
  for(i=0;i<5005;i++)
  {
    for(j=0;j<5005;j++)
      dp[i][j]=-1;
  }
  dp[1][1]=0;
  sol[1][1]=0;
  memset(sol,0,sizeof(sol));
  queue <pair < int, int> > quee;
  quee.push(make_pair(1,1));
  int layer=1,tt;
while(!quee.empty())
{
i=quee.front().first;
layer=(quee.front().second)+1;
  for(j=0;j<vs[i].size();j++)
  {
       if(dp[i][layer-1]!=-1)
       {
        int tdd=dp[vs[i][j].first][layer];
            if(tdd!=-1)
            {
              int temp1= dp[vs[i][j].first][layer];
              int temp2=dp[i][layer-1]+vs[i][j].second;
              if(temp1>temp2 && temp2<=t)
              {
                 dp[vs[i][j].first][layer]=temp2;
                sol[vs[i][j].first][layer]=i;
                quee.push( make_pair (vs[i][j].first, layer));
              }
            }
            else
            {
              int ss=t+1;
                ss=dp[i][layer-1]+vs[i][j].second;              
              if(ss<=t)
              {
                 dp[vs[i][j].first][layer]=ss;
                sol[vs[i][j].first][layer]=i;
               quee.push( make_pair (vs[i][j].first, layer));
              }
            }
       } 
  }
quee.pop();
}

vector < int> res;
int prev=n;

//Retreving the elements in the sorted order
while(prev>=1)
{
  res.push_back(prev);
  int mx=-1;
  int index=0;
  for(j=0;j<=n;j++)
  {

     if(dp[prev][j]!=-1 && (dp[prev][j]<=t))
     {
       mx=dp[prev][j];
       index=sol[prev][j];
    }
  }
  int val=0;
  for(i=0;i<vs[index].size();i++)
  {
     if(vs[index][i].first==prev)
      val=vs[index][i].second;
  }
  t=t-(val);
  prev=index;

 }
reverse(res.begin(),res.end());
cout<<res.size()<<endl;
for(i=0;i<res.size();i++)
  cout<<res[i]<<" ";
cout<<endl;

 	return 0;
 }
