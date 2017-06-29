#include <bits/stdc++.h>

using namespace std;

long long int dp[2][5005];
long long int prevs[5005];
long long int mod= 1000000007;
int ret( int a, int b)
{
    if(a<b)
        return 1;
    else
        return 0;
}

int main()
{
    long long int n,a,b,k;
    cin>>n>>a>>b>>k;
    memset(dp,0,sizeof(dp));
    memset(prevs,0,sizeof(prevs));
    long long int i,j,t,current_floor;
    for(i=1;i<=n;i++)
    {
        int val= ret(std::abs(a-i), std::abs(a-b));
        if(i==a || i==b)
        	val=0;
        dp[0][i]=(dp[0][i-1]+val)%(mod);
        prevs[i]=val%(mod);
    }

    for(i=1;i<k;i++)
    {
    	int at= (i &1);

        for(current_floor=1;current_floor<=n;current_floor++)
        {
            if(current_floor==b)
            {
                dp[at][current_floor]+=dp[at][current_floor-1];
                dp[at][current_floor]=dp[at][current_floor]%(mod);
                prevs[current_floor]=0;
            }

            else if(current_floor<b)
            {
                long long int tt= (b+current_floor+1)/2;
                long long  int val= dp[(at^1)][tt-1]-prevs[current_floor]+mod;
                val=val%(mod);
                prevs[current_floor]=val%(mod);
                dp[at][current_floor]=(dp[at][current_floor-1]+val+mod)%mod;

            } else{
                long long int tt= (b+current_floor)/2;
                long long  int val= dp[(at^1)][n]-prevs[current_floor]-dp[(at^1)][tt]+mod;
                val=val%(mod);
                prevs[current_floor]=val%(mod);
                dp[at][current_floor]=(dp[at][current_floor-1]+val+mod)%mod;
            }
        }
           for(current_floor=1;current_floor<=n;current_floor++)
    		dp[at^1][current_floor]=0;
    }

    cout<<dp[((k-1)&1)][n]%(mod)<<endl;
    return 0;
}