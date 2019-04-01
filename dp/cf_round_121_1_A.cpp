//
// Created by Sandeep on 8/27/2018.
//
#include <bits/stdc++.h>
using namespace std;
int dp[26][26]={};
int fst[5*100001];
int lst[5*100001];
int lgt[5*100001];
string st;

int main(){
  int n;
  cin>>n;

  for (int i = 0; i <n ; ++i) {
    cin >> st;
    fst[i]=st[0]-'a';
    lgt[i]=(int)st.size();
    lst[i]=st[lgt[i]-1]-'a';
  }


  for (int i = 0; i <n ; ++i) {
    int tr=0;
    if(dp[fst[i]][lst[i]]==0) {
      dp[fst[i]][lst[i]] = lgt[i];
      tr=1;
    }
    for (int start = 0; start < 26; ++start) {
        if ( dp[start][fst[i]]>0) {
          dp[start][lst[i]] =
              max(dp[start][lst[i]], dp[start][fst[i]] + lgt[i]);
        }
      }
    //Starting and ending Characters are the same
     if(fst[i]==lst[i] && tr==1)
       dp[fst[i]][lst[i]]-=lgt[i];
  }
  int ans=0;
  for (int j = 0; j <26 ; ++j) {
    ans = max(ans, dp[j][j]);
  }

  cout<<ans<<endl;
  return 0;
}
