#include <bits/stdc++.h>

using namespace std;
int dp[27][1505];
int sol[27][1505];
int main()
{
int n;
string s;
cin>>n;
int i,j,k,tt,ss;

cin>>s;
memset(dp,0,sizeof(dp));
for(i=0;i<26;i++)
   for(j=0;j<=n;j++)
    sol[i][j]=1;

for(i=0;i<26;i++)
{
   char var= i+'a';
   for(j=0;j<n;j++)
   {
      for(k=n;k>=0;k--)
      {
          if(s[j]!=var)
          {
            if(k==0)
              dp[i][k]=0;
            else
            dp[i][k]= dp[i][k-1]+1;
           sol[i][k]= max(dp[i][k],sol[i][k]);
          }
          else
          {
            dp[i][k]=dp[i][k]+1;
            sol[i][k]=max(sol[i][k], dp[i][k]);
          }
      }
  }
}

int q;
cin>>q;
for(i=0;i<q;i++)
{
 char val;
 int a;
 cin>>a>>val;
  cout<<sol[val-'a'][a]<<endl;
}


return 0;
}