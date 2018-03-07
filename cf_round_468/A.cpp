//
// Created by Avula, Sandeep on 3/4/18.
//

#include <bits/stdc++.h>
using namespace std;

int main(){
int a,b;
    cin>>a>>b;
    if(a==b) {
        cout << 0 << endl;
        return 0;
    }
    if(a>b){int tt=a;
     a=b; b=tt;}

    long long int temp=(b-a)-((b-a)/2);
    long long int val=(temp*(temp+1))/2;
    if((b-a)%2==0){
        cout<<(val +val) <<endl;
        return 0;
    }
    else{
        long long int val1=((temp-1)*(temp))/2;
        cout<<(val+val1)<<endl;
    }

    return 0;

}