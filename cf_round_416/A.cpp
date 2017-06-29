#include <bits/stdc++.h>

using namespace std;
 
long long int gcd( long long int a,  long long int b) {
    return b == (long long int)0 ? a : gcd(b, a % b);
}
 int main()
{

int i,j,c1,c2;
cin>>c1>>c2;
int first=0;
for(i=0;i< 40000005;i++)
{
 if((i%2==0))
 {
  if((c1-(i+1))<0)
  {
     first=0;
     break;
   }
    c1=c1-(i+1);   
  
 }
 else
 {
  if((c2-(i+1))<0)
  {
     first=1;
     break;
  }
   c2=c2-(i+1);
 }

}
if(first==0)
  cout<<"Vladik"<<endl;
else
  cout<<"Valera"<<endl;


return 0;
}