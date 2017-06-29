#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <memory.h>
using namespace std;
//char c[1000000];
long long int rbq[10005][3];
bool find_any_r(long long int w1,long long int w2, long lont int b1, long long int b2 )
{
long long int min1=w1,max1=0;
long long int min2=w2,max2=0;
	if(min1>b1)
	{
		  min1=b1;
		  max1=w1;
	}
	else
	{
		 min1=w1;
		  max1=b1;		
	}
	
	for(i=min1+1;i<max1;i++)
	{
		
	}
	
	return true;
}
bool find_any_b(long long int w1,long long int w2, long lont int b1, long long int b2 )
{

	if(w1==b1)
	{
		 long long int min=w2;
		 if(min<b2)
		  min=
		   
		   
	}
	else
	{
		 min1=w1;
		  max1=b1;		
	}
	
	for(i=min1+1;i<max1;i++)
	{
		if(rbq[i][0]!=-1)
		   return false;
	}
	
	return true;
}
int main()
{
int n;
long long int wx,wy;
cin>>n;
cin>>wx;
cin>>wy;
memset(rbq,-1,sizeof(rbq));
for(i=0;i<n;i++)
{
	char c;
	cin>>c;
	if(c=='R')
	rbq[i][0]=0;
	else if(c=='B')
	rbq[i][0]=1;
	else
	rbq[i][0]=2;
	cin>>rbq[i][1];
	cin>>rbq[i][2];
	
}

int falss=0;
for(i=0;i<n;i++)
{
	if(rbq[i][0]==0)
	{
		if((wx-rbq[i][1])==(wy-rbq[i][2]))
		{
			if(!find_any_r(wx,wy,rbq[i][1],rbq[i][2]))
			{
				cout<<"yes"<<endl;
				flass=1;
				break;
			}
		}						
	}
	if(rbq[i][0]==1)
	{
		if((wx==rbq[i][1] || wy==rbq[i][2])
		{
			if(!find_any_b(wx,wy,rbq[i][1],rbq[i][2]))
			{
				cout<<"yes"<<endl;
				flass=1;
				break;
			}
		}						
	}
	  if(rbq[i][0]==2)
	{
		if((wx==rbq[i][1] || wy==rbq[i][2] ) || (wx-rbq[i][1])==(wy-rbq[i][2]) )
		{
		if((wx==rbq[i][1] || wy==rbq[i][2])
		{
			if(!find_any_b())
			{
				cout<<"yes"<<endl;
				flass=1;
				break;
			}
		}
		else
		{
	    	if(!find_any_r())
			{
				cout<<"yes"<<endl;
				flass=1;
				break;
			}
			
		}
		
		
		}						
	}
	   
}





	return 0;	
	
}
