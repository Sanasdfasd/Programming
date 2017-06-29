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

int n,m,k,i,j;
cin>>n>>m>>k;
int holes[n+5];
memset(holes,0,sizeof(holes));
for(i=0;i<m;i++)
{
  int t;
  cin>>t;
  holes[t-1]=1;
}
int fin_answ=0;
for(j=0;j<k;j++)
{
  int u,v;
  cin>>u>>v;
if(holes[fin_answ]==1)
{
  break;
}
if((u-1)==fin_answ ||(v-1)==fin_answ)
{

  if((u-1)==fin_answ)
  {
     fin_answ=v-1;
  }
  else
  {
    fin_answ=u-1;
  }
}
}

cout<<fin_answ+1<<endl;
	return 0;

}