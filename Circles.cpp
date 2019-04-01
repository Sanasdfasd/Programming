//
// Created by Sandeep on 11/16/2018.
//
#include <bits/stdc++.h>
using namespace std;
vector< pair<double, double> > circles;
double radius=4.0;
void random_generator( int n){
  for(int i=0;i<n;i++) {
    double x_cord = rand() % 100;
    double y_cord = rand() % 100;
    circles.push_back({x_cord, y_cord});
  }
}

bool cmp(pair<double,double> fst, pair<double, double> sec){
  if( fst.first != sec.first)
    return fst.first<sec.first;
  else
    return fst.second< sec.second;
}
bool intersect( pair<double, double> fst , pair< double, double> sec){\
  double dist= sqrt(pow((sec.first- fst.first),2)+ pow((sec.second- fst.second),2));
   if( abs(dist-(2.0*radius))<0.000000001)
     return true;
  return false;
}
int main(){
  srand (time(NULL));
  int n;
  cin>>n;
  random_generator(n);
  sort(circles.begin(),circles.end(),cmp);

   vector<pair<int, int> > res;
  //two circles xi,yi and xj,yj
  // sqrt((xj-xi)^2+ (yj-yi)^2) <=2r
  for(int i=0;i<circles.size();i++){
   for(int j=i+1;j<circles.size();j++){
        if(intersect(circles[i],circles[j])){
          res.push_back({i,j});
        }
   }
  }
  cout<<res.size()<<endl;
  for(int i=0;i<res.size();i++){
    cout<<res[i].first<<" "<<res[i].second<<endl;
  }
  vector <int> mat[26][26];

  //insert c1 into this position of mat[floor(c1.x/radius)][[floor(c1.y/radius)]
  for(int i=0;i<circles.size();i++){
       mat[(int)floor(circles[i].first/radius)][(int)floor(circles[i].first/radius)]]=i;
  }
  for(int i=0;i<26;i++){
    for(int j=0;j<26;j++){

      //if mat[i][j] has a circle
      //loop through matrix positions mat[i-1][j-1] through mat[i+1][j+1] and
      //find all the circles in them
      //run the intersect functions on these circles

      //check for neighbouring circles
      if(mat[i-1][j])

    }
  }





return 0;
}
