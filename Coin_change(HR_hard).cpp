#include<stdio.h>
#include<iostream>
#include<memory.h>
//
#include<cstdlib>
#include<string>
//#include<cstring>
using namespace std;
long long int Arr[300][300],c[300],n,m;
long long int compute(int coeff, int b,int size)
{
	if(b==0)
	{
		return 1;
	}
	else if(size==0|| coeff >=m)
	{
		return 0;
	}
	if(Arr[coeff][b]!=-1)
	{
		return Arr[coeff][b];
	}
	int i;
	long long int res=0;
	for(i=0;i<=b;i++)
	{
		int temp=(c[coeff]*i);
		if(temp<=b)
		{
			res =res+compute(coeff+1,b-temp,size-1);
		}
		else
		{
			break;
		}
	}
	Arr[coeff][b]=res;
	return res;
}
int main()
{
	int i;
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>c[i];
	}
	memset(Arr, -1, sizeof(Arr));
	long long int res=compute( 0,n,m);
	cout<<res<<endl;
	return 0;
}
