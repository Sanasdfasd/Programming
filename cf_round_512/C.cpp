//
// Created by Sandeep on 12/22/2018.
//
#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  long long int ans=0;
  long long int mod=1e9+7;
  int prev_index=-1;
  bool cond=false;
  for(int i=0;i<s.size();i++){

    if(!(s[i]=='a' || s[i]=='b')) continue;
    if(s[i]=='b')cond=true;
    if(s[i]=='a'){
     if(prev_index==-1) {
       ans = 1;
       prev_index=i;
     }
      else{
       if(cond) {
         ans += (ans * 2LL)+1LL;
         ans = ans % (mod);
       } else {
         ans += (ans * 1LL)+1LL;
         ans = ans % (mod);
       }
     }
      cond=false;
    }
  }
  cout<<ans<<endl;
  return 0;
}

