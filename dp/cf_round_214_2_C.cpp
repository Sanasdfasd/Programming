//
// Created by Sandeep on 3/27/18.
//
#include <bits/stdc++.h>
using namespace std;
int dp[2][200022];
int main(){
int n,k;
  cin>>n>>k;
  int ar[n+5];
  int br[n+5];
  for (int i = 0; i <n ; ++i)
    cin>>ar[i];
  for (int j = 0; j < n; ++j)
    cin>>br[j];
  for(int i=0;i<2;i++){
    for (int j = 0; j <200022 ; ++j) {
      dp[i][j]=-1;
    }
  }
  dp[0][100010]=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<200022;j++){
      int cur_val= (i&1);
     if( dp[cur_val][j]>=0){
        dp[cur_val^1][j]= max(dp[cur_val^1][j], dp[i&1][j]);
        int val = ar[i]-k*(br[i]);
        dp[cur_val^1][j+(val)]=max(dp[cur_val^1][j+(val)],(dp[i&1][j]+ar[i]));
      }
    }
    for(int l=0;l<200022;l++)
      dp[i&1][l]=-1;
  }
  if( dp[n&1][100010]>0)
    cout<<dp[n&1][100010]<<endl;
  else
    cout<<-1<<endl;

  return 0;
}
