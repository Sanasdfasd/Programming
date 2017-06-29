#include <bits/stdc++.h>

using namespace std;

int dp[505][505];

int main()
{
    int n;
    cin>>n;
    int ar[n+5];
    int i,j,k;
    for(i=0;i<n;i++)
        cin>>ar[i];
    memset(dp,0,sizeof(dp));
    for(j=0;j<n;j++)
    {
    for(i=n-1;i>=0;i--)
    {
            if(i>j) continue;
            if(i==j){dp[i][j]=1; continue;}
            if(ar[i]==ar[j] && (j-i+1)==2)
                dp[i][j]=1;
            if(ar[i]!=ar[j] && (j-i+1)==2)
                dp[i][j]=2;
            if((j-i+1)>2 )
            {
                dp[i][j]= 1+dp[i+1][j];
                if(ar[i]==ar[j])
                    dp[i][j]=min(dp[i][j], dp[i+1][j-1]);
                dp[i][j]=min(dp[i][j],1+dp[i][j-1]);
                for(k=i+1;k<j;k++)
                    dp[i][j]= min(dp[i][j], (dp[i][k]+dp[k+1][j]));
            }
        }
    }

cout<<dp[0][n-1]<<endl;

    return 0;
}