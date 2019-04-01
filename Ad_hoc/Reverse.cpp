//
// Created by Sandeep on 11/3/2018.
//
#include <bits/stdc++.h>
using namespace std;
string s;
string reverse(int index){
  if(index==s.size())
    return"";
  return reverse(index+1)+s[index];
}
int main(){
  s="Hello World";
   for(int i=0;i<s.size()/2;i++){
     char v=s[i];
     s[i]=s[s.size()-1-i];
     s[s.size()-1-i]=v;
   }
  cout<<s<<endl;
  return 0;
}
