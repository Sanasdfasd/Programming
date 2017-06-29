#include <bits/stdc++.h>

using namespace std;

long long int dp[500005][27];
long long int sol[500005][27];

int main()
{
    /*int n,k;
    cin>>n>>k;
    string s;
    int i,j,t,guess;
    cin>>s;
    for(i=0;i<n;i++)
    {
        for(j=0;j<k;j++)
            dp[i][j]=1000000000;
    }
    for(i=0;i<n;i++)
    {
        for(t=0;t<k;t++)
        {
           for(guess=0;guess<k;guess++)
           {
               if(t==k)continue;
               int val= ((char)(guess+'A'))==(s[i]);
               dp[i][guess]= min( dp[i][guess], dp[i][t]+val);
           }
        }
    }
   long long int mi=1000000000;
    for(i=0;i<k;i++)
        mi=min(mi,dp[n-1][i]);
    cout<<mi<<endl;*/

    return 0;
}