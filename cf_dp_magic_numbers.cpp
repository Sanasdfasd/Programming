
#include <iostream>
#include <stdlib.h> 
#include <time.h>    
#include <string>
int as[300005];
using namespace std;
int main()
{
std::string a;
//memset(a,0,sizeof(a));
//scanf("%s",a);
cin>>a;
 int i,j,k,o,q;
 j=a.size();
  long long int cal=0;
  as[0]=a[0]-'0';
  if(as[0]%4==0)
  	cal=cal+1;
 for(i=1;i<j;i++)
 {
 	as[i]=a[i]-'0';
 	  if(as[i]%4==0)
  	cal=cal+1;
     if((((as[i-1]*10)+a[i])%4)==0)
          cal=cal+i;
 }
cout<<cal<<endl;
return 0;
}