#include<bits/stdc++.h>
using namespace std;

const int modulo=1e9+7;
int main(){
   string inp;
   cin>>inp;
   int mod;
   cin>>mod;
   vector<vector<int>> dp(inp.size()+1,vector<int>(mod));
   
   for(int i=0;i<inp.size();i++){
   	for(int j=0;j<mod;j++)
   		dp[i][j]=0;
   }
   int eq_sum=0;
   eq_sum=(inp[0]-'0')%mod;
   for(int i=0;i<(inp[0]-'0');i++){
     dp[0][i%mod]++;
   }

   for(int i=1;i<inp.size();i++){
   	//count the ones that are less the given value
     for(int j=0;j<mod;j++){
      for(int k=0;k<=9;k++){
      	dp[i][(j+k)%mod]+=dp[i-1][j];
      	dp[i][(j+k)%mod]%=modulo;
      }
     }
    //Count the equal ones
     for(int k=0;k<(inp[i]-'0');k++){
     	dp[i][(eq_sum+k)%mod]++;
     	dp[i][(eq_sum+k)%mod]%=modulo;
     }
     eq_sum+=(inp[i]-'0')%mod;    
   }

   int eq_count=((eq_sum%mod) ==0);
   int val= (dp[inp.size()-1][0]-1+modulo)%modulo;
   cout<<(val+(eq_count)%(modulo))%modulo<<endl;
	return 0;	
}