//
// Created by Sandeep on 3/23/2019.
//
#include <bits/stdc++.h>
using namespace std;

int main(){
 int n;
  cin>>n;
  string s;
  cin>>s;
  int ar[s.size()+2];
  ar[s.size()]=0;
  for(int i=n-1;i>=0;i--){
    ar[i]=ar[i+1]+((s[i]-'0')%2==0);
  }
  long long int ans=0;
  for(int i=0;i<n;i++) {
    ans += ar[i];
  }
    cout<<ans<<endl;
  return 0;
}
