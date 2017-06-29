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
long long int digit_count[10];


//check the validity of digit and return the result  --> result =-1 numbers are not valid
int check_validity(int limit )
{
  int result=-1,i;
for(i=limit;i>=0;i--)
{
  if(digit_count[i]>0)
  {
    digit_count[i]=digit_count[i]-1;
    result=i;
    break;
  }
}
 return result;
}

int main()
{
int res[4];
memset(digit_count,0,sizeof(digit_count));
memset(res,0,sizeof(res));
int i,a;
for(i=0;i<4;i++)
{
  cin>>a;
  if(a<=9)
  digit_count[a]=digit_count[a]+1;
}
//check for the first digit of the hour's hand:
  res[0]=check_validity(2);
if(res[0]==-1)
  cout<<" not valid"<<endl;
else
{
//check the second digit of the hour's hand:
  res[1]=check_validity(9);
  if( res[1]==-1)
    cout<<" not valid"<<endl;
 else
 {
//check the first digit of the minutes hand
 res[2]=check_validity(5);
 if(res[2]==-1)
  cout<<" not valid"<<endl;
 else
 {
   //check the  second digit of the minutes hand
   res[3]=check_validity(9);
   if(res[3]==-1)
      cout<<" not valid"<<endl;
    else
    cout<<" Max time is  "<<res[0]<<res[1]<<":"<<res[2]<<res[3]<<endl;
 } 
}
}

return 0;
}