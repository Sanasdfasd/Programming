#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	vector<int>abs(n);
	for(int i=0;i<n;i++) cin>>abs[i];
    
    vector< long long int> dp(n);
    vector<int>a_Index(n);

    long long ans=0,b_Index,a_Ind; // Answer at a given point stores the max 2k sequences 

	long long int  sum=0;

	for(int i=0;i<k;i++) sum+=abs[i];

    dp[k-1]=sum;
   
    a_Index[k-1]=k-1;
	
	for(int i=k;i<n;i++){
     sum-=abs[i-k];
     sum+=abs[i];

     if(sum> dp[i-1]){
       dp[i]=sum;
       a_Index[i]=i;
     }
     else{
     	dp[i]=dp[i-1];
     	a_Index[i]=a_Index[i-1];
     }
    if((sum+dp[i-k])>ans){
    	ans=sum+dp[i-k];
    	b_Index=i;
    	a_Ind=a_Index[i-k];
    } 
	}	
    
    cout<<a_Ind-k+2<<" "<<b_Index-k+2<<endl;


	return 0;	
}