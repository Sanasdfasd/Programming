//
// Created by Sandeep on 2/14/2019.
//
Alan and Bob finish their construction contract and go to collect their wages.
Alan get N bags and Bob gets M bags of money
There’s been a mistake (one bag is swapped) and hence Alan and Bob get non-uniform wages.
Find a pair of bags (x,y) such that if Alan gives Bob bag x and Bob gives Alan bag y, they get equal wages
    A=(2,5,10,6)
B=(5,6,2,9,12)

sum_A -x +y = sum_B- y +x
2y=sumB-sum_A+2x;
y=(suB-sum_A+2*x)/2;
// -1, -1;
pair<int, int>  equalwages( vector<int>& a, vector<int> b){
  // sum of both these vectors and store it in sum1 and sum2
  // iterate thorugh vector b and count of each value in a map;
  // iterate through vector a and
          // cur element  sum1-cur= sum2-l
                 // sum1+l= sum2+cur-l;
  pair<int,int> ans;
  ans.first=-1;
  ans.second=-1;
  int sum_A=0,sum_B;
  for(int i=0;i<a.size();i++) {
    sum_A+=a[i];
  }
  for(int i=0;i<b.size();j++){
    sum_B+=b[i];
  }
  set<int> s;
  for(int i=0;i<b.size();i++){
    s.insert(b[i]);
  }

 for(int i=0;i<a.size();i++){
   int elem= (abs(sum_B-sum_A)+2*a[i])/2;
    if(s.find(elem)!=s.end()){
      ans.first=a[i];
      ans.second=elem;
      return ans;
    }
 }

  return ans;
}
