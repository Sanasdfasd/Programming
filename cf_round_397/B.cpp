#include <bits/stdc++.h>

using namespace std;

int main()
{


 memset(arr, 0,sizeof(arr));
 for(i=0;i<n;i++)
 {
 	cin>>pr[i];
 	if((pr[i])!=i+1)
 		arr[i]=1;
 }
 as[0]=arr[0];

 for(i=1;i<n;i++)
 {
   as[i]=as[i-1]+arr[i];
cout<<as[i]<<"  ";
}
cout<<endl;
cout<<" iam her dfsdf"<<endl;
for(i=0;i<m;i++)
{
  int a,b,c;
  cin>>a>>b>>c;
  if((b-a)==0)
  	cout<<"Yes"<<endl;
  else
  {
  	    int temp= as[c-1];
  	if( (a-1 )==0)
       temp=temp-0;
   else
   	  temp=temp-as[a-2];
    int temp2=as[b-1]-as[c-1];
       	cout<<" the values of tempare  "<<temp<<"  "<<temp2<<endl;
    if(temp==temp2)
    	cout<<"Yes"<<endl;
    else
    	cout<<"No"<<endl;
  }

}

return 0;
}