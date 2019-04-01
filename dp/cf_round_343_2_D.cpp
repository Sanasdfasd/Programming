//
// Created by Sandeep on 8/4/2018.
//
#include <bits/stdc++.h>
using namespace std;
long long int mod =1000000007;
long long int dpl[2005][2005]={};
int main(){
  //cout<<" executing this script"<<endl;
  int n,m;
  cin>>n>>m;
  string s;
  cin>>s;
  int mx_pre=0;
  int lbr[n+5];
  lbr[0]=0;
  for (int i = 0; i <s.size(); ++i) {
    lbr[i+1]=lbr[i]+(s[i]=='(');
    if((i+1- lbr[i+1])>=lbr[i+1])
      mx_pre=max(mx_pre,(i+1- lbr[i+1]));
  }
  //Compute possible ways for the left side of given string
  for (int i = 0; i <=(n-m); ++i) {
    for (int j = 0; j <= i; ++j) {
      if ((i - j) > j) continue;
      if ((j - (i - j)) < mx_pre)continue;
      if (i == 0 && j == 0) {
        dpl[i][j] = 1;
        continue;
      }
      dpl[i][j] += dpl[i - 1][j-1];
      dpl[i][j] = dpl[i][j] % mod;
      dpl[i][j] += dpl[i - 1][j +1];
      dpl[i][j] = dpl[i][j] % mod;
    }
  }
  for (int i = 0; i <=(n-m); ++i) {
    cout<<" the value of i is "<<i<<endl;
    for (int j = 0; j <= i; ++j) {
      cout<<" the value of j is "<<j<<" "<<dpl[i][j]<<endl;
    }
  }


  //Compute possible ways for the right side of given string



  return 0;
}
