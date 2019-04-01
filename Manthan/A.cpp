//
// Created by Sandeep on 9/4/2018.
//
#include <bits/stdc++.h>
using namespace std;

bool arithmeticBoggle(int magic_number, list<int> numbers) {

  if(numbers.size()==0)
    return (magic_number==0);

  bool dp[2005][2];
  for(int i=0;i<2005;i++)
    for(int j=0;j<2;j++)
      dp[i][j]=false;

  dp[1000+numbers.front()][0]=true;
  dp[1000-numbers.front()][0]=true;

  int cur_itr=0;

  for (std::list<int>::iterator it=numbers.begin(); it != numbers.end(); ++it){
    if(cur_itr==0) {cur_itr++;continue;}
    int cur_bit= cur_itr&1;
    cur_itr++;
    for(int i=0;i<2005;i++) { dp[i][cur_bit]=false;}
    for(int i=0;i<2005;i++){
      if(dp[i][cur_bit^1]){
        cout<<" the true value is "<<i<<endl;
        if((i-(*it))>=0)
          dp[i-(*it)][cur_bit]=true;
        if((i+(*it))<2005)
          dp[i+(*it)][cur_bit]=true;
      }
    }
  }
  int last_bit= (numbers.size()-1)&1;
  return dp[1000+magic_number][last_bit];
}

int main(){

  int my_ints[4]={1,2,3,4};
  list<int> vls;
  vls.assign(my_ints, my_ints+4);

  cout<<(bool)arithmeticBoggle(2,vls)<<endl;
  return 0;
}
