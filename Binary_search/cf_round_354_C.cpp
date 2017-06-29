#include <bits/stdc++.h>
using namespace std;


int n,k;
string s;
int as[100005], bs[100005];
int main()
{

cin>>n>>k>>s;
int i,j;
for(i=0;i<n;i++)
{
	long long int prev=0,prev1=0;
	  if(i!=0)
	  {
      prev=as[i-1];
      prev1=bs[i-1];
      }
	as[i]= prev+(s[i]=='a');
    bs[i]= prev1+(s[i]=='b');
}

int res=1;
for(i=0;i<n;i++)
{

  int low=i, hi=n-1, ans=1;
  while(low<=hi)
  {

     int mid=(low+hi)/2;
     long long int prev=0;
     if( i!=0)
      prev=as[i-1];
     if((as[mid]-prev)<=k)
     {
        low=mid+1;
        ans=mid-i+1;
     }
      else
      	hi=mid-1;
     }
     res=max(res, ans);

      {
          int low=i, hi=n-1, ans=1;
    while(low<=hi)
    {
     int mid=(low+hi)/2;
     long long int prev=0;
     if( i!=0)
      prev=bs[i-1];
     if((bs[mid]-prev)<=k)
     {
        low=mid+1;
        ans=mid-i+1;
     }
      else
      	hi=mid-1;
     }
   res=max(res, ans);
  }

}

cout<<res<<endl;
	return 0;
}