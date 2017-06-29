#include <bits/stdc++.h>
using namespace std;

int dp[1005];
int pos[1005][6];
int mat[1005][6];
 int main()
 {
 int n,k,t;
 cin>>n>>k;
int i,j,a,b;
fill(dp,dp+1004,1);

for(j=0;j<k;j++)
{
 for(i=0;i<n;i++)
 {
    cin>>a;
    pos[a-1][j]=i;
    mat[i][j]=a-1;
 }
}
for(i=0;i<n;i++)
{
  for(j=0;j<i;j++)
  {
  	int br=0;
    for(t=0;t<k;t++)
    {
      if(pos[mat[i][0]][t]<pos[mat[j][0]][t]) 
      {     
        br=1;
        break;
       }
    }
    if(br==0)
    	dp[mat[i][0]]=max(dp[mat[i][0]], dp[mat[j][0]]+1);
  }
}
int res=0;

for(i=0;i<n;i++)
  res=max(res,dp[i]);

cout<<res<<endl;
 	return 0;
 }


