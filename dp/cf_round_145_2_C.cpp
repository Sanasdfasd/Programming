//
// Created by Sandeep on 11/2/2017.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int i, j;
    int neg_count[n+5];
    int pos_count[n+5];
    for (i = 0; i < n; i++) {
        int temp=0;
        cin >> temp;
        if (temp < 0) {
            if(i==0) {
                neg_count[i] = 1;
                pos_count[i]=0;
            }
            else {
                neg_count[i] = neg_count[i - 1] + 1;
                pos_count[i]=pos_count[i-1];
            }
        }
        else if (temp > 0) {
            if(i==0) {
                neg_count[i] = 0;
                pos_count[i]= 1;
            }
            else {
                neg_count[i] = neg_count[i - 1];
                pos_count[i]= pos_count[i - 1] + 1;
            }
        }
        else{
            if(i==0) {
                neg_count[i] = 0;
                pos_count[i] = 0;
            }
            else {
                neg_count[i] = neg_count[i - 1];
                pos_count[i]=pos_count[i-1];
            }
        }
    }
    int ans = INT_MAX;
    for (i = 0; i < n-1; i++) {
        int leftSide=(i+1)-neg_count[i];
        ans=min( ans, leftSide+(n-1-i-(pos_count[n-1]-pos_count[i])));
    }
    cout<<ans<<endl;
    return 0;
}

