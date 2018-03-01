//
// Created by Sandeep on 1/9/2018.
//

#include <bits/stdc++.h>
using namespace std;

bool checkPreOrder(vector<int> pre) {
    stack<int> s;
    int root = INT_MIN;
    for (int i = 0; i < pre.size(); i++) {
        if (pre[i] < root)
            return false;
        while (!s.empty() && s.top() < pre[i]) {
                root = s.top();
                s.pop();
        }
        s.push(pre[i]);
    }
    return true;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int q;
    cin>>q;
    while(q--){
        int n;
        vector<int>vals;
        cin>>n;
        int a;
        for(int i=0;i<n;i++){
            cin>>a;
            vals.push_back(a);
        }
        if(checkPreOrder(vals))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}