#include <iostream>
#include <cstring>
#include <memory>
#include <stdlib.h> 
#include <time.h>    

using namespace std;

long long int dp[101][205];

int a[200005];

long long int pow[200005];

void cal_pow()
{
	int i;
	pow[0]=1;
	for(i=1;i<200005;i++)
	{
       pow[i-1]=pow[i-1]%(1000000009);
       pow[i]=pow[i-1]*2;
       pow[i]=pow[i]%(1000000009);
	}
}

int main(){

memset(dp,0,sizeof(dp));
memset(a,0,sizeof(a));
memset(pow,0,sizeof(pow));
int n;
int i,j;
cal_pow();
cin>>n;

for(i=0;i<n;i++)
{
	cin>>a[i];
}
dp[a[0]][0]=1;
for(i=1;i<n;i++)
{ 
	  dp[a[i]][0]=dp[a[i]][0]+1;
	for(j=1;j<=100;j++)
	{
		if(j!=a[i])
		{
      if(dp[j][0]!=0)
      {
      	 int val=a[i]-j;
        if((a[i]-j)<0)
          val=100-(a[i]-j);
        if(dp[j][val]!=0)
        { 
        	dp[a[i]][val]=dp[j][val]+(dp[j][0]*(1))+dp[a[i]][val];
        	dp[a[i]][val]=dp[a[i]][val]%(1000000009);
        }
        else
        { 
        	dp[a[i]][val]=dp[a[i]][val]+(dp[j][0]*1);
        }
        
       }
   }
    }        
}
long long int cal=0;
for(i=0;i<101;i++)
{
	for(j=0;j<=200;j++)
	{
      if(j==0)
      {
       cal=cal+(pow[dp[i][j]]-1);
      }
      else
      {
      	cal=cal+dp[i][j];
      }

      cal=cal%(1000000009);
	}
}
cout<<cal+1<<endl;
return 0;
}
