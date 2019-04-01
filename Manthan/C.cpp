//
// Created by Sandeep on 9/4/2018.
//
#include <bits/stdc++.h>
using namespace std;
int main(){
   int n;
  cin>>n;
    string a,b;
    cin>>a>>b;
  int dp[a.size()];
  int l[2];
  l[0]=-1, l[1]=-1;
  for (int i = 0; i <a.size() ; ++i) {
    if( a[i]==b[i]){ if(i==0) dp[i]=0; else dp[i]=dp[i-1];}
    else{
      if( a[i]=='0') l[0]=i;
      else l[1]=i;
      int tt=0;
      if(i!=0)
        tt=dp[i-1];
      dp[i]=tt+(a[i]!=b[i]);
      //swap now
      int pt=(a[i]-'0')^1;
      if(l[pt]!=-1) {
        if( l[pt]!=0)
        dp[i] = min(dp[i],dp[i-1]-(dp[l[pt]]-dp[l[pt]-1]) + i-l[pt]);
        else
          dp[i] = min(dp[i],dp[i-1]-1+ i-l[pt]);
      }
    }
    }
  cout<<dp[a.size()-1]<<endl;
  return 0;
}
