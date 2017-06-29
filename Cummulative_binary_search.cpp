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
//#include <unordered_map>

using namespace std;

int find_max(int a,int b)
 {
 if(a>=b)
     return a;
    else
        return b;   
}
int maxLength(vector < int > a, int k) {
       int i,j;
    int a_size=a.size();
    int c_sum[a_size+5];
    memset(c_sum,0,sizeof(c_sum));
 c_sum[0]=a[0];
 cout<<c_sum[0]<<endl;
    for(i=1;i<a_size;i++)
   {
 	 c_sum[i]=a[i]+c_sum[i-1];
 	 cout<<c_sum[i]<<endl;
   }
   int g_max=0;
    for(i=0;i<a_size;i++)
    	
     {  
     	if(a[i]<=k)
     	{
          int l=0,h=i;
          int ind=h;
          while(l<=h)
         {
       	 int mid=(l+h)/2;
       	 int temp=c_sum[i]-c_sum[mid]+a[mid];
       	 cout<<"l : "<<l<<" h : "<<h<<endl;
       	 cout<<"mid is "<<mid<<endl;
       	 cout<<"the temp sum is "<<temp<<endl;
         if(temp==k)
         {
         	cout<<"EQUAL---- "<<ind<<endl;
         	ind=mid;
           break;
         }
         else if(temp<k)
         {
         	cout<<"setting the lower index "<<h<<endl;
         	ind=mid;
            h=mid-1;
         }
        else 
        {
        	cout<<"setting the upper index "<<h<<endl;
            l=mid+1;
        }

       }
       //ind=(l+h)/2;
       cout<<"(i-ind+1)  "<<(i-ind+1)<<endl;   
       if(g_max<(i-ind+1))
       {
       	 g_max=(i-ind+1);
       	 cout<<" i for it is  "<<i<<"  g_max is   "<<g_max<<endl;
       }
      }
     } 
     cout<<"g_max is "<<g_max<<endl;
  return g_max;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    int res;
    
    int _a_size = 0;
    cin >> _a_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _a.push_back(_a_item);
    }
    
    int _k;
    cin >> _k;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    res = maxLength(_a, _k);
    fout << res << endl;
    
    fout.close();
    return 0;
}
