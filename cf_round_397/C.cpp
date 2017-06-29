#include <bits/stdc++.h>

using namespace std;

int main()
{

 long long int n,k;
 cin>>n>>k;
 long long int arr[n+5];
 int mark[n+5];
 memset(mark,0,sizeof(mark));
 int i,j;
 for(i=0;i<=n;i++)
 	arr[i]=i;
int counter=1;
mark[1]=1;
while(k>=1)
{
	int sec=0;
   long long int temp=-k+arr[counter];
   long long int temp1=k+arr[counter];
   if(temp>0 && temp<=n )
   {
   	   if( mark[temp]!=1)
   	   {
         arr[counter+1]=temp;
         mark[temp]=1;
   	   }
   	   else
   	   {
   	   	 arr[counter+1]=temp1;
   	   	 mark[temp1]=1;
   	   }
   } 
   else
   {
     arr[counter+1]=temp1;
     mark[temp1]=1;
   }
   counter++;
   k--;
}

for(i=1;i<=n;i++)
	cout<<arr[i]<<" ";
cout<<endl;



return 0;
}