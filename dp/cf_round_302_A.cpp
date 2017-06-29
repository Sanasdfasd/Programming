#include <bits/stdc++.h>

using namespace std;

long long int n,mod; 
int dp[505][505];
long long int a[505];
int m,b;

int main()
{

int i;
cin>>n>>m>>b>>mod;
for(i=0;i<n;i++)
  cin>>a[i];;

memset(dp,0,sizeof(dp));
long long int res=0;
int j,k;
 dp[0][0]=1%(mod);

for(i=0;i<n;i++)
{
  for(j=0;j<=m;j++)
   {
     for(k=0;k<=(b);k++)
     {
       if((j+1 )<= m && (k+a[i])<=b)
        {
          dp[j+1][k+a[i]]=dp[j+1][k+a[i]]+dp[j][k];
          dp[j+1][k+a[i]]=dp[j+1][k+a[i]]%(mod);
        }
     }
   }
}
for(i=0;i<=b;i++)
{
   res= res+ dp[m][i];
   res=res%(mod);
}
cout<<res<<endl;
	return 0;
}
