//
// Created by Sandeep on 1/9/2018.
//
#include <bits/stdc++.h>
using namespace std;

vector <int> balancedOrNot(vector <string> expressions, vector <int> maxReplacements) {

    vector <int> res;
    int i,j;
    for( i=0;i<expressions.size();i++){
        stack<char> vals;
        for(j=0;j<expressions[i].size();j++){
           if( expressions[i][j]=='<')
               vals.push('<');
            else if(expressions[i][j]=='>'){
                if(!vals.empty()){
                    char topelem = vals.top();
                    if(topelem=='<')
                        vals.pop();
                    else
                        vals.push('>');
                }
                else
                    vals.push('>');
            }
        }
        if(vals.empty()){
            res.push_back(1);
            continue;
        }
        else{
            int cnt=0;
            int leftSymbolCount=0;
            while(!vals.empty()){
                char topelem= vals.top();
                 vals.pop();
                if(topelem=='>')
                    cnt++;
                if(topelem=='<'){
                    leftSymbolCount++;
                    break;
                }

            }
            if(leftSymbolCount>0 || (cnt>maxReplacements[i]))
                res.push_back(0);
            else
                res.push_back(1);
        }
    }


}




int main(){


    return 0;
}
