#include <bits/stdc++.h>
using namespace std;


int n,k;
//string s;
int as[300005], bs[300005];
int s[300005];
int main()
{

cin>>n>>k;
int i,j;
for(i=0;i<n;i++)
 cin>>s[i];
for(i=0;i<n;i++)
{
	long long int prev=0,prev1=0;
	  if(i!=0)
    {
      prev=as[i-1];
      prev1=bs[i-1];
    }
	as[i]= prev+(s[i]==1);
    bs[i]= prev1+(s[i]==0);
}
//cout<<endl;
int res=0;
int indx=0;
for(i=0;i<n;i++)
{
  int low=i, hi=n-1, ans=0,vals=0;
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
        vals=mid;
     }
      else
      	hi=mid-1;
     }
     if(ans>=res)
     {
        indx=vals;
     }
     res=max(res, ans);    
}
int tt=0;
int count=0;
for(tt=indx;tt>=0;tt--)
{
    if(s[tt]==0 && (count<k))
    {
      s[tt]=1;
      count++;
    }
    if(count>=k)
    {
      break;
    }
}

cout<<res<<endl;
for(i=0;i<n;i++)
  cout<<s[i]<<" ";
cout<<endl;
return 0;
}