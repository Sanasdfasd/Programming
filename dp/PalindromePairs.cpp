//
// Created by Sandeep on 10/30/2017.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    cin >> str;
    bool pali[str.size()][str.size()];
    int i, j;
    for (j = 0; j < str.size(); j++) {
        for (i = 0; i < str.size(); i++) {
            pali[i][j] = false;
            if (i > j)
                continue;
            if (i == j)
                pali[i][j] = true;
            else {
                if((i+1)<=(j-1))
                pali[i][j] = (pali[i + 1][j - 1] && (str[i] == str[j]));
                else
                    pali[i][j]= (str[i] == str[j]);
            }
        }
    }
    long long int sum[str.size()];
   long long  int dp[str.size()];
    for (i = 0; i < str.size(); i++) {
        sum[i] = 0;
        dp[i] = 0;
    }
    sum[0]=1;
    for (i = 1; i<str.size(); i++) {
        sum[i]+=sum[i-1];
        dp[i]+=dp[i-1];
        for (j = i;j>0; j--) {
            sum[i]+= (long long int) (pali[j][i]);
            dp[i] +=(sum[j - 1] *pali[j][i]);
        }
        sum[i]+=(long long int) (pali[j][i]);
    }
    cout<<dp[str.size()-1]<<endl;
    return 0;
}

