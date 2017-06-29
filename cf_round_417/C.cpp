#include <bits/stdc++.h>

using namespace std;

int main()
{
long long int n,s;
cin>>n>>s;
long long int arr[n+5];
long long int i,j;
long long int pre_sums[n+5];
cout<<" I am failing here okkk"<<endl;
for(i=0;i<n;i++)
{
  cin>>arr[i];
  if(i!=0)
  pre_sums[i]=pre_sums[i-1]+arr[i];
else
   pre_sums[i]=arr[i];
}
for(i=0;i<n;i++)
   cout<<pre_sums[i]<<"  ";
cout<<endl;

long long int mx=0,mi= 100000000000000000;
sort(arr,arr+n);
for(i=n-1;i>=0;i--)
{
 long long int low=0, hi= i, res=0, res1=0;
while(low<=hi)
{
   long long int mid= (low+hi)/2;
   cout<<" the low value is "<<low<<"  "<<hi<< "  "<<mid<<endl;
   long long int temp=mid-low+1;
   temp=(temp*(temp+1)/(long long int) 2);
   long long int val= pre_sums[mid]+ ((i+1)* temp); 
   if(val<=s)
   {
      res=mid-low+1;
      low=mid+1;
      res1=val;
   }
   else
    hi=mid-1;
}

cout<<" the final result values are "<<res<<"  "<<res1<<endl;
cout<<" the value of mx "<<mx<<"  "<<mi<<"  "<<endl;
if(res >= mx)
{
    if(res1< mi)
    {
       mx=res;
       mi=res1;
    }
}

}
if(mx==0)
 mi=0;
cout<<mx<<" "<<mi<<endl;


return 0;
}