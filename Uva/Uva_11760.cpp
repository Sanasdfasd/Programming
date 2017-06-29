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
#include <math.h>
#include <string.h>
#include <string>
using namespace std;
int ar[100009];
int ar_sum[100009];
int main()
{
 int t;
while(cin>>t)
{
 memset(ar,-1,sizeof(ar)); 
 memset(ar_sum,0,sizeof(ar_sum));
 int i,j;
 for(i=0;i<pow(2,t);i++)
   cin>>ar[i];
for(i=0;i<pow(2,t);i++)
{
  for(j=0;j<t;j++)
  {
     int variant= (i^(1<<j));
    ar_sum[i]=ar_sum[i]+ar[variant];
  }
} 

int mx=-1;
for(i=0;i<pow(2,t);i++)
{
  for(j=0;j<t;j++)
  {
     int variant= (i^(1<<j));
     mx= max(mx, ar_sum[i]+ar_sum[variant]);
  }
} 

cout<<mx<<endl;
  
}



return 0;
}