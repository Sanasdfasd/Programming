#include <bits/stdc++.h>

using namespace std;
 
long long int gcd( long long int a,  long long int b) {
    return b == (long long int)0 ? a : gcd(b, a % b);
}
 int main()
{
int n;
cin>>n;
if(n%2!=0)
{
  cout<<0<<endl;
  return 0;
}
else
{
  int temp= (n/4);
  if(((n/2)-temp)==(temp))
    temp=temp-1;
  cout<<temp<<endl;
}


return 0;
}