//
// Created by Sandeep on 4/8/18.
//
#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
  cin>>n;
  int dp[n+5];
  memset(dp,-1, sizeof(dp));
  dp[0]=0;
  dp[7]=7;
  dp[4]=4;
  dp[8]=4;
  for (int i = 11; i <=n; ++i) {
    int min1=INT_MAX;
    int min2=INT_MAX;
    if(dp[i-7]!=-1)
    min1= (dp[(i-7)-dp[i-7]]*10 + dp[i-7])*10+7;
    if(dp[i-4]!=-1)
    min2=(dp[(i-4)-dp[i-4]]*10 + dp[i-4])*10+4;
    if(min1==INT_MAX && min2==INT_MAX)
      dp[i]=-1;
    else if(min1==INT_MAX)
      dp[i]=4;
    else if(min2==INT_MAX)
      dp[i]=7;
    else {
      if (min1 <= min2)
        dp[i] = 7;
      else dp[i] = 4;
    }
  }
  if(dp[n]==-1){
    cout<<-1<<endl;
    return 0;
  }
  vector<int> ans;
  while(dp[n]!=0){
    ans.push_back(dp[n]);
    n=n-dp[n];
  }
  reverse(ans.begin(),ans.end());
  for (int i = 0; i <ans.size(); ++i)
    cout<<ans[i];
  cout<<endl;

  return 0;
}

