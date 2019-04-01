#include <bits/stdc++.h>
using namespace std;
int dp[3005][3005]={};
class Solution {
  bool solve(int s_index,int p_index, string s, string p){

    if(s_index==s.size() && p_index==p.size())
      return true;
    if(p_index==p.size()-1 && s_index==s.size() && p[p_index]=='*')
      return true;

    if(s_index==s.size() || p_index==p.size())
      return false;
    if(dp[s_index][p_index]!=0){
      if(dp[s_index][p_index]==1)
        return false;
      else
        return true;
    }

    bool ans=false;

    if(p[p_index]=='?'){
      ans=ans|solve(s_index+1,p_index+1,s,p);
    }
    else if(p[p_index]=='*'){
      ans=ans|solve(s_index,p_index+1,s,p);
      ans= ans| solve(s_index+1,p_index,s,p);
    }
    else{
      ans=(s[s_index]==p[p_index])&solve(s_index+1,p_index+1,s,p);
    }
    if(ans)
      dp[s_index][p_index]=2;
    else
      dp[s_index][p_index]=1;

    return ans;

  }

 public:
  bool isMatch(string s, string p) {
    return solve(0,0,s,p);
  }
};

string stringToString(string input) {
  assert(input.length() >= 2);
  string result;
  for (int i = 1; i < input.length() -1; i++) {
    char currentChar = input[i];
    if (input[i] == '\\') {
      char nextChar = input[i+1];
      switch (nextChar) {
        case '\"': result.push_back('\"'); break;
        case '/' : result.push_back('/'); break;
        case '\\': result.push_back('\\'); break;
        case 'b' : result.push_back('\b'); break;
        case 'f' : result.push_back('\f'); break;
        case 'r' : result.push_back('\r'); break;
        case 'n' : result.push_back('\n'); break;
        case 't' : result.push_back('\t'); break;
        default: break;
      }
      i++;
    } else {
      result.push_back(currentChar);
    }
  }
  return result;
}

string boolToString(bool input) {
  return input ? "True" : "False";
}

int main() {
  string line;
  while (getline(cin, line)) {
    string s = stringToString(line);
    getline(cin, line);
    string p = stringToString(line);

    bool ret = Solution().isMatch(s, p);

    string out = boolToString(ret);
    cout << out << endl;
  }
  return 0;
}