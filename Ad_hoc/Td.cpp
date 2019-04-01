//
// Created by Sandeep on 9/19/2018.
//
#include <bits/stdc++.h>
using namespace std;

int main(){

  string s;
  cin>>s;
  int dp[3]={};
  dp[0]=s[0]=='Q';
  for(int i=1;i<s.size();i++){
    if( s[i]!='Q' && s[i]!='A') continue;
    if( s[i]=='Q'){
      dp[2]=dp[2]+dp[1];
      dp[0]++;
    }
    else
      dp[1]=dp[1]+dp[0];
  }

  cout<<dp[2]<<endl;

  return 0;
}
