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
cin>>n;
long long int arr[n+5];
long long int i,res=0;
for(i=0;i<n;i++)
	cin>>arr[i];
long long int pre_sum=0;
sort(arr, arr+n);
long long int ans=0;
for(i=0;i<n;i++)
{
  pre_sum= (((pre_sum)+ arr[i]))%(1000000007);
  //pre_sum=(pre_sum)%(1000000007);
  if(i!=0)
  {
    long long int t1= ((i+1)*(arr[i]))%(1000000007);
    long long int t2= (t1-pre_sum)%(1000000007);
     ans=(ans+t2)%(1000000007);
  }

}
cout<<ans<<endl;
return 0;
}