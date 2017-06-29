#include <iostream>
#include <cstring>
#include <memory>
#include <stdlib.h> 
#include <time.h>  

using namespace std;
long long int total_count=0;
int ar[400009];
int prime[100];
void prime_number()
{  prime[2]=1;
   prime[3]=1;
   prime[5]=1;
   prime[7]=1, prime[11]=1, prime[13]=1, prime[17]=1, prime[19]=1, prime[23]=1, prime[29]=1, prime[31]=1, prime[37]=1, prime[41]=1, prime[43]=1;
}

void prime_generator(int size,int n)
{
 if(size==(n))
 {
   cout<<"the prime number is "<<ar[0]<<ar[1]<<ar[2]<<ar[3]<<ar[4]<<ar[5]<<endl;
   //<<ar[7]<<ar[8]<<ar[9]<<ar[10]<<ar[11]<<ar[12]<<endl;
   total_count=total_count+1;
   total_count=(total_count)%(1000000007);
 }
 else
 {
 	int val=0;
 	if(size==0)
 	{
     val=1;
 	}
 	int i,k;
  for(i=val;i<=9;i++)
  {
    ar[size]=i;
      int fl=0;
     if((size-2)>=0)
     {
      if(prime[ar[size]+ar[size-1]+ar[size-2]]!=1)
          fl=1;
     }
    if((size-3)>=0)
     {
      if(prime[ar[size]+ar[size-1]+ar[size-2]+ar[size-3]]!=1)
          fl=1; 
     }
     if(size-4>=0)
     {
      if(prime[ar[size]+ar[size-1]+ar[size-2]+ar[size-3]+ar[size-4]]!=1)
          fl=1;  
     }
     if(fl==0)
    prime_generator(size+1,n);
  }
 }

}


int main(){
    int q;
    cin >> q;
    memset(prime,0,sizeof(prime));
    prime_number();
   for(int a0 = 0; a0 < q; a0++){
        int n;
        cin >> n;
        //int ar[400009];
        memset(ar,0,sizeof(ar));
        prime_generator(0,n);
        cout<<total_count<<endl;
        total_count=0;
    }

 	    return 0;
}
