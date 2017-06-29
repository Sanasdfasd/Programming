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

	long long int count1=0;
bool AreSame(double a, double b) {
    return std::fabs(a - b) < std::numeric_limits<double>::epsilon();
}

long long int gcd(long long int a,long long int b)
{
   return b==0 ? a : gcd(b,a%b);
}

int main()
{

int t_case=0;
cin>>t_case;

while(t_case>0)
{
int x,y,p,q;
cin>>x>>y>>p>>q;
int a, b;
long long int gc_value=0;
if(x>y)
gc_value=gcd(x,y);
else
gc_value=gcd(y,x);
double val1= (double)(x/(double )y);
double val2= (double)(p/(double )q);
if(((x/gc_value)==p && (y/gc_value)==q))
   cout<<0<<endl;
else
{
long long int low= 0;
long long hi= 1000000009;
long long int count1=-1;
 long long int mid=0;
 long long int c1=0;
 long long int c2=0;
while(low<=hi )
{
mid=(low+hi)/2;
long long int gc_value=0;
 c1=(p*mid)-x;
 c2=(q*mid)-y;
//cout<<" the value  of high and low are    "<<low<<"  "<<hi<<"   "<<mid<<endl; 
if((p*mid)>(q*mid))
gc_value=gcd((p*mid),(q*mid));
else
gc_value=gcd((q*mid),(p*mid));
if((c1<0 || c2<0) || (c1>c2))
	low=mid+1;
else{
  hi= mid-1;
  count1=c2;
}

}
if(mid==1000000009)
count1=-1;
cout<<count1<<endl;
}
t_case--;
}
return 0;
}