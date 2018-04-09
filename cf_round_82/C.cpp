//
// Created by Sandeep on 4/7/18.
//
#include <bits/stdc++.h>
using namespace std;
int ar[10][4];
int dp[1005][2]={};
int main(){
  int n,m,c,d;
  cin>>n>>m>>c>>d;
  for (int i = 0; i <1005 ; ++i)
    for (int i1 = 0; i1 <2 ; ++i1) dp[i][i1]=-1;
  for (int i = 0; i <m ; ++i) cin>>ar[i][0]>>ar[i][1]>>ar[i][2]>>ar[i][3];
  dp[n][1]=0;
  for (int i = 0; i <m; ++i) {
    for (int j = 1; j <1001; ++j) {
      if ((ar[i][0] - (j * ar[i][1])) < 0) break;
      for (int k = (j * ar[i][2]); k < 1001; ++k) {
        int xr = i & 1;
        if (dp[k][xr ^ 1] != -1) {
          int temp = k - (j * ar[i][2]);
          dp[temp][xr] = max(dp[temp][xr], (dp[k][xr ^ 1] + ar[i][3] * j));
        }
      }
    }
      for (int l = 0; l <1001; ++l) {
        int xr = i & 1;
        dp[l][xr] = max(dp[l][xr], dp[l][xr ^ 1]);
        dp[l][xr ^ 1] = -1;
      }
  }
  int ans=0;
  for (int k1 = 0; k1 <2 ; ++k1) {
    for (int i = 0; i < 1001; ++i) {
      if (i < c) ans = max(ans, dp[i][k1]);
      else {
        if (dp[i][k1] != -1)
          ans = max(ans, dp[i][k1]+((i/c)*d));
      }
    }
  }
cout<<ans<<endl;
  return 0;
}
