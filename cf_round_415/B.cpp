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


bool compar( pair < int, int > a, pair < int , int > b)
{
  /* if ( (a.second - a.first) > ( b.second - b.first))
    return 1;
   else
   return 0;  */
  if(a.first ==0 || a.second ==0)
    return 0;
  else if ( b.first ==0 || b.second ==0)
    return 1;
  long long int as,bs;
   as= 2*(a.first);
   bs= 2*(b.first);
   if(as > (a.second))
    as=a.second;
   if(bs > (b.second))
    bs=b.second;
   if( as > bs)
   {
    if( (a.second -as) > ( b.second -bs))
    return 1;
    else
      return 0;
  }
   else
  {
    if( (a.second -as) > ( b.second -bs))
    return 1;
    else
      return 0;
  }

}


int main()
{
int n,f;
cin>>n>>f;
int a,b,i,j;
std::vector< pair < int , int > > vs;
for(i=0;i<n;i++)
{
  cin>>a>>b;
  vs.push_back( make_pair( a, b));
}

sort(vs.begin(), vs.end(),compar);

/*for(i=0;i<n;i++)
{
  cout<<vs[i].first <<"  "<<vs[i].second <<endl;
}*/

long long int res=0, count=0;
for(i=n-1;i>=0;i--)
{
  if(count >= f)
  {
     int dd= min(vs[i].first, vs[i].second);
     res=res+dd;
  }
  else
  {

         long long int as= (vs[i].first) *(2);

         if(as > vs[i].second)
           as=vs[i].second;
        // cout<<" the value of as is "<<as<<endl;
         //(min((2*vs[i].first) , vs[i].second))-(min((vs[i].first), (vs[i].second)))
        res=res+as;
      count++;
    
  }

}

cout<<res<<endl;


}