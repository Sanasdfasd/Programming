#include <bits/stdc++.h>

using namespace std;
 long long int ts[2000000+5];
int main()
{

 long long int n,c;

 long long int i,j;
 cin>>n>>c;
 for(i=0;i<n;i++)
 	cin>>ts[i];
long long int count=n;
long long int curr_counter=0;
for(i=0;i<n;i++)
{
	//cout<<" the value of i is "<<i<<endl;
	//int temp_var=i+1;
	//cout<<" the temp _varible is "<<temp_var<<endl;
	if((i+1)<n)
	{
		if((ts[i+1]-ts[i]) > c)
        {
        	count=(count-(i-curr_counter+1));
        	curr_counter=i+1;
        	//cout<<" iam here "<<endl;
        }

	}
	//cout<<" the count is "<<count<<"  "<<curr_counter<<endl;
}


cout<<count<<endl;
	return 0;
}