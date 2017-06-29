#include <iostream>
#include <cstring>
#include <memory>
#include <stdlib.h> 
#include <time.h>    
long long int dp[10];
using namespace std;

long long int solve(long long int n,long long int m)
{

long long int i,j,k;
long long int dp1[10];
memset(dp1,0,sizeof(dp1));
for(i=1;i<=9;i++)
{
	if(m%i==0)
	{
		dp[i]=1;
	}
}
//the dp's that are true are given by
/*for(i=1;i<=9;i++)
{
  cout<<"i:"<<i<<" "<<dp[i]<<endl;
}*/

for(i=1;i<n;i++)
{
	for(j=1;j<=9;j++)
	{
		for(k=1;k<=9;k++)
		{
			if((m%k==0 && m%j==0) && (j%k!=0 && k%j!=0)||(j==1 || k==1) )
            {
            	if(j==1 || k==1)
            	{
            		if(j==1)
            		{
            			if(m%k!=0)
            				continue;
            		}
            	   else
            	   {
            	   	  if(m%j!=0)
            	   	  	 continue;
            	   }
            	}
              //cout<<"i:"<<i<<" "<<"j:"<<j<<"K:"<<k<<" "<<dp[j]<<" "<<dp[k]<<endl;
               dp1[k]=dp[j]+dp1[k];
               dp1[k]=dp1[k]%(1000000007);
		     }
         }
	}
 memset(dp,0,sizeof(dp));
 memcpy(dp,dp1,sizeof(dp));
 memset(dp1,0,sizeof(dp));
}
long long int cal=0;
for(i=1;i<=9;i++)
{
 cal=cal+dp[i];
 cal=cal%(1000000007);
}
return cal;
}

int main()
{
int q,i;
long long int n,m;
cin>>q;
for(i=0;i<q;i++)
{
memset(dp,0,sizeof(dp));
cin>>n>>m;
long long int res=solve(n,m);
cout<<res<<endl;
}

 return 0;
}