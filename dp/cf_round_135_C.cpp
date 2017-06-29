#include <bits/stdc++.h>

using namespace std;

long long int dp[500005][27];
long long int sol[500005];

int main()
{
    int n,k;
    cin>>n>>k;
    string s;
    int i,j,t,guess,st;
    cin>>s;
    int temp=100000000;
    int prev=0;
    int best[2];
    memset(best, 0, sizeof(best));
    vector <  pair < int , int> > vs;
    for(j=0;j<k;j++) {
        int val = ((char) (j + 'A')) != (s[0]);
        dp[0][j]=val;
        vs.push_back(make_pair(val,j));
    }
    if(n>=2){
        sort(vs.begin(), vs.end());
        best[0]=vs[0].second;
        best[1]=vs[1].second;
    }
    vs.clear();
    for(i=1;i<n;i++)
        for(j=0;j<k;j++)
            dp[i][j]=100000000;
    int tts=0;
    for(i=1;i<n;i++)
    {
        vs.clear();
        int temp=100000000;
        int temp1=100000000;
        prev=0;
        for(tts=0;tts<2;tts++) {

            for (guess = 0; guess < k; guess++) {
                int val = ((char) (guess + 'A')) != (s[i]);
                if (guess == best[tts])continue;
                dp[i][guess] = min(dp[i][guess], dp[i - 1][best[tts]] + val);
            }
        }
        for(st=0;st<k;st++)
        {
          vs.push_back(make_pair(dp[i][st],st));
        }
        sort(vs.begin(), vs.end());
        best[0]=vs[0].second;
        best[1]=vs[1].second;

    }
    long long int mi=1000000000;
    for(i=0;i<k;i++) {
        if(mi>=dp[n-1][i])
        {
            sol[n-1]=i;
            mi= dp[n-1][i];
        }
        mi = min(mi, dp[n - 1][i]);
    }
    cout<<mi<<endl;
    for(i=n-2;i>=0;i--)
    {
        int temp=1000000000;
        for(st=0;st<k;st++)
        {    int val = ((char) (st + 'A')) != (s[i]);
            if(st==sol[i+1])continue;
            if(temp>=dp[i][st]+val)
            {
               sol[i]=st;
                temp=dp[i][st]+val;
            }
        }
    }

 for(i=0;i<n;i++) {
     char c= ((char)sol[i]+'A');
     cout <<c;
 }
 cout<<endl;


    return 0;
}