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
#include <cmath>
#include <limits>
using namespace std;

int main()
{
long long int n;
long long int sum=0;
int i,j;
cin>>n;
int arr[n+5];
int count[n+5], sum_prefix[n+5];
for(i=0;i<n;i++)
{
  cin>>arr[i];
  sum=sum+arr[i];
}
long long int ans=0;
if((sum%3)!=0)
{ cout<<0<<endl;
	return 0;
}
sum=sum/3;
long long int pre=0;
for(i=n-1;i>=0;i--)
{
	pre=pre+arr[i];
	if( pre ==sum)
	{
      	count[i]=1;
	}
	else
	{
      count[i]=0;
	}
}
pre=0;

for(i=n-2;i>=0;i--)
	count[i]=count[i]+count[i+1];



for(i=0;(i+2)<n;i++)
{
	pre=pre+arr[i];
	if( pre ==sum)
      ans=ans+count[i+2];
}

cout<<ans<<endl;

return 0;
}	