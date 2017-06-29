#include<stdio.h>
#include<iostream>
#include<memory.h>
//
#include<cstdlib>
#include<string>
//#include<cstring>
using namespace std;
long long int arr[400][400];
int next_index[205];
long long int compute_recursive(int i, int j,char str[])
{
	int p,q;
	for(q=0;q<=j;q++)
	{
		for(p=j;p>=0;p--)
		{
			cout <<"p"<<p <<"q"<<q<<endl;
			if(p>=q)
			{
				arr[p][q]=0;
			}
			else
			{

		int m,top=0,seq=0;
		long long int count=0;
		memset(next_index,0,sizeof(next_index));
		for(m=p+1;m<=(q);m++)
		{
			if(str[p]==str[m])
			{
				next_index[top++]=m;
			}
		}
		
		if((p+1)<=j)
		{
		  count =arr[p+1][q];
		  cout <<"iam adding value of "<<count<<endl;
		}
		if(top==0)
		{
			arr[p][q]=count;
		}
		else
		{
      int first=0;
		for(m=p+1;m<=q;m++)
		{
			if(str[p]==str[m])
			{
				if(m+1<=q)
				{
					count =count+arr[m][q]-arr[m+1][q];
				}

			 if(first==0)
			 {
			 	count=count+1;
			 	first++;
			 }	
			}	
		}
		seq=top-1;
		int locator=q,counter=1;
           cout <<"the first 1 cout is "<<count <<endl;
		for(m=q;m>=p+1;m--)
		{
		    if(str[p]==str[m])
			{
			
			    count =((counter)*count) + arr[p+1][locator]-arr[p+1][next_index[seq]]-arr[next_index[seq]][locator];
				seq--;
				locator=next_index[seq];
			}
		}
		 cout <<"the first 2 cout is "<<count <<endl;
		arr[p][q]=count;
		cout<<"iam here 2 "<<arr[p][q]<<endl;
		}
	}
	}
	}
	return arr[i][j];
  
}
 int main()
 {
 	int test_cases;
 	cin>>test_cases;
 	while((test_cases--)>0)
 	{
 		char str[205];
 		scanf("%s",str);
 		int i=0;
 		while(str[i]!='\0')
 		{
 			i++;
		}
 		memset(arr,-1,sizeof(arr));
 		//cout<<"str length  is "<<i-1<<endl;
 		long long int res=0;
		 res=compute_recursive(0,i-1,str);
 		cout<<res<<endl;
    }
 	return 0;
 }
