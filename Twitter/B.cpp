//
// Created by Sandeep on 8/4/2018.
//
#include <bits/stdc++.h>
using namespace std;
void textQueries(vector<string> sentences, vector<string> queries) {
  map<string, map<int, int> >ind;
  for(int i=0;i<sentences.size();i++){
    istringstream buf(sentences[i]);
    for(string word; buf >> word; ) {
      map<int, int> cnt;
      ind[word][i]+=1;
    }
  }
  for (int i = 0; i < queries.size(); ++i) {
    vector<string> wds;
    istringstream buf(sentences[i]);
    for(string word; buf >> word; ) {
     wds.push_back(word);
    }
    int mi_index=100000000;
    string st;
    int flg=0;
    vector<pair<int, int>> vls;
    for (int j = 0; j <wds.size() ; ++j) {
      if(ind[wds[j]].size()==0){
        flg=1;
        break;
      }
      if(mi_index>ind[wds[j]].size()){
        mi_index=ind[wds[j]].size();
        st=wds[j];
      }
    }
     if(flg==1)
       cout<<-1<<endl;
     else{
       vector<pair<int, int>> fi;
       for (map<int, int>::iterator it= ind[st].begin(); it!=ind[st].end();it++) {
         int cnt_mi=9000000;
         for (int j = 0; j <wds.size() ; ++j) {
            if(ind[wds[j]][it->first]!=ind[wds[j]].end()){
              cnt_mi=min(cnt_mi, ind[wds[j]][it->first]);
            }
           else
              break;
         }
         if(cnt_mi!=9000000)
           fi.push_back({it->first, cnt_mi});
       }
       if(fi.size()==0){
         cout<<-1<<endl;
         continue;
       }
       for (int k = 0; k <fi.size() ; ++k) {
         int tt=fi[k].second;
         while(tt--){
           cout<<fi[k].first<<" ";
         }
       }
       cout<<endl;
     }

    }
  

}
int main(){

  return 0;
}
