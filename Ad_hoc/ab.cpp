//
// Created by Sandeep on 9/1/2018.
//
#include <bits/stdc++.h>
using namespace std;
i    void connect(TreeLinkNode *root) {

  queue<pair<TreeLinkNode* , int> > q;

  q.push( make_pair( root, 0));

  while(!q.empty()){

    pair<TreeLinkNode* , int> tp = q.front();

    q.pop();

    if(!q.empty()  && q.front().second!=tp.second)
      tp.first->next = NULL;

    if(q.empty())
      tp.first->next= NULL;

    tp.first->next = q.front().first;
    if( tp.first->left !=NULL)
      q.push( make_pair(tp.first->left, tp.second+1));

    if( tp.first->right !=NULL)
      q.push( make_pair(tp.first->right, tp.second+1));

  }

}
int main()
{
  return 0;
}
