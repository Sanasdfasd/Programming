#include <bits/stdc++.h>
using namespace std;

int main()
{
long long int n,m;
cin>>n>>m;
long long int arr[n+5][m+5];
long long int store[n+5][m+5];
long long int dp[n+5];
long long int k;
int i,j;
for(i=0;i<n;i++)
{
	long long int mx=1;
	for(j=0;j<m;j++)
	{
	    	cin>>arr[i][j];
	    	 if(arr[i-1][j]<=arr[i][j] && i!=0)
	    	 {
	    	 	store[i][j]=store[i-1][j]+1;
	    	 	mx=max( mx, store[i][j]);
	    	 }
	    	 else
	    	 	store[i][j]=1;
	}
dp[i]=mx;
}
cin>>k;

for(i=0;i<k;i++)
{
 int l,r;
 cin>>l>>r;
 if(dp[r-1] > (r-l))
 	cout<<"Yes"<<endl;
  else
  	cout<<"No"<<endl;

}

	return 0;

}
