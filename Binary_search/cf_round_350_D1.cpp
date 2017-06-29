#include <bits/stdc++.h>
using namespace std;
long long int n,k;
long long int as[100005];
long long int bs[100005];

long long int check_cond( long long int val)
{
   long long int i ,res=1;
   long long int pre_sum=0;
   long long int temp_k=k;
   for(i=0;i<n;i++)
   {
       long long int temp=((bs[i]- (as[i]*val)));
       if( (val+as[i]) >= (long long int ) 10000000009)
       	return -1;
       if(temp < (long long int)0)
       {
           if((-temp) > (temp_k))
             return -1;
           else
            temp_k=temp_k+temp;
       }
   }
 return res;
}

int main()
{
cin>>n>>k;
int i,j,a,b;
for(i=0;i<n;i++)
  cin>>as[i];
for(i=0;i<n;i++)
  cin>>bs[i];
long long int low=0, hi= 100000000000008;
long long int res=0;
while(low<=hi)
{

  long long int mid= (low+hi)/2;
 // cout<<" the value of low  "<<low<<"   "<<hi<<"   "<<mid<<"  "<<check_cond(mid)<<endl;
  if(check_cond(mid)< (long long int )0)
     hi=mid-1;
 else
 {
   low=mid+1;
   res=mid;
 }
}

cout<<res<<endl;

	return 0;
}