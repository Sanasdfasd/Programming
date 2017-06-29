#include <iostream>
#include <memory.h>
#include <fstream>
#include <cstring>
#include <map>
#include <dirent.h>
#include <utility>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <functional>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <string.h>
#include <string>
using namespace std;

int dp[7006][3];
int n, l,p;
int set1[7006][2];
int lp[7006][2];
int mark[7006][2];
int rec(int pos, int ply  )
{
  cout<<"the pos: "<<pos<<" "<<ply<<endl;
if(dp[pos][ply]!=-1)
{
  return dp[pos][ply];
}
else
{
  int i,j;
  int val=l;
  if(ply==1)
      val=p;
      int tt=0;
      int mx=-1;
      int t_foun=-1;
      if(lp[n-pos][ply]==1)
      {
          tt=1;
      }
      else
    {
     for(i=0;i<val;i++)
     {
        int t=2;
        if(mark[(set1[i][ply]+pos)%n][ply]==0)
        {
          mark[(set1[i][ply]+pos)%n][ply]=1;
           t=rec((set1[i][ply]+pos)%n, (ply+1)%2);
         }      
          mark[(set1[i][ply]+pos)%n][ply]=0;
           if(t<mx)
            mx=t;
        
       }
     }
     if(tt==1)
     {
      dp[pos][ply]=1; 
      return 0;
     }
     else
     {
       // cout<<"the max is "<<mx<<endl;
         dp[pos][ply]=mx;
         if(mx==0 || mx==1)
           return((mx+1)%2);
         else            
          return mx;
     }
}

}


int main()
{
 memset(dp,-1,sizeof(dp));
 memset(set1,0,sizeof(set1));
 memset(lp,0,sizeof(lp));
 cin>>n;
 cin>>l;
 int i,j;
 for(i=0;i<l;i++)
 {
  cin>>set1[i][0];
  lp[set1[i][0]][0]=1;
}
cin>>p;
 for(i=0;i<p;i++)
 {
  cin>>set1[i][1];
   lp[set1[i][1]][1]=1;
}
 memset(mark,0,sizeof(mark));
 for(i=1;i<n;i++)
  {cout<<"iam here it is "<<i<<endl;
   rec(i,0);
 }
for(i=1;i<n;i++)
  rec(i,1);
for(i=0;i<n;i++)
{
  cout<<dp[i][0]<<" ";
}
cout<<endl;
return 0;
}