#include <bits/stdc++.h>

using namespace std;
 
long long int gcd( long long int a,  long long int b) {
    return b == (long long int)0 ? a : gcd(b, a % b);
}
 int main()
{
long long int l,r;
cin>>l>>r;
long long int i,j,k;
long long int a,b,c;

for(i=l;i<r;i++)
{
  //cout<<" the value of a is "
  a=i;
  for(j=i+1;j<r;j++)
  {
     b=j;
     for(k=j+1;k<=r;k++)
     {
       c=k;
       long long int ans1= gcd(a,b);
       long long int ans2=gcd(b,c);
       long long int ans3= gcd(a,c);
         if(ans1==1 && ans2==1 && ans3!=1 )
         {
            cout<<a<<" "<<b<<" "<< c << endl;
            return 0;

         }      

     }
  }
}

cout<<-1<<endl;

return 0;
}