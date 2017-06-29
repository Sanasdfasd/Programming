#include <bits/stdc++.h>

using namespace std;
int dp[10005];
int main()
{

int n;
cin>>n;
int as[n+5];
int bs[n+5];
int cs[n+5];
int i,j,k;
for(i=0;i<n;i++)
cin>>as[i];
for(j=0;j<n;j++)
cin>>bs[j];
for(i=0;i<=10005;i++)
  dp[i]=0;

for(i=0;i<n;i++)
{ 
//  cout<<as[i]<<"  "<<bs[i]<<endl;
   if(as[i]==bs[i])
   {
       dp[as[i]]=dp[as[i]]+1;
   }
}
int a1=0,b1=0,count=0; 
for(i=1;i<=n;i++)
{//cout<<" the value of i is "<<i<<"  "<<dp[i]<<endl;
  if(dp[i]==0)
  {
    if(dp[i]==0 && count==0)
    {
      a1=i;
    }
     if(dp[i]==0 && count==1)
      b1=i;
   // if(dp[i]==0)
      count++;
  }
}
//cout<<a1<<   "   "<<b1<<endl;
count=0;
for(i=0;i<n;i++)
{
  if(as[i]!=bs[i] && count==0)
  {
    cs[i]=a1;
  }
  else if(as[i]!=bs[i] && count==1)
  {
    cs[i]=b1;
  }
  else
  {
   cs[i]=as[i];
  }
  if(as[i]!=bs[i])
    count++;
}

int count1=0,count2=0;
count=0;
for(i=0;i<n;i++)
{
  if(as[i]==cs[i])
    count1++;
   if(bs[i]==cs[i])
    count2++;
}
if(count1==n-1 && count2==n-1)
{
   for(i=0;i<n;i++)
    cout<<cs[i]<<" ";

}
else
{ count=0;
     for(i=0;i<n;i++)
    {
      if(as[i]!=bs[i] && count==0)
      {
         cout<<b1<<" ";
      }
        else if(as[i]!=bs[i] && count==1)
       {
        cout<<a1<<" ";
       }   
        else
        {
          cout<<as[i]<<" ";
        }
        if(as[i]!=bs[i])
          count++;

    }


}


cout<<endl;


return 0;
}