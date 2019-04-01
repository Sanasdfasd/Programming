//
// Created by Sandeep on 12/15/2017.
//

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>por[n];
    vector <int> sum[n];
    vector<int> dp[n];
    int ans[2][m+1];
    int i,j,k;
    for(i=0;i<n;i++){
        int val;
        cin>>val;
        for(j=0;j<val;j++){
            int v;
            cin>>v;
            por[i].push_back(v);
            if(j==0)
                sum[i].push_back(v);
            else
                sum[i].push_back(v+sum[i][j-1]);
        }
    }
    for(i=0;i<n;i++) {
        for (j = 0; j < por[i].size(); j++) {
            dp[i].push_back(0);
            for (k = 0; k <=j;k++){
              dp[i][j] =max( dp[i][j], sum[i][k]+sum[i][por[i].size()-1]- sum[i][por[i].size()-1-j+k] );
            }
        }
    }
    int cur=0, old=1;
    for(i=0;i<=m;i++)
        ans[cur][i]=0;
    for(i=0;i<n;i++){
        int cur=cur^1,old=old^1;
        for(j=0;j<m;j++) ans[cur][j]=ans[old][j];
        for(j=0;j<dp[i].size();j++){
            for(k=0;k<m;k++){
                  ans[cur][k]= max( ans[cur][k], ans)
            }
        }
    }

    return 0;
}