//
// Created by Sandeep on 3/16/18.
//
#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
long long int dp[1005][1005][2] = {};
int main() {
  string s;
  int red_cnt = 0;
  cin >> s >> red_cnt;
  int cnt[1005] = {};
  if( red_cnt==0){
    cout<<1<<endl;
    return 0;
  }
  for (int k = 2; k < 1005; ++k) {
    int temp = k;
    int ones_cnt = 0;
    while (temp > 0) {
      if (temp & 1) ones_cnt++;
      temp = temp >> 1;
    }
    cnt[k] = cnt[ones_cnt] + 1;
  }

  dp[0][0][0] = 1;
  long long int tcnt = 0;
  int total_ones=0;
  for (int i = 0; i <s.size(); ++i) {
    for (int j = 0; j <= i; ++j) {
      for (int k = 0; k < 2; ++k) {
        dp[i+1][j][k]+=dp[i][j][k];
        dp[i+1][j+1][k]+=dp[i][j][k];
        dp[i+1][j+1][k]%=mod;
      }
    }
    if( s[i]=='0'){
      if( dp[i+1][total_ones+1][0]){
        dp[i+1][total_ones+1][0]-=1;
        dp[i+1][total_ones+1][1]+=1;
        dp[i+1][total_ones+1][1]%=(mod);
      }
    }
    if(s[i]=='1') total_ones++;
  }
  for (int l = 1; l < 1005; ++l) {
    if ((cnt[l] + 1) == red_cnt) {
      tcnt += dp[s.size()][l][0];
      tcnt = tcnt % mod;
    }
  }
  if( red_cnt==1)
    cout<<tcnt-1<<endl;
  else
    cout << tcnt << endl;

  return 0;
}