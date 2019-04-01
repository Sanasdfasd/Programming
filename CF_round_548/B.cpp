//
// Created by Sandeep on 3/23/2019.
//
#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> inp(n+5);
  for(int i=0;i<n;i++) {
    cin>>inp[i];
  }
  long long int ans=inp[n-1];
  //Iterate from the back
  int next=inp[n-1];
  for(int i=n-2;i>=0;i--){
    if(next==0){
      break;
    }
    if(inp[i]>=next){
     next=next-1;
    }
    else{
      next=inp[i];
    }
    ans+=next;
  }

cout<<ans<<endl;
  return 0;
}
