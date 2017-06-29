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
#include <memory.h>
#include <stdio.h>

using namespace std;


int main(){

int t_cases;
cin>>t_cases;
while(t_cases--)
{
	char str[105];
	scanf("%s",str);
	long long int m,n;
	cin>>m;
	cin>>n;
	long long int i=0,length=0;
	long long int blue_count[100];
	memset(blue_count,0,sizeof(blue_count));
	while(str[i]!='\0')
	{
		if(str[i]=='B')
		{
		 if(i!=0)
		 blue_count[i]=blue_count[i-1]+1;
		 if(i==0)
		 blue_count[i]=1;
     	}
		 i=i+1;
		 length=length+1;
	}
cout<<"lenght sis "<<length<<endl;
  cout<<"Case #"<<t_cases<<": "<<blue_count[(m%length)]-blue_count[(n%length)]<<endl;	
}
    return 0;
}

