
#include<bits/stdc++.h>
using namespace std;

class link{

 private:
  int data;
  link* next;
 public: static link* head;
 public:
  link( int );
  ~link();
  void insert(int v );
  void displaylist();
};

link* link::head=NULL;
link::link(int v){
  this->data=v;
  next=NULL;
}

link::~link(){
  cout<<" the distuctor is called "<<endl;
}
void link::insert( int val){
  if(head==NULL){
    head= new link(val);
  }
  else{
    link* cur=head;
    link* prev=NULL;
    while(cur!=NULL){
      prev=cur;
      cur=cur->next;
    }
    prev->next=new link(val);
  }
}

void link::displaylist(){
  cout<<"displaying the actual list "<<endl;
  link* cur=head;
  while(cur!=NULL){
    cout<<cur->data<<" ";
    cur=cur->next;
  }
}

int main(){
  link* c;
  for(int i=0;i<0;i++){
    c->insert(i);
  }

  c->displaylist();


  return 0;
}





