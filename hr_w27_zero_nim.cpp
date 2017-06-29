#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int g;
    cin >> g;
    for(int a0 = 0; a0 < g; a0++){
        int n;
        cin >> n;
        vector<int> p(n);
        for(int p_i = 0;p_i < n;p_i++){
           cin >> p[p_i];
        }
        int i;
        for(i=0;i<n;i++)
        {
          if(p[i]!=0)
            p[i]=p[i]+1;
        }
       long long int vals=0;
       for(i=0;i<n;i++)
       {
        vals=vals^p[i];
       }
      if(vals!=0)
        cout<<"W"<<endl;
      else
        cout<<"L"<<endl;
        
    }
    return 0;
}
