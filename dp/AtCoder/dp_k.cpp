#include <bits/stdc++.h>
using namespace std;

//dp[i] true if player can win 
int main(){
	int n,k;
cin>>n>>k;
vector<int> inp(n);
for(int i=0;i<n;i++){
	cin>>inp[i];
}
vector<bool> dp(k+1);

for(int i=0;i<=k;i++){
	for(int v:inp){
		if((i-v)>=0 && !dp[i-v]){
			dp[i]=true;
		}
	}
}

if(dp[k])cout<<"First"<<endl;
else
cout<<"Second"<<endl;

}