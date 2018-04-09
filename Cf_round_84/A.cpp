//
// Created by Sandeep on 4/8/18.
//
#include <bits/stdc++.h>
using namespace std;
void yes(){
  cout<<"YES"<<endl;
  exit(0);
}
void no(){
  cout<<"NO"<<endl;
  exit(0);
}

int main(){
  string s;
  cin>>s;
  int cnt=0;
  for (int i = 0; i <s.size(); ++i) {
    if(s[i]=='4'|| s[i]=='7')cnt++;
  }
  if(cnt==4 || cnt==7)yes();
  else no();
  return 0;
}
