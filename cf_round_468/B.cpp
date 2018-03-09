//
// Created by Avula, Sandeep on 3/4/18.
//

#include <bits/stdc++.h>
using namespace std;
int rounds;

vector<int> vls;
int sts;
void rcur(vector<int> vls,int a,int b){
    vector<int> ps;
   rounds++;
    int i=0;
    int found=0;
    int cs=0;
    while(i<vls.size()){
        if(vls[i]==a && vls[i+1]==b) {
            found=1;
        }
        else if(vls[i]==a || vls[i+1]==a) {
            ps.push_back(a);
            cs++;
        }
        else if( vls[i]==b || vls[i+1]==b) {
            ps.push_back(b);
            cs++;
        }
        else {
            ps.push_back(vls[i]);
            cs++;
        }

        i=i+2;
}
   if(found==1){
       if(cs==0)
       sts=1;
       return;
   }
    rcur(ps,a,b);

}


int main(){
    rounds=0;
    int n,a,b;
    cin>>n>>a>>b;
    if(a>b){
     int tempa=a;
        a=b;
        b=tempa;
    }
    for(int i=0;i<n;i++)
     vls.push_back(i+1);

   rcur(vls,a,b);
    if(sts==1)
        cout<<"Final!"<<endl;
    else
   cout<<rounds<<endl;
    return 0;

}