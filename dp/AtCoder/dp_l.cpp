#include <bits/stdc++.h>
using namespace std;
int main(){
   int n;
   cin>>n;
   vector<int> inp(n);
   vector<vector<long long int>>dp(n+1, std::vector<long long int>(n+1));
   long long int sum=0;
   std::vector<long long int > pre_sums(n+1);
   for(int i=0;i<n;i++){
   	cin>>inp[i];
    sum+=inp[i];
    pre_sums[i+1]=(long long int)inp[i]+pre_sums[i];
  }

  for(int j=0;j<n;j++){
  	dp[j][j]=inp[j];
   for(int i=j-1;i>=0;i--){
    dp[i][j]=max(inp[i]+(pre_sums[j+1]-pre_sums[i+1])-dp[i+1][j], inp[j]+(pre_sums[j]-pre_sums[i])-dp[i][j-1]);
   }
  }



cout<<(dp[0][n-1]-(sum-dp[0][n-1]))<<endl;

	return 0;
}