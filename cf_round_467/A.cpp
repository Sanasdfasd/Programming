//
// Created by Avula, Sandeep on 2/25/18.
//
#include <bits/stdc++.h>
using namespace std;

int main(){

    set<int> ms;
    int n,t;
    cin>>n;
    for (int i = 0; i <n ; ++i) {
        cin>>t;
        if(t!=0)
        ms.insert(t);
    }
    std::set<int>::reverse_iterator rit;
    int sz= ms.size();
    int cr=0;
    //cout<<sz<<endl;
    for(rit=ms.rbegin();rit!=ms.rend();rit++){
        int val =*rit;
        if( val > 0){
            break;
        }
        cr++;
    }

    cout<<(sz-cr)<<endl;
    return 0;
}
