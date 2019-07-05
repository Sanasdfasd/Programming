#include <bits/stdc++.h>
using namespace std;
vector<int>a,b,c;
int n;
int dp[3005][2];

 int solve( int pos, int seen){

if( pos==n-1){
	if(seen==0)
		return a[pos];
	else
		return b[pos];
}
if(dp[pos][seen]!=-1)
	return dp[pos][seen];

int a1=0,a2=0,a3=0,a4=0;
if(seen==1){
  a1=solve(pos+1, 0)+c[pos];
   a2=solve(pos+1,1)+b[pos];
}
else{
  a3=solve(pos+1,0)+b[pos];
    a4=solve(pos+1,1)+a[pos];
}
dp[pos][seen]=max(dp[pos][seen], max(max(a1,a2), max(a3,a4)));

 return dp[pos][seen];
}

int main()
{

	cin>>n;
	int t;
	for(int i=0;i<n;i++){
		cin>>t;
		a.push_back(t);
	}
	
	for(int i=0;i<n;i++){
		cin>>t;
		b.push_back(t);
	}

	for(int i=0;i<n;i++){
		cin>>t;
		c.push_back(t);
	}
      for(int i=0;i<n+1;i++){
      	for(int j=0;j<2;j++)
      		dp[i][j]=-1;
      }
      

      cout<<solve(0,0)<<endl;

	return 0;

}