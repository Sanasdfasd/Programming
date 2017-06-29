#include <iostream>
#include <stdio.h>
#include <cstring>
#include <memory>
#include <stdlib.h> 
#include <time.h>    

using namespace std;
char a[300005];
int as[300005];
long long int dp[10][4];
long long int dp1[10][4];
int main()
{
memset(dp,0,sizeof(dp));
 memset(dp1,0,sizeof(dp));
 int sz=0;
memset(a,0,sizeof(a));
scanf("%s",a);
//cout<<"the size of the character array is "<<strlen(a)<<endl;
 int i,j,k,o,q;
 for(i=0;i<sz;i++)
 {
 	as[i]=a[i]-'0';
 	//cout<<as[i]; 
 }
 int rem=as[0]%8;
 //dp[as[0]][rem]=1;
for(i=0;i<sz;i++)
{
   rem=as[i]%8;
   dp1[as[i]][rem]=dp1[as[i]][rem]+1;
 for(k=0;k<=9;k++)
  {
   for(j=0;j<8;j++)
   {
   	 if(dp[k][j]!=0)
   	 {
       int val= (j*10)+as[i];
       rem=val%8;
      // cout<<"the value is given by state is "<<i<<" "<<k<<as[i]<<"rem is "<<j<<"current remainderis"<<rem<<endl;
       dp1[as[i]][rem]=dp1[as[i]][rem]+dp[k][j];
       //cout<<"the value is given by state is "<<i<<" "<<k<<as[i]<<"rem is "<<j<<"rem"<<rem<<"orginal"<<dp[k][j]<<"aded"<<dp1[as[i]][rem]<<endl;
       // dp1[k][j]=dp1[k][j]+dp[k][j];
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
	//cout<<"those ending with "<<i<<" "<<dp[i][0]<<endl;
 cal=cal+dp[i][0];
}
cout<<"the cal is "<<cal<<endl;
	return 0;
}