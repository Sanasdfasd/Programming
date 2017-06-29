#include <bits/stdc++.h>
using namespace std;

int main()
{
long long int i,j;
long long int n,m,k;
cin>>n>>m>>k;
long long int arr[(n*m)+5];
long long int top=0;
for(i=0;i<n;i++)
{
	for(j=0;j<m;j++)
	{
       arr[top]=((i+1)*(j+1));
       top++;
	}
}
sort(arr, arr+top);
cout<<arr[k-1]<<endl;



	return 0;
}