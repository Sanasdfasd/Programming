#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;
    int n;
    int q;
    int nodes[25000];
    int edges[25000][2];
//vector< vector<int> > edges(n-1,vector<int>(2));
int store[25000];
int cp[9000][9000];
bool res(int a,int b)
{

   if(a<=b)
   {
      if((b%a)!=0 || a==1)
        return false;
      else
        return true;
   }
   else if(a>b)
   {
         if((a%b)!=0 || b==1)
        return false;
      else
        return true;
   }
   
}

void recursive_solve(int stack[25000],int size)
{
 int i,j;
 //cout<<"the value od stack is "<<stack[size-1]<<endl;
 int prev=store[stack[size-1]];
 //cout<<"the value of previous is "<<prev<<endl;
 if(prev!=-1)
 { prev=edges[prev][0];
 for(i=store[stack[size-1]];i<=n-1;i++)
 {
  if(prev==edges[i][0])
  {
     for(j=0;j<size;j++)
     { cout<<"bwtween the values that are"<<edges[i][1]<<"  "<<stack[j]<<endl;
       if(!res(nodes[edges[i][1]],nodes[stack[j]]))
       { //cout<<"it is true"<<endl;
         int min=stack[j],min1=edges[i][1];
         if(min>min1)
         {
           int temp=min1;
           min1=min;
           min=temp;
         }
         cp[min][min1]=cp[min][min1]+1;
       }
     }
     cout<<"the edge that is pushed is "<<edges[i][1]<<endl;
     stack[size]= edges[i][1];
     recursive_solve(stack,size+1);
  }
  else
    break;
 }
}
}


int main(){

    cin >> n >> q;

    memset(store,-1,sizeof(store));
    memset(nodes,-1,sizeof(nodes));
    memset(edges,-1,sizeof(edges));
    for(int nodes_i = 0;nodes_i < n;nodes_i++){
       cin >> nodes[nodes_i];
    }
    int pre_val=0;
    int initial_value=0;

    for(int edges_i = 0;edges_i < n-1;edges_i++){
       for(int edges_j = 0;edges_j < 2;edges_j++){
        int val;
          cin >>val;
           edges[edges_i][edges_j]=val-1;
          if(pre_val!=val && edges_j==0)
             {
               store[val-1]=edges_i; 
               pre_val=val;
               if(edges_i==0)
                  initial_value=val-1;
             }
       }

    }
    int i,j;
    cout<<"the store value is "<<endl;
    for(i=0;i<n;i++)
    {
      cout<<store[i]<<" ";
    }
    cout<<endl;
    cout<<"the initial_vlaue is "<<initial_value<<endl;
    int stack[25000];
    memset(stack,-1,sizeof(stack));
    stack[0]=initial_value;
    
    memset(cp,0,sizeof(cp));
    recursive_solve(stack,1);
    cout<<"the value of cp is"<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
          cout<<cp[i][j]<<" ";
        }
        cout<<endl;
    }

    /*for(int a0 = 0; a0 < q; a0++){
        int u;
        cin >> u;
        int v;
        cin >> v;
        // your code goes here
    }*/
    return 0;
}
