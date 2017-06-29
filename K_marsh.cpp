#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include<memory.h>
using namespace std;
int m,n;
char arr[505][505];
int up[505][505];
int down[505][505];
int lft[505][505];
int fn[505][505];
void compute_up()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		if(arr[0][i]=='.')
		up[0][i]=-1;
		else
		up[0][i]=0;
	}
	for(i=1;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(arr[i][j]=='.')
			up[i][j]=up[i-1][j];
		     else
		     {
		     	  up[i][j]=i;
			 }
          
		}
	}
}
void compute_down()
{
	int i,j;
	  for(i=0;i<n;i++)
	{
		if(arr[m-1][i]=='.')
		down[m-1][i]=m;
		else
		down[m-1][i]=m-1;
	}
	   for(i=m-2;i>=0;i--)
	{
		for(j=0;j<n;j++)
		{
			if(arr[i][j]=='.')
			down[i][j]=down[i+1][j];
			else
            down[i][j]=i;
		}
	}
}
void compute_left()
{
		int i,j;
	  for(i=0;i<n;i++)
	{
		if(arr[i][0]=='.')
		lft[i][0]=-1;
		else
		lft[i][0]=0;
	}
	for(i=0;i<=m;i++)
	{
		for(j=1;j<n;j++)
		{
			if(arr[i][j]=='.')
			lft[i][j]=lft[i][j-1];
			else
            lft[i][j]=j;
		}
	}
}
void print()
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<up[i][j]<<" ";
		}
		cout <<endl;
	}
	cout <<endl;
}
int maxi_5(int a,int b,int c,int d)
{
	int max=a;
	if(b>max)
	{
		max=b;
	}
	if(c>max)
	{
		max=c;
	}
	if(d>max)
	{
		max=d;
	}
	return max;
}
void compute_fn()
{
	memset(fn,0, sizeof(fn));
	int i,j,sum;
	for(i=0;i<m;i++)
	{
		fn[0][i]=0;
	}
	for(i=1;i<n;i++)
	{
		fn[i][0]=0;
	}
	for(i=1;i<m;i++)
	{
		int sum=0;
		for(j=1;j<n;j++)
		{
		  if(arr[i][j]=='.')
		  {
		  	int k,m;
		  	int lftptr=lft[i][j];
		  	int storel=lftptr;
		  	int upptr=up[i][j];
		  //	cout<<"upptr"<<upptr<<endl;
		  	int l1leftptr;
		  	l1leftptr=lft[upptr+1][j];
		  	// cout <<"left left ptr" <<"val is "<<l1leftptr<<endl;
		  	int a=lftptr,b=l1leftptr;
		  	if(a<b)
		  	 lftptr=l1leftptr;
		  	 else
		  	 l1leftptr=lftptr;
		  	 sum=0;
		  	// cout <<"left ptr" <<"val is "<<lftptr<<endl;
		   while((lftptr+1)<j)
		  {	   
		  	 int up1ptr=up[i][lftptr+1];
		  	// cout <<"up1ptr" <<"val is "<<up1ptr<<endl;
		  	 int va=0;
		  	 if(up1ptr>lftptr)
		  	  up1ptr=lftptr;
		  	 	if((j-(up1ptr+1))>0)
		  	    va=(i-(up1ptr+1))*2 + (j-(lftptr+1))*2;
		  	  //  cout <<"va value is "<<va<<endl;
		  	 	if(sum<va)
		  	 	sum=va;
		  	 	//cout <<sum<<endl;
             lftptr=lftptr+1;
	   	 }
		  	 
		  }

		  	 fn[i][j]=maxi_5(fn[i-1][j],fn[i][j-1],fn[i-1][j-1],sum);

		}
	}
}
int main()
{	
	int t_cases,i,j;
	cin>>t_cases;
	while(t_cases-->0)
	{
		cin>>m;
		cin>>n;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				cin>>arr[i][j];
			}
		}
		compute_up();
		compute_down();
		compute_left();
		//print();debug if necessary.
		compute_fn();
		if(fn[m-1][n-1]==0)
		{
			cout <<"impossible"<<endl;
		}
		else
		cout<<fn[m-1][n-1]<<endl;
	}
	
	
	return 0;
	
}
