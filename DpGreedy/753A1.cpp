#include <bits/stdc++.h>
using namespace std;

int main(){

   int n;
   cin>>n;
   int k=n;
   while((k*(k+1)/2)>n){
      k--;
   }

   if(n==(k*(k+1)/2)){
   	cout<<k<<endl;
    for(int j=k;j>=1;j--){
     cout<<j<<" ";
     }
   }
   else{
     k++;
     int tot_value=(k*(k+1))/2;
     int left_over=tot_value-n;
     cout<<k-1<<endl;
     for(int i=1;i<=k;i++){
      if(i!=left_over)
     	cout<<i<<" ";
     }
   }
   
    cout<<endl;
	return 0;
}