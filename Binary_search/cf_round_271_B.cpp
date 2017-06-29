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
 int n,a,i,j;
 cin>>n;
 std::vector<int> v;
 int m;
 int sum=0;

 for(i=0;i<n;i++)
  {
  	cin>>a;
  	sum=sum+a;
  	v.push_back(sum);
  }
 cin>>m;
for(i=0;i<m;i++)
{
   cin>>a;

int low=0, hi=n-1, res=0;
while(low<=hi)
{
	int mid= ((low+hi)/2);
	if(a<=v[mid] && a>v[mid-1] && mid>0)
	{
		res=mid;
	  break;
	}
	else if(a<=v[mid] && a>0 && mid==0)
	{
		res=mid;
	  break;
	}
	else  if(a >v[mid]  )
	{
      low= mid+1;
	}
	else
	{
         hi=mid-1;
	}
}

cout<<res+1<<endl;

}

 return 0;
}	