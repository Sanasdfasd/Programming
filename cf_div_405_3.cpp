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
int n,k;
string arr[55];

int global_coun=0;

string res[55];
string yn[55];
int total=0;
void dfs(int set, int curr_index )
{
 if(set<total)
 {

  if(yn[set][0]=='N')
  {
    arr[curr_index]=arr[set];
    dfs( set+1,curr_index+1);
  }
  else
  {

    //cout<<"the index+ k is "<< set<<"  "<<set+k<<endl;
     dfs( set+1,set+k);
  }
 }

}

void generate_strings(int len, int index, string ap)
{
    if(index<5)
    {
   if(len==10)
   {
     index=index+1;
     len=0;
   }
  if(len==0)
  {
    ap.clear();
    ap.push_back('A'+index);
    arr[global_coun]=ap;
    global_coun++;
    len++;
    generate_strings(len,index,ap);
  }
  else
  {
    ap.push_back(index+'a');
    arr[global_coun]=ap;
    global_coun++;
    len++;
     generate_strings(len,index,ap);
  }

  }
}


int main()
{

cin>>n>>k;
string l;
generate_strings(0,0,l);
int i;
total=(n-k)+1;
for(i=0;i<total;i++)
{
    cin>>yn[i];
}
dfs(0,1);
for(i=0;i<n;i++)
{
    cout<<arr[i]<<"  ";
}
cout<<endl;

    return 0;

}