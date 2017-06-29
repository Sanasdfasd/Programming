#include <bits/stdc++.h>
using namespace std;

int main()
{
long long int n;
cin>>n;
long long int i,j;

for(i=1;i<1000005;i++)
{
   long long int low=1, hi=100005;
   while(low<=hi)
   {
     long long int mid= (low+hi)/2;
     long long int res= (i*(i+1)/(long long int )2) +  (mid*(mid+1)/(long long int )2);
     if(res==n)
     {
     //	cout<<i<<"  "<<mid<<endl;
     	cout<<"YES"<<endl;
     	return 0;
     }
     else
     {
     	if( res > n)
     		hi=mid-1;
     	else
     		low=mid+1;
     }
   }
}


cout<<"NO"<<endl;


	return 0;
}

