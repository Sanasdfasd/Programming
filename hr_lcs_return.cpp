#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std ;

int a_size=5000,b_size=5000;

char a[5000],b[5000];

int lcs[5000][5000];

int main()
{
scanf("%s",a);
scanf("%s",b);
int a_size= strlen(a);
int b_size= strlen(b);

int i,j,k;
std::memset(lcs , 0 , sizeof(lcs));

for(i=0;i<a_size;i++)
{
	int max=0;
	for(j=0;j<b_size;j++)
	{
       if(a[i]==b[j])
       { if(i!=0 && j!=0)
          lcs[i][j]=lcs[i-1][j-1]+1;
          else
          	lcs[i][j]=1;
       }

      else if(i!=0 && j!=0)
       {   
     	  max=lcs[i-1][j];
          if(max <lcs[i][j-1])
           	max=lcs[i][j-1];
              lcs[i][j]=max;   
       }
	}
}

cout<<"the value of it is "<<lcs[i-1][j-1]<<endl;
int val;
int max_value=lcs[i-1][j-1];
int total_no=0;
for(i=a_size;i>=0;i--)
{
for(k=0;k<26;k++)
 {int tr=0;
  for(j=b_size-1;j>=0;j--)
  { int store=0;
    if((i-1)>-1)
    {
       int v='a'+k;
    //   cout<<"the value is "<<(char)v<<endl;
       if((char)v==(b[j]))
       {
        //cout<<"Iam equal at this point and i,j are1 "<<i<<" "<<j<<endl; 
        if((j-1)!=-1)
          {long long int gh1=(lcs[a_size-1][j-1]-lcs[i-1][j-1]);
            long long int gh2=(lcs[i-1][b_size-1]-lcs[i-1][j-1]);
          store=1+max_value-(lcs[a_size-1][j]-lcs[a_size-1][j-1]);
          if(gh1>0)
            store=store-gh1;
          if(gh2>0)
            store=store-gh2;
        }
        else
          store=1;
        //cout<<"Iam equal at this point and i,j are1 "<<i<<" "<<j<<"store"<<store<<endl; 
       }
    }
    else
    {
       int v='a'+k;
       if((char)v==(b[j]))
       {
         if((j-1)!=-1)
          store=0+max_value+1-(lcs[a_size-1][j]-lcs[a_size-1][j-1]);
        else
           store=0+1+max_value-lcs[a_size-1][j];
        // cout<<"Iam equal at this point and i,j are2 "<<i<<" "<<j<<"store"<<store<<endl; 
       }
    }
   if(store>max_value)
   {
   // cout<<"total_no is at is "<<total_no<<endl;
    total_no=total_no+1;
    tr=1;
     break;
    }
  }
  /*if(tr==1)
    break;*/
}
}
cout<<total_no<<endl;

return 0;
}