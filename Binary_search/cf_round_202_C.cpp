#include <bits/stdc++.h>

using namespace std;
int n;
int arr[400005];
long long int check(  long long int games)
{
 int i;
 long long int pre_sum=0;
 for(i=0;i<n;i++)
 {
   pre_sum=pre_sum+ (games-arr[i]);
 }
return pre_sum;
}
int main()
{

cin>>n;
int i,j,a=0,b;
long long int pre_sum=0;
for(i=0;i<n;i++)
{

	cin>>arr[i];
	  pre_sum=pre_sum+arr[i];
}

sort(arr, arr+n);
reverse(arr, arr+n);
long long int  low=arr[0], hi= 100000000009;
long long int ans=0;
while(low<=hi)
{

  long long int mid= (low+hi)/2;
   if( (check(mid))< mid)
   {
      low=mid+1;
   }
   else
   {
      hi=mid-1;
      ans=mid;
   }
}

cout<<ans<<endl;
return 0;
}	