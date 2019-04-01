//
// Created by Sandeep on 9/18/2018
#include <bits/stdc++.h>

using namespace std;

class lst{

 private:
  int data;
  lst* next;

 public:
  static lst* head;
  void insert( int);
  void delet( int);
  void display();
};

lst* lst::head=NULL;

void lst::insert(int val){

  lst* temp= new lst();
  temp->data = val;
  temp->next =NULL;

  if(head==NULL){
    head = temp;
    temp->next = head;
  }

  else if(val<(head->data)){

    lst* iter = head;
    while(iter->next!= head) iter=iter->next;
    temp->next = head;
    iter->next = temp;
    head =temp;

  }

  else{

    lst* iter= head;
    lst* prev=head;
    while( (iter->data) <= val && (iter->next!=head)){
      prev=iter;
      iter=iter->next;
    }
    if(iter->data <=val){
      iter->next = temp;
      temp->next= head;
    }
    else{
      prev->next = temp;
      temp->next= iter;
    }

  }

}

void lst::delet(int val){

  if(head==NULL)
    return ;

  lst* iter = head;

  if(iter== iter->next && val == head->data){
    head=NULL;
    return ;
  }
  else{

    if((head->data) == val){
      while(iter->next!= head) iter=iter->next;
      head = head->next;
      iter->next =head;
    }
    else{
      lst* prev =head;
      lst* cur =head;
      while(cur->data != val && cur->next!=head ){
        prev = cur;
        cur=cur->next;
      }
      if(cur->data==val)
        prev->next = cur->next;
    }
  }
}

void lst::display(){

  if(head ==NULL)
    return;

  lst* iter=head;

  do{
    cout<<iter->data<<" ";
    iter=iter->next;
  }
  while(iter!=head);

  cout<<endl;

}


int main(){

  lst *list1 = NULL;
  int arr[] = {12, 56, 2, 11, 1, 90};
  for(int i=0;i<6;i++){

    list1->insert(arr[i]);
    list1->display();

  }

  srand ( time(NULL) );

  for(int i=0;i<20;i++){
    int ind = rand()%(20-i);
    cout<<" to be delelted value is "<<arr[ind]<<endl;
    list1->delet(arr[ind]);
    list1->display();
  }
  list1->display();


  return 0;
}