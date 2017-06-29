#include <bits/stdc++.h>
using namespace std;
int main()
{
int n,m;
cin>>n>>m;
int as[n+5],bs[m+5];
int a,b,i,j;
for(i=0;i<n;i++)
	cin>>as[i];
for(i=0;i<m;i++)
	cin>>bs[i];

sort(as, as+n);
for(i=0;i<m;i++)
{
 int res=-1;
 int low=0, hi=n-1;
 while(low<=hi)
 {
   int mid= (low+hi)/2;
   if(as[mid]<= bs[i])
   {
   	res=mid;
   	low=mid+1;
   }
   else
    hi=mid-1; 
 }
 cout<<res+1<<" ";
}
cout<<endl;
	return 0;
}