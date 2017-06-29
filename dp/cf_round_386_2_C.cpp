#include <bits/stdc++.h>
using namespace std;
int ma[30005];
int dp[30005][510];
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
	ma[a]+=1;
}

for(i=0;i<30005;i++)
{
	 if(i==0)
      { 
         if((d-1)>0 && (i+d-1)<=30004) 
         	dp[i+d-1][d-1]=max(dp[i+d-1][d-1],ma[i+d-1]);
         if((i+d)<= 30004)
         	dp[i+d][d]=max(dp[i+d][d],ma[i+d]);   
          if((i+d+1)<= 30004)
         	dp[i+d+1][d]=max(dp[i+d+1][d],ma[i+d+1]); 
         continue;
      }
	for(j=1;j<510;j++)
	{
              if((j-1)>0 && (i+j-1)<=30004) 
         	dp[i+j-1][j-1]=max(dp[i+j-1][j-1],(ma[i+j-1]+dp[i][j]));
         if((i+j)<= 30004)
         	dp[i+j][j]=max(dp[i+j][j],(ma[i+j]+dp[i][j]));   
          if((i+j+1)<= 30004)
         	dp[i+j+1][j]=max(dp[i+j+1][j],(ma[i+j+1]+dp[i][j])); 
        // continue
	}
}
int res=0;
for(i=0;i<30005;i++)
	for(j=0;j<510;j++)
		res=max(res,dp[i][j]);
cout<<res<<endl;




	return 0;
}
