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
 int n,k;
 cin>>n>>k;
long long int arr[n+5];
memset( arr, 0,sizeof(arr));
int i,j,a,b;
for(i=0;i<n;i++)
	cin>>arr[i];
int p= (n-k);
p=(p*2);
long long int mx=0;
if((p==0) && (n==(2*k)))
{
	p=(n/2)*2;
}
for(i=0;i<n;i=i+1)
{ 
if(i < p)
{
 mx= max( mx, arr[i]+arr[p-i-1]);
  i=i+1;
}
else
   mx= max( mx, arr[i]);

}

cout<<mx<<endl;


	return 0;
}