//
// Created by Sandeep on 10/27/2018.
//
#include <bits/stdc++.h>
using namespace std;

bool arithmeticBoggle(int magic_number, list<int> numbers) {
  int dp[2005][2] = {};
  dp[1001][0]=1;
  int cur_it=0;
  for (auto it:numbers) {
    cout<<" the it is "<<it<<endl;
    cur_it=cur_it^1;
    for(int i=2004;i>=0;i--){
      if(dp[i][cur_it^1]==1){
        cout<<" the true at the value is "<<i<<" "<<cur_it<<endl;
        if((i+it)<2005 ) {
          dp[i+it][cur_it]=dp[i][cur_it^1];
          cout<<" the value is "<<dp[i+it][cur_it]<<endl;
        }
        if((i-it)>=0){
          dp[i-it][cur_it]=dp[i][cur_it^1];
          cout<<" the value is "<<dp[i-it][cur_it]<<endl;
        }
      }
    }
    for(int i=0;i<2005;i++) dp[i][cur_it^1]=0;
  }
  return (dp[magic_number+1001][numbers.size()%2]==1);
}
int main(){
 vector<int>nums;
  list<int> numbers;
  numbers.push_back(1);
  cout<<arithmeticBoggle(1,numbers);

  return 0;
}

