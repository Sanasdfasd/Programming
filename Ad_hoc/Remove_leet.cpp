//
// Created by Sandeep on 9/13/2018.
//
#include <bits/stdc++.h>
using namespace std;
class Solution {
  bool vls[105];

 public:
  int removeBoxes(vector<int>& boxes){
    for(int i=0;i<105;i++)vls[i]=true;
    return dfs(boxes);
  }

  int dfs(vector<int>& boxes){
    int res=0;
    int out_cnt=0,in_cnt=0;

    while(out_cnt<boxes.size()){
      if( vls[out_cnt] ==false) { out_cnt++;continue;}

      in_cnt=out_cnt;

      int cur_val=0;

      vector<int> rev;

      while(in_cnt<boxes.size()){
        if(vls[in_cnt]==false) { in_cnt++;continue;}
        if(boxes[out_cnt]==boxes[in_cnt]) { rev.push_back(in_cnt);cur_val++; vls[in_cnt]=false;}
        if(boxes[out_cnt]!=boxes[in_cnt]) break;
        in_cnt++;
      }

      cur_val=cur_val*cur_val;
      if(cur_val>0) cur_val+=dfs(boxes);
      res =max(res, cur_val);

      for(int i=0;i<rev.size();i++) vls[rev[i]]=true;
      out_cnt=in_cnt;
    }

    return res;
  }
};

void trimLeftTrailingSpaces(string &input) {
  input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
    return !isspace(ch);
  }));
}

void trimRightTrailingSpaces(string &input) {
  input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
    return !isspace(ch);
  }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
  vector<int> output;
  trimLeftTrailingSpaces(input);
  trimRightTrailingSpaces(input);
  input = input.substr(1, input.length() - 2);
  stringstream ss;
  ss.str(input);
  string item;
  char delim = ',';
  while (getline(ss, item, delim)) {
    output.push_back(stoi(item));
  }
  return output;
}

int main() {
  string line;
  getline(cin, line);
    vector<int> boxes = stringToIntegerVector(line);

    int ret = Solution().removeBoxes(boxes);

    string out = to_string(ret);
    cout << out << endl;

  return 0;
}

