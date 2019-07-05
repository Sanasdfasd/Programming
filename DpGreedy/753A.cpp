#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005]={};
int dp1[1005][1005]={};
int main(){

   int n;
   cin>>n;
   for(int i=1;i<=n;i++){
    dp[i][i]=1;
    dp1[i][i]=1;
   	for(int j=1;j<i;j++){
   		if(dp1[i-j][j-1]>0)
   		dp[i][j]=dp1[i-j][j-1]+1;
   	}
     for(int j=1;j<=n;j++){
     	dp1[i][j]=max(dp[i][j], dp1[i][j-1]);
     }
   }

  int iter=n;
  vector<int> ans; 
  while(iter!=0){
   int mx=0;
   int indx=-1;
   for(int i=1;i<=iter;i++){
     if(dp[iter][i]>mx){
       indx=i;
       mx=dp[iter][i];
     }
   }
   ans.push_back(indx);
   iter=iter-indx;
   }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
    	cout<<ans[i]<<" ";
	return 0;
}