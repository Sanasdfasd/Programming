//
// Created by Sandeep on 3/6/2019.
//

#include<bits/stdc++.h>
using namespace std;
// Hi this is sandeep
class complexNumber{
    private:
    int real;
    int img;
C
    public:
    complexNumber(int r=0,int i=0){
      real=r;
      img=i;
    }
  const complexNumber operator=(int a){
    return complexNumber(a);
  }
  friend const complexNumber operator*( const complexNumber& left, const complexNumber& right);

  void print(){
      cout<<real<<" "<<img<<endl;
    }
};

const complexNumber operator*(const complexNumber& left,const complexNumber& right){
  complexNumber res;
  res.real= left.real* right.real;
  res.img= -left.img*right.img;
  return res;
}
int main(){
  complexNumber a (2,3);

  complexNumber b (4,-5);
  complexNumber r1 = a*b; // stmt 1
  r1.print();
  complexNumber r2 = -6*a; //stmt 2
   r2.print();
  complexNumber r3 = b*-7; //stmt 3
  r3.print();

}


