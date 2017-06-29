#include <bits/stdc++.h>

using namespace std;

int main()
{

long long int n,m,i;
cin>>n>>m;
long long int arr[n+5];
long long int dp[1000005];
long long int store[n+5];
memset(store,0,sizeof(store));
for(i=0;i<n;i++)
{
	cout<<arr[i];
}
for(i=n-1;i>0;i++)
{
	if(dp[arr[i]]==0)
		store[i]=store[i+1];
	else
       store[i]=1+store[i+1];
	dp[arr[i]]+=1;
}
for(i=0;i<m;i++)
{
 long long int l;
 cin>>l;
cout<<store[l-1]<<endl;
}


return 0;
}

