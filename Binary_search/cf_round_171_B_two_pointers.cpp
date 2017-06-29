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
   
long long int n,t,i,j;
cin>>n;
cin>>t;
int arr[n+5];
for(i=0;i<n;i++)
	cin>>arr[i];
long long int pre_sums[n+5];
pre_sums[0]=arr[0];
for(i=1;i<n;i++)
  pre_sums[i]=pre_sums[i-1]+arr[i];
int left_ptr=0, right_ptr=0;
int ans=0;
while( left_ptr <n && right_ptr <n)
{

  long long int val= 0;
  if(left_ptr==0)
  val=pre_sums[right_ptr];
else
	val= pre_sums[right_ptr]-pre_sums[left_ptr-1];
 if( val < t)
 {
    ans= max( ans, right_ptr-left_ptr+1 );
    right_ptr++;
 }
 else if( val== t)
 {
   ans= max( ans, right_ptr-left_ptr+1 );
   left_ptr++;
 }
 else
	left_ptr++;

}

cout<<ans<<endl;
return 0;
}