//
// Created by Sandeep on 9/26/2018.
//
#include <bits/stdc++.h>
using namespace std;
int dp[3005][3005]={};
class Solution {
  bool solve(int s_ind, int p_ind, string s, string p){

    if(s_ind==s.size() && p_ind==p.size())
      return true;
    if(s_ind==s.size()|| p_ind==p.size())
      return false;
    if(dp[s_ind][p_ind]!=0){
      if(dp[s_ind][p_ind]==1)
        return false;
      else
        return true;
    }


    bool ans=false;
    if(p[p_ind]>='a' && p[p_ind]<='z')
      ans=s[s_ind]==p[p_ind];

    if( ans || p[p_ind]=='?')
      ans =solve(s_ind+1,p_ind+1,s,p);

    if(p[p_ind]=='*')
    {
      for(int i=s_ind;i<=s.size();i++)
        ans=ans|solve(i,p_ind+1,s,p);
    }
    if(ans)
      dp[s_ind][p_ind]=2;
    else
      dp[s_ind][p_ind]=1;

    return ans;
  }

 public:
  bool isMatch(string s, string p) {
    for(int i=0;i<3005;i++)
      for(int j=0;j<3005;j++)
        dp[i][j]=0;

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
