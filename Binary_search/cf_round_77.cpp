#include <bits/stdc++.h>
using namespace std;

long long int n;
 long long int res=1000000000000000;
 int ass[16];
 void check( int c1 ,int c2, long long  int prev)
 {
  if( prev < 9000000000000)
  {
   if(c1==c2)
   	{
      if(prev >= n)
        res=min(res, prev);

   	}
   long long int val1= (prev*(long long int )10)+(long long int)4;
    check(c1+1,c2,val1);
   val1= (prev*(long long int)10)+(long long int)7;
     check(c1,c2+1,val1);
 }

 }

int main()
{
cin>>n;
check(0,0,0);
cout<<res<<endl;

	return 0;
}