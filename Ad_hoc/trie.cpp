//
// Created by Sandeep on 9/18/2018.
//
#include <bits/stdc++.h>
using namespace std;

class node{

 private:
  int val;
  node* nxt[26];

 public:

  node();

  ~node();

  void init();

  void insert(string );

  node* lookup(string s, int& );

  bool search(string s);
};



node::node(){

  this->val=0;
  for(int i=0;i<26;i++)
    this->nxt[i]=NULL;
}


node::~node(){
  cout<<" destrcutor is called "<<endl;
}


node* node::lookup(string s, int& pos){

  node* itr=this;

  int i;
  for(i=0;i<(int)s.size();i++){

    if(itr->nxt[s[i]-'a']!=NULL)
      itr=itr->nxt[s[i]-'a'];
    else
      break;
  }

  pos=i;
  return itr;
}

void node::insert(string s){

  int pos=0;

  node* itr = lookup(s,pos);

  for(int i=pos;i<(int)s.size();i++){
    node* temp = new node();
    itr->nxt[s[i]-'a']=temp;
    itr=itr->nxt[s[i]-'a'];
  }

}

bool node::search(string s){
  int pos=0;
  lookup(s, pos);
  return ((int)s.size()==pos);
}


int main(){

  string keys[] = {"the", "a", "there",
                   "answer", "any", "by",
                   "bye", "their" };

  node* vl = new node();

  int n = sizeof(keys)/sizeof(keys[0]);
  cout<<" the size of the keys are "<<sizeof(keys)<<" "<<sizeof(keys[1])<<endl;

  for(int i=0;i<n;i++){
    vl->insert(keys[i]);
  }

  string s;

  while(cin>>s){
    cout<<vl->search(s)<<endl;
  }

  return 0;

}

