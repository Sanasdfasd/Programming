#include <bits/stdc++.h>
using namespace std;
long long int n,d;
long long int arr[1000005];

int main()
{
cin>>n>>d;
int i,j,a,b;
for(i=0;i<n;i++)
	cin>>arr[i];
long long int final_ans=0; 
for(i=2;i<n;i++)
{
 long long int low=0, hi= i-1;
 long long int ans=0;
  while(low<=hi)
  {
     long long int mid= (low+hi)/2;
     if( abs(arr[i]-arr[mid])>d)
     	low=mid+1;
      else
      {
         hi=mid-1;
         ans=i-mid+1;
      }
  }
 if((ans)>=3)
 {
   long long int temp= ((ans-2)*(ans-1))/((long long int)2);
     final_ans= final_ans+temp;
 }

}
cout<<final_ans<<endl;
	return 0;
}
