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

int n,t,k,d;
cin>>n>>t>>k>>d;
if((n<=k))
{
  cout<<"NO"<<endl;
}
else
{
  int total= ((n+(k-1))/k);
  int total1= total*t;
  if((d)<(total1-t))
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;

}


return 0;
}