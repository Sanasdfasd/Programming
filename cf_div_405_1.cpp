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
using namespace std;

int main() {

    int a,b;
    cin>>a>>b;
    int i;
    for(i=1;i<10000000;i++)
    {
        a=(a*3);
        b=(b*2);
        if(a>b)
            break;
    }
    cout<<i<<endl;

    return 0;
}