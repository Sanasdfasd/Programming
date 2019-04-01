//
// Created by Sandeep on 4/8/18.
//
#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
  cin>>n;
  int x=-1;
  for(int i=0;i<=n;i++){
    if((n-(4*i))>=0) {
      if (((n - (4 * i)) % 7) == 0) {
        x = i;
        break;
      }
    }
    else break;
  }
  if((x==-1)) cout<<x<<endl;
  else{
    for(int i=0;i<x;i++)cout<<4;
    int y= (n-(4*x))/7;
    for (int j = 0; j <y ; ++j) cout<<7;
  }

  return 0;
}
