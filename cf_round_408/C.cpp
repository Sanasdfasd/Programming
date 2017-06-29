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
std::vector<int> val[5000006];



int main()
{
int n,i,j,k;
cin>>n;
int ar[n+5];
for(i=0;i<n;i++)
  cin>>ar[i];
for(i=0;i<n-1;i++)
{
   int u ,v;
  cin>>u>>v;
  val[u-1].push_back(v-1);
  val[v-1].push_back(u-1);
}
int max_deg=0,max_ver=0;
for(i=0;i<n;i++)
{
  val.si
}


}