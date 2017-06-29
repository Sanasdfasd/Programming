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
   //string array to store attributes and class label
   using namespace std;
   string arr[100];

class node{
	public:
		int class_label;
		float Entrophy;
		int pos_inst,neg_inst;
		int attrval;
		int predictive_class;
		class node * left_ptr;
		class node *right_ptr;
		class node* parent;
		public:
			node();
			~node();
			float compute_entropy(int attr, vector<int> &attr_list, vector<int>& que, vector<int> & path, int& pos,int& neg,int& pos1,int& neg1,int &,int&,float,float & );
			void select_best_attribute(vector<int> &attr_list,vector<int>& que, vector<int> & path,int index,int convert,int& break_cond,float);
			void entropy_rootnode();
			void display(class node * r, vector<char> ss,int vs);
			void ID3_alg(class node* nt, vector<int> attr,vector<int> que, vector<int> path,int index,float);
			
};
class node * root=NULL;
 node::node()
{
    class_label=0;
     Entrophy=0;
  	pos_inst=0;neg_inst=0;
  	predictive_class=-1;
	left_ptr=NULL;
	attrval=-1;
    right_ptr=NULL;parent=NULL; 	
}
 node::~node()
{
  cout<<"node is pruned"<<endl;	
}

float node::compute_entropy(int attr,vector<int> &attr_list, vector<int>& que, vector<int> & path, int& pos,int& neg,int& pos1,int& neg1,int & tot1,int & tot2,float ent,float & ent_tot)
{


int ss;

     	int i,j;
     	float yes=0,no=0,total=0,total1=0;
        int l=0;
     	//target=YES(1) calculation for entropy
    	for(int i=0;i<row;i++)
    	{ l=0;
    		for(j=0;j<que.size();j++)
    		{
    			if(training_data[i][que[j]]!=path[j])
    			  {
    			  	l=1;
    			  	break;
				  }
			}
			if(l==0)
			{ //cout<<"selecte row is "<<i<<endl;
		
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
           
    	}
    	tot1=total;
    	tot2=total1;
    //	cout <<"no "<<no <<"yes "<<yes<<"total "<<total<<"total1 "<<total1 <<endl;
    
    	float cal; // stores Entrophy for H(Y/(X = NO))
    	if(total!=0)
    	{
    	float pr1=no/total;
    //	int nss=pr1;
    	if(pr1==0)
        	pr1=1;
    	float pr2=1-(no/total);
    		if(pr2==0)
        	pr2=1;
    	
    	cal=((-pr1)*log2(pr1)-(pr2)*log2(pr2));
    	 	/*if(pr1==0)
    	     cal=0;*/
    //	cout <<"calis "<<cal<<endl;
		pos=no;
    	neg=total-pos;
		}
		else
		{
			cal=0;
			pos=no;
         	neg=total-pos;
		}

    	
    	float cal1; //stores Entrophy for H(Y/(X = YES))
    	if(total1!=0)
    	{
	
    	float pr3=yes/total1;
    	  	if(pr3==0)
    	  	{
    	  		pr3=1;
			  }
            
    	float pr4=1-(yes/total1);
    	  	if(pr4==0)
    	  	{
    	  		pr4=1;
			  }
    	cal1=((-pr3)*log2(pr3)-(pr4)*log2(pr4));
    //	cout <<"cal1is1 "<<cal1<<endl;
    /*	if(pr3==0)
    	  cal1=0;*/
		pos1=yes;
    	neg1=total1-pos1;
      }
      else
      {cal1=0;
      	pos1=yes;
    	neg1=total1-pos1;
	  }
    	
    	float sum=total+total1;
    	float no_pr=total/sum;
    	float yes_pr=total1/sum;
    	
     float total_entrophy= (no_pr*(cal)+yes_pr*(cal1));
         //	cout<<"taotal entrophy"<<total_entrophy<<endl;
    	//	cout<<"parent entrophy"<<ent<<endl;
    	//cout<<"the Gain converted is "<<(ent-total_entrophy)<<endl;
    	ent_tot=total_entrophy;

    	return (ent-total_entrophy);
	}

void node::select_best_attribute(vector<int> &attr_list,vector<int>& que, vector<int> & path,int index,int convert,int& break_cond,float ent)
{
	int i,store=0;
	float max=-9999;
	
	int str_pos=0,str_pos1=0,str_neg=0,str_neg1=0,str_tota1=0,str_tota2=0;
	float str_ent_tot=0;

	for(i=0;i<attr_list.size();i++)
	{
		int pos=0,pos1=0,neg=0,neg1=0,tota1=0,tota2=0;
				float ent_tot1=0;
	    float computed=compute_entropy(attr_list[i],attr_list,que,path,pos,neg,pos1,neg1,tota1,tota2,ent,ent_tot1);
		if(max < computed)
		{
			max=computed;
			store=attr_list[i];
			str_pos=pos;
			str_neg=neg;
			str_pos1=pos1;
			str_neg1=neg1;
			str_tota1=tota1;
			str_tota2=tota2;
			str_ent_tot=ent_tot1;
			
		}
		
	}
	if(str_tota1==0 || str_tota2==0)
	{
		cout<<"iam here plesae"<<endl;
		 break_cond=1;
		 //return;
	}
	
	 
if(convert==0)
{

	//cout<<" Entrophy  "<<max <<" store  "<<store<<" str_pos  "<<str_pos<<" str_neg   "<<str_neg<<" str_pos1   "<<str_pos1<<" str_neg1   "<<str_neg1<<endl;
	this->pos_inst=str_pos;
    this->neg_inst=str_neg;

	this->class_label=index;
	this->Entrophy=str_ent_tot;
	this->attrval=store;
	for(i=0;i<attr_list.size();i++)
	{
		if(store==attr_list[i])
		{
			break;
		}
	}
	cout<<"the element erased is "<<attr_list[i]<<endl;
	attr_list.erase(attr_list.begin()+i);

	
	//cout<<endl;
	  que.push_back(store);
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
	   if(pr==0)
	     pr=1;
	   float pr1=no/total;
	    if(pr1==0)
	      pr1=0;
	   //cout<<"pr "<<pr<<"pr1 "<<pr1<<endl;
	   target_entropy=(-pr*(log2(pr))-(pr1*(log2(pr1))));
	   this->class_label=1;
	    this->Entrophy=target_entropy;
	    this->pos_inst=yes;
	    this->neg_inst=no;
	    
	    	  
	
}

void node::display(class node * r,vector<char> ss,int vs)
{
  if(r)
   {
   	int i;
   	for(i=0;i<ss.size();i++)
   	{
   		cout<<ss[i]<<" ";
    }
   	if((r->attrval)!=-1)
   	{
        cout<<"ris value "<<arr[r->attrval]<<" : "<<vs<<endl;
        ss.push_back('|');
	}

  /*//cout<<"entropy "<<r->Entrophy<<endl;
   cout<<"r-label is "<<r->class_label<<endl;
   cout<<"postive inst "<<r->pos_inst<<endl;
   cout<<"negative inst "<<r->neg_inst<<endl;
   cout<<"r Entropy stored "<<r->Entrophy<<endl;
   //cout<<"predictive_class "<<r->predictive_class<<endl;

   //cout<<"************"<<endl;
   //cout<<"************"<<endl;*/
   display(r->left_ptr,ss,0);
   display(r->right_ptr, ss,1);
  }
}


//ID3 Algorithm Implementation Starts here.

void node::ID3_alg(class node* nt, vector<int> attr,vector<int> que, vector<int> path,int index,float ent)
{
	if(nt)
	{
cout <<"attribute size is "<<attr.size()<<"que size"<<que.size()<<endl;
int i,j;
cout<<"attr_list";
vector<int> attr_temp;
vector<int> que_temp;
vector<int> path_temp;
for(i=0;i<attr.size();i++)
{
	cout<<" "<<attr[i];
	attr_temp.push_back(attr[i]);
	//	cout<<" "<<attr_temp[i];
		
}
cout<<"que";
for(j=0;j<que.size();j++)
{
	cout<<" "<<que[j];
	que_temp.push_back(que[j]);
//	cout<<" "<<que_temp[j];
}
cout<<endl;
cout<<"path is ";
for(j=0;j<path.size();j++)
{
	
	path_temp.push_back(path[j]);
	cout<<" "<<path_temp[j];
}
cout <<endl;
	if(attr.size()==0)
	{
		int ma;
		ma=nt->pos_inst;
		nt->predictive_class=1;
		if(ma<nt->neg_inst)
		 {
	    	nt->predictive_class=0;
		 } 
		 cout<<"iam returning here"<<endl;
		 return ;
		  
	}
	if(nt->pos_inst==0)
	{
		nt->predictive_class=0;
		cout<<"iam returning here 1"<<endl;
		return;
		
	}
	if(nt->neg_inst==0)
	{
		nt->predictive_class=1;
		cout<<"iam returning here 2"<<endl;
		return;
		
	}
	
    if(que.size()==columns-1)
   {
   	 	int ma;
		ma=nt->pos_inst;
		nt->predictive_class=1;
		if(ma<nt->neg_inst)
		 {
	    	nt->predictive_class=0;
		 } 
		 cout<<"iam returning here 3"<<endl;
		 return;
   }
   else
   {
   	 class node* tem1=new class node;
     class node* tem2=new class node;  
     int convert=0;
    int break_cond=0;
   	ent=nt->Entrophy;
     tem1->select_best_attribute(attr,que,path,index+1,convert,break_cond,ent);
     path.push_back(0);
     nt->left_ptr=tem1;
     tem1->parent=nt;
     //display(tem1);
     if(break_cond!=1)
      ID3_alg(nt->left_ptr,attr,que,path,index+1,ent);
     else
      cout<<"returning it is ****"<<endl;
     cout <<"index+1 is"<<index+1<<endl;
cout<<"attr_list";
for(i=0;i<attr_temp.size();i++)
{
	cout<<" "<<attr_temp[i];
	
}
cout<<"que_temp";
for(j=0;j<que_temp.size();j++)
{
	cout<<" "<<que_temp[j];
}
cout<<endl;

    //path_temp.erase(path.end()-1,path.end());
    path_temp.push_back(1);
    cout<<"path_temp is";
for(j=0;j<path_temp.size();j++)
{
	cout<<" "<<path_temp[j];
}
cout<<endl;
       convert=1;
       	tem2->attrval=nt->left_ptr->attrval;
	for(i=0;i<attr_temp.size();i++)
	{
		if(tem2->attrval==attr_temp[i])
		{
			break;
		}
	}
	cout<<"the element erased is "<<attr_temp[i]<<endl;
	int bbc=attr_temp[i];
	attr_temp.erase(attr_temp.begin()+i);
	que_temp.push_back(bbc);
	tem2->class_label=index+2;
	tem2->Entrophy=nt->left_ptr->Entrophy;
	ent=tem2->Entrophy;
	tem2->pos_inst=(nt->pos_inst)-(nt->left_ptr->pos_inst);
	tem2->neg_inst=(nt->neg_inst)-(nt->left_ptr->neg_inst);
	
    break_cond=0;
    tem2->select_best_attribute(attr_temp,que_temp,path_temp,index+2,convert,break_cond,ent);
     path_temp.push_back(1);
    nt->right_ptr=tem2;
     tem2->parent=nt;
    //display(tem2);
   // cout<<"iam breaking here 4"<<endl;
   if(break_cond!=1)
    ID3_alg(nt->right_ptr,attr_temp,que_temp,path_temp,index+2,ent);
     else
     cout<<"returning1 it is ****"<<endl;

    

     
   }
}
}

int main()
{
	//Read Input from text file 
    ifstream infile("C:\\Users\\SANDEEP\\Desktop\\Programming\\san.txt");
 //  infile>>test_cases;
    string line;
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
  // attr.erase(attr.end()-1);
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
   
   vector<int> que;
    vector<int> path;
   class node * tree = new class node;
   tree->entropy_rootnode();
   root=tree;
   root->Entrophy=target_entropy;
     vector<int> attrs;
     for(i=0;i<columns-1;i++)
     {
     	attrs.push_back(i);
	 }

   tree->ID3_alg(root,attrs,que,path,1,target_entropy);
   vector<char> ss;
   tree->display(root,ss,0);
      
   
	return 0;
}




