//
// Created by Sandeep on 8/24/2018.
//
#include <bits/stdc++.h>
using namespace std;
 int pre_comp[505][505]={};
vector<int> gap[505];
long long int dp[505][505]={};
int n,m,k;
int main(){
 cin>>n>>m>>k;
  string s;
  for (int i = 0; i < n; ++i) {
      cin>>s;
    for (int j = 0; j < m; ++j) {
       if(s[j]=='1')
      gap[i].push_back(j);
    }
  }
 for (int i = 0; i <n ; ++i) {
    if(gap[i].size()>0){
    pre_comp[i][0]=gap[i][gap[i].size()-1]-gap[i][0]+1;
    for (int sz= 1; sz <=k && sz<gap[i].size() ; sz++) {
      for(int lptr=0;lptr<=sz;lptr++) {
        if (pre_comp[i][sz] != 0)
          pre_comp[i][sz] = min(pre_comp[i][sz], (gap[i][gap[i].size() - 1 - abs(sz - lptr)] - gap[i][lptr] + 1));
        else
          pre_comp[i][sz] = (gap[i][gap[i].size() - 1 - abs(sz - lptr)] - gap[i][lptr ] + 1);
         }
      }
    }
  }
  //Calculate the DP values
  for (int i = 0; i <n ; ++i) {
    for (int pre = 0; pre <=k ; ++pre)
      dp[i+1][pre]=dp[i][pre]+pre_comp[i][0];
    for (int j = 0; j <= k; ++j) {
      for (int miss = 1; (miss + j) <= k; ++miss) {
        dp[i + 1][miss + j] = min(dp[i + 1][miss + j], dp[i][j] + pre_comp[i][miss]);
      }
    }
  }
  cout<<dp[n][k]<<endl;

  return 0;
}
