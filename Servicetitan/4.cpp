//
// Created by Sandeep on 1/9/2018.
//
#include <bits/stdc++.h>
using namespace std;

long kSub(int k, vector <int> nums) {
long long int res=0;
    long long int curdp[k+1];
    long long int prevdp[k+1];
    int i,j;
    for(j=0;j<k;j++){
        curdp[j]=0;
        prevdp[j]=0;
    }
    for(i=0;i<nums.size();i++){
        curdp[nums[i]%k]+=1;
        for(j=0;j<k;j++){
           curdp[(i+nums[j])%k]+=prevdp[j];
        }
        for(j=0;j<k;j++){
            prevdp[j]=curdp[j];
            curdp[j]=0;
        }
        res+=curdp[0];
    }

}


int main(){


    return 0;
}
