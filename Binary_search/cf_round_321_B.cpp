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
 int n,d;
 cin>>n>>d;
 vector < pair < int, int > > vs;
 vector < long long int> pre_sums;
 vector <int> money;
 int i,j, a, b;
 long long int su=0;
 long long int ans=0;
 for(i=0;i<n;i++)
 {
   cin>>a>>b;
   vs.push_back( make_pair(a,b));
  
 }
sort(vs.begin(), vs.end());

for ( vector < pair < int,int> >::const_iterator it = vs.begin() ; it != vs.end(); it++){
        su=su+(it->second);
        pre_sums.push_back(su);
    }

int left_ptr=0, right_ptr=0;

while((left_ptr < n) && (right_ptr < n))
{
	long long int val= 0;
	if( left_ptr==0)
      val=pre_sums[right_ptr];
    else
     val= pre_sums[right_ptr]-pre_sums[left_ptr-1];
     if( (left_ptr==right_ptr))
     {
          ans= max(ans,val);
          right_ptr++;
     }
     else
     {
        int ss=0;
           ss= (vs[right_ptr].first) - ( vs[left_ptr].first);
       if(ss>= d)
       {
       	 left_ptr++;
       }
       else
       {
          right_ptr++;
          ans= max( ans,val);
       }
     }
}

cout<<ans<<endl;

	return 0;
}