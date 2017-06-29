#include <bits/stdc++.h>

using namespace std;
long long int dp[105][105];
long long int dp1[105][105];

int main()
{
long long int n,m,l;
cin>>n>>m>>l;
int cols[n+5];
long long int paints[n+5][n+5];
long long int i,j,k,a,b,t,ls,ts;
memset(dp,-1,sizeof(dp));
memset(dp1,-1,sizeof(dp1));
for(i=0;i<n;i++)
	cin>>cols[i];
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
		cin>>paints[i][j];
}
int first=0,der=0;
for(i=0;i<n;i++)
{
	cout<<"*********** Iteration: "<<i<<endl;
  if(cols[i]!=0)
  {
     if(i==0)
      dp1[cols[i]][1]=0;
      else
      {
        for(ls=1;ls<=m;ls++)
        {
          for(ts=0;ts<=l;ts++)
          {
          	 if( dp[ls][ts]!=-1)
              {
                   if( ls!=cols[i])
                   	  dp1[ls][ts+1]=dp[ls][ts];
                   	else
                   	  dp1[ls][ts]=dp[ls][ts];	
              }
          }
        }

      }
      cout<<" in this block"<<endl;
 for(ls=1;ls<=m;ls++)
 {
 	for(ts=0;ts<=l;ts++)
 	{
 		cout<<dp1[ls][ts]<<"  ";
 	}
 	cout<<endl;
 }
cout<<endl;

  continue;  	
  }


   for(j=0;j<m;j++)
   {
      for(k=1;k<=m;k++)
      {
         for(t=0;t<=l;t++)
         {
               if(cols[i]!=k && cols[i]==0 && i!=0)
               {   
               	if( dp[k][t]!=-1 && dp1[k][t+1]!=-1)
               	    dp1[k][t+1]= min((dp[k][t]+paints[i][j]), dp1[k][t+1]);  
               	 if( dp[k][t]!=-1 && dp1[k][t+1]==-1)
                    dp1[k][t+1]= dp[k][t]+paints[i][j];
               }
                if(cols[i]==k && i!=0)
                {
                	if(dp[k][t]!=-1 && dp1[k][t]!=-1)
                		dp1[k][t]= min(dp[k][t]+paints[i][j], dp1[k][t]);
                	 if(dp1[k][t]==-1 && dp[k][t]!=-1)
                        dp1[k][t]=dp[k][t]+paints[i][j];
                }
               
         }

      }
        if(i==0)
         dp1[j+1][1]=paints[i][j];
   }
 for(ls=1;ls<=m;ls++)
 {
 	for(ts=0;ts<=l;ts++)
 	{
 		cout<<dp1[ls][ts]<<"  ";
 	}
 	cout<<endl;
 }
cout<<endl;

   memset(dp,-1,sizeof(dp));
   memcpy( dp,dp1, sizeof(dp));
}

long long int mi=0;
for(i=1;i<=m;i++)
{
	if(dp[i][l]!=-1)
	   mi= min(dp[i][l],mi);
}
if(mi==0)
	mi=-1;

cout<<mi<<endl;

return 0;
}