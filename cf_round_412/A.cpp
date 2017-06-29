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

int n;
cin>>n;
vector <int> in,fi;
//memset(in,0,sizeof(in));
//memset(fi,0,sizeof(fi));
int rate=-1,i;
for(i=0;i<n;i++)
{
  int a,b;
  cin>>a>>b;
  in.push_back(a);
  fi.push_back(b);
  if(fi[i]-in[i]!=0)
    rate=1; 
}
if(rate==1)
cout<<"rated";
else
{
  rate=0;
  sort(in.begin(), in.end());
  std::reverse(in.begin(), in.end());
 int i;
 int count=0;
 for(i=0;i<n;i++)
 {
 // cout<<in[i]<<"\n";
    if(fi[i]!=in[i])
       count++;  
 }
 if(count==0)
 cout<<"maybe";
else
  cout<<"unrated";

}


return 0;
}