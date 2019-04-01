//
// Created by Sandeep on 11/1/2018.
//
#include<bits/stdc++.h>
using namespace std;
int ind[prices.size()-1]
stack<int> st;

for(int i=prices.size()-1; i>=0; --i) {
while(!st.empty() && stack.peek() > prices[i])
stack.pop();
//now the top of the stack is the result for index i
if(!st.empty())
result[i] = st.peek();
//push the new element on the stack. The stack will still contain all relevant
//elements in decreasing order from top to bottom
st.push(prices[i]);
}
return result;



int main(){


  return 0;
}
