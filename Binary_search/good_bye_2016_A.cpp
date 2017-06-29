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
int n,k;
cin>>n>>k;
int low=0, hi=n, res=0;
while(low<=hi)
{
 int mid=(low+hi)/2;
 int ss= (5*(mid+1)*(mid))/2;
 if(k+(ss)>240)
  hi=mid-1;
  else
  {
  	low=mid+1;
  	res=mid;
  }
}

cout<<res<<endl;
return 0;
}	