#include <map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include<string>
#include<fstream>
#include<sstream>
#include <algorithm>
#include <memory.h>
#include <math.h>
#include <stdlib.h>     
#include <time.h>  
#include <stddef.h>
using namespace std;
/* Head ends here */
long long int factorial[10000];
long long int fn[10000][10000];
  	long long int m,n;
long long int _factorial(long long int s)
{
	long long int i;
	factorial[0]=1;
	for(i=1;i<=s;i++)
	{
		factorial[i]=i*factorial[i-1];
		
	}
	return factorial[s];
}
long long int solve_problem(long long int count_m,long long int count_n,long long int prev_m,long long int prev_n,int b)
{
	if(prev_m>prev_n && prev_m==1)
	{
		return 1;
	}
	if(prev_n>=prev_m && b!=0)
	  return 0;
	else if( fn[count_m][count_n]!=0)
	{
		return fn[count_m][count_n];
	}
    long long int i,j,t_count=0;
	if((count_m)-(count_n)>1)
    	{
    		t_count=t_count+(count_n)*solve_problem(count_m,count_n-1,prev_m,prev_n+1,1);
    		t_count=t_count+(count_m)*solve_problem(count_m-1,count_n,prev_m+1,prev_n,1);
		}
		else if(((count_m)-(count_n)<=1))
		{
			t_count=t_count+((count_m)*solve_problem(count_m-1,count_n,prev_m+1,prev_n,1));
		}
		fn[count_m][count_n]=t_count;
		return t_count;

}

int main() {
  
  int t_cases;
  cin>>t_cases;
  int p=0;
  while(p<t_cases)
  {

  	cin>>m;
  	cin>>n;
  	memset(fn,0,sizeof(fn));
   long long int poss=solve_problem(m,n,0,0,0);
   long long int fact= _factorial(m+n);
   double possibl=poss;
   doublefactor=fact;
   //cout<<"factorial is "<<fact<<endl;
   //cout<<"possibilites"<<poss<<endl;
   double res=possibl/factor;
   cout<<"Case #"<<p+1<<":"<<" "<<res<<endl;  
 p++;
  }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}

