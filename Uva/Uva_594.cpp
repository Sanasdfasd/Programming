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

 int t;

while(cin>>t)
{
 int l= 0;
 int i=0;
 int s=t;
for(i=0;i<4;i=i+1)
 {
   int vl= (1<<8)-1;
   int temp=(t & vl) ;
   int val=temp;
  l=l+val;
  if(i!=3) 
  l=l<<8;
  t=t>>8;
 }
cout<<s<<" converts to "<<l<<endl;
}



return 0;
}