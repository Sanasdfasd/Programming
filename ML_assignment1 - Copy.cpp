#include <cmath>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iostream>
#include<string>
#include<fstream>
#include<sstream>
#include <algorithm>
#include <memory.h>
#include <math.h>
int no_of_attr=0;//No of attributes

int training_data[10000][10000];
int row,columns; // training  array
float target_entropy=0;

using namespace std;
class node{
	public:
		int class_label;
		float Entrophy;
		int pos_inst,neg_inst;
		int predictive_class;
		class node * left_ptr;
		class node *right_ptr;
		class node* parent;
		public:
			node();
			~node();
			float compute_entropy(int attr, int& pos,int& neg,int& pos1,int& neg1);
			void select_best_attribute(vector<int> attr_list);
			void entropy_rootnode();
			void display(class node * r);
			void ID3_alg();
			
};
class node * root=NULL;
 node::node()
{
    class_label=0;
     Entrophy=0;
  	pos_inst=0;neg_inst=0;
  	predictive_class=-1;
	left_ptr=NULL;
    right_ptr=NULL;parent=NULL; 	
}
 node::~node()
{
  cout<<"node is pruned"<<endl;	
}

float node::compute_entropy(int attr, int& pos,int& neg,int& pos1,int& neg1)
{

     	int i,j;
     	float yes=0,no=0,total=0,total1=0;
     	
     	//target=YES(1) calculation for entropy
    	for(int i=0;i<row;i++)
    	{
           if(training_data[i][attr]==0)
           {
           	 total++;
           	 if(training_data[i][columns-1]==1)
           	     no++;
           }
           else
           {
           	 total1++;
           	 if(training_data[i][columns-1]==1 )
           	     yes++;
		   }    	
           
    	}
    	
    	float cal; // stores Entrophy for H(Y/(X = NO))
    	float pr1=no/total;
    	float pr2=1-(no/total);
    	cal=((-pr1)*log2(pr1)-(pr2)*log2(pr2));
    //	cout <<"calis "<<cal<<endl;
		pos=no;
    	neg=total-pos;
    	
    	float cal1; //stores Entrophy for H(Y/(X = YES))
    	float pr3=yes/total1;
    	float pr4=1-(yes/total1);
    	cal1=((-pr3)*log2(pr3)-(pr4)*log2(pr4));
    //	cout <<"cal1is1 "<<cal1<<endl;
    	
		pos1=yes;
    	neg1=total1-pos1;
    	
    	float sum=total+total1;
    	float no_pr=total/sum;
    	float yes_pr=total1/sum;
    	
     float total_entrophy= (no_pr*(cal)+yes_pr*(cal1));
    	
    	return (target_entropy-total_entrophy);
	}

void node::select_best_attribute(vector<int> attr_list)
{
	int i,store;
	float max=-9999;
	int str_pos=0,str_pos1=0,str_neg=0,str_neg1=0;
	for(i=0;i<attr_list.size();i++)
	{
		int pos=0,pos1=0,neg=0,neg1=0;
	    float computed=compute_entropy(attr_list[i],pos,neg,pos1,neg1);
		if(max < computed)
		{
			max=computed;
			store=attr_list[i];
			str_pos=pos;
			str_neg=neg;
			str_pos1=pos1;
			str_neg1=neg1;
			
		}
		
	}
}

void node::entropy_rootnode()
{
     	int i,j;
     	float yes=0,no=0,total=0 ,total1=0;
     	
     	//target=YES(1) calculation for entropy
    	for(int i=0;i<row;i++)
    	{
           	 if(training_data[i][columns-1]==1)
           	     yes++;
        }	
	   total=row;
	   no=total-yes;
	   float pr=yes/total;
	   float pr1=no/total;
	   cout<<"pr "<<pr<<"pr1 "<<pr1<<endl;
	   target_entropy=(-pr*(log2(pr))-(pr1*(log2(pr1))));
	   this->class_label=1;
	    this->Entrophy=target_entropy;
	    this->pos_inst=yes;
	    this->neg_inst=no;
	    	  
	
}

void node::display(class node * r)

{

   cout<<"entropy "<<target_entropy<<endl;
   cout<<"postive inst "<<r->pos_inst<<endl;
   cout<<"negative inst "<<r->neg_inst<<endl;
   cout<<"predictive_class "<<r->predictive_class<<endl;
}


//ID3 Algorithm Implemenataion Starts here.

void node::ID3_alg()
{
	int not_comp;

}

int main()
{
	//Read Input from text file 
    ifstream infile("C:\\Users\\SANDEEP\\Desktop\\Programming\\san.txt");
 //  infile>>test_cases;
   string line;
   //string array to store attributes and class label
   string arr[100];
   
    getline(infile,line,'\n');
   stringstream str(line);
   int counter=0;
   string temp;
   while (str>>temp !='\0')
   {
   	arr[counter]=temp;
   //	cout <<arr[counter]<<" ";
   	counter++;
   }
   no_of_attr=counter;
   columns=counter;
   
   memset(training_data,-1,sizeof(training_data));
   
   //cout <<endl;
  // cout<<test_cases<<endl;
  int i=0,j;
   while(getline(infile,line,'\n'))
   {  
     stringstream str1(line);
     int t1;
     j=0;
     while(str1>>t1 !='\0')
     {
     	training_data[i][j]=t1;
     	cout<<training_data[i][j]<<" ";
     	j++;
     
	 }
	 i++;
	 cout<<endl;
   }
   row=i;  
   
   class node * tree = new class node;
   
   tree-> entropy_rootnode();
 root=tree;
   tree->display(root);
   
   //Debug process 
   /*for(i=0;i<2;i++)
   {
   	int pos=0,neg=0,pos1=0,neg1=0;
   	class node* ss;
   	float ent=ss->compute_entropy(i,pos,neg,pos1,neg1);
   	   cout<<"entropy "<<ent<<endl;
       cout<<"postive_left inst "<<pos<<endl;
       cout<<"negative left inst "<<neg<<endl;
       cout<<"postive_right inst "<<pos1<<endl;
       cout<<"negative_right inst "<<neg1<<endl;
     //cout<<"predictive_class "<<r->predictive_class<<endl;
   }*/
   
   
	return 0;
}




