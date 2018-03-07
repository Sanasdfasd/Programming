//
// Created by Avula, Sandeep on 3/4/18.
//
#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100010];
int dp[100010]={};
void dfs(int v, int ht=0)
{
    dp[ht]++;
    for(int ver:adj[v]) dfs(ver,ht+1);
}
int main(){
int n;
    cin>>n;
    for (int i = 1; i <n ; ++i) {
        int t;
        cin >> t;
        adj[t-1].push_back(i);
    }
    int ans=0;
    dfs(0);
    for(int i=0;i<=n;i++){
        if((dp[i]%2)!=0) ans++;
    }
    cout<<ans<<endl;

    return 0;

}
