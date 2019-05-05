//
// Created by Sandeep on 4/1/2019.
//
#include <iostream>
#include <queue>

using namespace std;
class node {
 public:
  int row;
  int col;
  int k_left;
  char v;
  node(int row, int col, int k_left, char v) {
    this->row = row;
    this->col = col;
    this->k_left = k_left;
    this->v = v;
  }
};
bool check(int row, int col, int n) {
  if (row < n && col < n)
    return true;
  return false;
}
node *vec[2007][2007];
char inp[2007][2007];
queue<node *> q;
void update(int row, int col, int r, int c, int k_left, char v) {
  vec[row][col]->row = r;
  vec[row][col]->col = c;
  vec[row][col]->k_left = k_left;
  vec[row][col]->v = v;
  q.push(new node(row, col, k_left, v));
}

void processNode(node *top, int row, int col) {
  if (inp[row][col] != 'a' && (top->k_left > 0 && vec[row][col]->k_left < top->k_left - 1)) {
    update(row, col, top->row, top->col, top->k_left - 1, 'a');
  } else {
    int r = vec[row][col]->row;
    int c = vec[row][col]->col;
     if(r!=-1 && c!=-1) {
    //   cout<<" the values are "<<" "<<top->row<<" "<<top->col<<" "<<(int)vec[r][c]->v<<" "<<(int)top->v<<endl;
       if ((int) vec[r][c]->v >= (int) top->v) {

         update(row, col, top->row, top->col, top->k_left, vec[row][col]->v);
       }
     }
    else{
       update(row, col, top->row, top->col, top->k_left, vec[row][col]->v);
     }

  }
}

int main() {
  int n, k;
  cin >> n;
  cin >> k;
  for (int i = 0; i < n; i++) {
    cin >> inp[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) vec[i][j] = new node(-1, -1, -1,inp[i][j]);
  }
  if (k > 0 && inp[0][0] != 'a') {
    q.push(new node(0, 0, k - 1, 'a'));
    vec[0][0]->k_left = k - 1;
    vec[0][0]->v = 'a';
  } else {
    q.push(new node(0, 0, k, inp[0][0]));
    vec[0][0]->k_left = k;
    vec[0][0]->v = inp[0][0];
  }
  while (!q.empty()) {
    node *top = q.front();
    q.pop();
    int row = top->row;
    int col = top->col + 1;
    if (check(row, col, n)) {
      processNode(top, row, col);
    }
    row = top->row + 1;
    col = top->col;
    if (check(row, col, n)) {
      processNode(top, row, col);
    }
  }
  for (int i = 0; i < n; i++) {
    cout << " the row is " << i + 1 << endl;
    for (int j = 0; j < n; j++) {
      cout << vec[i][j]->k_left << " ";
    }
    cout << "\n";
  }
  for (int i = 0; i < n; i++) {
    cout << " the row is " << i + 1 << endl;
    for (int j = 0; j < n; j++) {
      cout << vec[i][j]->row << "," << vec[i][j]->col << " ";
    }
    cout << "\n";
  }

  return 0;
}



