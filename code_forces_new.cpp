#include <iostream>
#include <cstring>
#include <memory>
#include <stdlib.h> 
#include <time.h>       

using namespace std;
 long long int ar[1005];
long long int n,k;
long long int min_sum=9999999999999;
long long int global_array[10005];
void solve(int index, int val[1005],int top,long long int sum,long long int pr)
{
if(index==-1)
	return ;
else
 {
    solve(index-1,val,top,sum,pr);
    val[top]=index;
    top++;
   sum=sum+ar[index];
   pr=pr*ar[index];
   pr=pr%k;
   if(pr==0)
   {
   	  if(sum<min_sum)
   	  {
   	  	min_sum=sum;
      int tt;
      for(tt=0;tt<top;tt++)
      {
      	global_array[tt]=val[tt];
      }
     }
   }
   else
    solve(index-1,val,sum,pr);
 }
}


int main()
{
 cin>>n;
 cin>>k;
 int i;
 for(i=0;i<n;i++)
  cin>>ar[i];
memset(global_array,0,sizeof(global_array));
memset(val,0,sizeof(val));
  solve(n-1,val,0,0,1);

return 0;
}