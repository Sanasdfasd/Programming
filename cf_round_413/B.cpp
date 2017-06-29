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

//int div=0;

bool check( long long int s, int p)
{
  long long int count=0,i;
i = ((s / 50)) % 475;
//cout<<"the value of i is "<<i<<endl;
while(count<25){
    i = ((i * 96) + 42) % (475);
   // cout<<i+26<<" ";
  if((i+26)==p)
    return true;
    count++;
}

return false;
}

int main()
{

long long int p,x,y;
cin>>p>>x>>y;
 //div=p;
int i,j;

if(check(x,p)==true)
  cout<<0<<endl;
else
{
 // cout<<endl;
  int br=0;
for(i=0;i<=(2*102);i++)
{
  //cout<<" the value of i is ********"<<endl;
   long long int temp= x+ (i*100);
   //cout<<" the value of temp i s"<<temp<<endl;
  for(j=0;j<=(4*102);j++)
  {

    long long int temp1 =temp-(j*50);
   // cout<< " the value of temp is "<<
    if( temp1>=y)
    {
      if(check(temp1,p)==true)
      {
        br=1;
        break;
      }
     // cout<<endl;
    }
    else 
    {
      break;
    }

  }
 if(br==1)
 {
  break;
 }
}
cout<<i<<endl;

}


}