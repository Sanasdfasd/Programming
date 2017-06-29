#include <bits/stdc++.h>
using namespace std;
int ma[30005];
int dp[30005][2105];
int solve(int a,int b)
{
	if(a>30000 || b==0) return 0;
	return ma[a]+max(max(solve(a+b,b),solve(a+b+1,b+1)),solve(a+b-1,b-1));
}
int main()
{
int n,d;
cin>>n>>d;
memset(ma,0,sizeof(ma));
memset(dp,0,sizeof(dp));
int i,j;
for(i=0;i<n;i++)
{
	int a;
	cin>>a;
	//a=a-1;
	ma[a]=ma[a]+1;
}
if(d>2020)
{
	cout<<solve(d,d);
	return 0;
}
for(i=0;i<30005;i++)
	for(j=0;j<2105;j++)
		dp[i][j]=-1;

for(i=1;i<30005;i++)
{
	 if(i==1)
      { 
         if((d)<= 30004)
         	dp[d][d]=max(dp[d][d],ma[d]);   
        // continue;
      }
	for(j=1;j<2050;j++)
	{
            if((j-1)>0 && (i+j-1)<=30004 && dp[i][j]>=0) 
         	dp[i+j-1][j-1]=max(dp[i+j-1][j-1],(ma[i+j-1]+dp[i][j]));
         if((i+j)<= 30004 && dp[i][j]>=0)
         	dp[i+j][j]=max(dp[i+j][j],(ma[i+j]+dp[i][j]));   
          if((i+j+1)<= 30004 && dp[i][j]>=0)
         	dp[i+j+1][j+1]=max(dp[i+j+1][j+1],(ma[i+j+1]+dp[i][j])); 
	}

}
int res=0;
for(i=0;i<30005;i++)
	for(j=0;j<2050;j++)
	 res=max(res,dp[i][j]);
cout<<res<<endl;

	return 0;
}
