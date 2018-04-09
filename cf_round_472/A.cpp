//
// Created by Sandeep on 3/24/18.
//
#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
 cin>>n>>s;
  int two_con=0;
  for(int i=1;i< s.size();i++) {
    if (s[i] == s[i - 1] && s[i] != '?') {
      cout << "No" << endl;
      return 0;
    } else if (s[i] == s[i - 1] && s[i] == '?')
      two_con++;
  }
  if(s[0]=='?' || s[s.size()-1]=='?' ) {
    cout << "Yes" << endl;
    return 0;
  }
  if( two_con==0){
    for (int i = 1; i <s.size() ; ++i) {
      if( s[i]=='?'){
        if(s[i-1]==s[i+1]){
          cout<<"Yes"<<endl;
          return 0;
        }
      }
    }
  }
  if(two_con>0)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
  return 0;
}
