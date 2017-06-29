#include <iostream>
#include <memory.h>
#include <fstream>
#include <cstring>
#include <map>
#include <dirent.h>
#include <utility>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <functional>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <string.h>
#include <string>
#include <cmath>
#include <limits>
using namespace std;

int main()
{
int n,l;
cin>>n>>l;
int i,j,a;
vector<int> as;
for(i=0;i<n;i++)
{   cin>>a;
	as.push_back(a);
}
sort(as.begin(), as.end());
int res= 2* max(as[0], l-as[n-1]);
for(i=1;i<n;i++)
	res= max(res, (as[i]-as[i-1]));
printf("%.10f\n", res/2.);


	return 0;
}
