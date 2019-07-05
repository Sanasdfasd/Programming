#include <bits/stdc++.h>
using namespace std;
long long int INF= 1e17+5;
void cmp(long long int & val1, long long int val2){
	if(val1>=val2 ){
      val1=val2;
	}
}
int main(){

  	int n;
  	cin>>n;
  	vector<long long int> inp(n);
  	vector<long long int> prefix_sums(n+1);
  	for(int i=0;i<n;i++) {
  		cin>>inp[i];
  		prefix_sums[i+1]=prefix_sums[i]+inp[i];
  	}
  	//tc[i][j] denotes the total cost incurred to combine slimes from i...j	
  	vector<vector<long long int>> tc( n+1, vector<long long int>(n+1, INF));
    for(int j=0;j<n;j++){
    	if((j-1)>=0)
           cmp(tc[j-1][j], inp[j-1]+inp[j]);
    	for(int i=(j-2);i>=0;i--){	
           	 cmp(tc[i][j], prefix_sums[j]- prefix_sums[i]+inp[j]+tc[i][j-1]);
           	 cmp(tc[i][j], prefix_sums[j+1]-prefix_sums[i+1]+inp[i]+tc[i+1][j]);
    		for(int k=i+1;k<(j-1);k++)
               cmp(tc[i][j], prefix_sums[j+1]-prefix_sums[i]+tc[i][k]+tc[k+1][j]);
    	}     
    }
    
    cout<<tc[0][n-1]<<endl;

	return 0;
}