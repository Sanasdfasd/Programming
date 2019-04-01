//
// Created by Sandeep on 12/24/2018.
//
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
       int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
   };
class Solution {

 public: void solve(vector<int> nums, int low, int hi, TreeNode root){
    if(low<=hi){
      int mid= (low+hi)/2;
      root.val=nums[mid];
      cout<<" the root val is "<<root.val<<endl;
      solve(nums, low,mid-1, root.(*left);
      solve(nums, mid+1, hi, root->right);
    }
  }

 public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    TreeNode* root;
    solve(nums, 0,nums.size()-1,root);
    return root;
  }
};

int main(){

  vector<int> nums;
  nums.push_back(1);
  Solution* s1= new Solution();
  TreeNode* root=s1->sortedArrayToBST(nums);
  cout<<" the root isssii "<<root->val<<endl;

  return 0;
}

