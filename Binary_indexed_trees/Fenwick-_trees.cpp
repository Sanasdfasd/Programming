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
using namespace std;

long long int bit0[2000005], bit1[2000005],bit2[2000005];

int n;
//
long long int Query(int val, long long  int bit[2000005])
{
	long long int sum=0;
  while(val>0)
  {
    sum+=bit[val];
    val-=(val&-(val));
  }

return sum;
}
void update(int val, int amount, long long  int bit[2000005])
{
  while(val<=(n+1))
  {
    bit[val]+=amount;
     val+=(val&-(val));
  }
}
/*
void Range_update(int l, int r, int val)
{
  update(l,val,bit1);
  update(r+1,-val,bit1);
  update(l,val*(l-1),bit2);
  update(r+1,-(val*r),bit2);
}
long long int range_cal(int l)
{
	return ((Query(l,bit1)*l)-(Query(l,bit2)));
}
//Range Query Sum
long long int  Range_sum(int l, int r)
{
 return(range_cal(r)-range_cal(l-1));
}
*/
int main()
{

    int m,i,j;
 cin>>n>>m;
 int pr[n+5];
 int arr[n+5];
 int as[n+5];
memset(bit0,0,sizeof(bit0));
memset(bit1,0,sizeof(bit1));
memset(bit2,0,sizeof(bit2));
//int i;
int dc[n+5];
dc[0]=0;
for(i=1;i<=n;i++)
{
	int val;
	cin>>val;
  //cout<<" the values are given by"<<val<<endl;
 //long long int vv= Query(n+1);
  //long long int vv1= Query(val);
   //cout<<"the value of vv "<<vv<<"  "<<vv1<<endl;
   //update(val,(vv-vv1),bit0);
  dc[i]=Query(n+1, bit0)-Query(val,bit0);
   update(val,1, bit0);
   //cout<<Query(val+1,bit0)-Query(val,bit0)<<endl;
}
for(i=1;i<=n;i++)
{
   dc[i]=dc[i-1]+dc[i];
   cout<<dc[i]<<"  ";
}
cout<<endl;
for(i=0;i<m;i++)
{
  int a,b,c;
  cin>>a>>b>>c;
   if( dc[b]-dc[a])
}
	return 0;
}
