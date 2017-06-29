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
int n,i,j,a,q;
cin>>n;
int v[n+5];
for(i=0;i<n;i++)
 cin>>v[i];
 sort(v, v+n);

 //cout<<endl;
 	cin>>q;
for(i=0;i<q;i++)
{
  cin>>a;
  int low=0, hi= n-1, res=0;
 while(low<=hi)
 {
  int mid= (low+hi)/2;
  //cout<<" the values of low and high are "<<low<<"  "<<hi<<"  "<<mid<<endl;
   if( a>= v[mid])
   {
   	 	 low=mid+1;
   	  res=mid;
   }
   else
    {
       hi=mid-1;
       // cout<<" the result value that is assigned is  " <<mid<<endl;
    	
    }   

 }

 //cout<<" the value of result is "<<res<<endl;
if( ((a<v[res]) && res==0))
	cout<<0<<endl;
else
	cout<<res+1<<endl;

}



return 0;
}


