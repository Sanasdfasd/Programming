//
// Created by Avula, Sandeep on 3/4/18.
//

#include <bits/stdc++.h>
using namespace std;

map<int, int> cnt;

int compute(int v1,int v2){
    if(v1<=cnt[v2])
        return 0;
    else
        return (v1 - cnt[v2]);

}
int main(){
    int n;
    cin>>n;
    int vls[n+5];
    set<int> ls;
    long long int sum=0;
    int mx=INT_MIN, mi=INT_MAX;
    for (int i = 0; i <n ; ++i) {
        cin>>vls[i];
        cnt[vls[i]]++;
        ls.insert(vls[i]);
        mx=max(mx,vls[i]);
        mi=min(mi, vls[i]);
        sum=sum+(long long int )vls[i];
    }
    if((mx-mi)<=1){
        cout<<n<<endl;
        for(int i=0;i<n;i++){
            cout<<vls[i]<<" ";
        }
        cout<<endl;
        return 0;
    }
    vector<int> vs(ls.begin(),ls.end());
    sort(vs.begin(),vs.end());
     int changes =0;
    if(cnt.size()<=2) {
        vs[2]=vs[1];
        vs[1]=vs[2]-1;
    }
     int c0=cnt[vs[0]],c1=cnt[vs[1]],c2=cnt[vs[2]];
     for(long long int i=0;i<=n;i++){
         long long int leftsum=sum-(i*(long long int)vs[0]);
         long long int minsum=((n-i)* (long long int )vs[1]);
         long long int maxsum= ((n-i)* (long long int )vs[2]);
         if(leftsum>=minsum && leftsum<=maxsum){
              int tempchanges=(compute(i,vs[0])+ compute((leftsum-minsum),vs[2])+ compute((n-(leftsum-minsum+i)), vs[1]));
             if(tempchanges>changes){
                 changes=tempchanges;
                  c0=i;
                 c2=leftsum-minsum;
                 c1=n-(c0+c2);
             }
         }
     }
    cout<<(n-changes)<<endl;

    for(int i=0;i<c0;i++)
        cout<<vs[0]<<" ";
    for(int i=0;i<c1;i++)
        cout<<vs[1]<<" ";
    for(int i=0;i<c2;i++)
        cout<<vs[2]<<" ";
    cout<<endl;

    return 0;

}