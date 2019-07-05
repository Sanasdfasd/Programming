#include <bits/stdc++.h>
using namespace std;

const int mod=1e9+7;

int main(){

  int n;
  cin>>n;
  vector<vector<int>> inp(n, vector<int>(n));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
      cin>>inp[i][j];
  }
  int dp[(1<<n)+5]={};

  dp[0]=1;

     for(int mask=0;mask<(1<<n)-1;mask++){
      int j=__builtin_popcount(mask);
       for(int k=0;k<n;k++){
         if(inp[j][k] && !(mask &(1<<k))){
            int val= mask^(1<<k);
            dp[val]+=dp[mask];
            dp[val]=dp[val]%mod;
         }
      }
    }
   cout<<dp[(1<<n)-1]<<endl; 

   return 0;

}