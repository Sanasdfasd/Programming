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
long long int n ,k;

cin>>n>>k;
long long int temp = (k&(-k));
long long int i;
if( temp==1)
	cout<<1<<endl;
else
{
	long long int count=0;
  for(i=temp; i>0; i=(i>>1))
  {
  	//cout<<" my value here is "<<i<<endl;
    count++;
   }
 
   cout<<count<<endl;

}

return 0;

}	