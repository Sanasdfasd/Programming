#include <bits/stdc++.h>

using namespace std;
int dp[1000005];

int main()
{

long long int n,m,i;
cin>>n>>m;
int arr[n+5];
 int store[n+5];
//cout<<" failing here okkk"<<endl;
memset(store,0,sizeof(store));
memset(dp,0,sizeof(dp));
for(i=0;i<n;i++)
	cin>>arr[i];
for(i=n-1;i>=0;i--)
{
	//cout<<" the value incremented is "<<arr[i]<<endl;
	dp[arr[i]]+=1;
	if(dp[arr[i]]==1)
		store[i]=1+store[i+1];
	else
       store[i]=store[i+1];
	
}

for(i=0;i<m;i++)
{
 int l;
 cin>>l;
cout<<store[l-1]<<endl;
}


return 0;
}

