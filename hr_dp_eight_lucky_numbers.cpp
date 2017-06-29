#include <iostream>
#include <stdio.h>
#include <cstring>
#include <memory>
#include <stdlib.h> 
#include <time.h>    

using namespace std;
string a;
int as[300005];
long long int dp[10][8];
long long int dp1[10][8];
int main()
{
 memset(dp,0,sizeof(dp));
 memset(dp1,0,sizeof(dp));
 int sz=0;
cin>>sz;
cin>>a;
 int i,j,k,o,q;
 for(i=0;i<sz;i++)
 	as[i]=a.at(i)-'0';
 int rem=as[0]%8;

for(i=0;i<sz;i++)
{
   rem=as[i]%8;
   dp1[as[i]][rem]=dp1[as[i]][rem]+1;
   dp1[as[i]][rem]=dp1[as[i]][rem]%(1000000007);
 for(k=0;k<=9;k++)
  {
   for(j=0;j<8;j++)
   {
   	 if(dp[k][j]!=0)
   	 {
       int val= (j*10)+as[i];
       rem=val%8;
       dp1[as[i]][rem]=dp1[as[i]][rem]+dp[k][j];
        dp1[as[i]][rem]=dp1[as[i]][rem]%(1000000007);
      }
    }
  }
 memset(dp,0,sizeof(dp));
 memcpy(dp,dp1,sizeof(dp));
 memset(dp1,0,sizeof(dp));
 memcpy(dp1,dp,sizeof(dp));
}
long long int cal=0;
for(i=0;i<=9;i++)
{
 cal=cal+dp[i][0];
    cal=cal%(1000000007);
}
cout<<cal<<endl;
	return 0;
}