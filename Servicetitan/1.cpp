//
// Created by Sandeep on 1/9/2018.
//
#include <bits/stdc++.h>

using namespace std;

string canReach(int x1, int y1, int x2, int y2) {

    if (x1 == x2 && y1 == y2)
        return "Yes";
    else if (x1 > (x2) || (y1 > y2))
        return "No";
    else {
        bool res = false;
        //Type 1
         if( canReach(x1+y1,y1,x2,y2)=="Yes")
             res=res | true;
        //Type 2
        if( canReach(x1,x1+y1,x2,y2)=="Yes")
            res=res | true;
        if(res)
            return "Yes";
        else
            return "No";
    }

}


int main() {


    return 0;
}
