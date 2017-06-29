#include <bits/stdc++.h>

using namespace std;

int arr[1000+5];
int n,k;

int found=0;
 int store[10000];
void  solve( int pos)
{
	int i;
  if(pos==n)
  {
     int sum=0;
     for(i=0;i<n;i++)
     {
     	sum=sum+arr[i];
     }
    if( store[sum]==k)
    	found=1;

  }
  else
  {
  	int val=0;
  	if(pos==0)
  		val=1;
    for(i=val;i<=9;i++)
    {

     arr[pos]=i;
     solve(pos+1);
     if(found==1)
     	break;
    }
  }
}



int main()
{

int i;
cin>>n>>k;
int counter=-1;
for(i=0;i<1000;i++)
{
   counter++;
  if(counter==10)
  	counter=0;
  store[i]=counter;
}


solve(0);
if(n==1 && k==0)
{
 cout<<0<<endl;
 return 0;
}
 if(found ==0 || (n>1 && k==0))
 cout<<"No solution"<<endl;
else
{
  for(i=0;i<n;i++)
  	cout<<arr[i];
}


return 0;
}