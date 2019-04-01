//
// Created by Sandeep on 2/18/2019.
//
#include <bits/stdc++.h>
using namespace std;

class Interval{
 private:
  int st, end;
  char c;
 public:
  Interval(){

  }
  Interval(int st, int end, char c){
    this->st=st;
    this->end=end;
    this->c=c;
  }
  void replace( string& s, vector<Interval*>& intervals){
    int j;
    for(int i=0;i<s.size();i++){
      for(j=intervals.size()-1;j>=0;j--) {
        if( i>=intervals[j]->st && i<=intervals[j]->end){
          break;
        }
      }
      if(j!=-1) {
        s[i]=intervals[j]->c;
      }
    }
    //Time complexity  O(n^2)
    // Space complexity  is O(1)

  }

};



int main(){
  string inp="qwertyt";
  vector<Interval*> in;
  Interval sol;
  in.push_back( new Interval(0,3,'b'));
  in.push_back( new Interval(2,4,'i'));
  in.push_back( new Interval(1,5,'s'));
  in.push_back( new Interval(2,3,'u'));
  sol.replace(inp,in);
  cout<<" The replaced string is "<<inp<<endl;



  return 0;
}

