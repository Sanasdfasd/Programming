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
using namespace std;

unsigned long long int grayToBinary(unsigned long long int num)
{
    unsigned  long long int mask;
    for (mask = num >> 1; mask != 0; mask = mask >> 1)
    {
        num = num ^ mask;
    }
    return num;
}


int main()
{

long long int t;
cin>>t;
while(t--)
{
  long long int n,k;
  cin>>n>>k;
  //k++;
 long long int val= k ^(k>>1);

cout<<val<<endl;

}


return 0;
}