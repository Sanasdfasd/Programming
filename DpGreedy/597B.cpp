#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    vector<pair<int,int> > inp(n);
    for(int i=0;i<n;i++){
    	cin>>inp[i].first;
    	cin>>inp[i].second;
    }

    sort( inp.begin(),inp.end(),[](pair<int,int> fst, pair<int,int> sec){
             return fst.second < sec.second;
    });
    int ans=1;
    int prev_end=inp[0].second;
    for(int i=1;i<inp.size();i++){
    	if( inp[i].first>prev_end){
    		ans++;
    		prev_end=inp[i].second;
    	}
    }

   cout<<ans<<endl;
	return 0;
}