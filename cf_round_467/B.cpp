//
// Created by Avula, Sandeep on 2/25/18.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t,y;
    cin>>t>>y;
    bool prime[666666];
    memset(prime, true, sizeof(prime));
    for (int p = 2; p <400000; p++) {
        if (prime[p] == true) {
            for (int i = p * 2; i <= 400000; i += p) {
                prime[i] = false;
            }
        }
    }
    int mx=-1;
    for (int j = y; j>=t; --j) {
        int td=0;
        for (int i = 2; i <400000 ; ++i) {
            if(i>t)
                break;
            if(prime[i]){
                if((j%i)==0) {
                    td = 1;
                    break;
                }
            }
        }
        if(td==0){
            mx=j;
            break;
        }
    }

    cout<<mx<<endl;
    return 0;
}