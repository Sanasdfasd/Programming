//
// Created by Sandeep on 4/7/18.
//
#include <bits/stdc++.h>
using namespace std;
int ar[105][4]={};
int main(){
  int n;
  cin>>n;
  for (int i = 0; i <n ; ++i)
    cin>>ar[i][0]>>ar[i][1]>>ar[i][2]>>ar[i][3];
  int mi=10000;
  int ans=0;
  for (int i = 0; i <n ; ++i) {
    bool outdated=false;
    for (int j = 0; j <n ; ++j) {
      if(j!=i) {
        if (ar[i][0] < ar[j][0] && ar[i][1] < ar[j][1] && ar[i][2] < ar[j][2] && ar[i][3] < ar[j][3]){
          outdated=true;
          break;
        }
      }
    }
    if(!outdated){
      if(mi>ar[i][3]){
        mi=ar[i][3];
        ans=i+1;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}