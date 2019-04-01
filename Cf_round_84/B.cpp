//
// Created by Sandeep on 4/8/18.
//
#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  char ar[]={'a','b','c','d'};
  cin>>n;
  for(int i=0;i<n;i++)
    cout<<ar[i%4];
  cout<<endl;
  return 0;
}

