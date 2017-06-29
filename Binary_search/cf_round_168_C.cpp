#include <bits/stdc++.h>
using namespace std;
set < long long int> vs;
int main()
{
long long int n,k;
cin>>n>>k;
long long int arr[n+5];
int i,j;
for(i=0;i<n;i++)
{	cin>>arr[i];
  vs.insert(arr[i]);
}
if(k==1)
{
 cout<<n<<endl;
  return 0;
}
sort(arr, arr+n);
for(i=0;i<n;i++)
{
 if(vs.count(arr[i])==1 && vs.count((long long int)arr[i]*k)==1)
    vs.erase(arr[i]*k);
}
cout<<vs.size()<<endl;
	return 0;
}