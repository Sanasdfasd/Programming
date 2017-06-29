#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
long long int a[3*100000],n,f[3*100000];
long long int max_contigous()
    {
    long long int max=0;
   long long int i;
    long long int count=0;
    for(i=0;i<n;i++)
        {
        count=count+a[i];
        if(count>=0)
        {
            if(max<count)
                max=count;
        }
        else
         count=0;
    }
    return max;
}
long long int max_non_contigous()
    {
    long long int i,count=0;
    for(i=0;i<n;i++)
        {   
        if(a[i]>0)
           count=count+a[i];
      }
    return count;
}
int main() {
    long long int t_cases;
  cin>>t_cases;
    while(t_cases-->0)
        {
        cin>>n;
        int i=0,j;
       long long int max=-100000;
       long long int val=-1;
        //cout<<"here"<<endl;
        while(i<n)
          {
            cin>>a[i];
            if(a[i]>0)
                val++;
            if(max<a[i])
                max=a[i];
            i++;
        }
        if(val == -1)
            cout<<max<<" "<<max<<endl;
        else
            {
            long long int val1=max_contigous();
           long long int val2= max_non_contigous();
           cout<<val1<<" " <<val2<<endl;
     
        }
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

