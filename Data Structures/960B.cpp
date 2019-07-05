#include <bits/stdc++.h>
using namespace std;

int main(){

	int n,k1,k2;
	cin>>n>>k1>>k2;
	vector<int> a(n);
	vector<int> b(n);
	for(int i=0;i<n;i++) cin>>a[i];
    for(int j=0;j<n;j++) cin>> b[j];
    
    long long int k=k1+k2;
    priority_queue<long long int, vector<long long int>, std::less<long long int> > pq;

   for(int i=0;i<n;i++){
     pq.push(abs(b[i]-a[i]));
   }

    while(k>0){
      long long int top=pq.top(); 
      if(top==0)
        break;
      pq.pop();
       pq.push(top-1LL);
       k--;
    }
    long long int ans=0;
    ans+=(k%2==1);

    while(!pq.empty()){
     long long int top= pq.top();
     pq.pop();
     ans+=(top*top);
    }	

   cout<<ans<<endl;
	return 0;
}