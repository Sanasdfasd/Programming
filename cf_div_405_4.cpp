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
int n,k;
std::vector<int > vs,arr,out;

int main()
{

string s;
cin>>s;
int i;
int dp[3],dp1[3];
memset(dp,0,sizeof(dp));
memset(dp1,0,sizeof(dp1));
int val= s[i]-'0';
dp[(val%3)]=1;
dp1[(val%3)]=1;
for(i=1;i<s.length();i++)
{
   int val= s[i]-'0';
    if(val!=0)
      {
      	if( dp[val%3]<1)
           dp[val%3]=1;
      }
	for(j=0;j<3;j++)
	{
      if(dp[j]!=0)
      {
            if( dp[(val+j)%3]>(dp[j]+1))
               dp[val%3]=dp[j]+1;
      }
	}

}


	return 0;
}