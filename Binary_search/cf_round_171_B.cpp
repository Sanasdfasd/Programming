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
   
long long int n,t,i,j;
cin>>n;
cin>>t;
int arr[n+5];
for(i=0;i<n;i++)
	cin>>arr[i];
long long int pre_sums[n+5];
pre_sums[0]=arr[0];
for(i=1;i<n;i++)
  pre_sums[i]=pre_sums[i-1]+arr[i];

int ans=0;

for(i=0;i<n;i++)
{
int low=i, hi= n-1,res=-1;
long long int  val=0;
if( i!=0)
	val=pre_sums[i-1];
while(low<=hi)
{
   int mid= (low+hi)/2;
  if( (pre_sums[mid]-val) > t)
     hi=mid-1; 
  else
  {
   low=mid+1;
   res=mid-i+1;
  }

}
ans= max( ans,res );
}

cout<<ans<<endl;
	return 0;
}