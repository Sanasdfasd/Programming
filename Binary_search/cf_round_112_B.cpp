#include <bits/stdc++.h>
using namespace std;
long long int n,k;
long long int check( long long int mid)
{
   long long res=mid;
      	long long int temp=res/k;
      	long long int temp_k=k;
   while( temp>0)
   {
       res =res+temp;
       temp_k=temp_k*k;
       temp=mid/(temp_k);
   }

 return res;
}

int main()
{

cin>>n>>k;
long long int low= 0, hi=1000000009;
long long int res=1;
while(low<=hi)
{
 long long int mid= (low+hi)/2;
  long long int temp=check(mid);
  if(temp < n)
  	low=mid+1;
  else
  {
  	hi=mid-1;
  	res=mid;
  }
}

cout<<res<<endl;

	return 0;
}
