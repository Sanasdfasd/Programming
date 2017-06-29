#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[105][4002];
int dp1[105][4002];

int dp_cal[105];
int dp_cal1[105];
int m,r,s;
int arr[105];
void calc(int sum1)
{ 
    int i,j,k;
    dp[0][0]=1;
    for(i=0;i<m;i++)
    {    
       //cout<<"the state"<<i+1<<endl;
     for(k=m-1;k>=0;k--)
      {
       for(j=0;j<=sum1;j++)
        {
              if(dp[k][j]!=0)
               {
                  //cout<<"the states at "<<k<<"left"<<j<<"  "<<dp[k][j]<<endl;
             
                    dp[k+1][j+arr[i]]= ((dp[k+1][j+arr[i]]+dp[k][j])%1000000007);  
  
               }
           }
            
        }
    }
  //  cout<<"the elements that form sum are"<<endl;
    for(i=0;i<=100;i++)
   {
      dp_cal[i]=(dp[i][sum1]%(1000000007));
     // cout<<dp_cal[i]<<" ";   
   }  
   //cout<<endl;
}

void calc_1(int sum1)
{ 
     int i,j,k;
    dp1[0][0]=1;
    for(i=0;i<m;i++)
    {    
       //cout<<"the state"<<i+1<<endl;
     for(k=m-1;k>=0;k--)
      {
       for(j=0;j<=sum1;j++)
        {
              if(dp1[k][j]!=0)
               {
                  //cout<<"the states at "<<k<<"left"<<j<<"  "<<dp[k][j]<<endl;
             
                    dp1[k+1][j+arr[i]]= ((dp1[k+1][j+arr[i]]+dp1[k][j])%1000000007);  
                  
               }
           }
            
        }
    }
   // cout<<"the elements that form sum 1 are"<<endl;
    for(i=0;i<=100;i++)
   {

      dp_cal1[i]=(dp[i][sum1]%(1000000007));   
     //   cout<<dp_cal1[i]<<" ";  
   }
  // cout<<endl;  
}



int main() {
    int i,j;
    memset(dp,0,sizeof(dp));
    memset(dp1,0,sizeof(dp1));
    cin>>m;
    cin>>r;
    cin>>s;
    for(i=0;i<m;i++)
    {
        cin>>arr[i];
    }
    int v1=(r+s)/2;
    int v2=(r-s)/2;
    //v1=500;
    calc(v1);
    calc_1(v2);
    long long int sum=0;
    //cout<<"the values are"<<endl;
    if(v1!=v2)
        {
   for(i=0;i<=100;i++) 
   {
      //cout<<dp_cal[i]<<" ";
     sum=sum+((dp_cal[i]*dp_cal1[i])%1000000007);
      sum=(sum%1000000007);
   }
    }
    else
    { 
        if(v1!=0 &&v2!=0)
            {
      for(i=0;i<=100;i++) 
      {
       if(dp_cal[i]!=0)
           {
           long long int values=(dp_cal[i]);
            values=values*values;
            values=values%(1000000007);
            sum=(sum+values)%(1000000007);
            sum=(sum%1000000007);
          }
      }
        }
        else
         {
          sum=0;   
        }
    }
    
   /* cout<<"here it starts"<<endl;
     for(i=1;i<=100;i++) 
   {
     cout<<dp_cal1[i]<<" ";
     /*sum=sum+((dp_cal[i]*dp_cal1[i])%1000000007);
      sum=(sum%1000000007);*/
   //}*/
    
cout<<sum<<endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
