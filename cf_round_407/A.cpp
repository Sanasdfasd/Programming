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
int dp[1000006][3]; // Store digits that are removed
int sol[1000006][3][3];
int main()
{

string val;
cin>>val;
int i,j,k,l, found=0;
int n= val.size();
memset(dp,n,sizeof(dp));
memset(sol,-1,sizeof(sol));
int maxs[3],prev[3],maxs1[3],prev1[3];
for(i=0;i<n;i++)
{
	for(j=0;j<3;j++)
	{
		dp[i][j]=n;
	}
}
for(i=0;i<3;i++)
maxs[i]=n;

memset(prev,-1,sizeof(prev));
for(i=0;i<n;i++)
{
	int v=val[i]-'0';
	maxs1[0]=n,maxs1[1]=n,maxs1[2]=n;
	prev1[0]=-1,prev1[1]=-1,prev1[2]=-1;
  if(v!=0)
   {
       dp[i][v%3]=n-1;
       if(maxs[v%3]>dp[i][v%3])
       {
       	  maxs1[v%3]=dp[i][v%3];
       	  prev1[v%3]=i;
       }
   }
   else
   	found=1;
	for(j=0;j<3;j++)
	{
         if((maxs[(j+v)%3]>(maxs[j]-1)) && prev[j]!=-1)
         {
               maxs1[(j+v)%3]=(maxs[j]-1);
               dp[i][(j+v)%3]=maxs1[(j+v)%3];
               prev1[(j+v)%3]=i;
               sol[i][(j+v)%3][j]=prev[j];
         }  
	
   }
for(j=0;j<3;j++)
 {
	if(maxs[j]>maxs1[j])
	{
		maxs[j]=maxs1[j];
		prev[j]=prev1[j];
	}

 }
}
int min=n,index=-1,index1=-1,index3=-1;
for(i=0;i<n;i++)
{

	if(dp[i][0]<min)
	{
		index3=i;
		min=dp[i][0];
		int mins=n+5;
        	for(k=0;k<3;k++)
        	{
        		if( sol[i][0][k]!=-1)
        		{

        				if( dp[sol[i][0][k]][k]<mins && dp[sol[i][0][k]][k]!=n)
        				{
        					mins= dp[sol[i][0][k]][k];
        					index=sol[i][0][k];
        					index1=k;
        				}
        		}
       	}       
	}
}

int t=0;
std::vector<int> vs;
if(index3!=-1)
vs.push_back(index3);
if(index!=-1)
vs.push_back(index);	
while(index3>0 && index!=-1)
{
    int cur_index=index,cur_index1=index1;
      index=-1, index=-1;
		int mind=n+5;
          for(k=0;k<3;k++)
        	{
        		if( sol[cur_index][cur_index1][k]!=-1)
        		{
        				if( dp[sol[cur_index][cur_index1][k]][k]<mind  )
        				{
        					mind=dp[sol[cur_index][cur_index1][k]][k];
        					index=sol[cur_index][cur_index1][k];
        					index1=k;
        					vs.push_back(index);
        				}
        		}
        	}
}
reverse(vs.begin(),vs.end());
int div=0;
for(i=0;i<vs.size();i++)
{
	cout<<val[vs[i]];
	int t=val[vs[i]]-'0';
	div=(div+t)%3;
}

if(index3==-1)
{
if(found==1)
	cout<<"0";
else
	cout<<"-1";

}
	return 0;
}