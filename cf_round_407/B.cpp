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

int main()
{

long long int n,q;
cin>>n>>q;
int i,j;
long long int val;
for(i=0;i<q;i++)
{
  cin>>val;
  string s;
  cin>>s;
  for(j=0;j<s.size();j++)
  {
     long long int temp_val=val;
     long long int offset=temp_val&(-temp_val);
    if(s[j]=='U')
    {
       offset= offset<<1;
       temp_val=temp_val | offset;
       long long int offset1=(temp_val&-temp_val); 
       temp_val= temp_val^offset1;
         if(temp_val!=(n+1))
            val=temp_val;
    }
    else if( s[j]=='R')
    {
       offset= offset>>1;
        if(offset!=0)
        {
          val=val+offset;
        }
    }
    else
    {
         offset= offset>>1;
        if(offset!=0)
          val=val-offset;
    }
  }
cout<<val<<endl;
}

	return 0;

}