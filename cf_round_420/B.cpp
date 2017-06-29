#include <bits/stdc++.h>

using namespace std;
//int dp[10005];
int main()
{
long long int m,b;
cin>>m>>b;
if(m==1 && b==1)
{
  cout<<1<<endl;
  return 0;
}
long long int y,x;
long long int pt1=m*b;
long long int pt2=b;
long long int ans=0;
long long int ans2=0;
for(y=0;y<=b;y++)
{
     x=m*(b-y);

 // cout<<" the value of y is "<<x<<"  "<<y;
  //x=0;
  if(y==b)
  {
    long long int temp= (y*(y+1))/2;
    //cout<<"   "<<temp<<endl;
    ans= max(ans,temp);

  }
  else
  {
     
   long long int val1= (x*(x+1))/2;
   long long int val2=(y*(y+1))/2;
   long long int res= (val1*(y+1))+(val2*(x+1));
    // cout<<"   "<<res<<endl;
  ans= max(res,ans);
  }
  ans2=ans2+x+y;
}
cout<<ans2<<" "<<endl;
//ans= max(ans2,ans);
cout<<ans<<endl;
return 0;
}