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

int main()
{

int n,k,i,j;
cin>>n>>k;
int arr[n+5];
 long long int sum=0;
for(i=0;i<n;i++)
{ 
  cin>>arr[i];
  sum=sum+arr[i];
}


double res= (double) sum /(double)n;
//cout<<" res is "<<res<<endl;
if( res >= k)
{
  cout<<0<<endl;
return 0;
}
double reg= ((double)k)-0.5;
double vals= ((double)(n*(reg)) - (double) sum);
 res= vals*(2.0);
 int ans= ceil(res);

if( ans<=0)
  ans=0;
cout<<ans<< endl;
return 0;
}