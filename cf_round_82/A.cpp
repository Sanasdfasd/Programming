//
// Created by Sandeep on 4/7/18.
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
  map<char,int> ar;
  ar['6']=0, ar['7']=1, ar['8']=2, ar['9']=3, ar['T']=4, ar['J']=5, ar['Q']=6,ar['K']=7,ar['A']=8;
  char s;
  cin>>s;
  char vl[2][2];
  cin>>vl[0][0]>>vl[0][1]>>vl[1][0]>>vl[1][1];
  if(vl[0][1]==s && vl[1][1]!=s)yes();
  if(vl[1][1]==s && vl[0][1]!=s)no();
  if(vl[0][1]!=vl[1][1]) no();
  else{
    if(ar[vl[0][0]]>ar[vl[1][0]]) yes();
    else no();
  }
  return 0;
}

