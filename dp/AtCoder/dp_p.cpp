#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
long long int dp[100005][2];

long long int mod=1e9+7;

long long int solve( int root, int prev, int col){
   //coloring the root with black color
   if(dp[root][col]!=-1)
   	return dp[root][col];
   dp[root][col]=1;
   if( col==0){
     for(int v:adj[root]){
     	if(v!=prev){
          solve(v,root, 1);
          dp[root][col]*=dp[v][1];
          dp[root][col]%=mod;
     	}
     }  
   } 
   else{
     
     for(int v:adj[root]){
     	if(v!=prev){
     	  solve(v,root,0);
     	  solve(v,root, 1);	
          dp[root][col]*=((dp[v][0]+dp[v][1])%mod);
          dp[root][col]%=mod;
     	}
     } 
   }
   return dp[root][col]%mod;
  
}


int main(){

int n;
cin>>n;
int u,v;
for(int i=0;i<n-1;i++){
	cin>>u;
	cin>>v;
	adj[u].push_back(v);
	adj[v].push_back(u);
}
for(int i=1;i<=n;i++){
   for(int j=0;j<2;j++)
   	dp[i][j]=-1;
}

cout<<((solve(1,-1,0)+ solve(1,-1,1))%mod)<<endl;
}