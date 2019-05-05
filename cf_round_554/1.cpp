//
// Created by Sandeep on 4/27/2019.
//

#include <bits/stdc++.h>
using namespace std;

int main(){

  int n,m,a;
  cin>>n>>m;
  int ev1=0, od1=0, ev2=0, od2=0;
  for(int i=0;i<n;i++) {
    cin>>a;
    ev1+=(a%2==0);
    od1+=(a%2==1);
  }
  for(int i=0;i<m;i++) {
    cin>>a;
    ev2+=(a%2==0);
    od2+=(a%2==1);
  }

  cout<<min(ev1,od2)+min(ev2,od1)<<endl;

  return  0;
}