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
int hack[2005][2005];
int orginal_hack[2005][2005];
int hack1[2005][2005];
int dp[7];
int ls[3];
    int n,q;
//rotate 90 degress
int rotate_90()
{
 int i,j;
 for(i=0;i<n;i++)
 {
    for(j=0;j<n;j++)
    {
        hack[i][j]=hack1[n-j-1][i];
    }
 }
 int count=0;
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        if(orginal_hack[i][j]!=hack[i][j])
            count=count+1;
        hack1[i][j]=hack[i][j];
    }
}
return count;

}

int main(){

    cin >> n >> q;
    memset(hack,0,sizeof(hack));
    memset(orginal_hack,0,sizeof(orginal_hack));
    int i,j;
    dp[0]=0,dp[1]=0,dp[2]=1,dp[3]=1,dp[4]=1,dp[5]=0,dp[6]=1;
    ls[0]=1,ls[1]=0,ls[2]=1;
    for(i=0;i<n;i++)
     {
        for(j=0;j<n;j++)
        {
            long long int cal=((i+1)*(j+1));
            cal=cal*cal;
            if(cal>=4)
            {
             cal=cal-4;
              hack[i][j]=dp[cal%7];
            }
            else
            {
                hack[i][j]=ls[cal-1];
            }
        }
    }
    
        for(i=0;i<n;i++)
      {
        for(j=0;j<n;j++)
        {  
           orginal_hack[i][j]=hack[i][j]; 
           hack1[i][j]=hack[i][j];
      }

   }
int c9,c18,c27;
      c9=rotate_90();
      c18=rotate_90();
      c27=rotate_90();

    for(int a0 = 0; a0 < q; a0++){
        int angle;
        cin >> angle;
        int val=angle%360;
        if(val==0)
        {
            cout<<0<<endl;
        }
        else if(val==90)
        {
         cout<<c9<<endl;
        }
        else if(val==180)
            cout<<c18<<endl;
        else if(val==270)
            cout<<c27<<endl;

        // your code goes here
    }
    return 0;
}
